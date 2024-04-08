#include <vector>

// leecode1700
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int> cnt(2,0);
    for (int stu : students) cnt[stu]++;
    // sandwich 顺序不变
    for (int san : sandwiches) {
        if (cnt[san] == 0) break;
        cnt[san]--;
    }
    return cnt[0] + cnt[1];
}