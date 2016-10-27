#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

void allocMemory(void **ptr, int size)    // ��ȯ�� ����, void ���� ������ �Ű����� ����
{
    *ptr = malloc(size);    // void **ptr�� �������Ͽ� void *ptr�� �޸� �Ҵ�
}

int main()
{
    long long *numPtr;

    // ���� ������ long long *numPtr�� �޸� �ּҴ� long long **�� ����, �Ҵ��� ũ�⵵ ����
    allocMemory(&numPtr, sizeof(long long));

    *numPtr = 10;
    printf("%lld\n", *numPtr);

    free(numPtr);    // ���� �޸� ����

    return 0;
}
