#ifndef N
#define N
#include<stdio.h>
#include<stdlib.h>

/* 宏定义 */
#define DATATYPE int


/*定义链式队列结构体*/
typedef struct linkQueue{
DATATYPE data;
struct linkQueue *next;
}LQUE;

/* 定义一个指针结构体 */
typedef struct point{
LQUE *front;
LQUE *rear;

}POINT;

/* 创建一个空的队列 用有头链表*/
POINT *createLinkQueue();

/* 链式队列入队 */
int inLinkQueue(POINT *p,DATATYPE data);

/* 链式队列出队 */
DATATYPE outLinkQueue(POINT *p);
/* 计算链式队列长度 */
int acmLinkQueue(POINT *p);

/* 判空 */
int isEmpLinkQueue(POINT *p);

/* 清空 */
int clearLinkQueue(POINT *p,int len);



#endif
