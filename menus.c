int exitGameMenu(ItemList *items, Status *stats)
{
    while (1)
    {
        system("cls");
        windowNameBanner("게임 종료 옵션");
        gotoxy(0, 7);
        printf(" 저장하고 종료\n\n");
        printf(" 저장하지 않고 종료\n\n");
        printf(" 게임으로 돌아가기");

        key_box(0);
        printf("[↑] 위로 이동\t");
        printf("[↓] 아래로 이동\t");
        gotoxy(62, 24);
        printf("[Q] 나가기\t");

        int num = cursor(6, 12, 2);

        switch (num)
        {
        case 0:
            system("cls");
            return 0;
        case 7:
        {
            system("cls");
            saveGame(items, stats);
            return 1;
            break;
        }
        case 9:
        {
            return 1;
            break;
        }
        case 11:
            return 0;
            break;

        default:
            break;
        }
    }
}

int interactionMenu(ItemList *list, Status *stats, PlayerData *playerdat)
{
    char input;
    char laststat[128];
    getCurrentStat(stats->laststatcode, stats); // 현재의 상태코드를 laststat에 입력시켜줌 (아직 개발중인 모듈임)
    int randomimg = 0;
    int displayflag = 1;
    system("cls");
    randomimg = getRandomCharacterNum(stats); // 현재 상태에 의거한 랜덤 이미지 번호 뽑아오기
    while (1)
    {
        if (StatUpdate(stats, 1) == 1 || displayflag == 1)
        {
            mainDisplay(list, stats, playerdat, randomimg, NULL, displayflag);
            if (displayflag == 1)
            {
                key_box(0);
                printf("[F] 먹이주기\t");
                printf("[G] 놀아주기\t");
                gotoxy(62, 24);
                printf("[Q] 나가기");
            }
            displayflag = 0;
            // 여기서부터 키 입력 메뉴 출력 & 입력 받기
            // 반드시 while문 마지막에 스크린 모두 지우기 실행
        }
        if (kbhit() == 1)
        {
            input = getch();
            switch (input)
            {
            case 'q':
            case 'Q':
                return 0;
            case 'F':
            case 'f':
                food(list, stats);
                system("cls");
                displayflag = 1;
                break;
            case 'G': // 임시할당
            case 'g':
                playing(list, stats);
                system("cls");
                displayflag = 1;
                break;
            default:
                continue;
            }
        }
        if (displayflag == 0)
        {
            Sleep(500);
        }
        // system("cls");
    }
    return 0;
}

int debugWindow(ItemList *items, Status *stats, PlayerData *playerdat)
{
    system("cls");
    char input[256];
    windowNameBanner("Debug");
    printf("Dream-Cat-Simulator 디버깅 도구\n");
    printf("디버깅 메뉴에 대한 도움말이 필요할 경우 help를 입력하십시오.\n");
    printf("계속하려면 아무 키나 누르십시오.");
    getch();
    while (1)
    {
        system("cls");
        windowNameBanner("Debug");
        printf("Dream-Cat-Simulator Debug ver. 1\n\n");
        printf("> ");
        scanf("%s", input);

        printf("\n");
        if (strcmp(input, "rsptimereset") == 0)
        {
            miniGameData *minigamedata = malloc(sizeof(miniGameData));
            loadMinigameData(minigamedata);
            minigamedata->rsp_lastPlayed = 0;
            saveMinigameData(minigamedata);

            printf("rsp_lastPlayed is now 0");
        }
        else if (strcmp(input, "addgold") == 0)
        {
            items->gold += 10000;
            printf("Added 10000 gold");
        }
        else if (strcmp(input, "stat") == 0)
        {
            scanf("%s", input);
            if (strcmp(input, "info") == 0)
            {
                printf("Delight = %d\n", stats->delight);
                printf("Anger = %d\n", stats->anger);
                printf("Sadness = %d\n", stats->sadness);
                printf("Hunger = %d\n", stats->hunger);
                printf("Health = %d\n", stats->health);
                printf("Friendship = %d\n", stats->friendship);
                printf("Current Stat = %s\n\n", stats->laststatcode);
                printf("Press any key to return");
                getch();
            }
        }
        else if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else if (strcmp(input, "help") == 0)
        {
            fileprint("./gamedata/textresources/debughelp.txt");
            printf("\n");
            printf("Press any key to return");
            getch();
        }
        else
        {
            printf("Unknown Command. Type 'help' for help");
        }
        Sleep(1000);
    }
    return 0;
}

int mainMenu(ItemList *list, Status *stats, PlayerData *playerdat)
{
    Status *oldStats = (Status *)malloc(sizeof(Status));
    char input;
    system("cls");

    getCurrentStat(stats->laststatcode, stats); // 현재의 상태코드를 laststat에 입력시켜줌 (아직 개발중인 모듈임)
    int randomimg = 0;
    randomimg = getRandomCharacterNum(stats); // 현재 상태에 의거한 랜덤 이미지 번호 뽑아오기
    int displayflag = 1;
    while (1)
    {
        if (StatUpdate(stats, 1) == 1 || displayflag == 1)
        {
            // 여기서부터 키 입력 메뉴 출력 & 입력 받기
            // 반드시 while문 마지막에 스크린 모두 지우기 실행
            // displayflag = 1 -> 화면이 처음 출력되거나 지워졌을 때 화면 전체를 다시 출력하도록 함
            mainDisplay(list, stats, playerdat, randomimg, NULL, displayflag);
            key_box(1);
            printf("[E] 인벤토리    ");
            printf("[M] 지도 열기    ");
            printf("[F] 상호 작용    ");
            printf("\n");
            printf("[S] 저장하기    ");
            printf("[O] 옵션");
            gotoxy(60, 23);
            printf("[Q] 나가기\t");
            displayflag = 0;
        }
        if (kbhit() == 1)
        {
            input = getch();
            switch (input)
            {
            case 'f':
                interactionMenu(list, stats, playerdat);
                displayflag = 1;
                eraser(23, 24);
                break;
            case 'e':
                seeinventory(list);
                displayflag = 1;
                system("cls");
                break;
            case 'm':
                openmap(list, stats, playerdat);
                displayflag = 1;
                break;
            case 's':
                gotoxy(0, 21);
                if (saveGame(list, stats) == 0)
                {
                    printf("알림: 게임을 성공적으로 저장했습니다!\n");
                }
                else
                {
                    printf("오류: 저장 오류가 발생했습니다.");
                }
                Sleep(1500);
                eraser(21, 21);
                gotoxy(0, 0);
                break;
            case 'o':
                optionsMenu(list, stats, playerdat);
                displayflag = 1;
                break;
            case 'd':
                debugWindow(list, stats, playerdat);
                displayflag = 1;
                break;
            case 'q':
                system("cls");
                if (exitGameMenu(list, stats) == 1)
                {
                    return 0;
                }
                displayflag = 1;
                break;
            default:
                continue;
            }
        }
        if (displayflag == 0)
        {
            Sleep(500);
        }
        // system("cls");
    }
    return 0;
}