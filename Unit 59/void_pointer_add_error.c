#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    void *ptr = malloc(100);    // 100����Ʈ��ŭ �޸� �Ҵ�

    printf("%p\n", ptr);
    printf("%p\n", ptr + 1);    // ������ ����. void �����ʹ� ������ ������ �� �� ����

    free(ptr);

    return 0;
}
