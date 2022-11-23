int printStatus(ItemList *list, Status *stats, PlayerData *playerdat, char *windowName)
{
    makebannerbox(5);
    gotoxy(3, 1);
    printf("사용자 이름: %s", playerdat->playerName);
    gotoxy(3, 2);
    printf("개냥이 이름: %s", playerdat->dreamCatName);
    gotoxy(0, 6);
    makebannerbox(5);
    gotoxy(3, 7);
    printf("배고픔: %d%%    건강: %d%%    친밀도: %d", stats->hunger / 10, stats->health / 10, stats->friendship / 10);
    gotoxy(3, 9);
    printf("기분: %s\n", stats->laststatcode);

    if (windowName != NULL)
    {
        makebannerbox(3);
        gotoxy(3, 11);
        printf("%s", windowName);
        gotoxy(0, 15);
    }
    else
    {
        gotoxy(0, 12);
    }

    return 0;
}

int getRandomCharacterNum(Status *stats)
{
    char imgname[128];
    char filedir[128] = "./catimg/";
    getCurrentStat(imgname, stats);
    strcat(filedir, imgname);
    strcat(filedir, ".txt");
    printf("%s", filedir);
    FILE *catimg = fopen(filedir, "r");

    // printf("%s", filedir);
    char input[128];
    fgets(input, sizeof(input), catimg);
    printf("%s", input);
    strtok(input, "=");
    if (strcmp(input, "imgcount") == 0)
    {
        char *ptr = 0;
        ptr = strtok(NULL, "");
        int imgcount = 0;
        strtok(NULL, "");
        for (int i = 0; ptr[i] != 10; i++)
        {
            imgcount *= 10;
            imgcount += ptr[i] - '0';
        }
        printf("%d", imgcount);

        int randomimg = getRandomValue(imgcount - 1);
        return randomimg;
    }
    else
    {
        printf("Error: Character print initilization Failed.");
        return -1;
    }

    return -1;
}

int printCharacter(int *imgnum, Status *stats)
{
    char currentstat[128];
    getCurrentStat(currentstat, stats);
    if ((stats->laststatcode != NULL) && (strcmp(stats->laststatcode, currentstat)) != 0) // 기분 상태가 변경되었는지 확인
    {
        *imgnum = getRandomCharacterNum(stats);
        strcpy(stats->laststatcode, currentstat);
    } // 마지막 출력으로부터 상태가 변경되어 새로운 이미지가 필요한지 판별

    // int imgnumcp = *imgnum;
    // int temp = 1;
    char strimgnum[128];

    // while (imgnumcp % temp > 10)
    // {
    //     temp *= 10;
    // }

    // for (int i = 0; temp != 1; i++)
    // {
    //     strimgnum[i] = (imgnumcp / temp) - '0';
    //     imgnumcp = imgnumcp - (temp * (strimgnum[i] - '0'));
    //     temp /= 10;
    // } // 이미지 코드 string으로 변환

    sprintf(strimgnum, "%d", *imgnum);
    strcat(strimgnum, "\n");
    char filedir[128] = "./catimg/";
    strcat(filedir, currentstat);
    strcat(filedir, ".txt");
    FILE *catimg = fopen(filedir, "r");

    char input[128];
    int flag = 0;
    while (fgets(input, sizeof(input), catimg) != 0)
    {
        if (strcmp(input, strimgnum) == 0)
        {
            printf("  ");
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        while ((fgets(input, sizeof(input), catimg) != 0) && (strcmp(input, "END\n") != 0))
        {
            printf("%s", input);
        }
        printf("\n");
    }
    else
    {
        printf("Error: Image not Found");
    }

    return 0;
}

int windowNameBanner(char *windowname)
{
    if (windowname != "NULL")
    {
        makebannerbox(3);
        gotoxy(3, 1);
        printf("%s", windowname);
        gotoxy(0, 3);

        return 0;
    }
    else
    {
        return -1;
    }
    return -1;
}

void shop_banner()
{
    printf("╔");
    for (int i = 1; i < 79; i++)
    {
        printf("═");
    }
    printf("╗\n");

    for (int i = 1; i < 6; i++)
    {
        printf("║");
        gotoxy(79, i);
        printf("║\n");
    }

    printf("╚");
    for (int i = 1; i < 79; i++)
    {
        printf("═");
    }
    printf("╝\n");

    FILE *fp = fopen(".\\shop_banner.txt", "r");
    char input[100];
    for (int i = 1; i < 6; i++)
    {
        fgets(input, sizeof(input), fp);
        gotoxy(20, i);
        printf("%s", input);
    }
}

void add_line() // 줄 만들기
{
    for (int i = 1; i < 80; i++)
    {
        printf("═");
    }
    printf("\n");
}