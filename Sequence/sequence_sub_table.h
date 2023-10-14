#ifndef S
#define S
#define N 10

typedef struct seqlist{
int data[N];
int last;//代表数组中最后一个有效元素的下标
}SEQ;


//创建一个空的顺序表
SEQ *CreateEpSeqlist();

//向顺序表指定位置插入
int InsertIntoSeqlist(SEQ *p,int post,int data);

//删除
int delSeqlist(SEQ *p,int post);

//打印
int show(SEQ *p);
//容错判断
int IsFullSeqlist(SEQ *p);
int IsEpSeqlist(SEQ *p);

//修改指定位置数据
int ChangeSeqlist(SEQ *p,int data);
#endif
