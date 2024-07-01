#include<stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int m;
    int n;
    int value;
    struct StackNode* next;
} StackNode;

StackNode* push(StackNode* top, int m, int n, int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->m = m;
    newNode->n = n;
    newNode->value = value;
    newNode->next = top;
    return newNode;
}

void pop(StackNode** top) {
    if (*top) {
        StackNode* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int ackermannIterative(int m, int n) {
    StackNode* stackTop = NULL;
    StackNode* node = push(stackTop, m, n, 0);

    while (node) {
        if (node->m == 0) {
            node->value = node->n + 1;
            pop(&stackTop);
        } else if (node->n == 0) {
            pop(&stackTop);
            node = push(stackTop, node->m - 1, 1, 0);
        } else {
            pop(&stackTop);
            node = push(stackTop, node->m, node->n - 1, 0);
            node = push(stackTop, node->m, node->value, 0); // Simulate the inner call by pushing again
        }

        if (node->next) {
            node = node->next;
        } else {
            break; // All calls have been processed
        }
    }

    int result = stackTop->value;
    while (stackTop) {
        pop(&stackTop);
    }
    return result;
}

int ack(int m,int n){
    if (m==0){
        return n+1;
    }else if (m!=0&&n==0){
        return ack(m-1,1);
    }else if (m!=0&&n!=0){
        return ack(m-1,ack(m,n-1));
    }
    return 0;
}

int ackermann(int m, int n) {
    int result = 0;
    while (m != 0) {
        if (n == 0) {
            // 规则A(m, 0) = A(m-1, 1)
            n = 1;
        } else {
            // 规则A(m, n) = A(m-1, A(m, n-1))
            --n;
            result = ackermann(m, n); // 这里使用了临时变量result来避免直接递归
        }
        --m;
    }
    return result + n + 1; // 当m=0时，结果为n+1
}

int main(){
    printf("%d\n",ack(2,1));
    printf("%d\n",ackermann(2,1));
    printf("%d\n",ackermannIterative(2,1));
}