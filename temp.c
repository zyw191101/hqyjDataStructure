//2023年10月13日14:59:37

typedef struct linkstack{
datatype data;
struct linkstack *next;
}STK;
/*
 * 创建链式栈结构体（空）函数*/
void creadteEmpChainStack(STK **p){
*p=NULL;
}
/*入栈
 * */
int pushChainStack(STK **ptop,datatype data){
//创建新的结点保存要入栈的数据
		STK *stack=(STK *)malloc(sizeof(STK));
stack->data=data;
//将新节点连接到链表，就是连接之前的栈顶节点
stack->next=ptop;
//移动指针到新节点，栈顶top永远指向栈顶节点
*ptop=stack;
}
/*
 *出栈，取栈内的数据
 */
datatype popStack(STK **ptop){
//容错判断
//定义一个pdel指针，指向被删除的节点，也就是此时栈顶的节点
STK *pdel=*top;
//定义一个临时变量，保存要出栈的数据。也就是保存栈针所指节点的数据
datatype data_temp=(*top)->data
//栈顶向下（移动栈针到后一个位置）
(*top)=pdel->next;
free(pdel);
//返回出栈数据
return data;
}

/*
 * 清空栈*/
void clearStack(STK **ptop){//用二级指针，是因为清空后需要将main函数中的top变为NULL
//循环出栈，只要不为空就出栈
while(1)
popStack(ptop);
if(*ptop==NULL)
{	return 0;}

}



//2023年10月13日10:38:31
/*创建顺序栈结构体函数*/
STK *createEmpSeqStack(int len){
//1.申请空间存储顺序栈
STK *p=(STK *)malloc(sizeof(STK));
if(NULL==p){
printf("*createEmpSeqStack 创建失败");
return NULL;
}
//初始化三个成员
p->maxlen=len;//保存栈的最大长度，通过传参拿到
p->data=(datatype *)malloc(sizeof(datatype)*len);//开辟一块存放数据的数组空间
P-top=-1;
if(NULL==p->data){
printf("p-data空间开辟失败");
return NULL;
}
return p;
}
}
/*判满*/
void isFullSeqStack(STK *p){
		return p->top==p->maxlen;//满了返回1真，不满返回0假
}
/*入栈*/
void pushSeqStack(STK *p,datatype data){
//容错判断
if(isFullSeqStack(p)){
printf("栈满,无法入栈")
}
p->top++;//将top向上移动一个单位
p->data[p->top]=data;//将数据入栈

}

/*
 * 判空*/
void isNullSeqStack(STK *p){
return p->top==-1;//相等为真1，
}
/*
 出栈
 */
datatype popSeqStack(STK *p){
//判空
if(isEmpSeqStack(p)){
printf("栈为空没有数据可以弹出");
}
p->top--;//往下移动指针
return p->data[p->top+1];//将栈顶数据取出

}

/*清空顺序栈*/
void empSeqStack(STK *p){
#if 0
		if(p->top>=0){
		p->data[p->top]=0;
		p->top--;
#else
		p->top=-1;
#endif
}

/*
 * 查看栈顶数据*/

datatype viewSeqStack(STK *p){
if(!isEmpSeqStack(p)){
		return p->data[p->top];}
return -1;

}






//-------------------------------------------------
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
	while (p->next != NULL)
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

#include<stdio.h>
typedef struct node{
int data;//数据域，存放节点的数据
//extern NODE *next;//extern不管用
struct node *next;//这里不能用NODE,因为系统还没有执行到相应语句
//指针域：结构体指针，用来指向下一个节点，也就是保存下一个节点的地址。（自身结构体指针）
} NODE;
int main(){
NODE a;//结构体变量
NODE *p;//结构体指针变量
//定义三个节点
a.data=0;
a.next=NULL;
NODE b={1,NULL};
NODE c={2,NULL};
//连接三个节点
a.next=&b;
b.next=&c;
printf("%d\n",a.data);
printf("%d\n",(a.next)->data);//->通过结构体指针访问指向->的内容
}
