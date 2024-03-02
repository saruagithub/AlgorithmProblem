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
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x),next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

// recursive code
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
    if (l1 == nullptr || l2 == nullptr) {
        return l1 == nullptr? l2 : l1;
    }
    ListNode* head = l1->val <= l2->val? l1 : l2;
    ListNode* cur1 = head->next;
    ListNode* cur2 = head == l1 ? l2 : l1;
    ListNode* p = head;
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->val <= cur2->val) {
            p->next = cur1;
            cur1 = cur1->next;
        } else {
            p->next = cur2;
            cur2 = cur2->next;
        }
        p = p->next;
    }
    p->next = cur1 == nullptr? cur2 : cur1;
    return head;
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
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
        } else {
            now->next = l2;
            l2 = l2->next;
        }
        now = now->next;
    }
    return head->next;
}


