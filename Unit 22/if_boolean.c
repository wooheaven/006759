#include <stdio.h>
#include <stdbool.h>    // bool, true, false�� ���ǵ� ��� ����

int main()
{
    if (true)              // �� true ���
        printf("��\n");    // ���̹Ƿ� ���� ��µ�
    else
        printf("����\n");

    if (false)             // �� false ���
        printf("��\n");
    else
        printf("����\n");  // �����̹Ƿ� ������ ��µ�

    return 0;
}
