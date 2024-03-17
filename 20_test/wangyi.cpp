//
//  wangyi.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/12.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

void travel_inoder(TreeNode* root){
    if (!root) return;
    travel_inoder(root->left);
    cout<<root->val<<endl;
    travel_inoder(root->right);
}

//wangyi 1
int main_wangyi1(){
    //m,n
    int m,n;
    cin >> m >> n;
    if (m <= 0) {
        cout<<"0"<<endl;
        return 0;
    }
    // big array
    int arr[100000] = {0};
    int maxlen = 0;
    arr[0] = 1;
    unordered_map<int, int> indexmap; //val,index
    indexmap[1] = 0;
    m--;
    
    while(m--) {
        int pval = 0, cval = 0;
        string trunk;
        cin >> pval >> trunk >> cval;
        if (indexmap.count(pval)) { //pval alread in
            if (trunk == "left") {
                arr[2*indexmap[pval] + 1] = cval;
                indexmap[cval] = 2*indexmap[pval] + 1;
                maxlen = 2*indexmap[pval] + 1;
            }
            else {
                arr[2*indexmap[pval] + 2] = cval;
                indexmap[cval] = 2*indexmap[pval] + 2;
                maxlen = 2*indexmap[pval] + 2;
            }
        }
    }
    //judge left & right both is leaf
    int res = 0;
    for(int i=0; i<maxlen ;i++){
        if(arr[i] > 0){
            //judge
            if(arr[2*i+1]!=0 && arr[2*i+2]!=0 && arr[2*(2*i+1)+1] == 0 && arr[2*(2*i+1)+2] == 0 && arr[2*(2*i+2)+1] == 0 && arr[2*(2*i+2)+1] == 0){
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
