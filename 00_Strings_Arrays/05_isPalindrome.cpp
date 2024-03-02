//
//  05_isPalindrome.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/3.
//

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

//leecode 9 121 - yes, -121 false
bool isPalindrome(int x) {
    if(x < 0) return false;
    long long y = 0, z = x;
    while (z){
        y = y * 10 + z % 10;
        z /= 10;
    }
    return y==x;
}

//leecode13 Roman numerals to integers
int romanToInt(string s) {
     //扫描字符串，注意3种特殊情况减法
     int ans = 0;
     for(int i=0; i< s.size(); i++){
         switch(s[i]){
             case 'V':
                 ans += 5;
                 break;
             case 'L':
                 ans += 50;
                 break;
             case 'D':
                 ans += 500;
                 break;
             case 'M':
                 ans += 1000;
                 break;
             case 'I':
                 if (s[i+1]  == 'V' || s[i+1] == 'X'){
                     ans += (s[i+1] == 'V' ? 4 : 9);
                     i++;
                 }else {
                     ans += 1;
                 }
                 break;
             case 'X':
                 if (s[i+1] == 'L' || s[i+1] == 'C'){
                     ans += (s[i+1] == 'L' ? 40 : 90);
                     i++;
                 }else{
                     ans += 10;
                 }
                 break;
             case 'C':
                 if (s[i+1] == 'D' || s[i+1] == 'M'){
                     ans += (s[i+1] == 'D' ? 400 : 900);
                     i++;
                 }else{
                     ans += 100;
                 }
         }
     }
     return ans;
 }
