#include <iostream>
#include "06_tree.h"
using namespace std;

// “对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // p q in root's children, two side
    // p = root, q is child  | q = root, p is child
    // 1, p q都能找到 返回最近公共祖先 2. p q 找到一个，返回p q 3. 都没找到 返回null

    //根节点不是p和q中的任意一个，那么就继续分别往左子树和右子树找p和q
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    //p和q都没找到，那就没有
    if (left == nullptr && right == nullptr) return nullptr;
    //左子树没有p也没有q，就返回右子树的结果
    if (left == nullptr) return right;
    //右子树没有p也没有q就返回左子树的结果
    if (right == nullptr) return left;
    //左右子树都找到p和q了，那就说明p和q分别在左右两个子树上，所以此时的最近公共祖先就是root
    return root;
}

int main() {
    TreeNode* root = buildTree(7);
    TreeNode* res;
    res = lowestCommonAncestor(root, root->left->left, root->left);
    cout << res->val << endl;
    return 0;
}