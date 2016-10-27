#define _CRT_SECURE_NO_WARNINGS    // fopen, strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <stdint.h>    // ũ�⺰�� ���� �ڷ����� ���ǵ� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <string.h>    // strcpy, strcmp, memset �Լ��� ����� ��� ����

#pragma pack(push, 1)    // ����ü�� 1����Ʈ ũ��� ����

// ��ī�̺� ���Ͽ� ����Ǵ� ����ü
typedef struct _ARCHIVE_HEADER {    // ��ī�̺� ��� ����ü ����
    uint16_t magic;                     // ��ī�̺� ���� ���� �ѹ�
    uint16_t version;                   // ��ī�̺� ���� ����
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

// ��ī�̺� ���Ͽ� ����Ǵ� ����ü
typedef struct _FILE_DESC {         // ���� ���� ����ü ����
    char     name[256];                 // ���� �̸�
    uint32_t size;                      // ���� ũ��
    uint32_t dataOffset;                // ���� �������� ��ġ
} FILE_DESC, *PFILE_DESC;

#pragma pack(pop)

// ���α׷������� ����ϴ� ����ü
typedef struct _FILE_NODE {         // ���� ��� ���� ����Ʈ ����ü ����
    struct _FILE_NODE *next;            // ���� ����� �ּҸ� ������ ������
    FILE_DESC desc;                     // ���� ����
} FILE_NODE, *PFILE_NODE;

// ���α׷������� ����ϴ� ����ü
typedef struct _ARCHIVE {           // ��ī�̺� ���� ����ü
    ARCHIVE_HEADER header;              // ��ī�̺� ���
    FILE *fp;                           // ��ī�̺� ���� ������
    FILE_NODE fileList;                 // ���� ��� ���� ����Ʈ�� �Ӹ� ���
} ARCHIVE, *PARCHIVE;

#define ARCHIVE_NAME "archive.bin"   // ��ī�̺� ���� �̸�

uint32_t getFileSize(FILE *fp)    // ������ ũ�⸦ ���ϴ� �Լ� ����
{
    uint32_t size;
    uint32_t currPos = ftell(fp);    // ���� ���� �������� ��ġ ����

    // ������ ������ �̵��Ͽ� ���� ũ�⸦ ����
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    fseek(fp, currPos, SEEK_SET);    // ���� �����͸� ���� ��ġ�� �ǵ���

    return size;
}

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

    // ��ī�̺� ��� �ٷ� �������� ���� �����͸� �̵���Ŵ
    fseek(archive->fp, sizeof(ARCHIVE_HEADER), SEEK_SET);

    // ���� �������� ���� ��ġ�� ���� ���� �������� ��ġ�� 
    // ���� ���� ũ�⸸ŭ ���������� �̵���Ų ��
    desc->dataOffset = ftell(archive->fp) + sizeof(FILE_DESC);

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

int main()
{
    PARCHIVE archive = malloc(sizeof(ARCHIVE));
    memset(archive, 0, sizeof(ARCHIVE));

    PFILE_NODE curr;

    FILE *fp = fopen(ARCHIVE_NAME, "r+b");    // ��ī�̺� ������ �б�/���� ���� ����
    if (fp == NULL)                           // ��ī�̺� ������ ������
    {
        fp = fopen(ARCHIVE_NAME, "w+b");      // ��ī�̺� ������ ����
        if (fp == NULL)                       // ���� ����(����)�� �����ϸ�
            return 0;                         // ���α׷� ����

        // �� ��ī�̺� ��� ����
        archive->header.magic = 'AF';         // ���� �ѹ� AF ����(��Ʋ ����𿡼��� FA�� �����)
        archive->header.version = 1;          // ���� ���� 1 ����

        // ��ī�̺� ���Ͽ� ��ī�̺� ��� ����
        if (fwrite(&archive->header, sizeof(ARCHIVE_HEADER), 1, fp) < 1)
        {
            printf("��ī�̺� ��� ���� ����\n");
            fclose(fp);
            return 0;
        }
    }
    else    // ��ī�̺� ������ ������
    {
        // ��ī�̺� ���Ͽ��� ��ī�̺� ��� �б�
        if (fread(&archive->header, sizeof(ARCHIVE_HEADER), 1, fp) < 1)
        {
            printf("��ī�̺� ��� �б� ����\n");
            fclose(fp);
            return 0;
        }
    }

    // ��ī�̺� ���� ���� �ѹ� �˻�
    if (archive->header.magic != 'AF')
    {
        printf("��ī�̺� ������ �ƴմϴ�.\n");
        fclose(fp);
        return 0;
    }

    // ��ī�̺� ���� ���� �˻�
    if (archive->header.version != 1)
    {
        printf("������ ���� �ʽ��ϴ�.\n");
        fclose(fp);
        return 0;
    }

    archive->fp = fp;    // ��ī�̺� ���� ������ ����

    int ret = 0;
    uint32_t size = getFileSize(fp);    // ��ī�̺� ������ ũ�⸦ ����
    uint32_t currPos = ftell(fp);       // ���� ���� �������� ��ġ�� ����

    while (size > currPos)         // ���� �������� ��ġ�� ���� ũ�⺸�� ���� �� �ݺ�
    {
        PFILE_NODE node = malloc(sizeof(FILE_NODE));
        memset(node, 0, sizeof(FILE_NODE));

        // ���� ���� �б�
        if (fread(&node->desc, sizeof(FILE_DESC), 1, fp) < 1)
        {
            printf("��ī�̺� ���� �б� ����\n");
            free(node);       // ���� �޸� ����
            ret = -1;         // -1�� ����
            goto FINALIZE;    // ��� ���� �޸� ���� �ڵ�� �̵�
        }

        // ���� ����Ʈ�� ���� ���� ���(FILE_NODE) �߰�
        node->next = archive->fileList.next;
        archive->fileList.next = node;

        // ���� ���� �������� ��ġ�� ���� ũ�⸦ ���Ͽ� ���� ���� ���� ��ġ�� �̵�
        currPos = ftell(fp) + node->desc.size;
        fseek(fp, currPos, SEEK_SET);
    }

    extract(archive, "hello.txt");    // hello.txt ���� ����

FINALIZE:
    // ���� ��� ���� ����Ʈ�� ��ȸ�ϸ鼭 �޸� ����
    curr = archive->fileList.next;    // ù ��° ���
    while (curr != NULL)
    {
        PFILE_NODE next = curr->next;
        free(curr);

        curr = next;
    }

    fclose(archive->fp);    // ��ī�̺� ���� ������ �ݱ�

    free(archive);    // ��ī�̺� ���� ����ü ����

    return ret;       // �����̳� ���гĿ� ���� 0 �Ǵ� -1�� ��ȯ
}
