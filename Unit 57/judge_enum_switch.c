#include <stdio.h>

enum MasterYiSkill {
    AlphaStrike = 1,
    Meditation,
    WujuStyle,
    Highlander
};

int main()
{
    /*_______________________


    _______________________*/

    switch (skill)
    {
    case AlphaStrike:
        printf("�ϰ� �ʻ�\n");
        break;
    case Meditation:
        printf("���\n");
        break;
    case WujuStyle:
        printf("���ַ� �˼�\n");
        break;
    case Highlander:
        printf("������ ����\n");
        break;
    default:
        break;
    }

    return 0;
}
