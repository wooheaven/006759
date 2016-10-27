#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    void *ptr = malloc(100);    // 100����Ʈ��ŭ �޸� �Ҵ�

    printf("%p\n", ptr);               // 00FADD20: �޸� �ּ�. ��ǻ�͸���, ������ ������ �޶���
    printf("%p\n", (int *)ptr + 1);    // 00FADD24: �ٸ� �����ͷ� ��ȯ�� �� ������ ����
    printf("%p\n", (int *)ptr - 1);    // 00FADD1C: �ٸ� �����ͷ� ��ȯ�� �� ������ ����

    void *ptr2 = ptr;    // �޸� �ּҸ� ��ȭ��ų ���� �ٸ� �����Ϳ� ����
    printf("%p\n", ++(int *)ptr2);      // 00FADD24: �ٸ� �����ͷ� ��ȯ�� �� ������ ����
    printf("%p\n", --(int *)ptr2);      // 00FADD20: �ٸ� �����ͷ� ��ȯ�� �� ������ ����

    printf("%p\n", ((int *)ptr2)++);    // 00FADD20: �ٸ� �����ͷ� ��ȯ�� �� ������ ����
    printf("%p\n", ((int *)ptr2)--);    // 00FADD24: �ٸ� �����ͷ� ��ȯ�� �� ������ ����

    free(ptr);

    return 0;
}
