#include "SubDoubleLinkList.h"
int main(int argc, char const *argv[])
{
    POINT *p = createDoubleLinkList();
    // for (int i = 0; i < 5; i++)
    // {
    //     int a = inDoubleLinkList(p, i, i+99);
    //     // printf("%d", a);
    // }
    inDoubleLinkList(p, 0, 777);
    inDoubleLinkList(p, 1, 999);
    inDoubleLinkList(p, 2, 888);
    inDoubleLinkList(p, 0, 666);
    printf("查找post%d",searchDataDoubleLinkList(p,666));

    showDoubleLinkList(p);
    return 0;
}
