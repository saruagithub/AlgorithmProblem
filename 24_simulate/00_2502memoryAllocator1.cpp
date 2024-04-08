#include "../21_Huawei/21_header.h"

class Allocator {
public:
    Allocator(int n)
    {
        mMemFree.insert({ 0, n - 1 });
    }

    int allocate(int size, int mID)
    {
        for (auto &chunk : mMemFree) {
            if ((chunk.second - chunk.first + 1) < size) {
                continue;
            }
            int start = chunk.first;
            int mid = chunk.first + size - 1;
            int end = chunk.second;
            mMemFree.erase(chunk);
            if (end > mid) {
                mMemFree.insert({ mid + 1, end });
            }
            mMemIndex[mID].emplace_back(start, mid);
            return start;
        }
        return -1;
    }

    int free(int mID)
    {
        int cnt{ 0 };
        if (mMemIndex.count(mID) == 0) {
            return cnt;
        }
        for (auto &chunk : mMemIndex[mID]) {
            mMemFree.insert(chunk);
            cnt += chunk.second - chunk.first + 1;
        }
        mMemIndex.erase(mID);
        MemUpdate();
        return cnt;
    }

private:
    unordered_map<int, vector<pair<int, int>>> mMemIndex;
    set<pair<int, int>> mMemFree;
    void MemUpdate()
    {
        deque<pair<int, int>> curQ;
        set<pair<int, int>> backMem = mMemFree;
        for (auto &chunk : backMem) {
            curQ.emplace_back(chunk);
            while (curQ.size() > 1) {
                Combine(curQ);
            }
        }
    }
    void Combine(deque<pair<int, int>> &curQ)
    {
        if (curQ.back().first == curQ.front().second + 1) {
            int start = curQ.begin()->first;
            int end = curQ.back().second;
            mMemFree.erase(curQ.front());
            curQ.pop_front();
            mMemFree.erase(curQ.back());
            curQ.pop_front();
            curQ.emplace_back(start, end);
            mMemFree.insert({ start, end });
        } else {
            curQ.pop_front();
        }
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */