//
//  01_mergeTwoList.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/23.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    ListNode* mergeNode = nullptr;
    if(l1->val < l2->val){
        mergeNode = l1;
        mergeNode->next = mergeTwoLists(l1->next,l2);
    }
    else{
        mergeNode = l2;
        mergeNode->next = mergeTwoLists(l1,l2->next);
    }
    return mergeNode;
}

ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* now = head;
    while(l1 != nullptr || l2 != nullptr){
        if(l1 == nullptr){
            now->next = l2;
            break;
        }
        if(l2 == nullptr){
            now->next = l1;
            break;
        }
        if(l1->val < l2->val){
            now->next = l1;
            l1 = l1->next;
        }
        else{
            now->next = l2;
            l2 = l2->next;
        }
        now = now->next;
    }
    return head->next;
}


