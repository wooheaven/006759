#include <stdio.h>

int main()
{
    for (int i = 1; i <= 100; i++)    // 1���� 100���� 100�� �ݺ�
    {
        if (i % 3 == 0)               // 3�� ����� ��
            printf("Fizz\n");         // Fizz ���
        else if (i % 5 == 0)          // 5�� ����� ��
            printf("Buzz\n");         // Buzz ���
        else
            printf("%d\n", i);        // �ƹ��͵� �ش���� ���� �� ���� ���
    }

    return 0;
}
