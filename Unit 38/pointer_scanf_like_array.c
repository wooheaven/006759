#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    int size;

    scanf("%d", &size);

    int *numPtr = malloc(sizeof(int) * size);    // (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�

    for (int i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
    {
        numPtr[i] = i;                // �ε����� �����Ͽ� �� �Ҵ�
    }

    for (int i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
    {
        printf("%d\n", numPtr[i]);    // �ε����� �����Ͽ� �� ���
    }

    free(numPtr);    // �������� �Ҵ��� �޸� ����

    return 0;
}
