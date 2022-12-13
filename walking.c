int event(ItemList *itemlist, Status *status, PlayerData *playerdat)
{
    int random = 8;
    int chance = 2;
    int wnq;
    switch (getRandomValue(random))
    {
    case 0:
        Sleep(2000);
        if (itemlist->itemArr[10].amount == 0)
        {
            printf("산책 중 개냥이가  ");
            printf("큰일이다. 배변봉투가 없다!!!\n\n");
            Sleep(1500);
            if (getRandomValue(chance) == 0)
            {
                printf("걸렸다!\n\n");
                Sleep(2000);
                printf("-400G\n\n");
                itemlist->gold -= 400;
            }
            else
                printf("다행히 안걸렸다!\n\n");
        }
        break;
    case 1:
        if (itemlist->itemArr[9].amount == 0)
        {
            printf("저런, 목줄이 없으셨네요..\n\n");
            Sleep(2000);
            printf("-400G\n\n");
            itemlist->gold -= 400;
        }
        break;
    case 2:
        printf("%s다른 개냥이와 시비가 붙었다!\n\n", playerdat->dreamCatName);
        Sleep(2000);
        printf("이겼다!!\n\n");
        Sleep(2000);
        printf("+300 Delight\n\n");
        status->delight = calcStatsValue(status->delight, 300);
        break;
    case 3:
        printf("다른 개냥이와 시비가 붙었다!\n\n");
        Sleep(2000);
        printf("져버렸다..\n\n");
        Sleep(2000);
        printf("+100 Anger\n\n");
        status->anger = calcStatsValue(status->anger, 100);
        break;
    case 4:
        printf("길을 가다가 무언가를 주웠다!\n\n");
        Sleep(2000);
        switch (getRandomValue(wnq))
        {
        case 0:
            printf("돈을 주웠다!\n\n");
            itemlist->gold += 500;
            Sleep(2000);
            printf("+500 G\n\n");
            break;
        case 1:
            printf("아이템 '무법자'를 얻었다!\n\n");
            itemlist->itemArr[11].amount += 1;
            Sleep(2000);
            printf("+ 무법자");
            break;
        case 2:
            printf("아이템 '부활'을 얻었다!\n\n");
            itemlist->itemArr[12].amount += 1;
            Sleep(2000);
            printf("+ 부활");
            break;
        }
        break;
    case 5:
        printf("갑자기 비가와서 산책을 그만해야하는 개냥이는 슬프다..\n\n");
        Sleep(2000);
        printf("+200 Sadness\n\n");
        status->sadness = calcStatsValue(status->sadness, 200);
        break;
    case 6:
        printf("넘어졌다..\n\n");
        Sleep(2000);
        printf("- Health\n\n");
        status->health = calcStatsValue(status->health, -1);
        break;
    case 7:
        printf("귀엽다고 칭찬받았다!\n\n");
        Sleep(2000);
        printf("+200 Delight\n\n");
        status->delight = calcStatsValue(status->delight, 200);
        break;
    }
}

int walking(ItemList *itemlist, Status *status, PlayerData *playerdat)
{
    char windowName[256];

    system("cls");
    sprintf(windowName, "산책 중...");
    windowNameBanner(windowName);
    for (int i = 0; i < 2; i++)
    {
        animationDisplay("./cat_anime/walk.txt", 0);
    }
    system("cls");
    sprintf(windowName, "산책 중...");
    windowNameBanner(windowName);
    printf("\n");
    event(itemlist, status, playerdat);

    Sleep(1000);
    system("cls");
    sprintf(windowName, "산책 끝!\n\n");
    windowNameBanner(windowName);
    status->hunger = calcStatsValue(status->hunger, 200);
    status->friendship = calcStatsValue(status->friendship, 300);
    Sleep(1500);
    gotoxy(0, 10);
    printf("-200 Hunger\n\n");
    Sleep(1500);
    printf("+300 Friendship\n\n");

    Sleep(2000);

    return 0;
}