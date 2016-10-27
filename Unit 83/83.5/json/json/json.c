#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free, atof �Լ��� ����� ��� ����
#include <stdbool.h>   // bool, true, false�� ���ǵ� ��� ����
#include <string.h>    // strchr, memset, memcpy �Լ��� ����� ��� ����

// ��ū ���� ������
typedef enum _TOKEN_TYPE {
    TOKEN_STRING,    // ���ڿ� ��ū
    TOKEN_NUMBER,    // ���� ��ū
} TOKEN_TYPE;

// ��ū ����ü
typedef struct _TOKEN {
    TOKEN_TYPE type;   // ��ū ����
    union {            // �� ���� �� �� ������ ������ ���̹Ƿ� ����ü�� ����
        char *string;     // ���ڿ� ������
        double number;    // �Ǽ��� ����
    };
    bool isArray;      // ���� ��ū�� �迭���� ǥ��
} TOKEN;

#define TOKEN_COUNT 20    // ��ū�� �ִ� ����

// JSON ����ü
typedef struct _JSON {
    TOKEN tokens[TOKEN_COUNT]; // ��ū �迭
} JSON;

char *readFile(char *filename, int *readSize)    // ������ �о ������ ��ȯ�ϴ� �Լ�
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
        return NULL;

    int size;
    char *buffer;

    // ���� ũ�� ���ϱ�
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // ���� ũ�� + NULL ������ŭ �޸𸮸� �Ҵ��ϰ� 0���� �ʱ�ȭ
    buffer = malloc(size + 1);
    memset(buffer, 0, size);

    // ���� ���� �б�
    if (fread(buffer, size, 1, fp) < 1)
    {
        *readSize = 0;
        free(buffer);
        fclose(fp);        
        return NULL;
    }

    // ���� ũ�⸦ �Ѱ���
    *readSize = size;

    fclose(fp);    // ���� ������ �ݱ�

    return buffer;
}

void parseJSON(char *doc, int size, JSON *json)    // JSON �Ľ� �Լ�
{
    int tokenIndex = 0;    // ��ū �ε���
    int pos = 0;           // ���� �˻� ��ġ�� �����ϴ� ����

    if (doc[pos] != '{')   // ������ ������ {���� �˻�
        return;

    pos++;    // ���� ���ڷ�

    while (pos < size)       // ���� ũ�⸸ŭ �ݺ�
    {
        switch (doc[pos])    // ������ ������ ���� �б�
        {
        case '"':            // ���ڰ� "�̸� ���ڿ�
        {
            // ���ڿ��� ���� ��ġ�� ����. �� ���� "�� �����ϱ� ���� + 1
            char *begin = doc + pos + 1;

            // ���ڿ��� �� ��ġ�� ����. ���� "�� ��ġ
            char *end = strchr(begin, '"');
            if (end == NULL) // "�� ������ �߸��� �����̹Ƿ� 
                break;       // �ݺ��� ����

            int stringLength = end - begin;    // ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ

            // ��ū �迭�� ���ڿ� ����
            // ��ū ������ ���ڿ�
            json->tokens[tokenIndex].type = TOKEN_STRING;
            // ���ڿ� ���� + NULL ������ŭ �޸� �Ҵ�
            json->tokens[tokenIndex].string = malloc(stringLength + 1);
            // �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
            memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

            // �������� ���ڿ��� ��ū�� ����
            // ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
            memcpy(json->tokens[tokenIndex].string, begin, stringLength);

            tokenIndex++;    // ��ū �ε��� ����

            pos = pos + stringLength + 1;    // ���� ��ġ + ���ڿ� ���� + "(+ 1)
        }
        break;
        case '[':            // ���ڰ� [�̸� �迭
        {
            pos++;           // ���� ���ڷ�

            while (doc[pos] != ']')    // �ݴ� ]�� ������ �ݺ� ����
            {
                // ���⼭�� ���ڿ��� ó��
                if (doc[pos] == '"')   // ���ڰ� "�̸� ���ڿ�
                {
                    // ���ڿ��� ���� ��ġ�� ����. �� ���� "�� �����ϱ� ���� + 1
                    char *begin = doc + pos + 1;

                    // ���ڿ��� �� ��ġ�� ����. ���� "�� ��ġ
                    char *end = strchr(begin, '"');
                    if (end == NULL)   // "�� ������ �߸��� �����̹Ƿ�
                        break;         // �ݺ��� ����

                    int stringLength = end - begin;    // ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ

                    // ��ū �迭�� ���ڿ� ����
                    // ��ū ������ ���ڿ�
                    json->tokens[tokenIndex].type = TOKEN_STRING;
                    // ���ڿ� ���� + NULL ������ŭ �޸� �Ҵ�
                    json->tokens[tokenIndex].string = malloc(stringLength + 1);
                    // ���� ���ڿ��� �迭�� ���
                    json->tokens[tokenIndex].isArray = true;
                    // �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
                    memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

                    // �������� ���ڿ��� ��ū�� ����
                    // ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
                    memcpy(json->tokens[tokenIndex].string, begin, stringLength);

                    tokenIndex++;    // ��ū �ε��� ����

                    pos = pos + stringLength + 1;    // ���� ��ġ + ���ڿ� ���� + "(+ 1)
                }

                pos++;    // ���� ���ڷ�
            }
        }
        break;
        case '0': case '1': case '2': case '3': case '4': case '5':    // ���ڰ� �����̸�
        case '6': case '7': case '8': case '9': case '-':              // -�� ������ ��
        {
            // ���ڿ��� ���� ��ġ�� ����
            char *begin = doc + pos;
            char *end;
            char *buffer;

            // ���ڿ��� �� ��ġ�� ����. ,�� �����ų�
            end = strchr(doc + pos, ',');
            if (end == NULL)
            {
                // }�� ������ ���ڿ��� ����
                end = strchr(doc + pos, '}');
                if (end == NULL)    // }�� ������ �߸��� �����̹Ƿ�
                    break;          // �ݺ��� ����
            }

            int stringLength = end - begin;    // ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ

            // ���ڿ� ���� + NULL ������ŭ �޸� �Ҵ�
            buffer = malloc(stringLength + 1);
            // �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
            memset(buffer, 0, stringLength + 1);

            // �������� ���ڿ��� ���ۿ� ����
            // ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
            memcpy(buffer, begin, stringLength);

            // ��ū ������ ����
            json->tokens[tokenIndex].type = TOKEN_NUMBER;  
            // ���ڿ��� ���ڷ� ��ȯ�Ͽ� ��ū�� ����
            json->tokens[tokenIndex].number = atof(buffer);

            free(buffer);    // ���� ����

            tokenIndex++;    // ��ū �ε��� ����

            pos = pos + stringLength + 1;    // ���� ��ġ + ���ڿ� ���� + , �Ǵ� }(+ 1)
        }
        break;
        }

        pos++; // ���� ���ڷ�
    }
}

void freeJSON(JSON *json) // JSON ���� �Լ�
{
    for (int i = 0; i < TOKEN_COUNT; i++) // ��ū ������ŭ �ݺ�
    {
        if (json->tokens[i].type == TOKEN_STRING) // ��ū ������ ���ڿ��̸�
            free(json->tokens[i].string);         // ���� �޸� ����
    }
}

int main()
{
    int size;    // ���� ũ��

    // ���Ͽ��� JSON ������ ����, ���� ũ�⸦ ����
    char *doc = readFile("example.json", &size);
    if (doc == NULL)
        return -1;

    JSON json = { 0, };    // JSON ����ü ���� ���� �� �ʱ�ȭ

    parseJSON(doc, size, &json);    // JSON ���� �Ľ�

    printf("Title: %s\n", json.tokens[1].string);        // ��ū�� ����� ���ڿ� ���(Title)
    printf("Year: %d\n", (int)json.tokens[3].number);    // ��ū�� ����� ���� ���(Year)
    printf("Runtime: %d\n", (int)json.tokens[5].number); // ��ū�� ����� ���� ���(Runtime)
    printf("Genre: %s\n", json.tokens[7].string);        // ��ū�� ����� ���ڿ� ���(Genre)
    printf("Director: %s\n", json.tokens[9].string);     // ��ū�� ����� ���ڿ� ���(Director)
    printf("Actors:\n");
    printf("  %s\n", json.tokens[11].string);            // ��ū�� ����� ���ڿ� ���(Actors �迭�� ���)
    printf("  %s\n", json.tokens[12].string);            // ��ū�� ����� ���ڿ� ���(Actors �迭�� ���)
    printf("  %s\n", json.tokens[13].string);            // ��ū�� ����� ���ڿ� ���(Actors �迭�� ���)
    printf("  %s\n", json.tokens[14].string);            // ��ū�� ����� ���ڿ� ���(Actors �迭�� ���)
    printf("  %s\n", json.tokens[15].string);            // ��ū�� ����� ���ڿ� ���(Actors �迭�� ���)
    printf("imdbRating: %f\n", json.tokens[17].number);  // ��ū�� ����� ���� ���(imdbRating)

    freeJSON(&json);    // json �ȿ� �Ҵ�� ���� �޸� ����

    free(doc);    // ���� ���� �޸� ����

    return 0;
}
