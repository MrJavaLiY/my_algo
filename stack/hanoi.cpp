
#include <stdio.h>

void hanoi_tower(int n, char source, char auxiliary, char target) {
    /**
     * ʵ�ֺ�ŵ������ĺ�����
     *
     * ����:
     * n -- ���ӵ�����
     * source -- ��ʼ���ӣ����ַ���ʾ����'A'��
     * auxiliary -- �������ӣ����ַ���ʾ����'B'��xxx
     * target -- Ŀ�����ӣ����ַ���ʾ����'C'��
     *
     * �˺���ͨ���ݹ鷽ʽ�����ŵ�����⡣
     */
    if (n == 1) {
        // ���ֻ��һ�����ӣ�ֱ�Ӵ�source�ƶ���target
        printf("������1��%c�ƶ���%c\n", source, target);
    } else {
        // ��n-1�����Ӵ�source����target�ƶ���auxiliary
        hanoi_tower(n-1, source, target, auxiliary);
        // �ƶ�ʣ�µ��������Ӵ�source��target
        printf("������%d��%c�ƶ���%c\n", n, source, target);
        // ��n-1�����Ӵ�auxiliary����source�ƶ���target
        hanoi_tower(n-1, auxiliary, source, target);
    }
}

int main() {
    int num_disks;
    printf("��������������: ");
    scanf("%d", &num_disks);
    hanoi_tower(num_disks, 'A', 'B', 'C');
    return 0;
}