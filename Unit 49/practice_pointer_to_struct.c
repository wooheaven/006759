#include <stdio.h>
#include <stdbool.h>

struct Item {
    char name[100];
    int price;
    bool limited;
};

int main()
{
    struct Item item1 = { "������ ���ϸ�� ���亥 ����� ����", 100000, false };
    /*(1)__________*/

    /*(2)__________*/

    ptr->limited = true;

    if (ptr->limited == true)
        printf("������\n");
    else
        printf("�Ϲ���\n");

    return 0;
}
