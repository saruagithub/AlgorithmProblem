#include "00_firstMethod.h"

ListNode* reverseListNode(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void reverseListNode1(ListNode** l) {
    ListNode *head = *l;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    l = &prev;
    while (*l) {
        cout << (*l)->val << " ";
        *l = (*l)->next;
    }
}

// leecode 92
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) return head;
    ListNode* tailnext, *prevnode = nullptr;
    ListNode* p = head;
    int i = 1;
    while (i < left) {
        prevnode = p;
        p = p->next;
        i++;
    }
    // begin reverse
    tailnext = p;
    ListNode* next, *prev, *cur;
    while (i <= right) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next; 
        i++;
    }
    tailnext->next = next;
    if (prevnode == nullptr) head = prev; // special case
    else prevnode->next = prev;
    return head;
}

int main() {
    // orig
    ListNode* myListNode = generateListNode(5);
    ListNode** ll = &myListNode;
    printListNode(myListNode);
    // new reversed
    // ListNode* reverse = reverseListNode(myListNode);
    // printListNode(reverse);
    reverseListNode1(&myListNode);
    // printListNode(myListNode);
}