#define _CRT_SECURE_NO_WARNINGS    // strtok ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100] = "this is c language";
    char *tokens[30] = { NULL, };    // �ڸ� ���ڿ��� �����͸� ������ �迭, NULL�� �ʱ�ȭ
    int count = 0;   // �ڸ� ���ڿ� ����

    char *ptr = strtok(text, " ");   // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ

    while (ptr != NULL)            // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        tokens[count] = ptr;       // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
        count++;                   // �ε��� ����

        ptr = strtok(NULL, " ");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
    }

    // 2-gram�̹Ƿ� �迭�� ���������� ��� �� �� �ձ����� �ݺ���
    for (int i = 0; i < count - 1; i++)
    {
        printf("%s %s\n", tokens[i], tokens[i + 1]);    // ���� ���ڿ��� �� ���� ���ڿ� ���
    }

    return 0;
}
