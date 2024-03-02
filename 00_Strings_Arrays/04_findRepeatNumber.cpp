//
//  04_findRepeatNumber.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/24.
//

#include<iostream>
#include<cmath>
using namespace std;
//int MAX_N = 10000000;


int main_repeat(){
    int N;
    cin>>N;
    int dp[100000] = {0};
    dp[0] = 1;
    dp[1] = 1;
    if(N == 0){
        cout<<0<<endl;
    }
    dp[2] = 2;
    for(int i=3; i<N; i++){
        for(int j=1; j<=i; j = 2*j){
            dp[i] += dp[i-j];
        }
    }
    cout<<dp[N-1]<<endl;
    return 0;
}
