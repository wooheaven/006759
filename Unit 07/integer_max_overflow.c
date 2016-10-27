#include <stdio.h>
#include <limits.h>    // �ڷ����� �ִ񰪰� �ּڰ��� ���ǵ� ��� ����

int main()
{
    char num1 = CHAR_MAX + 1;          // char�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�
    short num2 = SHRT_MAX + 1;         // short�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�
    int num3 = INT_MAX + 1;            // int�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�
    long long num4 = LLONG_MAX + 1;    // long long�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�

    // char, short, int�� %d�� ����ϰ� long long�� %lld�� ���
    // ��ȣ �ִ� �������� ������ �� �ִ� ������ �Ѿ�� �ּڰ����� �ٽ� ����
    printf("%d %d %d %lld\n", num1, num2, num3, num4);
    // -128 -32768 -2147483648 -9223372036854775808

    unsigned char num5 = UCHAR_MAX + 1;          // unsigned char�� �ִ񰪺��� ū ���� �Ҵ�
                                                 // �����÷ο� �߻�

    unsigned short num6 = USHRT_MAX + 1;         // unsigned short�� �ִ񰪺��� ū ���� �Ҵ�
                                                 // �����÷ο� �߻�

    unsigned int num7 = UINT_MAX + 1;            // unsigned int�� �ִ񰪺��� ū ���� �Ҵ�
                                                 // �����÷ο� �߻�

    unsigned long long num8 = ULLONG_MAX + 1;    // unsigned long long�� �ִ񰪺��� ū ���� �Ҵ�
                                                 // �����÷ο� �߻�

    // unsigned char, unsigned short, unsigned int�� %u�� ����ϰ�
    // unsigned long long�� %llu�� ���
    // ��ȣ ���� �������� ������ �� �ִ� ������ �Ѿ�� �ּڰ� 0���� �ٽ� ����
    printf("%u %u %u %llu\n", num5, num6, num7, num8); // 0 0 0 0

    return 0;
}
