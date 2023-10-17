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

/* 遍历双向链表 */
int showDoubleLinkList(POINT *p);

/* 删除双向链表指定位置的数据 */
int delPostDoubleLinklist(POINT *p, int post);

/* 查找指定数据出现的位置 */
int searchDataDoubleLinkList(POINT *p, DATATYPE data);

/* 修改指定位置的数据 */
int changeDataDoubleLinkList(POINT *p, int post, DATATYPE data);

/* 删除双向链表中的指定数据 */
int delDataDoubleLinkList(POINT *p, DATATYPE data);



#endif
