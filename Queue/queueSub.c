#include <stdio.h>
#include <stdlib.h>
#include "queueSub.h"
/* 创建空队列 */
QUE *createQueue()
{
    // 1.开辟空间
    QUE *p = (QUE *)malloc(sizeof(QUE));
    if (NULL == p)
    {
        printf("开辟空间失败");
        return NULL;
    }
    // 初始化
    p->front = 0;
    p->rear = 0;
    return p;
}

/*入列
对data和rear进行修改，所以一级指针指向内容就可以了*/
int inSeqQueue(QUE *p, DATATYPE data)
{
    //这里不判满，很容易会越界，从而使程序不报错，但是无法产出自己想要的结果
    if ((p->rear + 1)%MAXSIZE == p->front)
    {
        printf("队列满了");
        return 0;
    }
    #if 0
    while ((p->rear % MAXSIZE) + 1 != p->front)
    {
        p->data[p->rear] = data;
        p->rear++;
    }
    #else
     p->data[p->rear] = data;
     //将尾巴向后移动一个单位，注意要用循环的公式
     p->rear=(p->rear+1)%MAXSIZE;
     return 0;
     #endif
}
/*出列
对front进行处理*/
DATATYPE outQueue(QUE *p){
if (p->front==p->rear)
{
    printf("队列为空");
    return -1;
}
DATATYPE data_temp=p->data[p->front];
p->front=(p->front+1)%5;
return data_temp;

}

/*求队列长度*/
int acmLenQueue(QUE *p){
    //长度分情况，尾>=头，头<尾
    if (p->rear >=p->front)
    {
        return p->rear-p->front;
    }else
    return p->rear-p->front+MAXSIZE;
}

/* 清空队列函数 */
void clearQueue(QUE *p){
  //思想：只要不是空队列就出列
    while (!isEmptySequeue(p))//p->front != p->rear
    {
        printf("%d ",outSequeue(p));
    }
    printf("\n");
}

/* 判空 */
int isEmptySequeue(QUE *p)
{
    return p->front == p->rear;
}


/* 判满 */
//判断队列是否为满
int isFullSequeue(QUE *p)
{
    //思想上，舍去数组上的一个存储位置,用于判断队列是否为满
    //先判断rear的下一个位置是否等于front
    return (p->rear + 1) % MAXSIZE == p->front;
}











