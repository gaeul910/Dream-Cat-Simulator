int event(ItemList *itemlist, Status *status)
{
    int random = 9;
    int chance = 2;
    int wnq;
    switch (getRandomValue(random))
    {
    case 0:
        printf("큰일이다. 배변봉투가 없다!\n");
        Sleep(1000);
        if (itemlist->itemArr[10].amount == 0)
        {
            if (getRandomValue(chance) == 0)
            {
                printf("걸렸다!\n");
                Sleep(1000);
                printf("-400G\n");
                itemlist->gold -= 400;
            }
            else
                printf("다행히 안걸렸다!\n");
        }
        break;
    case 1:
        if (itemlist->itemArr[9].amount == 0)
        {
            printf("저런, 목줄이 없으셨네요..\n");
            Sleep(1000);
            printf("-400G\n");
            itemlist->gold -= 400;
        }
        break;
    case 2:
        printf("다른 개냥이와 시비가 붙었다!\n");
        Sleep(1000);
        printf("이겼다!!\n");
        Sleep(1000);
        printf("+300 Delight");
        status->delight += 300;
        break;
    case 3:
        printf("다른 개냥이와 시비가 붙었다!\n");
        Sleep(1000);
        printf("졌다..\n");
        Sleep(1000);
        printf("+100 Anger\n");
        status->anger += 100;
        break;
    case 4:
        printf("길을 가다가 무언가를 주웠다!\n");
        Sleep(1000);
        switch (getRandomValue(wnq))
        {
            /*case 0 == 돈
            case 1 ~ x == 아이템 가위바위보 아이템*/
        }
    case 5:
        printf("갑자기 비가와서 산책을 그만해야하는 개냥이는 슬프다..\n");
        Sleep(1000);
        printf("+200 Sadness\n");
        status->sadness += 200;
        break;
    case 6:
        printf("넘어졌다..\n");
        Sleep(1000);
        printf("- Health\n");
        status->health -= 1;
        break;
    case 7:
        printf("귀엽다고 칭찬받았다!\n");
        Sleep(1000);
        printf("+600 Delight\n");
        status->delight += 600;
        break;
    }
}

int walking(ItemList *itemlist, Status *status)
{
    // 산책 중... 출력
    char windowName[256];

    system("cls");
    sprintf(windowName, "산책 중...");
    windowNameBanner(windowName);

    // 2프레임 고양이 아스키아트 출력
    // 3~9 줄 까지 아스키아트 영역
    Sleep(1500);
    // 몇 초 후에 이벤트 발생
    gotoxy(0, 10);
    event(itemlist, status);
    // 이벤트 발생 후 스텟 영향 적용
    Sleep(1000);
    system("pause");
    // 산책 끝날 때 스텟 영향 적용
    system("cls");
    sprintf(windowName, "산책 끝!");
    windowNameBanner(windowName);
    // 고양이 아스키아트 추가
    status->hunger -= 200;
    status->friendship += 300;
    Sleep(1000);
    gotoxy(0, 10);
    printf("-200 Hunger\n");
    Sleep(1000);
    printf("+300 Friendship");

    Sleep(2000);

    return 0;
}