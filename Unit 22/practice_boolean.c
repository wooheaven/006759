#include <stdio.h>
/*(1)_____________*/

int main()
{
    bool b1 = true;
    bool b2 = false;

    if (b1 && /*(2)*/)
        printf("��\n");
    else
        printf("����\n");

    printf("%s\n", b2 || /*(3)*/ ? "��" : "����");

    return 0;
}
