#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    int *numPtr = malloc(sizeof(int));    // 4����Ʈ��ŭ �޸� �Ҵ�
    char *cPtr;

    *numPtr = 0x12345678;

    cPtr = (char *)numPtr;     // int ������ numPtr�� char �����ͷ� ��ȯ. �޸� �ּҸ� �����

    printf("0x%x\n", *cPtr);   // 0x78: ���� �ڸ��� 1����Ʈ�� �������Ƿ� 0x78

    free(numPtr);    // ���� �޸� ����

    return 0;
}
