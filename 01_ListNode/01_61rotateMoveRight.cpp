#include "00_firstMethod.h"


// leecode 61
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]
ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) return head;
    ListNode* p = head;
    int len = 1;
    while (p->next != nullptr) {
        p = p->next;
        len++;
    }
    int going = len - k % len;
    if (k == 0) return head;
    // link circle
    p->next = head;

    while (going > 0) {
        p = p->next;
        going--;
    }
    ListNode* newhead =  p->next;
    p->next = nullptr;
    return newhead;
}