#include <stdio.h>
#include <stdbool.h>    // bool, true, false�� ���ǵ� ��� ����

int main()
{
    bool b1 = true;
    bool b2 = false;

    printf(b1 ? "true" : "false");    // b1�� true�̹Ƿ� true�� ��µ�
    printf("\n");
    printf(b2 ? "true" : "false");    // b2�� false�̹Ƿ� false ��µ�
    printf("\n");

    printf("%s\n", b1 ? "true" : "false");    // b1�� true�̹Ƿ� true�� ��µ�
    printf("%s\n", b2 ? "true" : "false");    // b2�� false�̹Ƿ� false ��µ�

    return 0;
}
