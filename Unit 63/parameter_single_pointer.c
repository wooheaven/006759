#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

void allocMemory(void *ptr, int size)    // ��ȯ�� ����, void ������ �Ű����� ����
{
    ptr = malloc(size);    // ptr�� allocMemory�� ����� ����� �� ����
}

int main()
{
    long long *numPtr = NULL;

    // numPtr�� �Ҵ��� ũ�⸦ �־��� 
    allocMemory(numPtr, sizeof(long long));

    *numPtr = 10;    // �޸𸮰� �Ҵ���� �ʾ����Ƿ� ���� ����
    printf("%lld\n", *numPtr);

    free(numPtr);

    return 0;
}
