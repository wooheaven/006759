#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

typedef struct _Data {
    char c1;
    int num1;
} Data, *PData;    // ����ü ��Ī, ����ü ������ ��Ī ����

int main()
{
    PData d1 = malloc(sizeof(Data));    // ����ü ������ ��Ī���� ������ ����
    void *ptr;   // void ������ ����

    d1->c1 = 'a';
    d1->num1 = 10;

    ptr = d1;    // void �����Ϳ� d1 �Ҵ�. ������ �ڷ����� �޶� ������ ��� �߻����� ����.

    printf("%c\n", ((Data *)ptr)->c1);     // 'a' : ����ü ��Ī�� �����ͷ� ��ȯ
    printf("%d\n", ((PData)ptr)->num1);    // 10  : ����ü ������ ��Ī���� ��ȯ

    free(d1);    // ���� �޸� ����

    return 0;
}
