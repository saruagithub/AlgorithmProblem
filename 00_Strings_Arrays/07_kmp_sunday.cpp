//
//  07_kmp_sunday.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/4.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//leecode 28, find the first place of needle in haystack
int strStr(string haystack, string needle) {
    if(haystack.find(needle) != string::npos){
        return haystack.find(needle);
    }
    return -1;
}

// kmp string match, kmp algorithm
// 在文本匹配过的位置，不会重复匹配
// aabaabaac, aabaac 在一个已经匹配好的地方找一个后缀 和 某个前缀是一样的，把前缀移动到后面后缀的地方
// 对模式串，初始化next数组 next[0] = 0，指针j,i 初始分别在0,1
int kmp_strStr(string &test, string &pattern) {
    int next[1000] = {0};
    for (int i = 1,j = 0; i <pattern.size();) {
        if (pattern[i] == pattern[j]) {
            next[i] = j + 1;
            i++;
            j++;
        } else {
            //go back
            if (j == 0) {
                next[i] = 0;
                i++;
            } else {
                j = next[j-1];
            }
        }
    }
    //the location of match
    int ans = -1;
    for (int i = 0, j = 0; i < test.size(); ) {
        if (test[i] == pattern[j]){
            i++;
            j++;
            // pattern reachs the end, all matched
            if (j == pattern.size()) {
                ans = i - j;
                break;
            }
        } else {
            if (j == 0){
                i++;
            } else {
                //j go back
                j = next[j - 1];
            }
        }
    }
    return ans;
}

// sunday: string match algorithm
int sunday_strStr(string &text, string &pattern) {
    // 对应的字符最后一次出现在pattern中的位置
    int num[128];
    for (int i = 0; i < 128; i++) {
        // init the length, the char never show in pattern
        num[i] = pattern.size() + 1;
    }
    for (int i = 0; i < pattern.size(); i++){
        num[pattern[i]] = pattern.size() - i;
    }
    int ans = -1;
    //i起始位置 + pattern的长度 <= 文本长度，就一直匹配；一轮匹配之后pattern的指针重置为0
    for (int i = 0, j = 0; i + pattern.size() <= text.size(); j = 0) {
        while (j < pattern.size() && pattern[j] == text[i+j]) {
            j++;
        }
        // match success
        if (j == pattern.size()) {
            //i do not move
            ans = i;
            break;
        }
        // match failed, then i = i + num[?]
        i += num[text[i + pattern.size()]];
    }
    return ans;
}

void test_kmp_strStr(){
    string test, pattern;
    cin >> test >> pattern;
    cout << sunday_strStr(test,pattern) << endl;
}
