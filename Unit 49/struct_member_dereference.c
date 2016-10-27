#include <stdio.h>
#include <stdlib.h>

struct Data {
    char c1;
    int *numPtr;    // ������
};

int main()
{
    int num1 = 10;
    struct Data d1;    // ����ü ����
    struct Data *d2 = malloc(sizeof(struct Data));    // ����ü �����Ϳ� �޸� �Ҵ�

    d1.numPtr = &num1;
    d2->numPtr = &num1;

    printf("%d\n", *d1.numPtr);     // 10: ����ü�� ����� ������
    printf("%d\n", *d2->numPtr);    // 10: ����ü �������� ����� ������

    d2->c1 = 'a';
    printf("%c\n", (*d2).c1);      //  a: ����ü �����͸� �������Ͽ� c1�� ����
                                   // d2->c1�� ����
    printf("%d\n", *(*d2).numPtr); // 10: ����ü �����͸� �������Ͽ� numPtr�� ������ �� �ٽ� ������
                                   // *d2->numPtr�� ����

    free(d2);

    return 0;
}
