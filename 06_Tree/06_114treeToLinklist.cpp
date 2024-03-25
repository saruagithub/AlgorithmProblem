#include "06_tree.h"
#include <vector>
using namespace std;

void flatten(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        return;
    };
    flatten(root->left);
    flatten(root->right);
    if (root->left && root->right) {
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        //cout << "right left" << right->val << " " << left->val;
        root->right = left;
        root->left = nullptr;
        // key, tail left
        while (left->right != nullptr) left = left->right;
        left->right = right;
        left->left = nullptr;
        return;
    }
    if (root->left) {
        TreeNode* left = root->left;
        root->left = nullptr;
        root->right = left;
        return;
    }
}