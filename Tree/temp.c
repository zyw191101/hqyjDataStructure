#include<stdio.h>
#include<stdlib.h>

typedef int DATATYPE;
typedef struct node{
datatype data;//数据域用来存数据
struct node *lchild;
struct node *rchild;
}NODE;
/*创建二叉树，用递归函数创建*/
NODE *createBiTree(int n,int i)//i:根节点的编号，n:节点数，返回值：根节点的地址
{
//创建根节点
NODE *root=(NODE *)malloc(sizeof(NODE));
if(NULL==root){
perror("createBiTree root malloc err");
return NULL;
}
//对根节点初始化
root->data=i;
if(2*i<=n){//有左孩子
root->lchild=createBiTree(n,2*i);
}
else
{
root->lchild=NULL;
}
if(2*i+1<=n){//有右孩子
root—>rchild=createBiTree(n,2*i+1);
}
else{
root->rchild=NULL;
}
rerurn r;
}
/*前序*/
void preOrder(NODE *root){
if(NULL==root){
return;
printf("%d",r->data);//根
if(root->lchild !=NULL){
pre0rder(root->lchild);}//左
if(root->rchild!=NULL);//右
{preOrder(root->rchild);}
}}
