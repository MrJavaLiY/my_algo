
#include <stdio.h>
#include <string.h>

void get_next(const char* pattern, int next[]) {
    int m = strlen(pattern);
    next[0] = -1;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        next[i] = j;
    }
}

int kmp_search(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int next[m];
    get_next(pattern, next);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                return i - m;  // 匹配成功，返回起始索引
            }
        } else {
            if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;  // 未找到匹配
}

// 使用示例
int main() {
    char text[] = "abcxabcdabcdabcy";
    char pattern[] = "abcdabcy";
    int result = kmp_search(text, pattern);
    printf("Pattern found at index: %d\n", result);
    return 0;
}