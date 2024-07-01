#include<stdio.h>

void char_count(char *data,int size) {
    int value_count[35];
    for (int j = 0; j < 35; ++j) {
        value_count[j] = 0;
    }
    for (int i = 0; i < size; ++i) {
        int value = data[i];
        if (value >= 48 && value <= 57) {
            //数字
            value -= 48;
        } else if (value >= 65 && value <= 90) {
            //大写字母
            value -= 56;
        }else{
            continue;
        }
        value_count[value]++;
    }

    FILE *file = fopen("D:/c/my_algo/char_count.txt", "w");

    if (file == NULL) {
        perror("Error opening file");
    }else{
        for (int i = 0; i < 35; ++i) {
            if (value_count[i]!=0){
                char str = i<9?i+48:i+56;
                fprintf(file, "%c出现次数 %d\n",str,value_count[i]);
            }
        }
        fclose(file);
        printf("Data successfully written to file.\n");
    }
}

int main(){
    char data[] = {"ASDASD123asdasdasdsadas"};
    char_count(data,sizeof (data)/sizeof(data[0]));
    return 0;
}