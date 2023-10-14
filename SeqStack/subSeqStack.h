#ifndef N
#define N

// 创建顺序栈结构体
typedef struct subSeqStack
{
    int data[10];
    int top;
} SEQSTACK;

// 1.创建完整链表
SEQSTACK *createSeqStack();
// 2判空
int isEmpSeqStack(SEQSTACK *p);
// 3判满
int isFullSeqstack(SEQSTACK *p);
// 4出栈（删除数据）
void popSeqStack(SEQSTACK *p);
// 5入栈（添加数据）
void pushSeqStack(SEQSTACK *p, int data);
/*   6查看栈顶数据 */
int searchSeqStack(SEQSTACK *p);
/*   7求长度 */
int acmSeqStack(SEQSTACK *p);
/*  8清空 */
void clearSeqStack(SEQSTACK *p);

#endif