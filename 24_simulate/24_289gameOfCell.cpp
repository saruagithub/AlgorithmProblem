#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool flip(vector<vector<int>>& board, int i, int j) {
        // true flip
        // 8 directions
        int sum = 0;
        for (int k = i - 1; k < i + 2; k++) {
            for (int h = j - 1; h < j + 2; h++) {
                // index is valid ?
                if (k < 0 || k >= board.size() || h < 0 || h >= board[0].size()) continue;
                else sum += board[k][h];
            }
        }
        if (board[i][j] == 1) {
            sum -= 1;
            if (sum < 2) return true;
            else if (sum >= 2 && sum <= 3) return false;
            else return true;
        } else {
            if (sum == 3) return true;
        }
        return false;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<bool>> flip_flag(board.size(), vector<bool>(board[0].size(), 0));
        //vector<vector<int>> vec(3, vector<int>(4));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                flip_flag[i][j] = flip(board, i , j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (flip_flag[i][j]) board[i][j] = !board[i][j];
            }
        }
    }
};