// 清空
void clLinkList(STU *p)
{
	STU *pdel = NULL;
	while (p->next !NULL)
	{
		pdel = p->next;
		p->next = pdel->next;
		free(pdel);
		pdel = NULL;
	}
}

// 删除单项链表中指定位置的数据，post指定删除的位置
int delPostLinkList(STU *p, int post)
{
	STU *pdel = NULL;
	for (int i = 0; i < post; i++)
	{
		p = p->next;
	}
	pdel = p->next;
	free(pdel);
	pdel = NULL;
	return 0;
}

// 删除单项链表中出现的指定数据data，
int delPostDataLinkList(STU *head, float data)
{
	STU *pdel = NULL;
	STU *move = head->next;
	while (move != NULL)
	{
		if (move->data == data)
		{
			pdel = move;
			head->next = move - next; // 跨过
			free(pdel);
			move = head->next;
		}
		else
		{
			head = head->next;
			move = mov - next;
		}
	}
}

// 倒置链表
// 将头节点与当前节点断开，断开前保存头节点的下一个节点，以便能找。相当于遍历无头连接。
// 遍历无头链表，并且将遍历节点的下一个节点用指针保存下一个。然后遍历一个节点插入到头节点后面
int invertLinkList(STU *head)
{
	STU *move = head->next;
	STU *ptem = NULL;
	while (move != NULL)
	{
		ptem = move - next;
		move = move - next;
		head - next = move;
		move->next = temp;
	}
}

// 查找指定数据出现的位置，
// 找到返回节点标志，未找到返回-1
int searchDataLinkList(STU *p, float data)
{
	int post = 0;
	while (p->next != null)
	{
		p = p->next;
		post++;
		if (p->data == data)
		{
			return post;
		}
	}
	return -1;
}

// 修改链表指定数据
int changePostLinkList(STU *p, int post, int data)
{
	// 容错判断
	if (i = 0; i <= post, i++)
	{	//<移动到前一个
		// i=0,p=p->next,元素节点0
		// i=1,p=p->next,元素节点1
		p = p->next;
	}
	p->data = data;
}

// 删除数据i
