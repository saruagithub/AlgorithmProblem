#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// Leecode57 插入区间 /  合并区间
// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出：[[1,5],[6,9]]   
// 其实情况很多， 分类讨论不如直接求并集

vector<vector<int>> insert( vector<vector<int>>& intervals,  vector<int>& newInterval) {
    vector<vector<int>> ans;
    intervals.push_back(newInterval);
            // 区间第一位已经有序了 [1,3] [2,5] [6,9]
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (auto &x : intervals) {
        if (x[0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], x[1]);
        }
        else ans.push_back(x);
    }
    return ans;
}

// // init:  vector<vector<int>> vec(m, vector<int>(2, 0));  // all elem = 0
// Leecode 1272 删除区间
// 输入：intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
// 输出：[[0,1],[6,7]]
vector<vector<int>> removeInterval(vector<vector<int>>& intervals, 
                                    vector<int>& toBeRemoved) 
{
    vector<vector<int>> res;
    for (auto x: intervals) {
        if (x[0] > toBeRemoved[1] || x[1] < toBeRemoved[0]) {
            res.push_back(x);
        } else {
            if (toBeRemoved[0] > x[0]) res.push_back({x[0], toBeRemoved[0]});
            if (toBeRemoved[1] < x[1]) res.push_back({toBeRemoved[1], x[1]});
        }
    }
    return res;
}

// Leecode 435 无重叠区间
// 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
// 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
// 输出: 1
// 解释: 移除 [1,3] 后，剩下的区间没有重叠。
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int res = 0;
    if (intervals.size() <= 1) return res;
    vector<vector<int>> newinter;
    int lastend = intervals[0][1];  
    // 贪心 选择开始值大 结束值小的， 更新区间右边界
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < lastend) {
            res++;
            lastend = min(intervals[i][1], lastend);
        } else {
            lastend = intervals[i][1];
        }
    }
    return res;
}

// leecode 253 给你一个会议时间安排的数组 intervals ，
// 每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。
// 输入：intervals = [[0,30],[5,10],[15,20]]
// 输出：2
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) return 1;
    // duplicated, update the min end by priority_queue, res = queue.size
    sort(intervals.begin(), intervals.end());
    int res = 1;
    priority_queue<int, vector<int>, greater<int>> que;
    que.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= que.top()) {
            que.pop();
        }
        // more room and end time
        que.push(intervals[i][1]);
    }
    return que.size();
}
// 转换为最多线段重合的问题

// leecode 763, 划分字母区间
// 输入：s = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
vector<int> partitionLabels(string s) {
    vector<int> res;
    int array[26];
    for (int i = 0; i < s.size(); i++) {
        array[s[i] - 'a'] = i; 
    }
    int lastsplitindex = 0, farindex = 0;
    for (int i = 0; i < s.size(); i++) {
        farindex = max(farindex, array[s[i] - 'a']);
        if (i == farindex) {
            res.push_back(farindex + 1 - lastsplitindex);
            lastsplitindex = farindex + 1;
        }
    }
    return res;
}