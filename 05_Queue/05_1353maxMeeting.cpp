// 最多可以参加的会议数目
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 对于每一个时间点，所有在当前时间及之前时间开始，并且在当前时间还未结束的会议都是可参加的。
// 显然，在所有可参加的会议中，选择结束时间最早的会议是最优的, 因为其他会议还有更多的机会可以去参加。

// 我们可以使用一个小根堆记录所有当前可参加会议的结束时间。
// 在每一个时间点，我们首先将当前时间点开始的会议加入小根堆，
// 再把当前已经结束的会议移除出小根堆（因为已经无法参加了），
// 然后从剩下的会议中选择一个结束时间最早的去参加。

// 为了快速获得当前时间点开始的会议，
// 我们以O(N)O(N)O(N)时间预处理得到每个时间点开始的会议的序号。
int maxEvents(vector<vector<int>>& events) {
    int MAX = 1e5 + 1;
    vector<vector<int>> event_left(MAX);
    int res = 0;
    for (int i = 0; i < events.size(); i++) {
        event_left[events[i][0]].push_back(i);
        // event开始时间 所在原event的下标
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < MAX; i++) {
        //遍历所有 i 会议起始时间
        for (int j: event_left[i]) {
            pq.push(events[j][1]);
        }
        while(!pq.empty() && pq.top() < i) pq.pop();
        if (!pq.empty()) {
            pq.pop();  // 选了结束最早的会后，继续保留那些开始时间早的会
            res++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> events = {{1,2}, {2,3}, {3,4}, {1,2}};
    cout << maxEvents(events) << endl;
    return 0;
}