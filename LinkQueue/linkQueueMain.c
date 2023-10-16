#include "LinkQueueSub.h"

int main(int argc, char const *argv[])
{
    POINT *plinkQueue = createLinkQueue();

    int data_in = inLinkQueue(plinkQueue, 999);

    data_in = inLinkQueue(plinkQueue, 888);
    printf("%d\n", data_in);

    int len = acmLinkQueue(plinkQueue);
    printf("len:%d", len);
    
    //清空
    clearLinkQueue(plinkQueue,len);

     len = acmLinkQueue(plinkQueue);
    printf("len:%d", len);

     data_in = inLinkQueue(plinkQueue, 888);

    
     len = acmLinkQueue(plinkQueue);
    printf("len:%d", len);
        printf("gitigitgititi");
            printf("gitigitgititi");
    return 0;
}
