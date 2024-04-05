#include "../21_Huawei/21_header.h"
#include <list>

class Twitter {
public:
    unordered_map<int, int> tweetTime;
    unordered_map<int, list<int>> usrTweet;
    unordered_map<int, unordered_set<int>> usrusr;
    int recentMax, curtime;

    Twitter() {
        curtime = 0;
        recentMax = 10;
        //usrusr.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        // if (!usrTweet.count(userId)) {
        //     usrTweet[userId] = new list();
        // }
        if (usrTweet.count(userId) && usrTweet[userId].size() == recentMax) {
            usrTweet[userId].pop_back();
        }
        usrTweet[userId].push_front(tweetId);
        tweetTime[tweetId] = curtime;
        curtime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> allusr;
        allusr = usrusr[userId];
        if (!allusr.count(userId)) allusr.insert(userId);
        // alluser's tweet link list merge, get 10
        // tweet and time, sort by time

        struct cmp {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        // each user put 10 into priority_que
        for (int usr : allusr) {
            int cnt = 0;
            for (auto it = usrTweet[usr].begin(); it != usrTweet[usr].end(); it++) {
                if (cnt >= 10) break;
                que.push(make_pair(*it, tweetTime[*it]));
                cnt++;
            }
        }
        vector<int> res;
        for (int i = 0; i < 10; i++) {
            if (que.empty()) break;
            int tmp = que.top().first;
            que.pop();
            res.push_back(tmp);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // if (!usrTweet.count(followerId)) {
        //     usrTweet[followerId] = new list();
        // }
        // if (!usrTweet.count(followerId)) {
        //     usrTweet[followeeId] = new list();
        // }
        usrusr[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usrusr[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */