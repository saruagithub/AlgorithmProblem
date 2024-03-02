//
//  06_removeDuplicates.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/3.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//leecode 26, remove duplicates of a sorted array
int removeDuplicates_lee26(vector<int>& nums){
    //double pointer, save location - ind, loop location - i
    if (nums.size() == 0) return 0;
    int ind = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[ind]){
            nums[++ind] = nums[i];
        }
    }
    return ind+1;
}

//leecode 27,remove nums == val
int removeElement_lee27(vector<int>& nums, int val) {
    //two pointer
    int ind = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!= val){
            nums[ind++] = nums[i];
        }
    }
    return ind;
}


void test_removeDuplicates_lee26(){
    vector<int> nums = {1,1,1,2,3};
    cout<<removeDuplicates_lee26(nums)<<endl;
}
