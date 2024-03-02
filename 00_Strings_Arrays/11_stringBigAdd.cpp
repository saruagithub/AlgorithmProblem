//
//  11_stringBigAdd.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/11/5.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//haizei save 下标0处存位数 + 倒序
void big_add(string s1,string s2){
    //change save into the array
    size_t n1[1005]={0}, n2[1005]={0};
    n1[0] = int(s1.size());
    n2[0] = int(s2.size());
    for(size_t i = 1, j = s1.size() - 1; i <= n1[0]; i++, j--){
        n1[i] = s1[j] - '0';
    }
    for(size_t i = 1, j = s2.size() - 1; i <= n2[0]; i++, j--){
        n2[i] = s2[j] - '0';
    }
    //add res save into n1 array
    n1[0] = max(n1[0], n2[0]); // 最长位数
    for (int i = 1; i <= n1[0]; i++) {
        // add
        n1[i] += n2[i];
        if (n1[i] >= 10) {
            n1[i+1] += 1;
            n1[i] -= 10;
            // 最后一位，是否位数增多
            if (i == n1[0]) {
                n1[0]++;
            }
        }
    }
    //output from top
    for(size_t i = n1[0]; i >= 1; i--) {
        cout << n1[i];
    }
    cout << endl;
}

void test_big_add(){
    string s1 = "99";
    string s2 = "11";
    big_add(s1,s2);
}

//process IPad P8
string big_sub(string s1,string s2){
    //flag res is > 0 or < 0
    bool flag = 0;
    if(s1 < s2){
        flag = 1;
        swap(s1, s2);
    }
    if(s1 == s2) {
        cout << "0" << endl;
        return "0";
    }
    size_t n1[1005] = {0}, n2[1005] = {0};
    n1[0] = s1.size();
    n2[0] = s2.size();
    for (size_t i = 1, j = s1.size() - 1; i <= n1[0]; i++, j--) {
        n1[i] = s1[j] - '0';
    }
    for (size_t i = 1, j = s2.size() - 1; i <= n2[0]; i++, j--) {
        n2[i] = s2[j] - '0';
    }
    //sub
    for (int i= 1; i <= n1[0]; i++) {
        if( n1[i] < n2[i] ){
            //借位
            n1[i+1]--;
            n1[i] = 10 + n1[i] - n2[i];
        } else {
            n1[i] -= n2[i];
        }
    }
    for (size_t i = n1[0]; i>=0; i--) {
        if( n1[i] != 0){
            n1[0] = i;
            break;
        }
    }
    //output from top
    if(flag) cout<<"-";
    for(size_t i = n1[0]; i >= 1; i--) {
        cout << n1[i];
    }
    cout << endl;
    
    //return string
    string res = "";
    for(size_t i = n1[0]; i >= 1; i--) {
        res = res + to_string(n1[i]);
    }
    return res;
}


void big_mul(string s1,string s2){
    if(s1 < s2){
        swap(s1, s2);
    }
    if (s1 == "0" || s2 == "0"){
        cout << "0" << endl;
        return;
    }
    size_t n1[1005] = {0}, n2[1005] = {0} ,n3[1005] = {0};
    n1[0] = s1.size();
    n2[0] = s2.size();
    for (size_t i = 1, j = s1.size() - 1; i <= n1[0]; i++, j--) {
        n1[i] = s1[j] - '0';
    }
    for (size_t i = 1, j = s2.size() - 1; i <= n2[0]; i++, j--) {
        n2[i] = s2[j] - '0';
    }
    //位数之和
    n3[0] = n1[0] + n2[0];
    for (int i = 1; i <= n2[0]; i++) {
        for (int j = 1; j<=n1[0]; j++) {
            n3[i+j-1] += n2[i] * n1[j];
            // 进位
            if(n3[i+j-1] >= 10){
                n3[i+j] += n3[i+j-1] / 10;
                n3[i+j-1] = n3[i+j-1] % 10;
            }
        }
    }
    for (size_t i = n3[0]; i>=0; i--) {
        if( n3[i] != 0){
            n3[0] = i;
            break;
        }
    }
    for(size_t i = n3[0]; i >= 1; i--) {
        cout << n3[i];
    }
    cout << endl;
}


void big_divide(string s1,string s2){
    if(s1 < s2){
        swap(s1, s2);
    }
    if (s1 == "0" || s2 == "0"){
        cout << "0" << endl;
        return;
    }
    size_t n1[1005] = {0}, n2[1005] = {0};
    n1[0] = s1.size();
    n2[0] = s2.size();
    for (size_t i = 1, j = s1.size() - 1; i <= n1[0]; i++, j--) {
        n1[i] = s1[j] - '0';
    }
    for (size_t i = 1, j = s2.size() - 1; i <= n2[0]; i++, j--) {
        n2[i] = s2[j] - '0';
    }
    
}


void binary_add(string s1,string s2){
    //change save into the array
    size_t n1[1005]={0}, n2[1005]={0};
    n1[0] = s1.size();
    n2[0] = s2.size();
    for(size_t i = 1, j = s1.size() - 1; i <= n1[0]; i++, j--){
        n1[i] = s1[j] - '0';
    }
    for(size_t i = 1, j = s2.size() - 1; i <= n2[0]; i++, j--){
        n2[i] = s2[j] - '0';
    }
    //add res save into n1 array
    n1[0] = max(n1[0], n2[0]); // 最长位数
    for (int i = 1; i <= n1[0]; i++) {
        n1[i] += n2[i];
        if (n1[i] >= 2) {
            n1[i+1] += 1;
            n1[i] -= 2;
            if (i == n1[0]) {
                n1[0]++;
            }
        }
    }
    //output from top
    for(size_t i = n1[0]; i >= 1; i--) {
        cout << n1[i];
    }
    cout << endl;
}

/*
void binary_divide(string s1, string s2) {
    // 999 / 45, 取前俩位99 循环 - 45 不断+1 ，（2余9），接着借位99再循环减45
    string res = "";
    string left; //余数
    // if s1还有位数没用完
    if () {
        string divisor = "";
        string res_bit = "0";
        //while 递减
        while (divisor >= s2) {
            divisor = divisor - s2;
            res_bit
        }
    }
}
*/

/*
int main() {
    string s1 = "11";
    string s2 = "8";
    cout<< big_sub(s1, s2)<<endl;
    return 0;
}
*/
