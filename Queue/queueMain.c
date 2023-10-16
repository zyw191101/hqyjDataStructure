#include"queueSub.h"

int main(int argc, char const *argv[])
{
    QUE *queue= createQueue();
    #if 1
    for (int i = 0; i < 2; i++)
    {
    inSeqQueue(queue,i);
    }
    #else
    inSeqQueue(queue,999);
    #endif
    // int a=outQueue(queue);
    int len =acmLenQueue(queue);
    printf("长度:%d",len);

    return 0;
}
