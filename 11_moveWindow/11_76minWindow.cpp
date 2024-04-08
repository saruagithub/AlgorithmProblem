// leecode76 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 

// 在滑动窗口类型的问题中都会有两个指针，一个用于「延伸」现有窗口的 rrr 指针，和一个用于「收缩」窗口的 lll 指针。

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。

#include "../21_Huawei/21_header.h"

unordered_map<char, int> orig, window;
bool check() {
    for (auto &[k, v]: orig) {
        if (!window.count(k) || window[k] < v) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    for (char c : t) {
        orig[c]++;
    }
    if (t.size() == s.size()) {
        for (char c : s) window[c]++;
        if (check()) return s;
        else return "";
    }
    int l = 0, r = 0 ,res = INT_MAX;
    int resl, resr;
    //bool flag = false;
    while (r < s.size()) {
        // r expand
        while (r < s.size() && check() == false) {
            window[s[r]]++;
            r++;
        }
        //cout << "1-" << l << " " << r << endl;
        if (check() == true && r - l < res) {
            resl = l, resr = r;
            res = r - l;
        }
        while (l < s.size() && check() == true) {
            window[s[l]]--;
            l++;
        }
        //cout << "2-" << l << " " << r << endl;
        if (l <= r && r - l + 1 < res) {
            resl = l - 1, resr = r;
            res = r - l + 1;
        } 
    }
    //cout << "3-" << resl << " " << resr << "res=" << res << endl;
    if (l > 0 && res != INT_MAX) return s.substr(resl, resr - resl);
    else return "";
}