#include <stdio.h>

union Box {
    short candy;
    float snack;
    char doll[8];
};

enum BOX_TYPE {
    BOX_PAPER = 0,
    BOX_WOOD,
    BOX_PLASTIC
};

void printBox(union Box box)    // ��ȯ�� ����, ����ü �Ű����� �� �� ����
{
    printf("%d\n", box.candy);
}

void printBoxType(enum BOX_TYPE boxType)    // ��ȯ�� ����, ������ �Ű����� �� �� ����
{
    printf("%d\n", boxType);
}

int main()
{
    union Box box;
    enum BOX_TYPE boxType;

    box.candy = 10;
    boxType = BOX_PLASTIC;

    printBox(box);            // 10: �Լ��� ȣ���� �� ����ü ���� ����
    printBoxType(boxType);    //  2: �Լ��� ȣ���� �� ������ �� ����

    return 0;
}
