int interactionMenu(ItemList *list, Status *stats, PlayerData *playerdat)
{
    char input;
    char laststat[128];
    getCurrentStat(stats->laststatcode, stats); // 현재의 상태코드를 laststat에 입력시켜줌 (아직 개발중인 모듈임)
    int randomimg = 0;
    randomimg = getRandomCharacterNum(stats); // 현재 상태에 의거한 랜덤 이미지 번호 뽑아오기
    while (1)
    {
        if (StatUpdate(stats) == 1)
        {
            printStatus(list, stats, playerdat, NULL);
            printCharacter(&randomimg, stats);
            // 여기서부터 키 입력 메뉴 출력 & 입력 받기
            // 반드시 while문 마지막에 스크린 모두 지우기 실행
            printf("[F] 먹이주기    ");
        }
        if (kbhit() == 1)
        {
            input = getch();
            switch (input)
            {
            case 'f':
                food();
                break;
            default:
                continue;
            }
        }
        Sleep(2000);
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
        if (StatUpdate(stats) == 1)
        {
            printStatus(list, stats, playerdat, NULL);
            printCharacter(&randomimg, stats);
            // 여기서부터 키 입력 메뉴 출력 & 입력 받기
            // 반드시 while문 마지막에 스크린 모두 지우기 실행
            printf("[E] 인벤토리");
            printf("[M] 지도 열기");
            printf("[F] 상호 작용");
            printf("[S] 저장하기");
            printf("[O] 옵션");
            printf("%d", randomimg);
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
                // inventory(); //구현 X
                break;
            case 'm':
                // openmap(); //구현 X
                shop(list);
                break;
            case 's':
                system("cls");
                printf("[i] 게임을 저장하고 있습니다...");
                if (saveGame(list, stats) == 0)
                {
                    printf("게임을 성공적으로 저장했습니다!");
                }
                else
                {
                    printf("저장 오류가 발생했습니다.");
                }
                break;
            case 'o':
                // option();
                break;
            default:
                continue;
            }
        }
        Sleep(2000);
        system("cls");
    }
    return 0;
}