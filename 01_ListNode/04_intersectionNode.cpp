#include "00_firstMethod.h"

// If intersection, lenA == lenB, 当PA = PB的时候得到交点
// If intersection, lenA != lenB, 短的走完之后去走另一边，由于走的总长一致，所以总会最后一起走
// if not, lenA == lenB, both go to the tail at the same time
// if not, lenA != lenB, won't arrive at tail at the same time, 都会走两遍路
ListNode* getIntersectionNode(ListNode *headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode *PA = headA, *PB = headB;
    while (PA != PB) {
        PA = PA == nullptr? headB : PA->next;
        PB = PB == nullptr? headA : PB->next;
    }
    return PA;
}

int main() {
    ListNode *A = new ListNode();
    ListNode *node = new ListNode(1);
    A->next = node;
    ListNode *B = new ListNode();
    B->next = node;

    ListNode *res = getIntersectionNode(A, B);
    cout << res->val << endl;
    return 0;
}