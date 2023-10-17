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
	if (NULL == nodep)
	{
		perror("insertIntoDoubleLinkList pnew malloc err");
		return -1;
	}
	nodep->data = data;
	// 2.创建指针，指向要插入的数据节点的地址。
	DLL *temp = NULL;
	// 连接
	// printf("post:%d", post);
	// printf("p->len:%d\n", p->len);
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

/* 遍历双向链表 */
int showDoubleLinkList(POINT *p)
{
#if 0
	for (int i = 0; i < p->len; i++)
	{
				p->head=p->head->next;
		printf("len%ddata:%d\n",p->len,p->head->data);

	}
#else
	// 定义一个临时变量
	DLL *temp = p->head;
	printf("正向遍历");
	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("%d", temp->data);
	}
	printf("\n");
	printf("反向遍历：");
	temp = p->tail;
	while (temp->prior != p->head)
	{ // p->tail是有数据的，所以先打印，再移动
		printf("%d", temp->data);
		temp = temp->prior;
	}
	printf("\n");

#endif
	return 0;
}
/* 删除双向链表指定位置的数据 */
int delPostDoubleLinklist(POINT *p, int post)
{
	DLL *temp = NULL;
	// 容错判断
	if (post < 0 || post > p->len)
	{ // post大于0还是大于等于0todo
		printf("post指定错误");
		return -1;
	}
	// 2.删除操作，分情况
	if (post == p->len)
	{ // todo len是否要减一
		p->tail = p->tail->prior;
		free(p->tail->next);
	}
	else
	{
		if (post <= (p->len) / 2)
		{
			temp = p->head;
			for (int i = 0; i <= post; i++)
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = p->tail;
			for (int i = p->len; i > post; i--)
			{ // todo要不要减一
				temp = temp->prior;
			}
		}
		// 跨过被删除节点
		temp->next->prior = temp->prior;
		temp->prior->next = temp->next;
		// 释放被删除节点
		free(temp);
	}
	// 3.长度len--
	p->len--;
}
/* 查找指定数据出现的位置 */
int searchDataDoubleLinkList(POINT *p, DATATYPE data)
{
	int post = 0;
	DLL *temp = NULL;
	temp = p->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data == data)
		{
			return post;
		}
		post++;
	}
}
/* 修改指定位置的数据 */
int changeDataDoubleLinkList(POINT *p, int post, DATATYPE data)
{
	// 1.容错判断
	if (post < 0 || post >= p->len)
	{ // 也可以等于吧？todo
		printf("post指定错误");
		return -1;
	}
	// 2.定义temp指针将其移动到要修改的位置，分前段和后段
	DLL *temp = p->head;
	if (post < p->len / 2)
	{
		temp = p->head;
		for (int i = 0; i <= post; i++)
			temp = temp->next;
	}
	else
	{
		temp = p->tail;
		for (int i = p->len - 1; i > post; i--)
			// todo 为什么要-1，
			temp = temp->prior;
	}
	// 3.修改数据
	temp->data = data;
	return 0;
}
/* 删除双向链表中的指定数据 */
int delDataDoubleLinkList(POINT *p, DATATYPE data)
{
	// 1.定义一个指针指向头的下一个节点，相当于遍历无头列表
	DLL *temp = p->head->next;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			if (temp == p->tail)
			{
				p->tail = p->tail->prior;
				free(p->tail->next);
				p->tail->next = NULL;
			}
			else
			{
				// 为什么要用pdel再接收一下h呢？
				// 要在定义一个指针来指向要删除的数据节点，因为此时temp是while的判断条件之一，
				// 如果free temp,破坏了判断条件，很可能死循环或段错误
				DLL *pdel = temp;
				pdel->next->prior = pdel->prior;
				pdel->prior->next = pdel->next;
				temp = pdel->next;
				free(pdel);
				pdel = NULL;
			}
		}
		else // 不相等
		{
			temp = temp->next;
		}
	}
}