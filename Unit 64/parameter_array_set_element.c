#include <stdio.h>

void setElement(int arr[])    // �迭�� �����͸� ����
{
    arr[2] = 300;    // �Ű������� ���� �迭�� ��Ҹ� ����
}

int main()
{
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    setElement(numArr);    // �迭�� �־���

    printf("%d\n", numArr[2]);    // 300: setElement���� ������ ���� ��µ�

    return 0;
}
