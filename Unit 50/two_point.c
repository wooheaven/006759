#include <stdio.h>

struct Point2D {
    int x;
    int y;
};

int main()
{
    struct Point2D p1;    // ��1
    struct Point2D p2;    // ��2

    // ��1 ��ġ
    p1.x = 30;
    p1.y = 20;

    // ��2 ��ġ
    p2.x = 60;
    p2.y = 50;

    printf("p1: %d %d\n", p1.x, p1.y);    // 30 20
    printf("p2: %d %d\n", p2.x, p2.y);    // 60 50

    return 0;
}
