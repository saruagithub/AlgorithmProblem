/*
 * main.cpp
 *
 *  Created on: 2019年7月9日
 *      Author: lee
 */
#include<iostream>
#include<vector>
using namespace std;
 
struct BST {
	BST *left, *right;
	int val;
	BST(int a=0):left(nullptr), right(nullptr), val(a){ }
};
 
BST* constructBST(vector<int>&);
BST* constructBSTrecursively(vector<int>&);
void constructBSTcore(BST *&, int);
void preorder(const BST*);
void inorder(const BST*);
void postorder(const BST*);
void insertIntoBST(BST*&,int);
void deleteFromBST(BST*&,int);
BST* findSmallest(BST *);
void swap(int&, int&);
void deleteBST(BST*&);
void deleteCore(BST *&);
 
BST* constructBSTrecursively(vector<int> &v) {
	if(!v.size()) {
		return nullptr;
	}
	BST *root=nullptr;
	for(unsigned i=0; i<v.size(); ++i) {
		constructBSTcore(root, v[i]);
	}
	return root;
}
 
BST* constructBST(vector<int> &v) {
	if(v.size()==0) {
		return nullptr;
	}
	BST *root=new BST(v[0]), *cur=root;
	for(unsigned i=1; i<v.size(); ++i) {
		cur=root;
		while(cur) {
			if(cur->val==v[i]) {
				cout << "Skip this value because it exists already in the BST!" << endl;
				break;
			}
			else if(cur->val>v[i]) {
				if(!cur->left) {
					cur->left=new BST(v[i]);
					break;
				}
				else {
					cur=cur->left;
				}
			}
			else {
				if(!cur->right) {
					cur->right=new BST(v[i]);
					break;
				}
				else {
					cur=cur->right;
				}
			}
		}
	}
	return root;
}
 
void constructBSTcore(BST *&root, int i) {
	if(!root) {
		root=new BST(i);
		return;
	}
	if(root->val==i) {
		cout << "Skip this value because it exists already in the BST!" << endl;
		return;
	}
	if(root->val>i) {
		constructBSTcore(root->left, i);
	}
	else {
		constructBSTcore(root->right, i);
	}
}
 
void preorder(const BST *root) {
	if(root) {
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
 
void inorder(const BST *root) {
	if(root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}
 
void postorder(const BST *root) {
	if(root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->val << " ";
	}
}
 
void insertIntoBST(BST *&root, int num) {
	constructBSTcore(root, num);
}
 
void deleteFromBST(BST *&root, int num) {
	if(!root) {
		cout << "Can not find " << num << " in the BST!" << endl;
		return;
	}
	if(root->val==num) {
		deleteCore(root);
	}
	else if(root->val>num) {
		deleteFromBST(root->left, num);
	}
	else {
		deleteFromBST(root->right, num);
	}
}
 
void deleteCore(BST *&root) {
	if(!root->left) {
		BST *del=root;
		root=root->right;
		delete del;
		del=nullptr;
	}
	else if(!root->right) {
		BST *del=root;
		root=root->left;
		delete del;
		del=nullptr;
	}
	else {
		BST *del=findSmallest(root->right);
		//	swap(del->val, root->val);
		//	deleteFromBST(del, num);
 
		//	deleteFromBST(root, num);
		int t=del->val;
		deleteFromBST(root, t);
		root->val=t;
	}
}
 
BST* findSmallest(BST *root) {
	while(root&&root->left) {
		root=root->left;
	}
	return root;
}
 
void swap(int &a, int &b) {
	int t=a;
	a=b;
	b=t;
}
 
void deleteBST(BST* &root) {
	if(root) {
		deleteBST(root->left);
		deleteBST(root->right);
		delete root;
		root=nullptr;
	}
}

int main() {
    // construct tree
	cout << "Construct a binary search tree based on the entered number:" << endl;
	vector<int> v;
	int num=0;
	while(cin>>num) {
		v.push_back(num);
		if(getchar()=='\n') {
			break;
		}
	}
	BST *root=constructBST(v);

    // visit tree
	cout << "Traverse the BST in pre-order:" << endl;
	preorder(root);
	cout << endl;
	cout << "Traverse the BST in in-order:" << endl;
	inorder(root);
	cout << endl;
	cout << "Traverse the BST in post-order:" << endl;
	postorder(root);
	cout << endl;
 
    // insert node
	cout << "Enter a number to insert into the BST: ";
	cin >> num;
	insertIntoBST(root, num);
	cout << "Traverse the BST in in-order:" << endl;
	inorder(root);
	cout << endl;
 
    // delete node
	cout << "Enter a number to be deleted from the BST: ";
	cin >> num;
	deleteFromBST(root, num);
	cout << "Traverse the BST in in-order:" << endl;
	inorder(root);
	cout << endl;
 
    // destroy whole tree
	cout << "Destroy the BST." << endl;
	deleteBST(root);
	return 0;
}