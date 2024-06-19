#include<stdio.h>
#include <cstdlib>

typedef int SElemType;

typedef struct{
    int top[2],bot[2];
    SElemType *V;
    int m;
}DblStack;

DblStack *init(int m){
    DblStack *dblStack  = (DblStack *)malloc(sizeof(DblStack));
    SElemType sElemType[m];
    dblStack->V = sElemType;
    dblStack->m = m;
    dblStack->top[0] =0;
    dblStack->top[1] =m-1;
    dblStack->bot[0] =0;
    dblStack->bot[1] =m-1;
    return dblStack;
}
int empty(DblStack value){

    return 1;
}