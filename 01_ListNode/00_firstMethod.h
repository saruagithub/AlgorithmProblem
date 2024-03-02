#include <iostream>
#include <set>
#include <vector>

#include <cstdlib>
#include <time.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

// generate 0 - n-1, listNodes Sequence
ListNode* generateListNode(int n) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int i = 1;
    while (i < n) {
        ListNode *node = new ListNode(i);
        p->next = node;
        p = p->next;
        i++;
    }
    p->next = nullptr;
    return head;
}

// generate 0 - max random Sequence
// 产生[a,b)的随机数，可以使用 (rand() % (b-a))+a;
// 产生[a,b]的随机数，可以使用 (rand() % (b-a+1))+a;
// 产生(a,b]的随机数，可以使用 (rand() % (b-a))+a+1;
ListNode* generateRandomListNode(int size, int max) {
    srand((unsigned) time(NULL));
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int i = 0; i < size; i++) {
        int temp = (rand() % (max) + 0);
        p->next = new ListNode(temp);
        p = p->next;
    }
    return head;
}

void printListNode(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}