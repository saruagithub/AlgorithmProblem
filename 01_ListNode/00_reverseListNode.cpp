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

int main() {
    // orig
    ListNode* myListNode = generateListNode(5);
    printListNode(myListNode);
    // new reversed
    ListNode* reverse = reverseListNode(myListNode);
    printListNode(reverse);
}