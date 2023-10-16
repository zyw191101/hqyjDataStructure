#ifndef N
#define N
#define datatype int
#define MAXSIZE 10
// 创建顺序栈结构体
typedef struct subSeqStack
{
    datatype data[MAXSIZE];
    int top;
} SEQSTACK;

// 1.创建完整链表
SEQSTACK *createSeqStack();
// 2判空
int isEmpSeqStack(SEQSTACK *p);
// 3判满
int isFullSeqStack(SEQSTACK *p);
// 4出栈（删除数据）
void popSeqStack(SEQSTACK *p);
// 5入栈（添加数据）
void pushSeqStack(SEQSTACK *p, datatype data);
/*   6查看栈顶数据 */
datatype searchSeqStack(SEQSTACK *p);
/*   7求长度 */
int acmSeqStack(SEQSTACK *p);
/*  8清空 */
void clearSeqStack(SEQSTACK *p);

#endif