#include <stdio.h>

enum VayneSkill {
    Tumble = 1,     // ������
    SilverBolts,    // ��ȭ��
    Condemn,        // ����
    FinalHour       // ������ �ð�
};

int main()
{
    enum VayneSkill skill;

    skill = Tumble;

    /*(1)_______*/
    {
    case /*(2)_____*/:
        printf("������\n");
        break;
    case /*(2)_____*/:
        printf("��ȭ��\n");
        break;
    case /*(2)_____*/:
        printf("����\n");
        break;
    case /*(2)_____*/:
        printf("������ �ð�\n");
        break;
    default:
        break;
    }

    return 0;
}
