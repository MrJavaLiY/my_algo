
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

int precedence(char op);
int applyOp(int a, int b, char op);
void push(int stack[], int *top, int val);
int pop(int stack[], int *top);

bool evaluate(char* exp, int* result) {
    //数据栈
    int operands[MAX_STACK_SIZE];
    //符号栈
    int operators[MAX_STACK_SIZE];
    int operandTop = -1;
    int operatorTop = -1;
    int i = 0;

    while (exp[i] != '\0') {
        //判断是不是有效字符
        if (isspace(exp[i])) {
            i++;
            continue;
        }
        //判断是不是数字
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i++] - '0');
            }
            push(operands, &operandTop, num);
            --i; // 因为循环还会++i
        } else if (exp[i] == '(') {
            push(operators, &operatorTop, exp[i]);
        } else if (exp[i] == ')') {
            while (operators[operatorTop] != '(') {
                int val2 = pop(operands, &operandTop);
                int val1 = pop(operands, &operandTop);
                char op = pop(operators, &operatorTop);
                push(operands, &operandTop, applyOp(val1, val2, op));
            }
            pop(operators, &operatorTop); // 弹出左括号
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            while (operatorTop >= 0 && precedence(operators[operatorTop]) >= precedence(exp[i])) {
                int val2 = pop(operands, &operandTop);
                int val1 = pop(operands, &operandTop);
                char op = pop(operators, &operatorTop);
                push(operands, &operandTop, applyOp(val1, val2, op));
            }
            push(operators, &operatorTop, exp[i]);
        }
        i++;
    }

    // 处理剩余的操作符
    while (operatorTop >= 0) {
        int val2 = pop(operands, &operandTop);
        int val1 = pop(operands, &operandTop);
        char op = pop(operators, &operatorTop);
        push(operands, &operandTop, applyOp(val1, val2, op));
    }

    *result = operands[operandTop];
    return true;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // 注意：这里没有做除以0的检查
        default: return 0; // 非预期操作符
    }
}

void push(int stack[], int *top, int val) {
    if (*top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    //压栈
    stack[++(*top)] = val;
}

int pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    //弹栈
    return stack[(*top)--];
}

int main() {
    char exp[] = "(10 + 2) * (6 / 2)";
    int result;
    if (evaluate(exp, &result))
        printf("结果: %d\n", result);
    return 0;
}