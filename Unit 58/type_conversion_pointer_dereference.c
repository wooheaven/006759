#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    int *numPtr = malloc(sizeof(int));    // 4����Ʈ��ŭ �޸� �Ҵ�
    char *cPtr;

    *numPtr = 0x12345678;

    printf("0x%x\n", *(char *)numPtr);    // 0x78: numPtr1�� char �����ͷ� ��ȯ�� �� ������

    free(numPtr);    // ���� �޸� ����

    return 0;
}
