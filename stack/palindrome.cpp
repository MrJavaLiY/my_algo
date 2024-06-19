#include<stdio.h>


int is_pal(char value[],int size){
    int half = size%2==0? size/2:size/2+1;
    int stack[half];
    int top = 0;
    for (int i = 0; i < size; ++i) {
        if (i<half){
            stack[top++]=value[i];
        }else{
            if (stack[--top]!=value[i]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
//    char value[] ={'a','a','b','b','a','a'};
    char value[] ={'a','b','b','a'};
//    char value[] ={'a','b','d','b','a'};
    int a =is_pal(value,sizeof(value)/sizeof (value[0]));
    printf("%d\n",a);
}

