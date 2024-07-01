#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �ݹ麯�������ַ�������
void reverseStringHelper(char *start, char *end) {
    if (start>=end){
        return;
    }
    char tmp = *start;
    *start = *end;
    *end = tmp;
    reverseStringHelper(start+1,end-1);
}

// ��װ�����������û�����
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