#include <stdio.h>

/**
    * ʵ�ֺ�ŵ������ĺ����� �������Ľⷨ���о��ݹ�
    *
    * ����:
    * n -- ���ӵ�����
    * source -- ��ʼ���ӣ����ַ���ʾ����'A'��
    * auxiliary -- �������ӣ����ַ���ʾ����'B'��xxx
    * target -- Ŀ�����ӣ����ַ���ʾ����'C'��
    *
    * �˺���ͨ���ݹ鷽ʽ�����ŵ�����⡣
    * ��3Ϊ����������
    * Ϊ�˷�����⣬ֱ�Ӱ��βθĳ�ʵ�ʵ����ӱ�ʶ�������ü���
    *
    */
    /**
     * �߼�����n=3���ֱ���3���̣�3,2,1�ţ����ϵ�����С���󣬽���ʱ��3���̣���2���̽��ŵݹ飬ֱ��ֻ��1����ʱ
     * ����С��1���̷ŵ�B���ϣ���Ϊ����ط���3���̣�1���̶��ˣ�2����ҲҪ������Ȼ3��û����
     * ���԰�2���̷ŵ�C���ϣ�����A->3,B->1,C->2
     * ����Ҫ��3�ˣ�����3û��λ���ˣ����Ի�Ҫ������2�ź�1��
     * �������������������ڶ�
     *
     *
     */
void hanoi_tower(int n, char source, char auxiliary, char target) {

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
    int num_disks=4;
//    printf("��������������: ");
//    scanf("%d", &num_disks);
    hanoi_tower(num_disks, 'A', 'B', 'C');
    return 0;
}