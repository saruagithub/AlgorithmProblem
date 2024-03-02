#include "00_firstMethod.h"

// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5] 保持原来相对顺序

ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(-1);
    ListNode* large = new ListNode(-1);
    ListNode* smallHead = small, *largeHead = large;
    while (head) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = nullptr;
    small->next = largeHead->next;
    return smallHead->next;
}

int main() {
    ListNode* head, *res;
    head = generateRandomListNode(10, 15);
    printListNode(head);
    res = partition(head, 5);
    printListNode(res);
    return 0;
}