#include<stdio.h>
#include <cstdlib>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;

ListNode *newListNode(int data){
        ListNode *listNode = ( ListNode *) malloc(sizeof(ListNode));
        listNode->data = data;
        listNode->next=NULL;
    return listNode;
}
ListNode *rear;
ListNode *head;
ListNode *newLoopQueue(int size){
    ListNode *node = newListNode(-1);
    node->next=node;
    rear= node;
    head = head;
    return node;
}

bool isEmpty(ListNode *head){
    return head->next==head;
}

void input(ListNode *node){
    rear->next = node;
    rear=rear->next;
    rear->next=head;
}

ListNode *output(){
    ListNode  *node= head->next;
    head->next=head->next->next;
    return node;
}