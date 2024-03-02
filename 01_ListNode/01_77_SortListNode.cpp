#include "00_firstMethod.h"

// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 递归排序链表，先不停地按mid划分到最小单元，之后在比较合并起来
ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* dummy = new ListNode(0);
    ListNode* now = dummy;
    while (head1 || head2) {
        if (head1 == nullptr) {
            now->next = head2;
            break;
        }
        if (head2 == nullptr) {
            now->next = head1;
            break;
        }
        if (head1->val < head2->val) {
            now->next = head1;
            head1 = head1->next;
        } else {
            now->next = head2;
            head2 = head2->next;
        }
        now = now->next;
    }
    return dummy->next;
}

ListNode* sort(ListNode* head, ListNode* tail) {
    if (head == nullptr) return head;
    // eg, 1->2->3  slow = 3, merge(1,3)(3,null)
    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }
    ListNode *slow = head, *fast = head;
    // confuse why not fast->next != null && fast->next->next != null
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) fast = fast->next;
    }
    // slow is in mid now
    return merge(sort(head, slow), sort(slow, tail));
}

ListNode* sortList(ListNode* head) {
    // mergesort
    return sort(head, nullptr);
}