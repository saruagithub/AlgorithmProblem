#include <string>
#include <vector>
using namespace std;

// leecode 316 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
// 需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
// 示例 2：
// 输入：s = "cbacdcbc"
// 输出："acdb"
// cdadabcc  adbc
// bbcaac  bac

string removeDuplicateLetters(string s) {
    string res;
    //string temp;
    vector<int> memo(26, 0);
    for (char ele: s) memo[ele - 'a'] += 1; 
    for (char ch: s) {
        if (res.find(ch) != string::npos) {
            memo[ch - 'a'] -= 1;
            continue;
        }
        while (!res.empty() && res.back() > ch && memo[res.back() - 'a'] > 0) {
            // 出栈 保存在temp
            res.pop_back();
        } 
        // 入栈
        res.push_back(ch);
        memo[ch - 'a'] -= 1;
    }
    return res;
}