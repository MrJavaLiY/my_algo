#include<stdio.h>
#include<ctype.h>
int main(){
    int max = 100;
    char value[max];
    int data[max];
    int top =0;

    printf("�������沨�����ʽ��");
    fgets(value,max,stdin);
    for (int i = 0; i < max; ++i) {
        if (value[i]=='$'){
            break;
        }

        if (isdigit(value[i])){
            int num =0;
            while(isdigit(value[i])){
               num=num*10+(value[i++]-'0');
            }
            data[top++] =num;
            i--;
        }else{
            if (value[i]=='+'||value[i]=='-'||value[i]=='*'||value[i]=='/'){
                int val1 =    data[--top];
                int val2 = data[--top];
                switch(value[i]){
                    case '+':
                        data[top++]=val1+val2;
                        break;
                    case '-':
                        data[top++]=val2-val1;
                        break;
                    case '*':
                        data[top++]=val1*val2;
                        break;
                    case '/':
                        data[top++]=val2/val1;
                        break;
                }
            }
        }
    }
    printf("�����%d",data[--top]);
}