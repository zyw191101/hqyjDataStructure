#include <stdio.h>
#include <stdlib.h>
#include "SubLinkStack.h"
int main(int argc, char const *argv[])
{
    int keyboard;
    int data_in;
    LSTK *linkStack = createLinkStack();

#if 1
    while (1)
    {
        printf("请输入指令");
        scanf("%d", &keyboard);
        switch (keyboard)
        {
            // // 1.创建完整链表
            // case 1:
            //     printf("yiiljm");

            //     break;
            // // 2判空
        case 2:
            /* 判空 */
            ifEmpLinkStack(linkStack);
            break;
        // 出栈
        case 4:{
            popLinkStack(&linkStack);
            break;}
        // 入栈（添加数据）
        case 5:
            printf("输入插入数据");
            scanf("%d", &data_in);
            pushLinkStack(&linkStack, data_in);
            break;
        // // 查看栈顶数据
        case 6:
            // searchSeqStack(seqStack);
            topDataLinkStack(&linkStack);
            break;
        // // 求长度
        // case 7:
        //     // acmSeqStack(seqStack);
        //     printf("%d", acmSeqStack(seqStack));
        //     break;
        // // 清空
        // case 8:
        //     clearSeqStack(seqStack);
        //     break;
        case 0:
            return 0;
        default:
            printf("选项输入错误\n");
            break;
        }
    }
#else
#endif
    return 0;
}