#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> allres;
vector<vector<bool>> flags{101, vector<bool>(101, true)};
bool allsame(vector<vector<int>>& grid) {
    int sum = 0;
    for (auto v : grid) {
        for (auto ele: v) {
            sum += ele;
        }
    }
    if (sum == 0 || sum == grid.size() * grid.size()) return true;
    return false;
}

void reset(vector<vector<bool>>& flags) {
    for(auto ele:flags) {
        std::fill(ele.begin(), ele.end(), true);
    }
}

int each_res = 0;
void visit(vector<vector<int>>& grid, queue<pair<int,int>>& que, int depth) {
    int n = grid.size();
    // BFS search, not dfs, queue<pair(i,j)>
    int len = que.size();
    for (int i = 0; i < len; i++) {
        // get water
        pair wa = que.front();
        que.pop();
        // top,down,left, right
        int p = wa.first, q = wa.second;
        flags[p][q] = false;
        if ((q+1 < n && grid[p][q+1] == 1) ||
            (p+1 < n && grid[p+1][q] == 1) ||
            (p-1 >= 0 && grid[p-1][q] == 1) ||
            (q-1 >= 0 && grid[p][q-1] == 1)) {
                each_res = depth + 1;
                return;
            } 

        if (q+1 < n && flags[p][q+1] && grid[p][q+1] != 1) que.push(make_pair(p, q+1));
        if (p+1 < n && flags[p+1][q] && grid[p+1][q] != 1) que.push(make_pair(p+1, q));
        if (p-1 >= 0 && flags[p-1][q] && grid[p-1][q] != 1) que.push(make_pair(p-1, q));
        if (q-1 >= 0 && flags[p][q-1] && grid[p][q-1] != 1) que.push(make_pair(p, q-1));
    }
    if (!que.empty()) {
        visit(grid, que, depth + 1);
    }
}

int maxDistance(vector<vector<int>>& grid) {
    // sum all grid[i][j], if == 0 or n*n, return -1
    if (allsame(grid)) return -1;
    // visit all 0, top down left right go until meet1, return distance. max(distance)

    queue<pair<int,int>> que;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            if (grid[i][j] == 0) {
                que.push(make_pair(i,j));
                visit(grid, que, 0);
                allres.push_back(each_res);
                //cout << each_res << endl;
                each_res = 0;
                // reset flags
                reset(flags);
            }
        }
    }
    int res = 0;
    for (auto ele : allres) {
        res = max(res, ele);
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    cout << maxDistance(grid) << endl;
}



class Solution {
public:
    static constexpr int dx[4] = {-1,0,1,0};
    static constexpr int dy[4] = {0,1,0,-1};  // can be {-1,0,1,0,-1}
    static constexpr int MAX_N = 101;
    struct coord {
        int x, y, step;
    };
    int rows, cols;
    vector<vector<int>> a;
    bool vis[MAX_N][MAX_N];

    int find(int x, int y) {
        memset(vis, 0, sizeof(vis));
        queue<coord> q;
        q.push({x,y,0});
        vis[x][y] = 1;
        while(!q.empty()) {
            auto cord = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cord.x + dx[i], ny = cord.y + dy[i];
                if (!(nx >=0 && nx <= rows-1 && ny >=0 && ny <= cols - 1)) continue;
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    if (a[nx][ny] == 1) return cord.step + 1;
                    q.push({nx,ny, cord.step+1});
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        a = grid;
        int ans = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (a[i][j] == 0) ans = max(ans, find(i,j));
            }
        }
        return ans;
    }
};