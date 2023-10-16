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
LSTK *createLinkStack();

/* 链式栈入栈 */
void pushLinkStack(LSTK **ptop,DATATYPE data);

/* 链式栈出栈 */
DATATYPE popLinkStack(LSTK **ptop);

/* 查看栈顶元素 */
DATATYPE topDataLinkStack(LSTK **ptop);

/* 判空 */
int ifEmpLinkStack(LSTK *ptop);
























#endif