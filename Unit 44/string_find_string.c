#include <stdio.h>
#include <string.h>    // strstr �Լ��� ����� ��� ����

int main()
{
    char s1[30] = "A Garden Diary";     // ũ�Ⱑ 30�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�

    char *ptr = strstr(s1, "den");      // den���� �����ϴ� ���ڿ� �˻�, ������ ��ȯ

    printf("%s\n", ptr);    // den Diary

    return 0;
}
