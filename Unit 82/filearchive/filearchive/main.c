#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <string.h>    // strcmp �Լ��� ����� ��� ����
#include "archive.h"
#include "command.h"

int main(int argc, char *argv[])
{
    // ���� ���Ͽ� ������ �ɼ��� ���� �� ���α׷� ��� ��� ���
    if (argc == 1)
    {
        printf("filearchive <���> <���ϸ�>\n\n");
        printf("���:\n");
        printf("    append   ���� �߰�\n");
        printf("    list     ���� ��� ���\n");
        printf("    extract  ���� ����\n");
        return 0;
    }

    // �ʱ�ȭ
    PARCHIVE archive = initialize();
    if (archive == NULL)
        return -1;

    char *command = argv[1];
    char *filename = argv[2];

    if (strcmp(command, "append") == 0)        // ���� �߰� ���
    {
        if (!isExist(archive, filename))       // ��ī�̺� ���Ͽ� �߰��� ������ �ִ��� �˻�
        {
            // ������ �ߺ����� ������ �� ���� �߰�
            if (append(archive, filename) == -1)
            {
                printf("%s ���� �߰� ����\n", filename);
            }
        }
        else
        {
            printf("�̹� %s ������ �߰��Ǿ� �ֽ��ϴ�.\n", filename);
        }
    }
    else if (strcmp(command, "list") == 0)      // ���� ��� ��� ���
    {
        list(archive);
    }
    else if (strcmp(command, "extract") == 0)   // ���� ���� ���
    {
        if (isExist(archive, filename))         // ��ī�̺� ���Ͽ� ������ ������ �ִ��� �˻�
        {
            // ��ī�̺� ���Ͽ� ������ ������ ���� ����
            if (extract(archive, filename) == -1)
            {
                printf("%s ���� ���� ����\n", filename);
            }
        }
        else
        {
            printf("%s ������ �����ϴ�.\n", filename);
        }
    }

    finalize(archive);    // ���� ������ �ݱ�, ��� ���� �޸� ����

    return 0;
}
