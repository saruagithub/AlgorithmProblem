#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    unordered_set<char> uset;
    int res = 0;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
        while (uset.find(s[i]) != uset.end()) {
            uset.erase(s[left]);
            left++;
        }
        res = max(res, i - left + 1);
        uset.insert(s[i]);
    }
    return res;
}

