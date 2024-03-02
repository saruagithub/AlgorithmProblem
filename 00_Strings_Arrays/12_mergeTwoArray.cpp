//
//  12_mergeTwoArray.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/11/7.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    size_t i = nums1.size() - 1;
    m--;
    n--;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            swap(nums1[i--], nums1[m--]);
        }
        swap(nums1[i--], nums2[n--]);
    }
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 末尾挨个比较，放大的数到num1末尾，如果某个为空，某个
    if (m == 0){
        nums1.assign(nums2.begin(), nums2.end());
    }
    if (n == 0) return;
    // m + n 从末尾开始放元素, 直到 m or n == 0 剩下的不动
    int now = m + n - 1;
    int p = m - 1;
    int q = n - 1;
    while ( p >= 0 || q >= 0){
        if (p == -1 && q >= 0) {
            for( int i = q; i >= 0; i--){
                nums1[now] = nums2[i];
                now--;
            }
            return;
        }
        if (q == -1) return;
        if (nums1[p] >= nums2[q]) {
            nums1[now] = nums1[p];
            p--;
        } else {
            nums1[now] = nums2[q];
            q--;
        }
        now--;
    }
}

void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 末尾挨个比较，放大的数到num1末尾，如果某个为空，某个
    if (m == 0){
        nums1.assign(nums2.begin(), nums2.end());
    }
    if (n == 0) return;
    // m + n 从末尾开始放元素, 直到 m or n == 0 剩下的不动
    int now = m + n - 1;
    int p = m - 1;
    int q = n - 1;
    while ( p >= 0 && q >= 0){
        if (nums1[p] >= nums2[q]) {
            nums1[now] = nums1[p];
            p--;
        } else {
            nums1[now] = nums2[q];
            q--;
        }
        now--;
    }
    if( q >= 0 ){
        for(int i = q; i>=0; i--){
            //nums1[now] == nums2[i];
            now--;
        }
    }
}

void test_merge(){
    vector<int> nums1 =  {2,0};
    int m = 1;
    vector<int> nums2 = {1};
    int n = 1;
    merge3(nums1,m,nums2,n);
    for(int i=0; i<m+n; i++){
        cout<<nums1[i]<<" ";
    }
}

