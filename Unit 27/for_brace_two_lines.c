#include <stdio.h>

int main()
{
    for (int i = 0; i < 100; i++)
        printf("Hello, world!\n");    // �ݺ��� �ڵ尡 �� ���̶�� �߰�ȣ ����

    for (int i = 0; i < 100; i++)
    {    // �ݺ��� �ڵ尡 �� �� �̻��̶�� �߰�ȣ�� ������
        printf("for �ݺ���\n");
        printf("Hello, world!\n");
    }

    return 0;
}
