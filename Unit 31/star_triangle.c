#include <stdio.h>

int main()
{
    for (int i = 0; i < 3; i++)    // 3�� �ݺ�. ���� ����
    {
        for (int j = 0; j < 7; j++)    // 7�� �ݺ�. ���� ����
        {
            printf("*");               // �� ���
        }
        printf("\n");              // ���� �������� ���� �� �׸� �� ���� �ٷ� �Ѿ
    }

    return 0;
}
