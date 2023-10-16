#include "LinkQueueSub.h"

/* 创建一个空的队列 用有头链表*/
POINT *createLinkQueue()
{
    // 开辟装头尾指针的结构体大小的空间
    POINT *p = (POINT *)malloc(sizeof(POINT));
    if (NULL == p)
    {
        printf("存放头尾指针空间开辟失败");
        return NULL;
    }
    // 开辟一个头节点的空间，让rear和front都指向头节点
    p->front = p->rear = (LQUE *)malloc(sizeof(LQUE));
    if (NULL == p->front)
    {
        printf("头节点开辟失败");
    }
    p->front->next = NULL;
    return p;
}

/* 链式队列入队 */
int inLinkQueue(POINT *p, DATATYPE data)
{
    LQUE *nodep = (LQUE *)malloc(sizeof(LQUE));
    if (nodep == NULL)
    {
        printf("入队创建新节点失败");
        return -1;
    }

    nodep->data = data;
    // p->rear->data = nodep->data;
    p->rear->next = nodep;
    p->rear = nodep;
    return p->rear->data;
}
/* 链式队列出队 */
DATATYPE outLinkQueue(POINT *p)
{
    if (isEmpLinkQueue(p))
    {
        printf("队列为空");
        return -1;
    }
    LQUE *pdel = NULL;
    pdel = p->front;
    p->front = p->front->next;
    free(pdel);
    return p->front->data;
}
/* 判空 */
int isEmpLinkQueue(POINT *p)
{
    return p->front->next == NULL;
}

/* 计算链式队列长度 */
int acmLinkQueue(POINT *p)
{
    if (isEmpLinkQueue(p))
    {
        printf("队列为空");
        return -1;
    }

    int num = 0;
    LQUE *tp = p->front;
    // 因为p->front指向头节点的地址，地址如果改变找不到节点
    //跟出栈最根本的区别在于只移动了指针，但是数据节点没有free,所以要用临时temp代替
    while (tp->next != NULL)
    {
        tp = tp->next;
        num++;
    }
    return num;
}
/* 清空链式队列 */
int clearLinkQueue(POINT *p, int len)
{
#if 0
		if (isEmpLinkQueue(p))
{
    printf("队列为空");
    return -1;
}
for (int i = 0; i < len; i++)
{
    outLinkQueue(p);
}
#else
    while (!isEmpLinkQueue(p))
    {
        outLinkQueue(p);
    }
    return 0;
#endif
}
