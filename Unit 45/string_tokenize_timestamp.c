#define _CRT_SECURE_NO_WARNINGS    // strtok ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strtok �Լ��� ����� ��� ����

int main()
{
    char s1[30] = "2015-06-10T15:32:19";    // ũ�Ⱑ 30�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�

    char *ptr = strtok(s1, "-T:");    // -, T, �ݷ��� �������� ���ڿ��� �ڸ�
                                      // ������ ��ȯ

    while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        printf("%s\n", ptr);          // �ڸ� ���ڿ� ���
        ptr = strtok(NULL, "-T:");    // ���� ���ڿ��� �߶� �����͸� ��ȯ
    }

    return 0;
}
