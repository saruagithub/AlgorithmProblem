#include "00_firstMethod.h"
// 输入：head = [0,3,1,0,4,5,2,0]
// 输出：[4,11]
// leecode2181. 合并零之间的节点

ListNode* mergeNodes(ListNode* head) {
    ListNode* res = head;
    ListNode* p = head;
    
    while (head != nullptr) {
        int sum = 0;
        head = head->next;
        while (head != nullptr && head->val != 0) {
            ListNode* node = head;
            sum += head->val;
            head = head->next;
            delete node;
        }
        p->val = sum;
        //cout << "head" << head->val << " " << sum << endl;
        if (head->next == nullptr) {
            p->next = nullptr;
            break;
        }
        p->next = head;
        p = p->next;
    }
    return res;
}