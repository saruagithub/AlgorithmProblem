//
//  01array_search.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/2.
//

#include <iostream>
#include <vector>
using namespace std;

// leecode 121
// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序
// 每一列都按照从上到下递增的顺序排序。请完成一个函数，
// 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
bool findNumInArray(vector<vector<int>> &array, int target){
    bool found = false;
    if (array.size() <= 0 || array[0].size() <= 0) return false;
    int row = 0;
    long int col = array[0].size()-1;
    while (array.size() > 0 && row < array.size() && col >= 0) {
        if (array[row][col]==target) {
            found = true;
            return found;
        }
        else if(array[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return found;
}

void test_findNumInArray(){
    vector<vector<int>> array;
    array = {
        {1, 4, 7, 11, 15},
        {2, 5,  8, 12, 19},
        {3, 6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout<<findNumInArray(array,9)<<endl;
}
