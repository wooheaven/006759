#include <stdio.h>
#include <string.h>    // strcmp �Լ��� ����� ��� ����

int main()
{
    char s1[20];
    char s2[20];

    printf("���ڿ� �� ���� �Է��ϼ���: ");
    scanf("%s %s", s1, s2);

    int ret = strcmp(s1, s2);    // �Էµ� ���ڿ� ��
    printf("��ȯ��: %d\n", ret);

    // �������� OS X������ ASCII �ڵ尪�� ���̸� ��ȯ�ϹǷ�
    // if ���ǹ����� �Ǵ�
    if (ret == 0)
    {
        printf("�� ���ڿ��� ����\n");
    }
    else if (ret > 0)    // ����� ��
    {
        printf("%s���� %s�� ŭ\n", s2, s1);
    }
    else if (ret < 0)    // ������ ��
    {
        printf("%s���� %s�� ŭ\n", s1, s2);
    }

    return 0;
}
