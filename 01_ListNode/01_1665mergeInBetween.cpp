#include "00_firstMethod.h"

// list1的中间 a-b部分替换成list2
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    // list1 arrive a
    int lena = 0;
    ListNode* prev = nullptr;
    ListNode* node = nullptr;
    ListNode* p = list1;
    while (p && lena < a) {
        prev = p;
        p = p->next;
        lena++;
    }
    prev->next = list2;
    while (p && lena <= b) {
        node = p;
        p = p->next;
        delete node;
        lena++;
    }
    while (list2->next) {
        list2 = list2->next;
    }
    list2->next = p;
    return list1;
}