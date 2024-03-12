#include "06_tree.h"

// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
// https://leetcode.cn/problems/WNC0Lk/description/
int max_depth = 0;
void dfs(TreeNode* root, vector<int>& res, int depth) {
    // 尽量先访问right。 但left right 都需要访问，left的深度更大的时候才添加进res里
    if (depth > max_depth) {
        res.push_back(root->val);
        max_depth = depth;
    }
    if (root->right) {
        dfs(root->right, res, depth+1);
    }
    if (root->left) {
        dfs(root->left, res, depth+1);
    }
    //return;
}
vector<int> rightSideView(TreeNode* root) {
    int depth = 1;
    vector<int> res;
    if (root == nullptr) return res;
    dfs(root, res, depth);
    return res;
}