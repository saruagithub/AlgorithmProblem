#include "00_firstMethod.h"

//slow和fast的长度一定相差环长度的整数倍，又因为fast的长度是slow的两倍，所以slow走的长度就是环长度的整数倍，我们用一个变量cnt来记录。检测到环后，我们再把slow和fast放到head的位置，让fast先跑cnt长度，然后slow和fast每一次都只跑一步，slow和fast相遇的位置就是环入口了
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return nullptr; // no circle
    fast = head; // 重复利用fast, 跟slow 一步步走
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}