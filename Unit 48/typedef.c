#include <stdio.h>

int main()
{
    typedef int MYINT;      // int�� ��Ī MYINT�� ����
    typedef int* PMYINT;    // int �����͸� ��Ī PMYINT�� ����

    MYINT num1;        // MYINT�� ���� ����
    PMYINT numPtr1;    // PMYINT�� ������ ���� ����

    numPtr1 = &num1;   // �����Ϳ� ������ �ּ� ����
                       // ��� ����� �Ϲ� ����, �����Ϳ� ����

    return 0;
}
