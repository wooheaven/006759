#include <stdio.h>

struct Data {
    int num1;
    int num2;
};

int main()
{
    struct Data d[3] = { { 10, 20 }, { 30, 40 }, { 50, 60 } };    // ����ü �迭 ����� �� �ʱ�ȭ
    struct Data *ptr;    // ����ü ������ ����

    ptr = d;    // ����ü �迭 ù ��° ����� �޸� �ּҸ� �����Ϳ� ����

    printf("%d %d\n", (ptr + 1)->num1, (ptr + 1)->num2);    // 30 40: ����ü �迭���� ����� �� ���
                                                            // d[1]->num1, d[1]->num2�� ����

    printf("%d %d\n", (ptr + 2)->num1, (ptr + 2)->num2);    // 50 60: ����ü �迭���� ����� �� ���
                                                            // d[2]->num1, d[2]->num2�� ����

    return 0;
}
