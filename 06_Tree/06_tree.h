#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(int n) {
    vector<TreeNode*> nodes;
    for (int i = 1; i <= n; i++) {
        TreeNode* temp = new TreeNode(i);
        nodes.push_back(temp);
    }
    for (int i = 0; i < n/2; i++) {
        if (2 * i + 1 < n) nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n) nodes[i]->right = nodes[2 * i + 2];
    }
    return nodes[0];
}