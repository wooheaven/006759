#include <stdio.h>
#include <string.h>   // strrchr �Լ��� ����� ��� ����

int main()
{
    char s1[30] = "A Garden Diary";    // ũ�Ⱑ 30�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�

    char *ptr = strrchr(s1, 'a');      // ���ڿ� ���������� 'a'�� �����ϴ� ���ڿ� �˻�. ������ ��ȯ

    printf("%s\n", ptr);   // ary

    return 0;
}
