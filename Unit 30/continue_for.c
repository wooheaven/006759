#include <stdio.h>

int main()
{
    for (int i = 1; i <= 100; i++)    // 1���� 100���� �����ϸ鼭 100�� �ݺ�
    {
        if (i % 2 != 0)               // i�� 2�� �������� �� �������� 0�� �ƴϸ� Ȧ��
            continue;                 // �Ʒ� �ڵ带 �������� �ʰ� �ǳʶ�

        printf("%d\n", i);
    }

    return 0;
}
