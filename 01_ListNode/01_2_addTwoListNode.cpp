#include "00_firstMethod.h"

// leecode 2, 
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
    int sum = 0, carry = 0;
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (l1 != nullptr || l2 != nullptr) {
        int num1 = l1 == nullptr? 0 : l1->val;
        int num2 = l2 == nullptr? 0 : l2->val;
        sum = num1 + num2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        cur->next = new ListNode(sum);
        cur = cur->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    //如果最后两个数，相加的时候有进位数的时候，就将进位数，赋予链表的新节点。
    if (carry == 1) cur->next = new ListNode(carry);
    return dummy->next;
}

int main() {
    return 0;
}