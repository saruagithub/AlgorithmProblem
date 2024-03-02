//
//  02_merge_reverse.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/28.
//

#include <cstdio>
#include <cstdlib>

struct Node{
    int value;
    struct Node* next;
    Node(int x): value(x),next(NULL) {}
};

// 完成下面的函数
// list1 第一个链表的头节点
// list2 第二个链表的头节点
// merged 合并后的链表的头节点
// 所有链表都使用头节点表示
void merge_reverse(Node *list1, Node *list2, Node *merged) {
    list1 = list1->next;
    list2 = list2->next;
    Node* pre = nullptr;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->value <= list2->value){
            merged = list1;
            merged->next = pre;
            pre = merged;
            list1 = list1->next;
        }
        else{
            merged = list2;
            merged->next = pre;
            pre = merged;
            list2 = list2->next;
        }
    }
    while(list1){
        merged = list1;
        merged->next = pre;
        pre = merged;
        list1 = list1->next;
    }
    while(list2){
        merged = list2;
        merged->next = pre;
        pre = merged;
        list2 = list2->next;
    }
    Node *header = new Node(0);
    header->value = 0;
    header->next = merged;
    merged = header;
}

// 不要修改下面的内容
void parse_list(Node *header) {
    int M = 0;
    scanf("%d", &M);
    int j = 0;
    Node *p = header;
    for (j = 0; j < M; j++) {
        int d = 0;
        scanf("%d", &d);
        Node *node = new Node(0);
        node->value = d;
        node->next = NULL;
        p->next = node;
        p = node;
    }
}

void print_list(Node *header, int rank) {
    // output
    Node *p = header->next;
    printf("%d", rank);
    while (p) {
        printf(" %d", p->value);
        p = p->next;
    }
    printf("\n");
}

// main_mergereverse
int main() {
    Node* list1 = new Node(0);
    Node* list2 = new Node(0);
    Node* merged = new Node(0);

    int N = 0;
    scanf("%d", &N);
    
    int i = 0;
    for (i = 0; i < N; i++) {
        parse_list(list1);
        parse_list(list2);
        merge_reverse(list1, list2, merged);
        print_list(merged, i+1);
        list1->next = NULL;
        list2->next = NULL;
        merged->next = NULL;
    }
    return 0;
}
