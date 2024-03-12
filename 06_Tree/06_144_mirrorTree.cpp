#include "06_tree.h"

TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

void visit(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << endl;
    visit(root->left);
    visit(root->right);
}

int main() {
    TreeNode* root = buildTree(7);
    visit(root);
    root = mirrorTree(root);
    visit(root);
}