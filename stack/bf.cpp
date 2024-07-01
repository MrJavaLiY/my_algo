#include <stdio.h>
#include <string.h>

// BF算法实现
int boyerMooreSearch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int skipTable[256]; // 跳表，用于记录每个字符在pattern中的最后出现位置
    for (int i = 0; i < 256; ++i) {
        skipTable[i] = patternLen;
    }
    for (int i = 0; i < patternLen; ++i) {

        if (skipTable[pattern[i]]==patternLen){
            skipTable[pattern[i]] = i;
        }
    }

    for (int i = 0; i < textLen; ++i) {
        int textAscii = text[i];
        //命中字符
        if (skipTable[textAscii] != patternLen) {
            int sum = 1;
            int n = i;
            //获取到当前字符在病毒串中的位置
            int num = skipTable[textAscii];
            for (int j = 0; j < patternLen; ++j) {
                //进行下一位病毒串字符判断
                 num = num>=patternLen-1?0:num+1;
                 //下一位需要判断字符
                int nextText = text[++n];
                int nextHash = skipTable[nextText];
                //下一个值是否和下一位病毒字符一致，如果一致就加一；
                if (num == nextHash) {
                    sum++;
                }else{
                        break;
                }
                //不一致就跳过

            }
            if (sum >= patternLen){
                return i;
            }
        }
    }


    return -1; // 未找到匹配
}

int main() {
    char text[] = "asdzczxc";
    char virusPattern[] = "zxc"; // 假定这是我们要找的病毒模式串

    int index = boyerMooreSearch(text, virusPattern);
    if (index != -1) {
        printf("发现病毒模式串，位于文本的第%d个字符开始。\n", index);
    } else {
        printf("未检测到病毒模式串。\n");
    }

    return 0;
}