// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
//  
// 示例 1：
// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1
// 示例 2：
// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3

#include <vector>
#include <iostream>
using namespace std;

void dfs(int x, int y, vector<vector<char>>& grid) {
  // visit four directions
  vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  grid[x][y] = '0';
  for (auto& direc : directions) {
    int nx = x + direc[0], ny = y + direc[1];
    if (nx >= 0 && nx < grid.size() && 0 <= ny && ny < grid[0].size() && grid[nx][ny] == '1') {
      dfs(nx, ny, grid);
    }
  }
}

int main() {
  vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}};

  int res = 0;
  int N = grid.size();
  int M = grid[0].size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == '1') {
        dfs(i, j, grid);
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}