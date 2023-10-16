#include<stdlib.h>
#include<stdio.h>
#include"SubLinkStack.h"


/* 创建空的链式栈 */
LSTK *createLinkStack(){

    LSTK *ptop=(LSTK *)malloc(sizeof(LSTK));
    ptop->next=NULL;
    return ptop;
}
/* 入栈 */
void pushLinkStack(LSTK **ptop,DATATYPE data){
    LSTK *pinsert=(LSTK *)malloc(sizeof(LSTK));
    pinsert->next=ptop;
    pinsert->data=data;
    ptop=pinsert;
}

/* 查看栈顶元素 */
DATATYPE topDataLinkStack(LSTK **ptop){
    printf("%d",(*ptop)->data);
return (*ptop)->data;
}

