int getCurrentStat(char *statcode, Status *stats)
{
}

int printStatus(ItemList *list, Status *stats, PlayerData *playerdat, char *windowName)
{
    printf("사용자 이름: %s    개냥이 이름: %s\n", playerdat->playerName, playerdat->dreamCatName);
    printf("========================");
    printf("배고픔: %d%    건강: %d%    친밀도: %d%", stats->hunger, stats->health, stats->friendship);
    printf("기분: %d", stats->feeling);

    printf("========================");

    if (windowName != NULL)
    {
        printf("%s", windowName);
        printf("========================");
    }

    return 0;
}

int getRandomCharacterNum(Status *stats)
{
    char imgname[128];
    char input[128];
    FILE *fp = fopen(imgname, "r");
    fgets(input, sizeof(input), fp);
    strtok(input, "=");
    if (strcmp(input, "imgcount") == 0)
    {
        int imgcount = 0;
        strtok(NULL, "");
        for (int i = 0; input[i] != 10; i++)
        {
            imgcount *= 10;
            imgcount += input[i] - '0';
        }

        int randomimg = getRandomValue(imgcount);
        return randomimg;
    }
    else
    {
        printf("Error: Character print initilization Failed.");
        return -1;
    }

    return -1;
}

int printCharacter(int *imgnum, char *laststat, Status *stats)
{
    char currentstat[128];
    getCurrentStat(currentstat, stats);
    if ((laststat != NULL) && (strcmp(laststat, currentstat)) != 0) //기분 상태가 변경되었는지 확인
    {
        *imgnum = getRandomCharacterNum(stats);
    } // 마지막 출력으로부터 상태가 변경되어 새로운 이미지가 필요한지 판별

    int imgnumcp = *imgnum;
    int temp = 1;
    char strimgnum[128];

    while (imgnumcp % temp > 10)
    {
        temp *= 10;
    }

    for (int i = 0; temp != 1; i++)
    {
        strimgnum[i] = (imgnumcp / temp) - '0';
        imgnumcp = imgnumcp - (temp * (strimgnum[i] - '0'));
        temp /= 10;
    } // 이미지 코드 string으로 변환

    char imgname[128];
    char filedir[128] = "./catimg/";
    strcat(filedir, imgname);
    strcat(filedir, ".txt");
    FILE *catimg = fopen(filedir, "r");

    char input[128];
    int flag = 0;
    while (fgets(input, sizeof(input), catimg) != 0)
    {
        if (strcmp(input, strimgnum) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        while ((fgets(input, sizeof(input), catimg) != 0) && (strcmp(input, "END") != 0))
        {
            printf("%s", input);
        }
    }
    else
    {
        printf("Error: Image not Found");
    }

    return 0;
}