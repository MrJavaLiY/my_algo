//
// Created by ly on 2024/6/12.
//
#include<Stdio.h>
int fibonacci_recursive(int n) {
    if (n <= 0) {
        return -1; // 返回-1表示错误输入
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
            return -1; // 返回-1表示错误输入
        }
        int a = 0, b = 1, temp;
        //因为第1位和第2位固定了0和1的
        for (int i = 3; i <= n; i++) {
            //结果
            temp = a + b;
            //把大的那个数留着
            a = b;
            //把结果给大的那个数，下一次就能直接用大数和结果相加
            b = temp;
        }
        //要判断第1位和第2位的情况，然后再返回具体值
        return (n == 1) ? 0 : ((n == 2) ? 1 : b);
    }

int main(){
    printf("递归斐波那契数列结果为:%ld\n",fibonacci_recursive(10));
    printf("迭代斐波那契数列结果为:%ld\n",fibonacci_iterative(10));
    return 0;
}