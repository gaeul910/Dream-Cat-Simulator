

int cursor(int start, int end, int move) // 아이템 커서 이동 기능
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
                y -= move;
                break;
            }
            case 80:
                y += move;
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
            y += move;
        }
        else if (y > end)
        {
            y -= move;
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

    for (int i = 1; i < 6; i++)
    {
        printf(" o %s %d\n\n", list->itemArr[i].name, list->itemArr[i].amount);
    }

    int num = cursor(3, 7, 2);

    switch (num)
    {
    case 0:
        return;
    case 3:
    {
        if (list->itemArr[1].amount <= 0)
        {
            break;
        }
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

        list->itemArr[1].amount--;

        break;
    }
    case 4:
    {
        if (list->itemArr[2].amount <= 0)
        {
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "2\n") == 0)
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

        list->itemArr[2].amount--;

        break;
    }
    case 5:
    {
        if (list->itemArr[3].amount <= 0)
        {
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "3\n") == 0)
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

        list->itemArr[3].amount--;

        break;
    }
    case 6:
    {
        if (list->itemArr[4].amount <= 0)
        {
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "4\n") == 0)
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

        list->itemArr[4].amount--;

        break;
    }
    case 7:
    {
        if (list->itemArr[5].amount <= 0)
        {
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "5\n") == 0)
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

        list->itemArr[5].amount--;

        break;
    }

    default:
        break;
    }

    system("pause");
}

void playing(ItemList *list, Status *stats)
{
    system("cls");
    add_line();
    gotoxy(10, 1);
    printf("소지품\n");
    add_line();

    FILE *fp = fopen(".\\gamedata\\item_effect_info.txt", "r");

    for (int i = 6; i < 9; i++)
    {
        printf(" o %s %d\n\n", list->itemArr[i].name, list->itemArr[i].amount);
    }

    int num = cursor(3, 5, 2);

    switch (num)
    {
    case 0:
        return;
    case 3:
    {
        if (list->itemArr[6].amount <= 0)
        {
            break;
        }
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

        list->itemArr[6].amount--;

        break;
    }
    case 4:
    {
        if (list->itemArr[7].amount <= 0)
        {
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "2\n") == 0)
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

        list->itemArr[7].amount--;

        break;
    }
    case 5:
    {
        if (list->itemArr[8].amount <= 0)
        {
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "3\n") == 0)
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

        list->itemArr[8].amount--;

        break;
    }

    default:
        break;
    }

    system("pause");
}