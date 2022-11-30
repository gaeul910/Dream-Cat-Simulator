int exitGameMenu(ItemList *items, Status *stats)
{
    windowNameBanner("게임 종료");
    printf("정말로 게임을 종료하시겠어요?");
    while (1)
    {
        system("cls");
        windowNameBanner("옵션");
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
    randomimg = getRandomCharacterNum(stats); // 현재 상태에 의거한 랜덤 이미지 번호 뽑아오기
    while (1)
    {
        if (StatUpdate(stats, 1) == 1)
        {
            printStatus(list, stats, playerdat, NULL);
            printCharacter(&randomimg, stats);
            // 여기서부터 키 입력 메뉴 출력 & 입력 받기
            // 반드시 while문 마지막에 스크린 모두 지우기 실행
            key_box(0);
            printf("[F] 먹이주기    ");
            printf("[G] 놀아주기    ");
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
                break;
            case 'G': // 임시할당
            case 'g':
                playing(list, stats);
                break;
            default:
                continue;
            }
        }
        Sleep(1000);
        system("cls");
    }
    return 0;
}
int mainMenu(ItemList *list, Status *stats, PlayerData *playerdat)
{
    Status *oldStats = (Status *)malloc(sizeof(Status));
    char input;

    getCurrentStat(stats->laststatcode, stats); // 현재의 상태코드를 laststat에 입력시켜줌 (아직 개발중인 모듈임)
    int randomimg = 0;
    randomimg = getRandomCharacterNum(stats); // 현재 상태에 의거한 랜덤 이미지 번호 뽑아오기
    while (1)
    {
        if (StatUpdate(stats, 1) == 1)
        {
            printStatus(list, stats, playerdat, NULL);
            printCharacter(&randomimg, stats);
            // 여기서부터 키 입력 메뉴 출력 & 입력 받기
            // 반드시 while문 마지막에 스크린 모두 지우기 실행
            key_box(1);
            printf("[E] 인벤토리    ");
            printf("[M] 지도 열기    ");
            printf("[F] 상호 작용    ");
            printf("\n");
            printf("[S] 저장하기    ");
            printf("[O] 옵션");
            gotoxy(60, 23);
            printf("[Q] 나가기\t");
        }
        if (kbhit() == 1)
        {
            input = getch();
            switch (input)
            {
            case 'f':
                interactionMenu(list, stats, playerdat);
                break;
            case 'e':
                seeinventory(list);
                break;
            case 'm':
                openmap(list);
                break;
            case 's':
                system("cls");
                printf("[i] 게임을 저장하고 있습니다.\n");
                if (saveGame(list, stats) == 0)
                {
                    printf("게임을 성공적으로 저장했습니다!\n");
                }
                else
                {
                    printf("저장 오류가 발생했습니다.");
                }
                break;
            case 'o':
                optionsMenu(list, stats, playerdat);
                break;
            case 'q':
                if (exitGameMenu(list, stats) == 1)
                {
                    return 0;
                }
                break;
            default:
                continue;
            }
        }
        Sleep(1000);
        system("cls");
    }
    return 0;
}