#include "00_firstMethod.h"

// 间歇性插入
// 输入: head = [1,2,3,4]
// 输出: [1,4,2,3]
// 从中间开始，后面的链表反转，再融合俩链表
ListNode* findMid(ListNode* head) {
    ListNode* slow = head, *fast = head, *mid;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        //if (fast != nullptr) fast = fast->next;
    }
    mid = slow;
    return mid;
}
ListNode* reverse(ListNode* head) {
    ListNode* node = head;
    ListNode* prev = nullptr, *next = nullptr;
    while (node) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;
    ListNode* head1 = head, *head2, *mid;
    mid = findMid(head);
    head2 = mid->next;
    mid->next = nullptr;
    head2 = reverse(head2);
    // merge two listNode
    ListNode* tmp1, *tmp2;
    while(head1 != nullptr && head2 != nullptr) {
        tmp1 = head1->next;
        tmp2 = head2->next;
        head1->next = head2;
        head1 = tmp1;
        head2->next = head1;
        head2 = tmp2;
    }
}

int main() {
    ListNode* l1;
    l1 = generateListNode(5);
    reorderList(l1);
    printListNode(l1);
    return 0;
}