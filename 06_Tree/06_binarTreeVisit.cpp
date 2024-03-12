#include "06_tree.h"
#include <queue>

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
vector<vector< int >> levelOrder(TreeNode* root) {
    vector <vector <int>> ret;
    if (!root) {
        return ret;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(vector <int> ());
        for (int i = 1; i <= currentLevelSize; ++i) {
            TreeNode* node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return ret;
}

//链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/241885/er-cha-shu-de-ceng-xu-bian-li-by-leetcode-solution/


// leecode 617 merge treenode
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //if (root1 == nullptr && root2 == nullptr) return nullptr;
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main() {
    TreeNode* root;
    root = buildTree(7);
    //preVisit(root);
    vector<vector<int>> tmp;
    tmp = levelOrder(root);
    for (auto ele: tmp) {
        for (auto e: ele) {
            cout << e << " ";
        }
    }
    return 0;
}