#include <stdio.h>

int main()
{
    int num1 = 0;

    for (;;)     // ���� ����
    {
        num1++;  // num1�� 1�� ������Ŵ

        printf("%d\n", num1);

        if (num1 == 100)    // num1�� 100�� ��
            break;          // �ݺ����� ����. for�� �����帧�� ���
    }

    return 0;
}
