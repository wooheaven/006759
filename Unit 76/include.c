#include <stdio.h>
#define KO              // KO ��ũ�� ����
#include "message.h"    // message.h ��� ���� ����

int main()
{
    printf("%s\n", HELLO_MESSAGE);    // �ȳ��ϼ���: message.h�� ������ HELLO_MESSAGE�� ���� ��µ�
                                      // KO ��ũ�ΰ� ���ǵǾ� �����Ƿ� HELLO_MESSAGE�� "�ȳ��ϼ���"�� ��

    return 0;
}
