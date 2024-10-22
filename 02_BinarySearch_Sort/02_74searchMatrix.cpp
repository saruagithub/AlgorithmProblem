#include <vector>
#include <iostream>
using namespace std;

int bsearch(vector<int>& mat, int target) {
    // return idx
    // >= target的第一个数
    auto it = lower_bound(mat.begin(), mat.end(), target);
    if (it == mat.end()) return -1;
    return it - mat.begin();
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> cols;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        cols.push_back(matrix[i][n - 1]);
    }
    int tmp = bsearch(cols, target);
    if (tmp == -1) return false;
    if (matrix[tmp][n - 1] == target) return true;

    cols.clear();
    for (int j = 0; j < n; j++) {
        cols.push_back(matrix[tmp][j]);
    }
    int tmp1 = bsearch(cols, target);
    if (tmp1 == -1) return false;
    if (matrix[tmp][tmp1] == target) return true;
    else return false;
}

// 矩阵拉成一行
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int right = m*n-1, left = 0;
    while(left <= right){
        int mid = (left+right)/2;
        int i = mid/n, j = mid%n;
        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return false;
}