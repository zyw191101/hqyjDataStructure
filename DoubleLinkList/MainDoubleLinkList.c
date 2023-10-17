#include "SubDoubleLinkList.h"
int main(int argc, char const *argv[])
{
    POINT *p = createDoubleLinkList();
    for (int i = 0; i < 5; i++)
    {
        int a = inDoubleLinkList(p, i, i);
        // printf("%d", a);
    }
    inDoubleLinkList(p, 1, 999);
    inDoubleLinkList(p, 2, 888);

    return 0;
}
