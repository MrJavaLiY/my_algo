#include<stdio.h>

int main(){
    int maxIndex = 3;
    int data[maxIndex];
    int scan;
    int top=0;

    while(true){
        printf("请输入数据：");
        scanf("%d",&scan);
        if (scan==-1){
            //弹栈
           printf("出栈：%d",data[--top]);
        }else{
            if (top==maxIndex){
                printf("栈已满，请先出栈再入栈\n");
                break;
            }else{
                //入栈
                data[top++]=scan;
                if (top==maxIndex){
                    printf("栈已满，请先出栈再入栈\n");
                }
            }
        }
    }

}