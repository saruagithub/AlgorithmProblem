//
//  01_binaryTree_commonParent.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/2.
//

#include <iostream>
#include <vector>
using namespace std;

//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(){
    //[3,5,1,6,2]
    TreeNode* root = new TreeNode(3);
    TreeNode* node2 =new TreeNode(5);
    TreeNode* node3 =new TreeNode(1);
    TreeNode* node4 =new TreeNode(6);
    TreeNode* node5 =new TreeNode(2);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root==nullptr || root==p || root==q) {
        return root;
    }
    //在左子树找p或q，假如p和q都在左子树，返回的那个值就是祖先
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    //在右子树找p或者q，假如p和q都在右子树，返回的那个值就是祖先
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL) return right;
    if(right == NULL) return left;
    // p和q一个在左子树一个在右子树
    return root;
}

//BST tree
TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root==nullptr || root==p || root==q) {
        return root;
    }
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor_BST(root->left, p, q);
    }
    else if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor_BST(root->right, p, q);
    }
    else{
        return root;
    }
}

//
TreeNode* lowestCommonAncestorss(TreeNode* root, TreeNode* p, TreeNode* q) {
    if((root -> val - p->val)*(root -> val - q ->val) <= 0 ){
        return root;
    }
    if(root -> val > p -> val){
        return lowestCommonAncestor(root -> left, p, q);
    }
    if(root -> val < p -> val){
        return lowestCommonAncestor(root -> right, p, q);
    }
    return NULL;
}


int main_lowestCommonAncestorss(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node2 =new TreeNode(2);
    TreeNode* node3 =new TreeNode(6);
    TreeNode* node4 =new TreeNode(1);
    TreeNode* node5 =new TreeNode(3);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    
    TreeNode* res;
    res = lowestCommonAncestorss(root,node4,node5);
    cout<<res->val<<endl;
    return 0;
}
