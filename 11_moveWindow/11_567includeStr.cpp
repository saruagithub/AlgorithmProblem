#include "../21_Huawei/21_header.h"

unordered_map<char, int> s1mp, s2mp;
bool check() {
    for (auto &[k, v]: s1mp) {
        if (!s2mp.count(k) || s2mp[k] != v) return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size()) return false;
    for (char c1 : s1) {
        s1mp[c1]++;
    }
    //cout << "it is ok, 11111" << endl;
    int l = 0, r = s1.size(); // [l,r)
    for (int i = l; i < r; i++) {
        s2mp[s2[i]]++;
    }
    if (check()) return true;
    cout << "it is ok" << endl;
    while (r < s2.size()) {
        s2mp[s2[l]]--;
        s2mp[s2[r]]++;
        if (s2mp[s2[l]] == 0) s2mp.erase(s2[l]);
        l++;
        r++;
        //cout << " l = " << l << " r = " << r << endl;
        //for (auto &[k,v] : s2mp) cout << " k = " << k << " v = " << v;
        if (check()) return true;
    }
    return false;
}


bool checkInclusion(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    if (n > m) {
        return false;
    }
    vector<int> cnt1(26), cnt2(26);
    for (int i = 0; i < n; ++i) {
        ++cnt1[s1[i] - 'a'];
        ++cnt2[s2[i] - 'a'];
    }
    if (cnt1 == cnt2) {
        return true;
    }
    for (int i = n; i < m; ++i) {
        ++cnt2[s2[i] - 'a'];
        --cnt2[s2[i - n] - 'a'];
        if (cnt1 == cnt2) {
            return true;
        }
    }
    return false;
}

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/permutation-in-string/solutions/599202/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。