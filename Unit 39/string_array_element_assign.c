#include <stdio.h>

int main()
{
    char s1[10] = "Hello";    // ũ�Ⱑ 10�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�
                              // �迭�� ���ڿ��� �����

    s1[0] = 'A';              // ���� �迭�� �ε��� 0�� ���� A�� �Ҵ�

    printf("%s\n", s1);       // Aello: �ٲ� ���ڿ��� ��µ�

    return 0;
}
