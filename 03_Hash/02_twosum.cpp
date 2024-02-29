//
//  02_twosum.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/21.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//map存储之前的元素，target - nums[i] 是否在map里，
//map这个STL 红黑树为基础，key + value, 不允许key重复，元素以key自动排序，map的键不可以被修改
//unorder_map 以hash为基础， 无序，以key查找value，不会根据key排序
vector<int> twoSum1(vector<int>& nums, int target) {
    unordered_map<int,int> a; //hash table
    vector<int> b(2,-1); //save res
    for(int i=0;i<nums.size();i++){
        if(a.count(target - nums[i]) > 0 && a[target-nums[i]]!=i ){
            b[0] = i;
            b[1] = a[target - nums[i]];
            break;
        } else {
            a[nums[i]] = i;
        }
    }
    return b;
}

//leecode 167 double pointer
vector<int> twosum_seq(vector<int>& nums, int target) {
    vector<int> v;
    int l = 0, r  = nums.size()-1;
    while (l<r) {
        if (nums[l] + nums[r] == target) {
            v.push_back(l+1);
            v.push_back(r+1);
            break;
        }
        if (nums[l]+nums[r] < target) {
            l++;
        } else {
            r--;
        }
    }
    return v;
}

//二分查找 要求升序数组
// for 遍历的同时，二分查找 target - nums[i], l = i+1, r = size-1
// target - nums[i] < mid, r = mid - 1
// target - nums[i] > mid, r = mid + 1
vector<int> twoSum_twosplit(vector<int>& numbers, int target) {
    vector<int> v(2,-1);
    for(int i=0; i<numbers.size(); i++){
        int t = target - numbers[i], l = i+1, r = numbers.size()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (numbers[mid] == t) {
                v[0] = i + 1;
                v[1] = mid + 1;
                return v;
            }
            if (numbers[mid] < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return v;
}


void test_leecode167_towsum(){
    vector<int> a = {2,7,11,15};
    //vector<int> res = twosum_seq(a, 9);
    //cout<<res[0]<<res[1]<<endl;
    vector<int> res = twoSum_twosplit(a, 9);
    cout<<res[0]<<" "<<res[1]<<endl;
}
