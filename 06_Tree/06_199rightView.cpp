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
#include <vector>
#include "06_tree.h"

class Solution {
public:
    void visit(vector<int>& res, TreeNode*root, int depth) {
        if (root == nullptr) return;
        if (depth > res.size()) res.push_back(root->val);
        //maxdepth = max(maxdepth, depth);
        if (root->right) visit(res, root->right, depth+1);
        if (root->left) visit(res, root->left, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        visit(res, root, 0);
        return res;
    }
};