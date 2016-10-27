#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free, atof �Լ��� ����� ��� ����
#include <stdbool.h>   // bool, true, false�� ���ǵ� ��� ����
#include <string.h>    // strchr, strcmp, memset, memcpy �Լ��� ����� ��� ����

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

void freeJSON(JSON *json)    // JSON ���� �Լ�
{
    for (int i = 0; i < TOKEN_COUNT; i++)            // ��ū ������ŭ �ݺ�
    {
        if (json->tokens[i].type == TOKEN_STRING)    // ��ū ������ ���ڿ��̸�
            free(json->tokens[i].string);            // ���� �޸� ����
    }
}

char *getString(JSON *json, char *key)    // Ű�� �ش��ϴ� ���ڿ��� �������� �Լ�
{
    for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
    {
        // ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�ϸ�
        if (json->tokens[i].type == TOKEN_STRING && 
            strcmp(json->tokens[i].string, key) == 0)
        {
            // �ٷ� ���� ��ū(i + 1)�� ���ڿ��̸�
            if (json->tokens[i + 1].type == TOKEN_STRING)
                return json->tokens[i + 1].string;    // �ٷ� �ڿ� �ִ� ��ū�� ���ڿ� ��ȯ
        }
    }

    return NULL;    // Ű�� ã�� �������� NULL�� ��ȯ
}

// Ű�� �ش��ϴ� �迭 �� �ε����� �����Ͽ� ���ڿ��� �������� �Լ�
char *getArrayString(JSON *json, char *key, int index)
{
    for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
    {
        // ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
        if (json->tokens[i].type == TOKEN_STRING &&
            strcmp(json->tokens[i].string, key) == 0)
        {
            // �ٷ� ���� ��ū(i + 1)���� �迭�� ���
            // �ε����� ������ ��ū�� ���ڿ��̸鼭 �迭�̸�
            if (json->tokens[i + 1 + index].type == TOKEN_STRING && 
                json->tokens[i + 1 + index].isArray == true)
                return json->tokens[i + 1 + index].string;    // �ش� ��ū�� ���ڿ� ��ȯ
        }
    }

    return NULL;    // Ű�� ã�� �������� NULL�� ��ȯ
}

int getArrayCount(JSON *json, char *key)     // Ű�� �ش��ϴ� �迭�� ��� ������ ���ϴ� �Լ�
{
    for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
    {
        // ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
        if (json->tokens[i].type == TOKEN_STRING &&
            strcmp(json->tokens[i].string, key) == 0)
        {
            // �ٷ� ���� ��ū(i + 1)���� isArray�� true�� ��ū�� ������ ��� ��ȯ
            int j = 0;
            while (json->tokens[i + 1 + j].isArray == true)
                j++;

            return j;
        }
    }

    return 0;    // Ű�� ã�� �������� 0�� ��ȯ
}

double getNumber(JSON *json, char *key)    // Ű�� �ش��ϴ� ���ڸ� �������� �Լ�
{
    for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
    {
        // ��ū ������ �����̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
        if (json->tokens[i].type == TOKEN_STRING &&
            strcmp(json->tokens[i].string, key) == 0)
        {
            // �ٷ� ���� ��ū(i + 1)�� �����̸�
            if (json->tokens[i + 1].type == TOKEN_NUMBER)
                return json->tokens[i + 1].number;    // �ٷ� �ڿ� �ִ� ��ū�� ���� ��ȯ
        }
    }

    return 0.0;    // Ű�� ã�� �������� 0.0�� ��ȯ
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

    printf("Title: %s\n", getString(&json, "Title"));           // Title�� �� ���
    printf("Year: %d\n", (int)getNumber(&json, "Year"));        // Year�� �� ���
    printf("Runtime: %d\n", (int)getNumber(&json, "Runtime"));  // Runtime�� �� ���
    printf("Genre: %s\n", getString(&json, "Genre"));           // Genre�� �� ���
    printf("Director: %s\n", getString(&json, "Director"));     // Director�� �� ���
    
    printf("Actors:\n");
    int actors = getArrayCount(&json, "Actors");                // Actors �迭�� ������ ����
    for (int i = 0; i < actors; i++)                            // �迭�� ��� ������ŭ �ݺ�
        printf("  %s\n", getArrayString(&json, "Actors", i));   // �ε����� �����Ͽ� ���ڿ��� ������

    printf("imdbRating: %f\n", getNumber(&json, "imdbRating")); // imdbRating�� �� ���

    freeJSON(&json);    // json �ȿ� �Ҵ�� ���� �޸� ����

    free(doc);    // ���� ���� �޸� ����

    return 0;
}
