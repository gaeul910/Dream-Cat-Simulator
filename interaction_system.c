

int cursor(int start, int end) // 아이템 커서 이동 기능
{
    int x = 0;
    int y = start + 1;
    while (1)
    {
        int key = getch();
        if (key == 224 && y > 2)
        {
            gotoxy(x, y);
            printf(" ");
            key = getch();
            switch (key)
            {
            case 72:
            {
                y--;
                break;
            }
            case 80:
                y++;
                break;

            default:
                break;
            }
        }
        else if (key == 13)
        {
            return y;
        }
        else if (key == 81 || key == 113)
        {
            return 0;
        }
        if (y < start)
        {
            y++;
        }
        else if (y > end)
        {
            y--;
        }
        gotoxy(x, y);
        printf(">");
    }
}

void food(ItemList *list, Status *stats)
{
    system("cls");
    add_line();
    gotoxy(10, 1);
    printf("소지품\n");
    add_line();

    FILE *fp = fopen(".\\gamedata\\item_effect_info.txt", "r");

    for (int i = 1; i < 4; i++)
    {
        printf(" o %s %d\n", list->itemArr[i].name, list->itemArr[i].amount);
    }

    int num = cursor(3, 5);

    switch (num)
    {
    case 0:
        return;
    case 3:
    {
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "1\n") == 0)
            {
                break;
            }
        }
        char effect[20];
        while (1)
        {
            fgets(effect, 20, fp);
            if (strcmp(effect, "END\n") == 0)
            {
                break;
            }
            effect_type = judg_effect(strtok(effect, "="));
            effect_rate = change_rate(strtok(NULL, "="));
            apply_effect(stats, effect_type, effect_rate);
        }
        break;
    }
    case 4:
        printf("you select item2\n");
        break;
    case 5:
        printf("you select item3\n");
        break;

    default:
        break;
    }

    system("pause");
}