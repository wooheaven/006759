#include <stdio.h>

#define COUNT 10    // 10�� COUNT�� ����

int main()
{
    printf("%d\n", COUNT);    // 10

#undef COUNT        // �տ��� ������ COUNT ����
#define COUNT 20    // 20�� COUNT�� ����

    printf("%d\n", COUNT);   // 20: #undef�� COUNT�� ������ �� 20�� COUNT�� ���������Ƿ� 20�� ��µ�

    return 0;
}
