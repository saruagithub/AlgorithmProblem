//
//  01_yuesefu_circle.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/6.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 圆圈中最后剩下的数字 0,1,,n-1这n个数字排成一个圆圈，
// 从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
// 约瑟夫环问题
typedef struct node{
    int val;
    int index;
    struct node *next;
}Node;

Node* create_node(int val, int index){
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->val = val;
    p->index = index;
    p->next = nullptr;
    return p;
}

//len = n of circle link
Node* creat_circlelink(int n){
    Node *head=nullptr, *p=nullptr, *q=nullptr;
    int i;
    for (i = 0; i< n; i++) {
        p = create_node(i, i);
        if (i == 0) { //if it is head node
            head = p;
            q = head;
        }
        else{ //not head , point to next node
            q->next = p;
            q = p;
        }
    }
    q->next = head;
    return head;
}

int run_circlelink(int n,int m){
    Node *cir_head=nullptr, *q;
    cir_head = creat_circlelink(n);
    while (cir_head->next != cir_head) {
        for (int i = 0; i<m-1; i++) {
            cir_head = cir_head->next;
        }
        //the m out of circle
        q = cir_head->next; //q is the m to delete
        cir_head->next = cir_head->next->next;
        cir_head = cir_head->next;
        //std::cout<<"when delete: "<<q->index<<std::endl;
        free(q);
        q = nullptr;
    }
    return cir_head->index;
}

int yuesefu_cir(int n,int m)
{
    int p=0;
    if(n <= 1 || m <= 1)
        return -1;
    for(int i=2;i<=n;i++)
    {
        p=(p+m)%i;
    }
    return p;
}

//递归
int last_Remaining(int n, int m){
    if(n < 1 || m < 1)
        return -1;
    if(n == 1)
        return 0;
    return (last_Remaining(n-1, m) + m) % n;
}

int getCount(int n) {
    // write code here
    if(n==4) return 1;
    int aa,cc;
    int a,b,count=0;
    cc = pow(n,2);
    for(a=1; a<n/sqrt(2);a++){
        aa = pow(a,2);
        b = sqrt(cc-aa);
        if(pow(b,2)+aa==cc) count++;
    }
    return count;
}

int test_yesefu(){
    int n;
    cin>>n;
    cout<<getCount(n)<<endl;
//    while(std::cin>>n){
//        if(n>1000) n=1000;
//        //3std::cout<<run_circlelink(n,3)<<std::endl;
//        std::cout<<yuesefu_cir(n,3)<<std::endl;
//    }
    return 0;
}


int main_ebay(){
    int n,m;
    cin>>n>>m;
    long long arr[100000] = {0};
    for(int i=0 ;i < m; i++){
        int a=0,b=0,c=0;
        cin>>a>>b>>c;
        if(a > b) continue;
        if(a == b){
            arr[a] += c;
            continue;
        }
        if(b > n){
            b = n;
        }
        if(a < 1){
            a = 1;
        }
        for(int j=a-1; j<b; j++){
            arr[j] += c;
        }
        for(int i=0; i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


int main_meituan1(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    int res  = 0;
    for(int i=1; i<=n; i++){
        res += abs( arr[i-1] - i);
    }
    cout<<res<<endl;
    return 0;
}

vector<int> slove(int N,string &desk,int M,string sex){
    vector<int> res(M,-1);
    for(int i=1; i<sex.size()+1; i++){
        //each person
        if(sex[i-1] == 'M'){
            for (int j=1; j<desk.size()+1; j++) {
                if(desk[j-1] == '1'){
                    res[i-1] = j;
                    desk[j-1] = '2';
                    break;
                }
            }
            if(res[i-1] == -1){
                for (int j=1; j<desk.size()+1; j++) {
                    if(desk[j-1] == '0'){
                        res.push_back(j);
                        desk[j-1] = '1';
                        break;
                    }
                }
            }
        }
        else{
            for (int j=1; j<desk.size()+1; j++) {
                if(desk[j-1] == '0'){
                    res[i-1] = j;
                    desk[j-1] = '1';
                    break;
                }
            }
            if(res[i-1] == -1){
                for (int j=1; j<desk.size()+1; j++) {
                    if(desk[j-1] == '1'){
                        res[i-1] = j;
                        desk[j-1] = '2';
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<M; i++){
        cout<<res[i]<<endl;
    }
    return res;
}

vector<int> slove1(int N,string &desk,int M,string sex){
    vector<int> res(M,-1);
    set<int> s0,s1;
    for (int j=1; j<desk.size()+1; j++){
        if(desk[j-1] == '0'){
            s0.insert(j);
        }
        if(desk[j-1] == '1'){
            s1.insert(j);
        }
    }
    for(int i=1; i<sex.size()+1; i++){
        if(sex[i-1] == 'M'){
            if(!s1.empty()){
                res[i-1] = *s1.begin();
                s1.erase(s1.begin());
                continue;
            }
            else{
                res[i-1] = *s0.begin();
                s0.erase(s0.begin());
                s1.insert(res[i-1]);
                continue;
            }
        }
        else{
            if(!s0.empty()){
                res[i-1] = *s0.begin();
                s0.erase(s0.begin());
                s1.insert(res[i-1]);
                continue;
            }
            else{
                res[i-1] = *s1.begin();
                s1.erase(s1.begin());
                continue;
            }
        }
    }
    for(int i=0; i<M; i++){
        cout<<res[i]<<endl;
    }
    return res;
}

int main_meituanseat(){
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        int N,M;
        string desk,sex;
        cin >> N;
        cin >> desk;
        cin >> M;
        cin >> sex;
        slove1(N,desk,M,sex);
    }
    return 0;
}

