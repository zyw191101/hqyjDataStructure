#ifndef N
#define N

#include<stdio.h>
#include<stdlib.h>
/* 宏定义 */
#define DATATYPE int 
#define MAXSIZE 5
/* 创建队列结构体 */
typedef struct queue{
DATATYPE data[MAXSIZE];//循环队列装数据的数组
int front;
int rear;
}QUE;




/* 创建空队列 */
QUE *createQueue();
/* 入列 */
int inSeqQueue(QUE *p, DATATYPE data);
/* 出列 */
DATATYPE outQueue(QUE *p);
/* 计算长度 */
int acmLenQueue(QUE *p);







#endif
