#include<stdio.h>
#include<stdlib.h>
#include"subSeqStack.h"
/*  1.创建完整链表 */
SEQSTACK *createSeqStack()
{
    SEQSTACK *seqStack = (SEQSTACK *)malloc(sizeof(SEQSTACK));
    seqStack->top = -1;
    return seqStack;
}
/*     2判空 */
int isEmpSeqStack(SEQSTACK *p)
{
    return p->top == -1;
}
/*3判满 */
int isFullSeqStack(SEQSTACK *p)
{
    return p->top == MAXSIZE - 1;
}
/* 4出栈（删除数据） */
void popSeqStack(SEQSTACK *p)
{
    if (isEmpSeqStack(p))
    {
        printf("popSeqStack 栈为空无需出栈");
    }

    p->top--;
}
/* 5入栈（添加数据） */
void pushSeqStack(SEQSTACK *p, datatype  data)
{
    if (isFullSeqStack(p))
    {
        printf("popSeqStack 栈为空无需出栈");
    }
    // 当栈为空的时候，top=-1，所以先++，在赋值
    p->top++;
    p->data[p->top] = data;
}
/*   6查看栈顶数据 */
datatype searchSeqStack(SEQSTACK *p)
{
    return p->data[p->top];
}
/*   7求长度 */
int acmSeqStack(SEQSTACK *p)
{

    return p->top+1;
}
/*  8清空 */
void clearSeqStack(SEQSTACK *p)
{
    p->top = -1;
    printf("顺序栈已清空");
}