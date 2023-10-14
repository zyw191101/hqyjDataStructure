#include <stdio.h>
#include <stdlib.h>
#include "sequence_sub_table.h"

// 容错判断，数组为空，数组为0
int IsFullSeqlist(SEQ *p)
{
    return p->last == N - 1;
}

int IsEpSeqlist(SEQ *p)
{
    // 满足为1，不满足为0
    return p->last > 0;
}

// 创建一个空的顺序表
SEQ *CreateEpSeqlist()
{
    // 1.动态申请一块空间存放顺序表
    SEQ *p = (SEQ *)malloc(sizeof(SEQ));
    if (NULL == p) // 这里先写NULL一旦少写=会报告err先写p则不会
    {
        perror("p malloc err");
        return NULL;
    }
    /*2.对last初始化。
    因为last为下标初始为0，而赋值是++赋值，
    所以把last初值赋值为-1，
    这样，第一次last就为0 了。*/

    p->last = -1;
    return p;
}

// 向顺序表指定位置插入
int InsertIntoSeqlist(SEQ *p, int post, int data)
{
    // 1.容错判断
    if (IsFullSeqlist(p) < 0 || post > p->last + 1) // 这里last要+1，因为，last初始为-1，last是最后一个有效元素的下标
    {
        printf("delerr\n");
        return -1;
    }
    for (int i = p->last; i >= post; i--)
    {
        p->data[i + 1] = p->data[i];
    }
    p->data[post] = data;
    p->last++;
    // printf("pla%d",p->last);
}
// 遍历
int show(SEQ *p)
{

    for (int i = 0; i <= p->last; i++)
    {
        printf("%d", p->data[i]);
    }
}
// 删除
int delSeqlist(SEQ *p, int post)
{
    // 1.容错判断
    if (IsEpSeqlist(p) < 0 || post > p->last)
    {
        printf("delerr");
        return -1;
    }
    for (int i = post; i < p->last; i++)
    {
        p->data[i + 1] = p->data[i];
    }
    p->last--;
}


int ChangeSeqlist(SEQ *p,int data){
	for(int i=0;i<=p->last;i++){
	if(p->data[i]==data){
	printf("数据存在");
	}else{
//	printf("findErr");
	}
}
}
