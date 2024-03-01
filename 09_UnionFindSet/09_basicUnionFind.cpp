#include <iostream>
using namespace std;
// 一开始每个元素都拥有自己的集合，在自己的集合里只有这个元素自己  (有一个往上指的指针，指自己)
// find(i) 查找i所在集合的代表元素，代表元素来代表i所在的集合  （查代表）
// bool isSameSet(a, b)
// void union(a, b) a所在集合所有元素，b所在集合所有元素合并成一个集合. 合并的话 小的头挂到大的头上

// 只需要俩数组 father (代表头指针) ，size 只有代表结点的size有用 ！！！
// eg, 最初 father = {0, 1, 2, 3, 4, 5} size = {1, 1, 1, 1, 1, 1}  
// father里0 1 合并， 0->1->1自己， father = {1, 1, 2, 3, 4, 5}, size更新 = {1 脏数据, 2, 1, 1, 1}
// father里2 3 合并， 2->3->3自己， father = {1, 1, 3, 3, 4, 5}, size更新 = {1 脏数据, 2, 1 脏数据, 2, 1, 1}
// father里4 5 合并， 4->5->5自己， father = {1, 1, 3, 3, 5, 5}, size更新 = {1 脏数据, 2, 1 脏数据, 2, 1, 2}
// father里2 3 与 4 5 合并 2->3-> 5 <-4 father{1, 1, 3, 5, 5, 5}, size更新 = {1 脏数据, 2, 1 脏数据, 2 脏, 1, 4}
// 1 与 5合并，2->3-> 5 <-4 &  0->1->5，father{1, 5, 3, 5, 5, 5}, size更新 = {1 脏数据, 2脏, 1 脏, 2 脏, 1, 6}  小挂大!!!

// 如果链太长了，可以扁平化!!!  2->3->5  可以改成2->5, 3->5

const static int MAXN = 1000001;
static int father[MAXN];
static int sizee[MAXN];
static int stack[MAXN];
static int n;

void build() {
    // init
    for (int i = 0; i < n; i++) {
        father[i] = i;
        sizee[i] = i;
    }
}

// 第index结点往上找，找到代表结点则返回
int find(int index) {
    int size = 0;
    while (index != father[index]) {
        // 搜集中间点，一条链路保存在stack
        stack[size++] = index; 
        index = father[index];
    }
    while (size > 0) {
        // 扁平化, 减少高度
        father[stack[--size]] = index;
    }
    return index;
}

bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        // 小挂大
        if (sizee[fx] >= sizee[fy]) {
            sizee[fx] += sizee[fy];
            // fy 的father = fx
            father[fy] = fx;
        } else {
            sizee[fy] += sizee[fx];
            father[fx] = fy;
        }
    }
}

int main() {
    cin >> n;
    int temp, i = 0, j = 0;
    while (i < n && cin >> temp) {
        father[i] = temp;
        i++;
    }
    while (j < n && cin >> temp) {
        sizee[j] = temp;
        j++;
    }
    //father = {0, 1, 2, 3, 4, 5};
    //sizee = {1, 1, 1, 1, 1, 1};
    int n = 6;
    unite(0, 1);
    unite(2, 3);
    unite(4, 5);
    unite(2, 4);
    cout << find(4) << endl;
    for (int i = 0; i < n; i++) {
        cout << father[i] << " ";
    }
    return 0;
}