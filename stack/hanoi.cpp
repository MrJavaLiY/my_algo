
#include <stdio.h>

void hanoi_tower(int n, char source, char auxiliary, char target) {
    /**
     * 实现汉诺塔问题的函数。
     *
     * 参数:
     * n -- 盘子的数量
     * source -- 起始柱子（用字符表示，如'A'）
     * auxiliary -- 辅助柱子（用字符表示，如'B'）xxx
     * target -- 目标柱子（用字符表示，如'C'）
     *
     * 此函数通过递归方式解决汉诺塔问题。
     */
    if (n == 1) {
        // 如果只有一个盘子，直接从source移动到target
        printf("将盘子1从%c移动到%c\n", source, target);
    } else {
        // 将n-1个盘子从source借助target移动到auxiliary
        hanoi_tower(n-1, source, target, auxiliary);
        // 移动剩下的最大的盘子从source到target
        printf("将盘子%d从%c移动到%c\n", n, source, target);
        // 将n-1个盘子从auxiliary借助source移动到target
        hanoi_tower(n-1, auxiliary, source, target);
    }
}

int main() {
    int num_disks;
    printf("请输入盘子数量: ");
    scanf("%d", &num_disks);
    hanoi_tower(num_disks, 'A', 'B', 'C');
    return 0;
}