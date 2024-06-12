//
// Created by ly on 2024/6/12.
//
#include<Stdio.h>
int fibonacci_recursive(int n) {
    if (n <= 0) {
        return -1; // ����-1��ʾ��������
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}
    int fibonacci_iterative(int n) {
        if (n <= 0) {
            return -1; // ����-1��ʾ��������
        }
        int a = 0, b = 1, temp;
        //��Ϊ��1λ�͵�2λ�̶���0��1��
        for (int i = 3; i <= n; i++) {
            //���
            temp = a + b;
            //�Ѵ���Ǹ�������
            a = b;
            //�ѽ��������Ǹ�������һ�ξ���ֱ���ô����ͽ�����
            b = temp;
        }
        //Ҫ�жϵ�1λ�͵�2λ�������Ȼ���ٷ��ؾ���ֵ
        return (n == 1) ? 0 : ((n == 2) ? 1 : b);
    }

int main(){
    printf("�ݹ�쳲��������н��Ϊ:%ld\n",fibonacci_recursive(10));
    printf("����쳲��������н��Ϊ:%ld\n",fibonacci_iterative(10));
    return 0;
}