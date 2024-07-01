#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 递归函数用于字符串逆序
void reverseStringHelper(char *start, char *end) {
    if (start>=end){
        return;
    }
    char tmp = *start;
    *start = *end;
    *end = tmp;
    reverseStringHelper(start+1,end-1);
}

// 封装函数，方便用户调用
void reverseString(char *str) {
    if (str == NULL) {
        return;
    }
    int length = strlen(str);
    reverseStringHelper(str, str + length - 1);
}

int main() {
    char str[] = "Hello, World!";
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}