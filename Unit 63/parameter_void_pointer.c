#include <stdio.h>

enum TYPE {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT
};

void swapValue(void *ptr1, void *ptr2, enum TYPE t)    // ��ȯ�� ����, void ������ �Ű����� �� ����
{                                                      // ������ �ڷ����� �˷��� �������� ����
    switch (t)
    {
    case TYPE_CHAR:    // ���ڸ� char *�� ��ȯ�� �� �������Ͽ� ���� ���� �ٲ�
    {
        char temp;
        temp = *(char *)ptr1;
        *(char *)ptr1 = *(char *)ptr2;
        *(char *)ptr2 = temp;
        break;
    }
    case TYPE_INT:     // ������ int *�� ��ȯ�� �� �������Ͽ� ���� ���� �ٲ�
    {
        int temp;
        temp = *(int *)ptr1;
        *(int *)ptr1 = *(int *)ptr2;
        *(int *)ptr2 = temp;
        break;
    }
    case TYPE_FLOAT:   // �Ǽ��� float *�� ��ȯ�� �� �������Ͽ� ���� ���� �ٲ�
    {
        float temp;
        temp = *(float *)ptr1;
        *(float *)ptr1 = *(float *)ptr2;
        *(float *)ptr2 = temp;
        break;
    }
    }
}

int main()
{
    char c1 = 'a';
    char c2 = 'b';
    swapValue(&c1, &c2, TYPE_CHAR);       // ������ �޸� �ּҿ� TYPE_CHAR�� ����
    printf("%c %c\n", c1, c2);            // b a: swapValue�� ���ؼ� ���� ���� �ٲ�

    int num1 = 10;
    int num2 = 20;
    swapValue(&num1, &num2, TYPE_INT);    // ������ �޸� �ּҿ� TYPE_INT�� ����
    printf("%d %d\n", num1, num2);        // 20 10: swapValue�� ���ؼ� ���� ���� �ٲ�

    float num3 = 1.234567f;
    float num4 = 7.654321f;
    swapValue(&num3, &num4, TYPE_FLOAT);  // ������ �޸� �ּҿ� TYPE_FLOAT�� ����
    printf("%f %f\n", num3, num4);        // 7.654321f 1.234567: 
                                          // swapValue�� ���ؼ� ���� ���� �ٲ�

    return 0;
}
