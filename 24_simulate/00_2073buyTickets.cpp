#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n = tickets.size();
    int res = 0;
    for (int i = 0; i < n; ++i){
        // 遍历计算每个人所需时间
        if (i <= k){
            res += min(tickets[i], tickets[k]);
        }
        else{
            res += min(tickets[i], tickets[k] - 1);
        }
    }
    return res;
}


int timeRequiredToBuy(vector<int>& tickets, int k) {
    int res = 0;
    while (tickets[k] > 0) {
        for (int i = 0; i < tickets.size(); i++) {
            if (tickets[i] > 0) {
                res++;
                tickets[i]--;
            }
            if (tickets[k] == 0) return res;
        }
    }
    return res;
}