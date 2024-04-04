/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// leecode173 实现一个二叉搜索树迭代器类BSTIterator ，
// 表示一个按中序遍历二叉搜索树（BST）的迭代器
#include "../06_Tree/06_tree.h"
class BSTIterator {
public:
    vector<int> arr;
    int idx;

    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> initarr(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    BSTIterator(TreeNode* root): idx(0), arr(initarr(root)) {
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return (idx < arr.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */