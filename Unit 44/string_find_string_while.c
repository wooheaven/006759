#include <stdio.h>
#include <string.h> // strstr �Լ��� ����� ��� ����

int main()
{
    char s1[100] = "A Garden Diary A Garden Diary A Garden Diary";

    char *ptr = strstr(s1, "den");     // den���� �����ϴ� ���ڿ� �˻�, ������ ��ȯ

    while (ptr != NULL)                // �˻��� ���ڿ��� ���� ������ �ݺ�
    {
        printf("%s\n", ptr);           // �˻��� ���ڿ� ���
        ptr = strstr(ptr + 1, "den");  // den �����Ϳ� 1�� ���Ͽ� e���� �˻�
    }

    return 0;
}
