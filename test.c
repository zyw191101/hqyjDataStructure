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
