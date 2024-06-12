#include <stdio.h>

/**
    * 实现汉诺塔问题的函数。 汉罗塔的解法，研究递归
    *
    * 参数:
    * n -- 盘子的数量
    * source -- 起始柱子（用字符表示，如'A'）
    * auxiliary -- 辅助柱子（用字符表示，如'B'）xxx
    * target -- 目标柱子（用字符表示，如'C'）
    *
    * 此函数通过递归方式解决汉诺塔问题。
    * 以3为例解释流程
    * 为了方便理解，直接把形参改成实际的柱子标识，这样好记忆
    *
    */
    /**
     * 逻辑：设n=3，分别有3个盘，3,2,1号，从上到下由小到大，进入时是3个盘，拿2个盘接着递归，直到只有1个盘时
     * 将最小的1号盘放到B柱上，因为这个地方有3个盘，1号盘动了，2号盘也要动，不然3号没法动
     * 所以把2号盘放到C柱上，这样A->3,B->1,C->2
     * 接着要动3了，但是3没有位置了，所以还要继续动2号和1号
     * 这里最难理解的是柱子在动
     *
     *
     */
void hanoi_tower(int n, char source, char auxiliary, char target) {

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
    int num_disks=4;
//    printf("请输入盘子数量: ");
//    scanf("%d", &num_disks);
    hanoi_tower(num_disks, 'A', 'B', 'C');
    return 0;
}