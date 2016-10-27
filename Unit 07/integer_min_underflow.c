#include <stdio.h>
#include <limits.h>     // �ڷ����� �ִ񰪰� �ּڰ��� ���ǵ� ��� ����

int main()
{
    char num1 = CHAR_MIN - 1;          // char�� �ּڰ����� ���� ���� �Ҵ�. ����÷ο� �߻�
    short num2 = SHRT_MIN - 1;         // short�� �ּڰ����� ���� ���� �Ҵ�. ����÷ο� �߻�
    int num3 = INT_MIN - 1;            // int�� �ּڰ����� ���� ���� �Ҵ�. ����÷ο� �߻�
    long long num4 = LLONG_MIN - 1;    // long long�� �ּڰ����� ���� ���� �Ҵ�. ����÷ο� �߻�

    // char, short, int�� %d�� ����ϰ� long long�� %lld�� ���
    // ��ȣ �ִ� �������� �ּڰ����� �۾����� �ִ񰪺��� �ٽ� ����
    printf("%d %d %d %lld\n", num1, num2, num3, num4);
    // 127 32767 2147483647 9223372036854775807

    unsigned char num5 = 0 - 1;         // unsigned char�� �ּڰ����� ���� ���� �Ҵ�
                                        // ����÷ο� �߻�

    unsigned short num6 = 0 - 1;        // unsigned short�� �ּڰ����� ���� ���� �Ҵ�
                                        // ����÷ο� �߻�

    unsigned int num7 = 0 - 1;          // unsigned int�� �ּڰ����� ���� ���� �Ҵ�
                                        // ����÷ο� �߻�

    unsigned long long num8 = 0 - 1;    // unsigned long long�� �ּڰ����� ���� ���� �Ҵ�
                                        // ����÷ο� �߻�

    // unsigned char, unsigned short, unsigned int�� %u�� ����ϰ�
    // unsigned long long�� %llu�� ���
    // ��ȣ ���� �������� �ּڰ����� �۾����� �ִ񰪺��� �ٽ� ����
    printf("%u %u %u %llu\n", num5, num6, num7, num8);
    // 255 65535 4294967295 18446744073709551615

    return 0;
}
