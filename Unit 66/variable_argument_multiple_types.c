#include <stdio.h>
#include <stdarg.h>

void printValues(char *types, ...)    // ���� ������ �ڷ����� ����, ...�� ���� ���� ����
{
    va_list ap;    // ���� ���� ���
    int i = 0;

    va_start(ap, types);        // types ���ڿ����� ���� ������ ���ؼ� ���� ���� ������ ����
    while (types[i] != '\0')    // ���� ���� �ڷ����� ���� ������ �ݺ�
    {
        switch (types[i])    // ���� ���� �ڷ������� �б�
        {
        case 'i':                                // int���� ��
            printf("%d ", va_arg(ap, int));      // int ũ�⸸ŭ ���� ������
                                                 // ap�� int ũ�⸸ŭ ���������� �̵�
            break;
        case 'd':                                // double���� ��
            printf("%f ", va_arg(ap, double));   // double ũ�⸸ŭ ���� ������
                                                 // ap�� double ũ�⸸ŭ ���������� �̵�
            break;
        case 'c':                                // char�� ������ ��
            printf("%c ", va_arg(ap, char));     // char ũ�⸸ŭ ���� ������
                                                 // ap�� char ũ�⸸ŭ ���������� �̵�
            break;
        case 's':                                // char *�� ���ڿ��� ��
            printf("%s ", va_arg(ap, char *));   // char * ũ�⸸ŭ ���� ������
                                                 // ap�� char * ũ�⸸ŭ ���������� �̵�
            break;
        default:
            break;
        }
        i++;
    }
    va_end(ap);    // ���� ���� �����͸� NULL�� �ʱ�ȭ

    printf("\n");    // �ٹٲ�
}

int main()
{
    printValues("i", 10);                                       // ����
    printValues("ci", 'a', 10);                                 // ����, ����
    printValues("dci", 1.234567, 'a', 10);                      // �Ǽ�, ����, ����
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // ���ڿ�, ����, ����, �Ǽ�

    return 0;
}
