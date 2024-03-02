//
//  08_shangjioasuo.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/25.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

//1-n 从左到右第一个删除，跳一个删除
int test_shangjiao(){
    int n;
    cin>>n;
    vector<int> res;
    vector<int> temp;
    for(int i=1; i<=n; i++){
        res.push_back(i);
    }
    while(res.size() > 1){
        temp.clear();
        for(int i=1; i < res.size(); i += 2){
            temp.push_back(res[i]);
        }
        reverse(temp.begin(), temp.end());
        res = temp;
    }
    cout<<res[0]<<endl;
    return 0;
}
