//
//  02_multiArray.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/5.
//

#include <iostream>
#include <vector>
using namespace std;

//构建乘积数组，b[2] = a[0]*a[1]*a[3]...*a[n-1]
vector<int> constructArr(vector<int>& a){
    int tmp = 1;
    size_t n = a.size();
    vector<int> res(n,1);
    for (size_t i=0; i<n-1; i++) {
        res[i+1] = tmp *= res[i];
    }
    tmp = 1;
    for (size_t i = n - 2; i >= 0; --i)
        res[i] *= tmp *= a[i + 1];
    return res;
}

int main_constructArr(){
    int val;
    vector<int> vals;
    while (cin>>val) {
        vals.push_back(val);
    }
    constructArr(vals);
    return 0;
}
