#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����

int main()
{
    // JSON ������ ������ ������
    char *title = "Inception";
    int year = 2010;
    int runtime = 148;
    char *genre = "Sci-Fi";
    char *director = "Christopher Nolan";
    char actors[5][30] = {
        "Leonardo DiCaprio",
        "Joseph Gordon-Levitt",
        "Ellen Page",
        "Tom Hardy",
        "Ken Watanabe"
    };
    double imdbRating = 8.8;

    FILE *fp = fopen("example.json", "w");    // ���� ���� ���� ����

    // JSON ������ ���缭 fprintf �Լ��� �� ���
    fprintf(fp, "{\n");
    fprintf(fp, "  \"Title\": \"%s\",\n", title);
    fprintf(fp, "  \"Year\": %d,\n", year);
    fprintf(fp, "  \"Runtime\": %d,\n", runtime);
    fprintf(fp, "  \"Genre\": \"%s\",\n", genre);
    fprintf(fp, "  \"Director\": \"%s\",\n", director);
    fprintf(fp, "  \"Actors\": [\n");
    fprintf(fp, "    \"%s\", \n", actors[0]);
    fprintf(fp, "    \"%s\", \n", actors[1]);
    fprintf(fp, "    \"%s\", \n", actors[2]);
    fprintf(fp, "    \"%s\", \n", actors[3]);
    fprintf(fp, "    \"%s\" \n", actors[4]);
    fprintf(fp, "  ],\n");
    fprintf(fp, "  \"imdbRating\": %.1f\n", imdbRating);
    fprintf(fp, "}\n");

    fclose(fp);    // ���� �ݱ�

    return 0;
}
