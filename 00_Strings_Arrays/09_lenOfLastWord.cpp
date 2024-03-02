//
//  09_lenOfLastWord.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/31.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//leecode 58 最后一个单词就是最后出现的单词len

int lengthOfLastWord(string s) {
    if(s.size() == 0) return 0;
    //找最后一个不是空格的，再往前找到一个空格，输出之间的长度
    int l = 0, r = -1;
    for(int i = int(s.size()) - 1; i>=0; i--) {
        if(s[i] != ' '){
            r = i;
            break;
        }
    }
    if (r == -1) return 0;
    // "hello" 前面没有空格了，所以还是用判断!= ' ' 来更新l的位置
    for (int i = r; i >= 0; i--){
        if (s[i] != ' '){
            l = i;
        } else {
            break;
        }
    }
    return r-l+1;
}

// 更快
int lengthOfLastWord1(string s) {
    int len = 0;    //记录长度
    bool ifLast = false;  // 是否找到最后一个单词
    //meet two ''
    for(int i = int(s.length()) - 1; i >= 0; i--){
        //cout << "i = " << i << endl;
        // 去除末尾的字符
        if(s.at(i) == ' '){
            if(ifLast) break;
            continue;
        }
        
        len++;
        ifLast = true;
    }
   return len;
}

int lengthOfLastWord2(string s) {
    size_t l=0, r=s.size()-1;
    if(r == -1) return 0;
    while(s[r] == ' ') r--;
    if(r == -1) return 0;
    l = r;
    while(s[l]!= ' ') l--;
    return int(r-l);
}

void test_lengthOfLastWord(){
    cout<<lengthOfLastWord1("  hello  ")<<endl;
}
