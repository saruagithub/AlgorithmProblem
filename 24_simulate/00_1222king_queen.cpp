#include "../21_Huawei/21_header.h"

// leecode1222
// 在一个 下标从 0 开始 的 8 x 8 棋盘上，可能有多个黑皇后和一个白国王。

// 给你一个二维整数数组 queens，其中 queens[i] = [xQueeni, yQueeni] 表示第 i 个黑皇后在棋盘上的位置。
// 还给你一个长度为 2 的整数数组 king，其中 king = [xKing, yKing] 表示白国王的位置。
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    // from king, 8 directions visit.  whole is 8 * 8
    unordered_set<int> quee;
    for (auto& ele : queens) {
        quee.insert(ele[0] * 8 + ele[1]);
    }

    vector<vector<int>> res;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int newx = king[0] + dx;
            int newy = king[1] + dy;
            while (newx >= 0 && newx < 8 && newy >= 0 && newy < 8) {
                int tmp = newx * 8 + newy;
                if (quee.count(tmp)) {
                    res.push_back({newx, newy});
                    break;
                }
                newx += dx;
                newy += dy;
            }
        }
    }
    return res;
}


// 输入：queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
// 输出：[[2,2],[3,4],[4,4]]
int main() {
    vector<vector<int>> queens;
    vector<int> king = {3,3};
    int N, i = 0;
    cin >> N;
    while (i < N) {
        int a,b;
        scanf("%d, %d", &a, &b);
        queens.push_back({a,b});
        i++;
    }
    vector<vector<int>> res;
    res = queensAttacktheKing(queens, king);
    cout << "res" << endl;
    for (auto ele : res) cout << ele[0] << " " << ele[1] << endl;
    return 0;
}



// scanf 类型说明符：

// 类型	合格的输入	参数的类型
// %a、%A	读入一个浮点值(仅 C99 有效)。	float *
// %c	单个字符：读取下一个字符。如果指定了一个不为 1 的宽度 width，函数会读取 width 个字符，并通过参数传递，把它们存储在数组中连续位置。在末尾不会追加空字符。	char *
// %d	十进制整数：数字前面的 + 或 - 号是可选的。	int *
// %e、%E、%f、%F、%g、%G	浮点数：包含了一个小数点、一个可选的前置符号 + 或 -、一个可选的后置字符 e 或 E，以及一个十进制数字。两个有效的实例 -732.103 和 7.12e4	float *
// %i	读入十进制，八进制，十六进制整数 。	int *
// %o	八进制整数。	int *
// %s	字符串。这将读取连续字符，直到遇到一个空格字符（空格字符可以是空白、换行和制表符）。	char *
// %u	无符号的十进制整数。	unsigned int *
// %x、%X	十六进制整数。	int *
// %p	读入一个指针 。	 
// %[]	扫描字符集合 。	 
// %%	读 % 符号。	 