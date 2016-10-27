#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    short *numPtr1 = malloc(sizeof(short));    // 2����Ʈ��ŭ �޸� �Ҵ�
    int *numPtr2;

    *numPtr1 = 0x1234;

    numPtr2 = (int *)numPtr1;    // short ������ numPtr1�� int �����ͷ� ��ȯ. �޸� �ּҸ� �����

    printf("0x%x\n", *numPtr2);    // 0xfdfd1234: ���� �޸𸮸� ħ���Ͽ� ���� ������
                                   // 0xfdfd�� ��Ȳ�� ���� ���� �޶��� �� ����

    free(numPtr1);    // ���� �޸� ����

    return 0;
}
