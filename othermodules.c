int getRandomValue(int maxvalue)
{
    if (maxvalue == 0)
    {
        return 0;
    }
    else
    {
        srand(time(NULL));
        return rand() % maxvalue;
    }

    return -1;
}

void gotoxy(int x, int y) // cmd 커서 이동 함수
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int makebannerbox(int colsize)
{
    if (colsize < 2)
    {
        printf("Error: Banner box column size must be bigger than 2");
        return 0;
    }
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    for (int i = 0; i < colsize - 2; i++)
    {
        printf("║                                                                      ║\n");
    }
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    return 0;
}

int judg_effect(char *effect)
{
    if (strcmp(effect, "hunger") == 0)
    {
        return 1;
    }
    else if (strcmp(effect, "health") == 0)
    {
        return 2;
    }
    else if (strcmp(effect, "normal") == 0)
    {
        return 3;
    }
    else if (strcmp(effect, "delight") == 0)
    {
        return 4;
    }
    else if (strcmp(effect, "sadness") == 0)
    {
        return 5;
    }
    else if (strcmp(effect, "anger") == 0)
    {
        return 6;
    }
    else if (strcmp(effect, "friendship") == 0)
    {
        return 7;
    }
    else
    {
        return 0;
    }
}

int change_rate(char *rate)
{
    int num = 0;
    int minus = 1;
    int i = 0;
    while (rate[i] != 10)
    {
        printf("%d", rate[i]);
        num *= 10;
        if (rate[i] >= '0' && rate[i] <= '9')
        {
            num += rate[i] - '0';
        }
        else if (rate[i] == '-')
        {
            minus = -1;
        }
        i++;
    }

    return minus * num;
}

void apply_effect(Status *stats, int type, int rate)
{
    switch (type)
    {
    case 1:
    {
        stats->hunger += rate;
        break;
    }
    case 2:
    {
        stats->health += rate;
        break;
    }
    case 3:
    {
        stats->normal += rate;
        break;
    }
    case 4:
    {
        stats->delight += rate;
        break;
    }
    case 5:
    {
        stats->sadness += rate;
        break;
    }
    case 6:
    {
        stats->anger += rate;
        break;
    }
    case 7:
    {
        stats->friendship += rate;
        break;
    }
    default:
        break;
    }
}