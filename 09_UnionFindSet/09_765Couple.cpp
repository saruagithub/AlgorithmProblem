#include <vector>
using namespace std;

// 并查集上 ！
// n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。
// 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的 ID。
// 情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)。


//              {6,0,8,9,1,7,3,4,5,2} 
// 情侣第几对编号 {3,0,4,4,0,3,1,2,2,1}
// {3,0}+2 需交换1次  {4 4}  {1,2}{2,1} 需交换1次， 也就是集合有k次，需交换k-1次   res = 2

//eg {6,0,1,5,2,3,8,4,7,9}  情侣对的集合 {0,2,3,4} = 4 需交换3次 {1} , res = 3 = 5 - 2集合
// 并查集里有多少个集合，即总对数 - 集合类别数

const static int MAXN = 31;
int father[MAXN];
int sets;

void build(int s) {
    // init
    for (int i = 0; i < s; i++) {
        father[i] = i; // i是情侣对的编号
    }
    sets = s;
}

// 第index结点往上找，找到代表结点则返回
int find(int index) {
    if (index != father[index]) {
        father[index] = find(father[index]);
    }
    return father[index];
}

bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        // 合并集合
        father[fx] = fy;
        sets--;
    }
}
int minSwapsCouples(vector<int>& row) {
    // change 2 times, X 编号的人对应的第 X/2 对情侣
    int s = row.size() / 2;
    build(s);
    for(int i = 0; i < row.size(); i+=2) {
        unite(row[i]/2, row[i+1]/2);
    }
    return s - sets;
}