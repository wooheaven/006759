#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int *ten()    // int �����͸� ��ȯ�ϴ� ten �Լ� ����
{
    int *numPtr = malloc(sizeof(int));    // int ũ�⸸ŭ ���� �޸� �Ҵ�

    *numPtr = 10;    // �������� 10 ����

    return numPtr;   // ������ ��ȯ. malloc���� �޸𸮸� �Ҵ��ϸ� �Լ��� ������ ������� ����
}

int main()
{
    int* numPtr;

    numPtr = ten();    // �Լ��� ȣ���ϰ� ��ȯ���� numPtr�� ����

    printf("%d\n", *numPtr);    // 10: �޸𸮸� �����ϱ� ������ ������

    free(numPtr);    // �ٸ� �Լ����� �Ҵ��� �޸𸮶� �ݵ�� �����ؾ� ��

    return 0;
}
