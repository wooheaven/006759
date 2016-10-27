#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

struct Data {
    char c1;
    int num1;
};

int main()
{
    struct Data *d1 = malloc(sizeof(struct Data));    // �����Ϳ� ����ü ũ�⸸ŭ �޸� �Ҵ�
    void *ptr;    // void ������ ����

    d1->c1 = 'a';
    d1->num1 = 10;

    ptr = d1;    // void �����Ϳ� d1 �Ҵ�. ������ �ڷ����� �޶� ������ ��� �߻����� ����.

    printf("%c\n", ((struct Data *)ptr)->c1);      // 'a' : ����ü �����ͷ� ��ȯ�Ͽ� ����� ����
    printf("%d\n", ((struct Data *)ptr)->num1);    // 10  : ����ü �����ͷ� ��ȯ�Ͽ� ����� ����

    free(d1);    // ���� �޸� ����

    return 0;
}
