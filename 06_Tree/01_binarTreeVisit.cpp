#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
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

// 先序遍历 中 左 右
void preVisit(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << endl;
    preVisit(root->left);
    preVisit(root->right);
}

// 中序遍历 左 中 右
void midVisit(TreeNode* root) {
    if (root == nullptr) return;
    midVisit(root->left);
    cout << root->val << endl;
    midVisit(root->right);
}

// 后序遍历 左 右 中
void posVisit(TreeNode* root) {
    if (root == nullptr) return;
    posVisit(root->left);
    posVisit(root->right);
    cout << root->val << endl;
}

// leecode 102 层序遍历

int main() {
    TreeNode* root;
    root = buildTree(3);
    preVisit(root);
    return 0;
}