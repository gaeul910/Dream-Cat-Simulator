int changePlayerData(PlayerData *playerdat)
{
    system("cls");
    windowNameBanner("이름 변경");
    // key_box(0);
    // printf("[Q] 나가기");
    char input[256];
    int changecount = 0;

    gotoxy(0, 4);
    printf("[i] 기존 이름을 유지하려면 공백으로 입력하세요!\n\n");
    printf("새로운 사용자 이름을 입력하세요!\n\n");

    fgets(input, sizeof(input), stdin);
    removeEnter(input);
    if (strcmp(input, "") != 0)
    {
        strcpy(playerdat->playerName, input);
        changecount++;
    }
    else
    {
        printf("\n이름을 변경하지 않았습니다.");
    }

    printf("\n새로운 개냥이 이름을 입력하세요!\n\n");

    fgets(input, sizeof(input), stdin);
    removeEnter(input);
    if (strcmp(input, "") != 0)
    {
        strcpy(playerdat->dreamCatName, input);
        changecount++;
    }
    else
    {
        printf("\n이름을 변경하지 않았습니다.");
    }
    strcpy(playerdat->dreamCatName, input);

    if (changecount > 0)
    {
        FILE *fp = fopen("./savedata/Player_data.txt", "w");
        fprintf(fp, "PlayerName=%s\n", playerdat->playerName);
        fprintf(fp, "CatName=%s", playerdat->dreamCatName);
        fclose(fp);
        printf("\n이름이 성공적으로 변경되었습니다!");
        Sleep(1500);
    }
    else
    {
        printf("변경한 이름이 없습니다.");
        Sleep(1500);
    }

    return 0;
}

int runResetGame(ItemList *items, Status *stats, PlayerData *playerdat)
{
    FILE *fp = fopen("./savedata/items.txt", "w");
    fclose(fp);
    fp = fopen("./savedata/Minigame_data.txt", "w");
    fclose(fp);
    fp = fopen("./savedata/Player_data.txt", "w");
    fclose(fp);
    fp = fopen("./savedata/Status_data.txt", "w");
    fclose(fp);

    system("cls");
    initGame(items, stats, playerdat, 1);

    saveGame(items, stats);

    return 0;
}

int resetGame(ItemList *items, Status *stats, PlayerData *playerdat)
{
    system("cls");
    windowNameBanner("게임 초기화");
    char input = 0;
    printf("경고: 해당 동작을 수행할 경우, 현재 진행 상황이 모두 초기화됩니다.\n\n정말 계속하시겠습니까?");
    key_box(0);
    printf("[Y] 계속    ");
    printf("[N] 취소");

    while (1)
    {
        input = getch();
        switch (input)
        {
        case 'y':
            runResetGame(items, stats, playerdat);
            return 1;
        case 'n':
            return 0;
        default:
            gotoxy(0, 22);
            printf("오류: 잘못된 입력입니다.");
            Sleep(1500);
            eraser(22, 22);
            break;
        }
    }
}

int optionsMenu(ItemList *items, Status *stats, PlayerData *playerdat)
{
    while (1)
    {
        system("cls");
        windowNameBanner("옵션");
        gotoxy(0, 7);
        printf(" 이름 변경\n\n");
        printf(" 게임 초기화\n\n");

        key_box(0);
        printf("[↑] 위로 이동\t");
        printf("[↓] 아래로 이동\t");
        gotoxy(68, 24);
        printf("[Q] 나가기\t");

        int num = cursor(6, 9, 2);

        switch (num)
        {
        case 0:
            system("cls");
            return 0;
        case 7:
        {
            system("cls");
            changePlayerData(playerdat);
            break;
        }
        case 9:
        {
            resetGame(items, stats, playerdat);
            break;
        }
        case 8:
            printf("you select item2\n");
            break;
        case 10:
            printf("you select item3\n");
            break;

        default:
            break;
        }
    }
}