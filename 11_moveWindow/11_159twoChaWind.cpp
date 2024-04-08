#include "../21_Huawei/21_header.h"

// 输入：s = "ccaabbb"
// 输出：5
// 解释：满足题目要求的子串是 "aabbb" ，长度为 5 。

// 输入：s = "eceba"
// 输出：3
// 解释：满足题目要求的子串是 "ece" ，长度为 3 。

// k = 2

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> mp;
    int k = 2;
    int l = 0, r = 0;
    int res = 0;
    while (r < s.size()) {
        // r move
        while (r < s.size() && (mp.size() < k || mp.count(s[r]))) {
            mp[s[r]]++;
            r++;
        }
        res = max(res, r - l);
        // cout << "1- " << l << " " << r << endl;
        // if (r < s.size()) mp[s[r]]++;
        // l move
        while (l < s.size() && mp.size() >= k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
    }
    return res;
}