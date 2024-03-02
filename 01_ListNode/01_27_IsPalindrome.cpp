#include "00_firstMethod.h"
#include <stack>

// eg, 1 2 2 1 yes,   1 2 3 no.
// go to mid, reverse 
ListNode* getMid(ListNode* head) {
    // double pointer
    ListNode* slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr, *next;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
bool isPalindrome1(ListNode* head) {
    ListNode* mid, *head2;
    mid = getMid(head);
    head2 = mid->next;
    mid->next = nullptr;
    head2 = reverse(head2);
    while (head != nullptr && head2 != nullptr) {
        if (head->val != head2->val) return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
bool isPalindrome(ListNode* head) {
    if (head == nullptr) return false;
    stack<int> stk;
    ListNode* cur = head;
    while (cur) {
        stk.push(cur->val);
        cur = cur->next;
    }
    while (head) {
        if (head->val != stk.top()) return false;
        stk.pop();
        head = head->next;
    }
    return true;
}