#include <stdio.h>
#include <stdlib.h>
#include "linkedListSub.h"

#if 1
/* 创建一个链表结构体 */
STU *createLinkList()
{
    STU *head = (STU *)malloc(sizeof(STU));
    // 容错判断
    if (head == NULL)
    {
        printf("createLinkList malloc err");
        return NULL;
    }
    return head;
}
#else
createLinkList(STU *head)
{
    head = NULL;
    head = (STU *)malloc(sizeof(STU));
    // 容错判断
    if (head == NULL)
    {
        printf("createLinkList malloc err");
        return NULL;
    }
}
#endif
/*判断是否为空*/
int isEmptyLinkList(STU *head)
{
    return head->next == NULL;
}

/*写一个有头单项链表，用于保存输入的学生成绩，实现一输入学生成绩就创建一个新的节点，将成绩保存起来。再将该节点链接到链表的尾，直到输入-1结束。
要求：每个链表的节点由动态内存分配得到 , 也就是用malloc。
过程：
1.malloc申请空间link_node_t大小作为头节点
2.将新节点放到链表尾部
*/
int InsertEnd(STU *head, STU *tail, STU *pstu)
{
    head->next = NULL;
    tail = head;
    // printf("%p   \n", tail);
    while (1)
    {
        pstu = (STU *)malloc(sizeof(STU));
        printf("输入分数");
        // 容错判断
        if (pstu == NULL)
        {
            printf("pstuErr");
        }
        scanf("%f", &(pstu->score));
        tail->next = pstu;
        // printf("%.f\n", pstu->score);
        // printf("%p   \n", tail);
        tail = pstu;
        if (pstu->score == -1)
        {
            printf("程序结束");
            break;
        }
    }
}

/* 计算链表长度 */
int acmlenLinkList(STU *head)
{
    int num = 0;
    while (head->next != NULL)
    {
        head = head->next;
        num++;
    }
    return num;
}

/* 中间插入 */
void insertMdInto(STU *head, float data, int insert)
{
    // 容错处理
    //  printf(":%d",insert);
    //  printf("长度：%d",acmlenLinkList(head));
    if (insert < 0 || insert > acmlenLinkList(head))
    {
        printf("insertMdInto err");
    }
    // 移动指针到插入为止的前一个节点
    for (int i = 0; i < insert; i++)
    {
        head = head->next;
    }
    // 创建要插入的节点错！创建新节点保存要要插入的数据
    STU *pInsert = createLinkList();
    pInsert->score = data;
    pInsert->next = head->next; // 插入节点的指针域等于insert后的元素节点=======链接后面
    head->next = pInsert;       // 链接前面
}

/*
删除单链表指定位置的数据*/
int sigleDel(STU *head, int delNum)
{
    STU *del_t = NULL;
    // 容错判断
    if (isEmptyLinkList(head) || delNum < 0 || delNum >= acmlenLinkList(head))
    {
        printf("sigleDel err\n");
        return -1;
    }
    // 找出前一个被删除结点的前一个结点，for循环的使命就结束了
    for (int i = 0; i < delNum; i++)
    {
        head = head->next; // head向后移动，所以i<delnum.这时候head是要删除的元素节点错！！！
                           // 设delnum=0，i=0,i<delnum(0),for循环直接结束，那么语句没有执行。所以需要在外部在移动一次，同时说明这时候的head是被删除元素的前一个结点。
    }
    // head=head->next;//不能这么写这样的话head就改变值了，delt也就没有意义了,无法等量代还，head是指针
    del_t = head->next; // 找个临时替换一下，用于删除，如果不替换，free(?)不指定无法free吧？todo

    head->next = del_t->next; // 跨过
    printf("%.f", del_t->score);
    free(del_t);
    del_t = NULL; // 再次初始化一下
    // return 0;
}
/*
删除单链表指定数据*/
int sigleDel(STU *head, int data){
    STU *pdel=NULL;
    if (isEmptyLinkList(head))
    {
        printf("sigleDel err\n");
        return -1;
    }
    while (1)
    {
        head=head->next;
        if (head->score==data)
        {
        pdel =head;
        head->next=pdel->next->next;
        printf("单链表指定数据删除成功");
        free(pdel);
     
        
        }
        
    }
    
}

/*
清空链表
*/
int clearLinkList(STU *head)
{
    STU *delf = NULL;
    while (head->next != NULL)
    {
        delf = head->next;
        head->next = head->next->next;
        free(delf);
        delf = NULL;
    }
}

/*
查找指定数据出现的位置*/
int searchDataLinkList(STU *head, float data)
{
    // 定义一个接收标志（类似下标）
    int num = 0;
    // 容错判断
    if (acmlenLinkList(head))
    {
        printf("链表为空，没有查找的必要");
    }
    while (head->next != NULL)
    {
        head = head->next;
        num++;
        if (head->score == data)
        {

            return num;
        }
        else
        {
            return -1; // 既然说明数据不存在，那么为什么不是返回0呢？todo
        }
    }
}

/*
修改链表中指定数据,给定位置，传入修改数据
*/
#if 1
int changeDataLinkList(STU *head, int post, float data)
{
    // 容错判断
    if (post < 0 || post >= acmlenLinkList(head) || isEmptyLinkList(head))
    {
        printf("changeDataLinkList ERR");
    }
    for (int i = 0; i <= post; i++)
    {
        head = head->next;
    }
    head->score = data;
}
#else
// todo 传入查找数据，找到并修改。
#endif

/*
删除单向链表中出现的指定数据，data代表将单向链表中出现的所有data数据删除
思想：p始终指向被删除节点的前一个，让q遍历无头链表，用pdel指向被删除的节点
*/
int delDataLinkList(STU *head, float data)
{
    STU *pdel = NULL; // 用于指向被删除节点

    STU *move = head->next;

    while (move != NULL)
    {
        if (move->score == data)
        {
            pdel = move;
            head->next = move->next;

            free(pdel);
            pdel = NULL;
            move = head->next;
        }
        else
        {
            head = head->next;
            move = move->next;
        }
    }
}

/*
将头节点与当前链表断开
invert
*/
int invertLinkList(STU *head)
{
    STU *move = head->next;
    STU *pdel = NULL;
    while (move != NULL)
    {
        pdel = move->next;
        move->next = head->next;
        head->next = move;
        move = pdel;
    }
}

// 遍历STU链表
void show(STU *head)
{
    // 判断是否为空
    if (isEmptyLinkList(head))
    {
        printf("链表为空");
    }
    while (head->next)
    {
        head = head->next;
        printf("%f   ", head->score);
        printf("%p \n", head->next);
    }
}
