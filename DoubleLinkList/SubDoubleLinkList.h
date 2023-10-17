#ifndef N
#define N

#include<stdio.h>
#include<stdlib.h>
#define DATATYPE int
/*定义双向链表结构体*/
typedef struct node{
DATATYPE data;
struct node *next;//指向下一个节点的指针
struct node *prior;//指向前一个节点的指针
}DLL;
/*封装双向链表的指针（头指针和尾指针）
 *
 * */
typedef struct point{
DLL *head;
DLL *tail;
int len;
}POINT;

/* 创建 */
POINT* createDoubleLinkList();

/* 入队 */
int inDoubleLinkList(POINT *p, int post, DATATYPE data);





#endif
