#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

struct Phone;    // Phone ����ü ���� ����

struct Person {
    char name[20];
    int age;
    struct Phone *phone;    // ���� ���ǵ��� ���� ����ü�� �����ͷ� ����
};

struct Phone {    // Phone ����ü ����
    int areacode;
    unsigned long long number;
};

int main()
{
    struct Person *p1 = malloc(sizeof(struct Person));    // �ٱ� ����ü�� �����Ϳ� �޸� �Ҵ�
    p1->phone = malloc(sizeof(struct Phone));             // ��� �����Ϳ� �޸� �Ҵ�

    p1->phone->areacode = 82;          // ������->������->��� ������ �����Ͽ� �� �Ҵ�
    p1->phone->number = 3045671234;    // ������->������->��� ������ �����Ͽ� �� �Ҵ�

    printf("%d %llu\n", p1->phone->areacode, p1->phone->number);    // 82 3045671234

    free(p1->phone);    // ����ü ����� �޸𸮸� ���� ����
    free(p1);           // ����ü �޸� ����

    return 0;
}
