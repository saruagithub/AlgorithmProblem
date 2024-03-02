//
//  03_deleteDuplicates.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/11/13.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//leecode 83
ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return NULL;
    // while now == next, delete next (now -> next的next, delete next)
    ListNode* now = head;
    while(now->next){
        if(now->val == now->next->val){
            // delete
            ListNode* temp;
            temp = now->next;
            now->next = now->next->next;
            delete temp;
        }
        else now = now->next;
    }
    return head;
}
