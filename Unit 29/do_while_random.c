#include <stdio.h>
#include <stdlib.h>    // srand, rand �Լ��� ����� ��� ����
#include <time.h>      // time �Լ��� ����� ��� ����

int main()
{
    srand(time(NULL));    // ���� �ð������� �õ� ����

    int i = 0;
    do
    {
        i = rand() % 10;    // rand �Լ��� ����Ͽ� �������� ������ ������ �� 10 �̸��� ���ڷ� ����
        printf("%d\n", i);
    } while (i != 3);       // 3�� �ƴ� �� ��� �ݺ�

    return 0;
}
