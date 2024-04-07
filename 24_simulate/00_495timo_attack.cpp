#include <vector>

// leecode495
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int res = 0, right  = 0;
    for (int i = 0; i < timeSeries.size(); i++) {
        if (timeSeries[i] < right) {
            res += timeSeries[i] + duration - right;
        }
        else {
            res += duration;
        }
        right = timeSeries[i] + duration;
    }
    return res;
}