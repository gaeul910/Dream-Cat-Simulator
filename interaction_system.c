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
    makebannerbox(3);
    gotoxy(10, 1);
    printf("밥 줘요\n");

    gotoxy(0, 3);
    FILE *fp = fopen(".\\gamedata\\item_effect_info.txt", "r");

    for (int i = 1; i < 6; i++)
    {
        printf(" o %s %d\n\n", list->itemArr[i].name, list->itemArr[i].amount);
    }

    key_box(0);
    printf("[↑] 위로 이동\t");
    printf("[↓] 아래로 이동\t");
    gotoxy(68, 24);
    printf("[Q] 나가기\t");

    int num = cursor(2, 11, 2);

    switch (num)
    {
    case 0:
    {
        system("cls");
        return;
    }
    case 3:
    {
        if (list->itemArr[1].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
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
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[1].amount--;

        break;
    }
    case 5:
    {
        if (list->itemArr[2].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
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
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[2].amount--;

        break;
    }
    case 7:
    {
        if (list->itemArr[3].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
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
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[3].amount--;

        break;
    }
    case 9:
    {
        if (list->itemArr[4].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
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
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[4].amount--;

        break;
    }
    case 11:
    {
        if (list->itemArr[5].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
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
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[5].amount--;

        break;
    }

    default:
        break;
    }

    Sleep(1500);
}

void playing(ItemList *list, Status *stats)
{
    system("cls");
    makebannerbox(3);
    gotoxy(10, 1);
    printf("놀아줘요\n");

    key_box(0);
    printf("[↑] 위로 이동\t");
    printf("[↓] 아래로 이동\t");
    gotoxy(68, 24);
    printf("[Q] 나가기\t");

    gotoxy(0, 3);
    FILE *fp = fopen(".\\gamedata\\item_effect_info.txt", "r");

    for (int i = 6; i < 9; i++)
    {
        printf(" o %s %d\n\n", list->itemArr[i].name, list->itemArr[i].amount);
    }

    int num = cursor(2, 7, 2);

    switch (num)
    {
    case 0:
        return;
    case 3:
    {
        if (list->itemArr[6].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "6\n") == 0)
            {
                break;
            }
        }
        char effect[20];
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[6].amount--;

        break;
    }
    case 5:
    {
        if (list->itemArr[7].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "7\n") == 0)
            {
                break;
            }
        }
        char effect[20];
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[7].amount--;

        break;
    }
    case 7:
    {
        if (list->itemArr[8].amount <= 0)
        {
            gotoxy(0, 20);
            printf("갯수 부족!\n");
            Sleep(500);
            break;
        }
        char number[100];
        int effect_type;
        int effect_rate;

        while (1)
        {
            fgets(number, 100, fp);
            if (strcmp(number, "8\n") == 0)
            {
                break;
            }
        }
        char effect[20];
        gotoxy(0, 16);
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
            Sleep(500);
        }

        list->itemArr[8].amount--;

        break;
    }

    default:
        break;
    }

    Sleep(1500);
}