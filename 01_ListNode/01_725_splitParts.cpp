#include "00_firstMethod.h"

// 输入：head = [1,2,3], k = 5
// 输出：[[1],[2],[3],[],[]]
// 解释：
// 第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 

// 输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
// 输出：[[1,2,3,4],[5,6,7],[8,9,10]]
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> res;
    int len = 0;
    ListNode* cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    int div = len / k;
    int left = len % k;
    ListNode* now = head;
    for (int i = 0; i < k; i++){
        int partsize = div + (i < left? 1 : 0);
        if (partsize == 0) {
            res.push_back(nullptr);
            continue;
        }
        int temp = 0;
        ListNode *prev = nullptr;
        res.push_back(now);
        while (now && temp < partsize) {
            prev = now;
            now = now->next;
            temp++;
        }
        prev->next = nullptr;
    }
    return res;
}