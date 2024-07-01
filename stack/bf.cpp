#include <stdio.h>
#include <string.h>

// BF�㷨ʵ��
int boyerMooreSearch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int skipTable[256]; // �������ڼ�¼ÿ���ַ���pattern�е�������λ��
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
        //�����ַ�
        if (skipTable[textAscii] != patternLen) {
            int sum = 1;
            int n = i;
            //��ȡ����ǰ�ַ��ڲ������е�λ��
            int num = skipTable[textAscii];
            for (int j = 0; j < patternLen; ++j) {
                //������һλ�������ַ��ж�
                 num = num>=patternLen-1?0:num+1;
                 //��һλ��Ҫ�ж��ַ�
                int nextText = text[++n];
                int nextHash = skipTable[nextText];
                //��һ��ֵ�Ƿ����һλ�����ַ�һ�£����һ�¾ͼ�һ��
                if (num == nextHash) {
                    sum++;
                }else{
                        break;
                }
                //��һ�¾�����

            }
            if (sum >= patternLen){
                return i;
            }
        }
    }


    return -1; // δ�ҵ�ƥ��
}

int main() {
    char text[] = "asdzczxc";
    char virusPattern[] = "zxc"; // �ٶ���������Ҫ�ҵĲ���ģʽ��

    int index = boyerMooreSearch(text, virusPattern);
    if (index != -1) {
        printf("���ֲ���ģʽ����λ���ı��ĵ�%d���ַ���ʼ��\n", index);
    } else {
        printf("δ��⵽����ģʽ����\n");
    }

    return 0;
}