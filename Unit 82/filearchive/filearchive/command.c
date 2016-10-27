#define _CRT_SECURE_NO_WARNINGS    // fopen, strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <stdint.h>    // ũ�⺰�� ���� �ڷ����� ���ǵ� ��� ����
#include <string.h>    // strcpy, strcmp, memset �Լ��� ����� ��� ����
#include "archive.h"
#include "file.h"

int append(PARCHIVE archive, char *filename)    // ���� �߰� �Լ� ����
{
    int ret = 0;    // �Լ��� �����ߴ��� �����ߴ��� ��ȯ������ ǥ��

    // �߰��� ���� ����
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("%s ������ �����ϴ�.\n", filename);
        return -1;    // �Լ� ����. -1�� ����
    }

    uint8_t *buffer;
    uint32_t size;

    size = getFileSize(fp);    // �߰��� ������ ũ�⸦ ����
    buffer = malloc(size);

    // �߰��� ������ ������ ����
    if (fread(buffer, size, 1, fp) < 1)
    {
        printf("%s ���� �б� ����\n", filename);
        ret = -1;       // -1�� ����
        goto Error1;    // fp�� �ݰ� buffer�� �����ϴ� ���� ó���� �̵�
    }

    // �� ���� ���� ����
    PFILE_DESC desc = malloc(sizeof(FILE_DESC));
    memset(desc, 0, sizeof(FILE_DESC));
    strcpy(desc->name, filename);    // ���� ���� ����ü�� �߰��� ������ �̸� ����
    desc->size = size;               // ���� ���� ����ü�� �߰��� ������ ũ�� ����

    PFILE_NODE node = archive->fileList.next;    // ù ��° ���
    if (node == NULL)    // ��ī�̺� ���Ͽ� ������ �ϳ��� ������
    {
        // ��ī�̺� ��� �ٷ� �������� ���� �����͸� �̵���Ŵ
        fseek(archive->fp, sizeof(ARCHIVE_HEADER), SEEK_SET);

        // ���� �߰��� ���� �������� ���� ��ġ��
        // ���� ���� �������� ��ġ�� ���� ���� ũ�⸸ŭ ���������� �̵���Ų ��
        desc->dataOffset = ftell(archive->fp) + sizeof(FILE_DESC);
    }
    else    // ���� ����Ʈ���� ù ��° ��尡 ���� �������� �߰��� ����
    {
        // �������� �߰��� ������ ���� ������ ��ġ���� ���� ũ�⸸ŭ ���������� �̵�
        fseek(archive->fp, node->desc.dataOffset + node->desc.size, SEEK_SET);

        // ���� �߰��� ���� �������� ���� ��ġ�� 
        // �������� �߰��� ������ ���� ������ ��ġ���� 
        // ���� ũ��, ���� ���� ũ�⸸ŭ ���������� �̵���Ų ��
        desc->dataOffset = node->desc.dataOffset + node->desc.size + sizeof(FILE_DESC);
    }

    // ��ī�̺� ���Ͽ� �� ���� ���� ����
    if (fwrite(desc, sizeof(FILE_DESC), 1, archive->fp) < 1)
    {
        printf("���� ���� ���� ����\n");
        ret = -1;
        goto Error2;    // fp�� �ݰ�, desc�� buffer�� �����ϴ� ���� ó���� �̵�
    }

    // ��ī�̺� ���Ͽ� �� ���� ������ ����
    if (fwrite(buffer, size, 1, archive->fp) < 1)
    {
        printf("���� ������ ���� ����\n");
        ret = -1;
        goto Error2;    // fp�� �ݰ�, desc�� buffer�� �����ϴ� ���� ó���� �̵�
    }

    printf("%s ���� �߰� ����\nũ��: %d\n", filename, size);

Error2:
    free(desc);      // ���� ���� ����� ���� �޸� ����

Error1:
    free(buffer);    // ���� ���� ����� ���� �޸� ����

    fclose(fp);      // ���� ������ �ݱ�

    return ret;      // �����̳� ���гĿ� ���� 0 �Ǵ� -1�� ��ȯ
}

void list(PARCHIVE archive)    // ���� ��� ��� �Լ� ����
{
    printf("���� ���:\n");

    // ���� ��� ���� ����Ʈ�� ��ȸ�ϸ鼭 ���� �̸� ���
    PFILE_NODE curr = archive->fileList.next;    // ù ��° ���
    while (curr != NULL)
    {
        printf("    %s\n", curr->desc.name);

        curr = curr->next;
    }
}

int extract(PARCHIVE archive, char *filename)    // ���� ���� �Լ� ����
{
    // ���� ��� ���� ����Ʈ�� ��ȸ
    PFILE_NODE curr = archive->fileList.next;    // ù ��° ���
    while (curr != NULL)
    {
        // ������ ������ �ִ��� �˻�
        if (strcmp(curr->desc.name, filename) == 0)
        {
            int ret = 0;
            uint32_t size = curr->desc.size;
            uint8_t *buffer = malloc(size);

            // ���� �����Ͱ� �ִ� ������ ���� �����͸� �̵���Ŵ
            fseek(archive->fp, curr->desc.dataOffset, SEEK_SET);

            // ���� ������ �б�
            if (fread(buffer, size, 1, archive->fp) < 1)
            {
                printf("��ī�̺� ���� �б� ����\n");
                ret = -1;       // -1�� ����
                goto Error1;    // buffer�� �����ϴ� ���� ó���� �̵�
            }

            // ������ ������ ������ �� ���� ����
            FILE *fp = fopen(filename, "wb");
            if (fp == NULL)
            {
                printf("%s ���� ���� ����\n", filename);
                ret = -1;
                goto Error1;    // buffer�� �����ϴ� ���� ó���� �̵�
            }

            // ���� ������ ���Ͽ� ���� ������ ����
            if (fwrite(buffer, size, 1, fp) < 1)
            {
                printf("%s ���� ���� ����\n", filename);
                ret = -1;
                goto Error2;    // fp�� �ݰ�, buffer�� �����ϴ� ���� ó���� �̵�
            }

            printf("%s ���� ���� ����\nũ��: %d\n", filename, size);

        Error2:
            fclose(fp);    // ���� ������ �ݱ�

        Error1:
            free(buffer);    // ���� �޸� ����

            return ret;      // �����̳� ���гĿ� ���� 0 �Ǵ� -1�� ��ȯ
        }

        curr = curr->next;
    }

    return -1;
}
