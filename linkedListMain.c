#include<stdio.h>
#include<stdlib.h>
#include"linkedListSub.h"


int main()
{
//定义头指针，指向第一个节点。找到链表的头部
STU *head=createLinkList();


//定义尾指针，连接两个节点
STU *tail=NULL;//初始化防止野指针

//定义一个pstu接收学生结构体的指针
STU *pstu=NULL;//初始化防止野指针

//swapLinkList(head);
InsertEnd(head,tail,pstu);
insertMdInto(head,100,3);
// invertLinkList(head);
sigleDel(head,3);
searchDataLinkList(head,200);
show(head);
clearLinkList(head);
show(head);
free(head);
free(pstu);

}





/*
插入：第6行
//定义并创建链表
LNL A={'a',NULL};
LNL B={'b',&A};//定义的同时，必须全赋值
LNL C={'c',&B};
LNL D={'d',&C};
LNL E={'e',&D};

*/