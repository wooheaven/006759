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

union Box getBox()    // Box ����ü�� ��ȯ�ϴ� getBox �Լ� ����
{
    union Box b;  // ����ü ���� ����

    b.candy = 10;

    return b;     // ����ü ���� ��ȯ
}

enum BOX_TYPE getBoxType()    // BOX_TYPE �������� ��ȯ�ϴ� getBoxType �Լ� ����
{
    return BOX_WOOD;
}

int main()
{
    union Box box;
    enum BOX_TYPE boxType;

    box = getBox();        // ��ȯ�� ����ü ������ ������ b1�� ��� �����
    boxType = getBoxType();    // ��ȯ�� ������ ���� g1�� �����

    printf("%d\n", box.candy);    // 10: getBox���� ������ ��
    printf("%d\n", boxType);      //  1: getBoxType���� ��ȯ�� BOX_WOOD

    return 0;
}
