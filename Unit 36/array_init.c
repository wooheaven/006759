#include <stdio.h>

int main()
{
    int numArr[10] = { 0, };      // �迭�� ��Ҹ� ��� 0���� �ʱ�ȭ

    printf("%d\n", numArr[0]);    // 0: �迭�� ù ��°(�ε��� 0) ��� ���
    printf("%d\n", numArr[5]);    // 0: �迭�� ���� ��°(�ε��� 5) ��� ���
    printf("%d\n", numArr[9]);    // 0: �迭�� �� ��°(�ε��� 9) ��� ���

    return 0;
}
