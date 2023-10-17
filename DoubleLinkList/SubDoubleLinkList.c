#include "SubDoubleLinkList.h"

/*创空*/
POINT *createDoubleLinkList()
{
	// 1.申请存放头尾指针结构体大小的空间
	POINT *p = (POINT *)malloc(sizeof(POINT));
	if (NULL == p)
	{
		printf("头尾指针空间申请失败\n");
		return NULL;
	}
	// 2.初始化，头尾指针指向开辟的头节点空间
	p->head = p->tail = (DLL *)malloc(sizeof(DLL));
	if (p->head == NULL)
	{
		printf("头节点空间开辟失败\n");
		return NULL;
	}
	// 3.初始化头节点
	p->head->next = NULL;
	p->tail->prior = NULL;
	// 4.初始化长度
	p->len = 0;
	return p;
}

/*插入*/
int inDoubleLinkList(POINT *p, int post, DATATYPE data)
{
	if (post < 0 || post > p->len)
	{ // post可以等于len吗？todo
		printf("post指定错误");
		return -1;
	}
	// 1.创建数据节点和指向该数据节点指针保存插入数据
	DLL *nodep = (DLL *)malloc(sizeof(DLL));
	nodep->data = data;
	// 2.创建指针，指向要插入的数据节点的地址。
	DLL *temp = NULL;
	// 连接
	printf("post:%d", post);
	printf("p->len:%d\n", p->len);
	if (post == p->len)
	{ // 尾插
		p->tail->next = nodep;
		nodep->prior = p->tail;
		nodep->next = NULL;
		p->tail = nodep;
		printf("尾插%d\n", nodep->data);
	}
	else
	{
		if (post < (p->len) / 2)
		{
			// 通过循环找到插入的数据节点
			temp = p->head;
			for (int i = 0; i <= post; i++)
			{ // 要不要等于post
				temp = temp->next;
			}
			temp->prior->next = nodep;
			nodep->prior = temp->prior;
			nodep->next = temp->prior;
			printf("前部插%d\n", nodep->data);
		}
		else
		{
						// 通过循环找到插入的数据节点
			temp = p->tail;
			for (int i = p->len; i >= post; i--)
			{ // 要不要等于post
				temp = temp->prior;
			}
			temp->prior->next = nodep;
			nodep->prior = temp->prior;
			nodep->next = temp->prior;
			printf("前部插%d\n", nodep->data);
			printf("后半部分插入 \n");
		}
	}
	p->len++;
	return p->len;
}
