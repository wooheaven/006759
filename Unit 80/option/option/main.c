#include <stdio.h>

int main(int argc, char *argv[])      // �ɼ��� ������ �ɼ� ���ڿ��� �迭�� ����
{
    for (int i = 0; i < argc; i++)    // �ɼ��� ������ŭ �ݺ�
    {
        printf("%s\n", argv[i]);      // �ɼ� ���ڿ� ���
    }

    return 0;
}
