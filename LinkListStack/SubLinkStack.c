#include <stdlib.h>
#include <stdio.h>
#include "SubLinkStack.h"

/* 创建空的链式栈 */
LSTK *createLinkStack()
{

    LSTK *ptop = (LSTK *)malloc(sizeof(LSTK));
    ptop->next = NULL;
    return ptop;
}
/* 入栈 */
void pushLinkStack(LSTK **ptop, DATATYPE data)
{
    LSTK *pinsert = (LSTK *)malloc(sizeof(LSTK));
    pinsert->next = (*ptop);
    pinsert->data = data;
    (*ptop) = pinsert;
}

/* 出栈 todo*/
DATATYPE popLinkStack(LSTK **ptop)
{
    if (ifEmpLinkStack(*ptop))
    {
        printf("栈为空");
    }
    DATATYPE data_temp = (*ptop)->data;
    ;
    // 定义一个临时指针，指向被删除的节点
    LSTK *pdel = *ptop;
    (*ptop) = (*ptop)->next; // 跨过,实际跨过，所以要用二级指针
    free(pdel);
    pdel = NULL;
    printf("出栈数据为%d", data_temp);
    return data_temp;
}

/* 判空 */
int ifEmpLinkStack(LSTK *ptop)
{
    return ptop->next == NULL;
}

/* 查看栈顶元素 */
DATATYPE topDataLinkStack(LSTK **ptop)
{
    printf("%d", (*ptop)->data);
    return (*ptop)->data;
}
