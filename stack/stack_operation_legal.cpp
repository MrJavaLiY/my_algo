#include<stdio.h>
bool legal(char value[],int size){
int num = 0;
    for (int i = 0; i < size; ++i) {
        if (value[i]=='I'){
            num++;
        }else if (value[i]=='O'){
            if (num==0){
                return false;
            }
            num--;
        }
    }
    if (num!=0){
        return false;
    }
    return true;
}

int main(){
//    char value[]={'I','O','I','I','O','I','O','O'};
//    char value[]={'I','O','O','I','O','I','I','O'};
//    char value[]={'I','I','I','O','I','O','I','O'};
    char value[]={'I','I','I','O','O','I','O','O'};
    bool  b = legal(value,sizeof (value)/sizeof (value[0]));
    if (b){
        printf("操作合规");
    }else{
        printf("操作不合规");
    }
}