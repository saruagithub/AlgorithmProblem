#include <vector>
using namespace std;

// leecode498
// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,4,7,5,3,6,8,9]

// start from the (x,y) , go left and down
vector<int> visit(vector<vector<int>>& mat, int x, int y) {
    vector<int> res;
    while (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) {
        res.push_back(mat[x][y]);
        x++;
        y--;
    }
    return res;
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> ans;
    bool flip = true;
    // the top row
    for (int j = 0; j < mat[0].size(); j++) {
        vector<int> tempres = visit(mat, 0, j);
        if (flip) {
            reverse(tempres.begin(), tempres.end());
        } 
        ans.insert(ans.end(),tempres.begin(), tempres.end());
        flip = !flip;
    }
    // the right col
    for (int i = 1; i < mat.size(); i++) {
        //cout << i << " " << mat.size() << endl;
        vector<int> tempres = visit(mat, i, mat[0].size() - 1);
        if (flip) {
            reverse(tempres.begin(), tempres.end());
        }
        ans.insert(ans.end(),tempres.begin(), tempres.end());
        flip = !flip; 
    }
    return ans;
}