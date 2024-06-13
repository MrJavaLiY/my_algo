#include<stdio.h>
typedef struct{
    char name[20];
    char sex;
}Person;
#define MAX_SIZE 100
void Match(Person persons[],int num){
    Person woman[MAX_SIZE];
    Person man[MAX_SIZE];
    int manTop = 0;
    int womanTop = 0;
    int maxVal = 0;
    int womanVal = 0;

    for(int i=0;i<num;i++){
        Person people= persons[i];
        if (people.sex=='M'){
            man[manTop++] = people;
        }else{
           woman[womanTop++] = people;
        }
    }
    int min = manTop<=womanTop?manTop:womanTop;
    for (int i = 0; i <min ; ++i) {
            printf("man:%s To woman:%s\n",man[maxVal++].name,woman[womanVal++].name);
    }
//说明看【看【开辟【Top != womanTop){
        if (maxVal<manTop){
          int val2 = 0;
         for(int i = maxVal;i<manTop;i++){
              printf("男%s 没有舞伴，预配舞伴为：%s\n",man[i].name,woman[val2++].name);
             if (val2==womanTop){
                 val2=0;
             }
         }
        }else if (womanVal<womanTop){
            int val2 = 0;
            for(int i = womanVal;i<womanTop;i++){
                printf("女%s 没有舞伴，预配舞伴为：%s\n",woman[i].name,man[val2++].name);
                if (val2==manTop){
                    val2=0;
                }
            }
        }
    }

}

int main(){
    Person  person[]={
            {"A",'M'},
            {"B",'M'},
            {"C",'M'},
            {"D",'N'},
            {"E",'N'},
            {"F",'N'},
            {"G",'N'},
            {"H",'N'},
            {"I",'N'},
            {"J",'N'},
            {"K",'N'},
            {"L",'M'},
    };
    Match(person,sizeof(person)/sizeof(person[0]));
}