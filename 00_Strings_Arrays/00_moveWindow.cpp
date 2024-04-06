#include <unordered_set>
#include <iostream>
using namespace std;

// leecode 3
// 比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，
// 当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！
// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    unordered_set<char> lookup;
    int res = 0;
    int left = 0;
    for(int i = 0; i < s.size(); i++) {
        while (lookup.find(s[i]) != lookup.end()){
            lookup.erase(s[left]);
            left++;
        }
        res = max(res,i - left + 1);
        lookup.insert(s[i]);
    }
    return res;
    
}

// 作者：powcai
// 链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/3982/hua-dong-chuang-kou-by-powcai/