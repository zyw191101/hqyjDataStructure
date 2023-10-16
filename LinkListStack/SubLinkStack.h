#ifndef N
#define N
#include<stdlib.h>
#include<stdio.h>
#define DATATYPE int
typedef struct SubLinkStack
{
    DATATYPE data;
    struct SubLinkStack *next;
    
}LSTK;

/* 创建空的链式栈 */
LSTK *createLinkStack(){

    LSTK *ptop=(LSTK *)malloc(sizeof(LSTK));
    ptop->next=NULL;
    return ptop;
}

/* 链式栈入栈 */
void pushLinkStack(LSTK **ptop,DATATYPE data);

/* 查看栈顶元素 */
DATATYPE topDataLinkStack(LSTK **ptop);

























#endif