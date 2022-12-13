typedef struct miniGameData
{
    time_t rsp_lastPlayed;
} miniGameData;

int rockscissorspaper(ItemList *items)
{
    system("cls");
    windowNameBanner("아이템 가위바위보 - 게임 중");
    char input = 0;
    int computerplay = 0;
    computerplay = getRandomValue(3) + 1;
    int playerplay = 0; // sissors = 1, rock = 2, paper = 3
    int result = -2;
    int selecteditem = -1;
    printf("\n어떤 아이템을 사용하시겠습니까?");
    while (!(selecteditem >= 0 && selecteditem <= 3))
    {
        printf("\n0: 사용하지 않고 진행    1: 무법자    2: 부활\n");
        printf("\n>> ");
        scanf("%d", &selecteditem);

        switch (selecteditem)
        {
        case 0:
            break;
        case 1:
            if (items->itemArr[11].amount > 0)
            {
                items->itemArr[11].amount--;
                printf("\n무법자를 사용하여 게임을 진행합니다.\n");
            }
            else
            {
                printf("\n무법자 아이템이 부족합니다.");
                selecteditem = -1;
            }
            break;
        case 2:
            if (items->itemArr[11].amount > 0)
            {
                items->itemArr[11].amount--;
                printf("\n부활을 사용하여 게임을 진행합니다.\n");
            }
            else
            {
                printf("\n부활 아이템이 부족합니다.");
                selecteditem = -1;
            }
            // 부활 코드
            break;
        case 3:
            printf("\n미래를 보는 눈을 사용하여 게임을 진행합니다.\n");
            // 미래를 보는 눈
            break;
        default:
            printf("\n잘못된 입력입니다. 다시 입력해주세요!\n");
            break;
        }
    }
    printf("무엇을 내시겠습니까?\n");
    key_box(0);
    printf("[R] 바위   [S] 가위    [P] 보");
    while (playerplay == 0)
    {
        if (kbhit() == 1)
        {
            input = getch();
            switch (input)
            {
            case 's':
                playerplay = 1;
                break;
            case 'r':
                playerplay = 2;
                break;
            case 'p':
                playerplay = 3;
                break;
            default:
                gotoxy(0, 21);
                printf("\n잘못된 입력입니다. 다시 시도하세요.\n");
                Sleep(1500);
                eraser(21, 21);
                break;
            }
        }
    }

    // 가위바위보 플레이창 디자인

    if (playerplay == computerplay)
    {
        result = 0;
    }
    else if (playerplay == 1 && computerplay == 3)
    {
        result = 1;
    }
    else if (playerplay == 1 && computerplay == 2)
    {
        result = -1;
    }
    else if (playerplay == 2 && computerplay == 1)
    {
        result = 1;
    }
    else if (playerplay == 2 && computerplay == 3)
    {
        result = -1;
    }
    else if (playerplay == 3 && computerplay == 2)
    {
        result = 1;
    }
    else if (playerplay == 3 && computerplay == 1)
    {
        result = -1;
    }

    if (result == -1 && selecteditem == 2)
    {
        return 2;
    }
    else if (result == 0 && selecteditem == 1)
    {
        return 1;
    }
    else
    {
        return result;
    }

    return -2;
}

int rockscissorspapermenu(ItemList *items)
{
    system("cls");
    char input = 0;
    int result = -2;
    int goldinput = 0;
    int currentgold = 0;
    int wincount = 0;
    windowNameBanner("아이템 가위바위보");
    fileprint("./gamedata/imgresources/rsp_mainscreen.txt");
    key_box(0);
    printf("[S] 시작하기                    [Q] 나가기");
    while (result == -2)
    {
        if (kbhit() == 1)
        {
            input = getch();
            if (input == 's')
            {
                while (1)
                {
                    eraser(3, 24);
                    gotoxy(0, 4);
                    printf("얼마의 Gold를 걸으시겠습니까?\n\n>> ");
                    scanf("%d", &goldinput);
                    if (goldinput == 0)
                    {
                        printf("\n게임을 취소합니다.\n");
                        Sleep(1000);
                        return 0;
                    }
                    else if (items->gold / 11 >= goldinput)
                    {
                        items->gold -= goldinput;
                        printf("\n게임이 곧 시작됩니다.");
                        Sleep(1000);
                        system("cls");
                        result = rockscissorspaper(items);
                        break;
                    }
                    else
                    {
                        printf("Gold가 부족합니다. 걸 수 있는 Gold는 자산의 1/11입니다.\n");
                        Sleep(1000);
                    }
                }
            }
            else if (input == 'q')
            {
                return 0;
            }
            else
            {
                gotoxy(0, 21);
                printf("잘못된 입력입니다. 다시 입력해주세요.");
                Sleep(1500);
                eraser(21, 21);
            }
        }
    }

    while (1)
    {
        system("cls");
        windowNameBanner("아이템 가위바위보");
        Sleep(1000);
        eraser(3, 24);
        gotoxy(0, 4);
        if (result == -1)
        {
            // 가위바위보 실패창 디자인
            printf("실패..");
            Sleep(3000);
            return 0;
        }
        else if (result == 0)
        {
            // 가위바위보 비김창 디자인
            printf("비겼습니다. 다시!");
            Sleep(3000);
        }
        else if (result == 1)
        {
            // 가위바위보 성공창 디자인
            wincount++;
            switch (wincount)
            {
            case 1:
                currentgold = goldinput * 2;
                break;
            case 2:
                currentgold = goldinput * 4;
                break;
            case 3:
                currentgold = goldinput * 7;
                break;
            case 4:
                currentgold = goldinput * 11;
                break;
            case 5:
                printf("[i] 최대 시도 횟수 4회를 넘겼습니다!\n");
                printf("%d Gold를 벌었습니다!\n", currentgold);
                printf("운이 좋았군요!\n");
                Sleep(3000);
                return 0;
            default:
                printf("잘못된 값입니다.");
                break;
            }

            printf("이겼습니다!\n");
            printf("현재 Gold는 %d 골드입니다.\n", currentgold);
            printf("계속 하시겠습니까?\n");
            key_box(0);
            printf("[C] 계속하기    [Q] 그만하기");
            while (1)
            {
                if (kbhit() == 1)
                {
                    input = getch();
                    if (input == 'c')
                    {
                        break; // 아래의 가위바위보 다음 시도 실행
                    }
                    else if (input == 'q')
                    {
                        gotoxy(0, 10);
                        printf("\n%dGold를 벌었습니다!", currentgold);
                        items->gold += currentgold;
                        Sleep(3000);
                        return 0;
                    }
                    else
                    {
                        gotoxy(0, 21);
                        printf("잘못된 입력입니다. 다시 입력해주세요.");
                        Sleep(1500);
                        eraser(21, 21);
                    }
                }
            }
        }
        else if (result == 2)
        {
            printf("실패..\n");
            Sleep(1000);
            printf("그러나 부활을 사용하였습니다!\n");
            printf("게임을 쿨타임 없이 바로 진행할 수 있습니다!\n");
            printf("현재 Gold는 %d Gold입니다.\n", goldinput);
            Sleep(1500);

            while (1)
            {
                eraser(3, 24);
                gotoxy(0, 4);
                printf("얼마의 Gold를 걸으시겠습니까?\n취소하려면 0을 입력하세요.\n\n>> ");
                scanf("%d", &goldinput);
                if (goldinput == 0)
                {
                    printf("\n게임을 취소합니다.\n");
                    Sleep(1000);
                    return 0;
                }
                else if (items->gold / 11 >= goldinput)
                {
                    items->gold -= goldinput;
                    printf("\n게임이 곧 시작됩니다.");
                    Sleep(1000);
                    system("cls");
                    // result = rockscissorspaper(items);
                    break;
                }
                else
                {
                    printf("Gold가 부족합니다. 걸 수 있는 Gold는 자산의 1/11입니다.\n");
                }
            }
        }
        else
        {
            printf("알 수 없는 오류가 발생했습니다.");
            Sleep(1000);
            items->gold += goldinput;
            return -1;
        }

        // result = -2;
        result = rockscissorspaper(items); // 가위바위보 계속 시도
    }

    return 0;
}

int baseball(ItemList *items)
{
    int ans[5];
    int input[5];
    int strike = 0;
    int ball = 0;
    int out = 0;
    int count = 0;
    int overlap = 0;
    int i;
    int j;
    int difficulty;
    int size;
    int chance;
    int outcount;
    int cheat = 0;
    int reward;
    system("cls");
    printf("어떤 난이도로 하실건가요? 어려운 난이도일수록 보상이 늘어납니다!\n\n");
    Sleep(1000);
    printf("쉬움 난이도 : 3개의 숫자를 맞혀야 하며, 8번의 기회가 주어집니다.\n\n");
    Sleep(1000);
    printf("보통 난이도 : 4개의 숫자를 맞혀야 하며, 10번의 기회가 주어집니다.\n\n");
    Sleep(1000);
    printf("어려움 난이도 : 5개의 숫자를 맞혀야 하며, 12번의 기회가 주어집니다.\n\n");
    Sleep(1000);
    printf("이제 난이도를 선택해주세요!(쉬움 : 0  보통 : 1  어려움 : 2)\n");
    while (1)
    {
        scanf("%d", &difficulty);
        if (difficulty == 0)
        {
            printf("쉬움 난이도로 선택하셨습니다.\n");
            Sleep(1000);
            size = 3;
            chance = 8;
            outcount = 9;
            break;
        }
        else if (difficulty == 1)
        {
            printf("보통 난이도로 선택하셨습니다.\n");
            Sleep(1000);
            size = 4;
            chance = 10;
            outcount = 16;
            break;
        }
        else if (difficulty == 2)
        {
            printf("어려움 난이도로 선택하셨습니다! 무운을 빌게요!\n");
            Sleep(1000);
            size = 5;
            chance = 12;
            outcount = 25;
            break;
        }
        else
        {
            printf("0, 1, 2 중에서만 입력해주세요...\n");
        }
    }
    system("cls");
    srand((unsigned int)time(NULL));
    for (int a = 0; a < 5; a++)
    {
        ans[a] = rand() % 9;
        for (int b = 0; b < a; b++)
        {
            if (ans[a] == ans[b])
            {
                ans[a] = rand() % 9;
                a--;
                break;
            }
        }
    }
    printf("%d회 내에 맞히지 못하면 실패합니다!!\n", chance);
    while (1)
    {
        count++;
        printf("%d번째 입력입니다. 숫자 %d개를 입력하세요!! : ", count, size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &input[i]);
        }

        for (int c = 0; c < size; c++)
        {
            if (input[c] == 0)
            {
                cheat++;
            }
        }
        if (cheat == size)
        {
            printf("치트모드 발동!!!!!!\n\n");
            Sleep(1000);
            printf("답을 알려드리겠습니다!\n\n");
            Sleep(1000);
            for (int i = 0; i < size; i++)
            {
                printf("%d ", ans[i]);
            }
            Sleep(1000);
            printf("\n\n너무 치트모드를 자주 사용하시면 게임의 재미가 떨어질 수 있습니다...\n\n");
            Sleep(1000);
            printf("그러니까 치트모드는 적당히!! 사용해주세요... :)\n\n");
            count--;
            overlap = 0;
            cheat = 0;
            continue;
        }

        for (int c = 1; c < size; c++)
        {
            for (int d = 0; d < c; d++)
            {
                if (input[c] == input[d])
                {
                    overlap++;
                }
            }
        }
        if (overlap > 0)
        {
            printf("중복된 숫자를 입력하면 안 됩니다!! \n");
            overlap = 0;
            count--;
            continue;
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if ((ans[i] == input[j]) && i == j)
                {
                    strike++;
                }
                if ((ans[i] == input[j]) && i != j)
                {
                    ball++;
                }
                if ((ans[i]) != input[j])
                {
                    out++;
                }
            }
        }
        if (strike == size)
        {
            printf("정답을 맞히셨어요!!");
            Sleep(1500);
            if (size == 3)
            {
                reward = 1000 + 100 * (chance - count);
                printf("보상으로 %d골드를 획득했습니다! (기본 1000골드 + 남은 기회 비례 보너스 %d골드", reward, 100 * (chance - count));
            }
            else if (size == 4)
            {
                reward = 1500 + 150 * (chance - count);
                printf("보상으로 %d골드를 획득했습니다! (기본 1000골드 + 남은 기회 비례 보너스 %d골드", reward, 150 * (chance - count));
            }
            else
            {
                reward = 2000 + 200 * (chance - count);
                printf("보상으로 %d골드를 획득했습니다! (기본 1000골드 + 남은 기회 비례 보너스 %d골드", reward, 200 * (chance - count));
            }
            items->gold += reward;
            Sleep(2000);

            break;
        }
        else if (out >= outcount)
        {
            printf("아웃입니다!\n");
            out = 0;
            strike = 0;
            ball = 0;
        }
        else
        {
            printf("%d스트라이크 %d볼입니다!!\n", strike, ball);
            out = 0;
            strike = 0;
            ball = 0;
        }
        if (count == chance)
        {
            printf("기회를 모두 사용해서 실패입니다...");
            break;
        }
    }
}

int explain(ItemList *items)
{
    int respond;
    char fileinput[256];
    FILE *fp = fopen("./gamedata/textresources/baseballtutorial.txt", "r");
    if (fp == NULL)
        printf("File is NULL");
    while (fgets(fileinput, sizeof(fileinput), fp) != 0)
    {
        printf("%s\n", fileinput);
        Sleep(1500);
    }
    fclose(fp);
    while (1)
    {
        scanf("%d", &respond);
        if (respond == 0)
        {
            printf("이해하셨다니 다행입니다!!\n");
            Sleep(1000);
            printf("그렇다면, 이제부터 숫자야구를 시작하겠습니다!\n");
            Sleep(1000);
            printf("-----------------------------------------------------------------------\n");
            baseball(items);
        }
        else if (respond == 1)
        {
            printf("그렇다면, 다시 설명해드리겠습니다.\n");
            explain(items);
        }
        else
        {
            printf("0과 1중에서만 입력해주세요...\n ");
        }
    }
}
void experience(ItemList *items)
{
    int result;
    scanf("%d", &result);
    if (result == 0)
    {
        printf("그렇다면, 추가 설명 없이 바로 숫자야구를 시작하겠습니다!\n");
        Sleep(1000);
        baseball(items);
    }
    else if (result == 1)
    {
        explain(items);
    }
    else
    {
        printf("0과 1중에서만 입력해주세요...\n\n");
        experience(items);
    }
}

int startbaseball(ItemList *items)
{
    windowNameBanner("숫자 야구");
    printf("숫자야구에 오신 것을 환영합니다!\n\n");
    Sleep(1000);
    printf("이전에 숫자야구를 해보신 적이 있나요?\n\n");
    Sleep(1000);
    printf("있다면 0을, 없다면 1을 입력해주세요.\n");
    experience(items);
}

int saveMinigameData(miniGameData *minigamedata)
{
    FILE *fp = fopen("./savedata/Minigame_data.txt", "w");
    fprintf(fp, "rsp_lastplayed=%d", minigamedata->rsp_lastPlayed);
    fclose(fp);

    return 0;
}

int loadMinigameData(miniGameData *gamedata)
{
    char *ptr = 0;
    char itemName[256];
    FILE *fp = fopen("./savedata/Minigame_data.txt", "r");
    char input[256];

    if (fp != NULL)
    {
        while (fgets(input, sizeof(input), fp) != 0)
        {
            ptr = strtok(input, "=");
            strcpy(itemName, ptr);
            ptr = strtok(NULL, "");

            if (strcmp(itemName, "rsp_lastplayed") == 0)
            {
                gamedata->rsp_lastPlayed = 0;
                for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
                {
                    gamedata->rsp_lastPlayed *= 10;
                    gamedata->rsp_lastPlayed += ptr[i] - '0';
                }
            }
        }
    }
    else
    {
        gamedata->rsp_lastPlayed = 0;
    }
    fclose(fp);

    return 0;
}

int miniGameLobbyDisplay()
{
    system("cls");

    windowNameBanner("미니게임 로비");
    fileprint("./gamedata/imgresources/minigameLobby");
    key_box(0);
    printf("[1] 아이템 가위바위보    ");
    printf("[2] 숫자야구               ");
    printf("[Q] 이전");
}

int miniGameLobby(ItemList *items)
{
    char input[256];
    char keyinput = 0;
    miniGameData *gamedata = (miniGameData *)malloc(sizeof(miniGameData));
    loadMinigameData(gamedata);

    while (1)
    {
        miniGameLobbyDisplay();
        keyinput = getch();
        switch (keyinput)
        {
        case '1':
            if (time(NULL) - gamedata->rsp_lastPlayed > 300)
            {
                rockscissorspapermenu(items);
                gamedata->rsp_lastPlayed = time(NULL);
                saveMinigameData(gamedata);
            }
            else
            {
                gotoxy(0, 21);
                printf("오류: 쿨타임이 끝나지 않았습니다.\n다음 게임은 %d초 후 진행할 수 있습니다.", 300 - (time(NULL) - gamedata->rsp_lastPlayed));
                Sleep(1500);
                eraser(21, 22);
            }
            break;
        case '2':
        {
            system("cls");
            startbaseball(items);
            break;
        }
        case 'q':
            return 0;
            break;
        default:
            break;
        }
    }
}