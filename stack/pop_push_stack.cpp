#include<stdio.h>

int main(){
    int maxIndex = 3;
    int data[maxIndex];
    int scan;
    int top=0;

    while(true){
        printf("���������ݣ�");
        scanf("%d",&scan);
        if (scan==-1){
            //��ջ
           printf("��ջ��%d",data[--top]);
        }else{
            if (top==maxIndex){
                printf("ջ���������ȳ�ջ����ջ\n");
                break;
            }else{
                //��ջ
                data[top++]=scan;
                if (top==maxIndex){
                    printf("ջ���������ȳ�ջ����ջ\n");
                }
            }
        }
    }

}