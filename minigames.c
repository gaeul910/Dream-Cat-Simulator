int rockscissorspaper()
{
    char input = 0;
    int computerplay = 0;
    computerplay = getRandomValue(3) + 1;
    int playerplay = 0; // sissors = 1, rock = 2, paper = 3
    int result = -2;
    printf("무엇을 내시겠습니까?");
    while (playerplay == 0)
    {
        if (kbhit() == 1)
        {
            input = getch();
            printf("%c", input);
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
                printf("잘못된 입력입니다. 다시 시도하세요.");
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
        result == -1;
    }
    printf("result = %d", result);

    return result;
}

int rockscissorspapermenu(ItemList *items)
{
    items->gold = 10000;
    char input = 0;
    int result = -2;
    int goldinput = 0;
    int currentgold = 0;
    int wincount = 0;
    windowNameBanner("아이템 가위바위보");
    while (result == -2)
    {
        if (kbhit() == 1)
        {
            input = getch();
            if (input == 's')
            {
                while (1)
                {
                    printf("얼마의 Gold를 걸으시겠습니까? >> ");
                    scanf("%d", &goldinput);
                    if (goldinput == 0)
                    {
                        printf("게임을 취소합니다.\n");
                        Sleep(1000);
                        return 0;
                    }
                    else if (items->gold / 11 >= goldinput)
                    {
                        items->gold -= goldinput;
                        printf("게임이 곧 시작됩니다.");
                        Sleep(1000);
                        system("cls");
                        result = rockscissorspaper();
                        break;
                    }
                    else
                    {
                        printf("골드가 부족합니다. 걸 수 있는 골드는 자산의 1/11입니다.\n");
                    }
                }
            }
            else if (input == 'q')
            {
                return 0;
            }
            else
            {
                printf("잘못된 입력입니다. 다시 입력해주세요.");
            }
        }
    }

    while (1)
    {
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
            default:
                printf("잘못된 값입니다.");
                break;
            }
            printf("이겼습니다!\n");
            printf("현재 골드는 %d 골드입니다.\n", currentgold);
            printf("계속 하시겠습니까?");
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
                        printf("%d원을 벌었습니다!", currentgold);
                        items->gold += currentgold;
                        Sleep(3000);
                        return 0;
                    }
                    else
                    {
                        printf("잘못된 입력입니다. 다시 입력해주세요.");
                    }
                }
            }
        }
        else
        {
            printf("알 수 없는 오류가 발생했습니다.");
        }

        // result = -2;
        result = rockscissorspaper(); // 가위바위보 계속 시도
    }

    return 0;
}

int baseball()
{
    int ans[4];
    int input[4];
    int strike = 0;
    int ball = 0;
    int out = 0;
    int count = 0;
    int overlap = 0;
    int i;
    int j;
    for (int a = 0; a < 4; a++)
    {
        ans[a] = getRandomValue(10);
        for (int b = 0; b < a; b++)
        {
            if (ans[a] == ans[b])
            {
                a--;
                break;
            }
        }
    }
    printf("10회 내에 맞히지 못하면 실패합니다!!\n");
    while (1)
    {
        count++;
        printf("%d번째 입력입니다. 숫자 4개를 입력하세요!! : ", count);
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &input[i]);
        }
        for (int c = 1; c < 4; c++)
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
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
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
        if (strike == 4)
        {
            printf("정답을 맞히셨어요!!");
            break;
        }
        else if (out >= 16)
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
        if (count == 10)
        {
            printf("기회를 모두 사용해서 실패입니다...");
            break;
        }
    }
}

int explain()
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
            baseball();
        }
        else if (respond == 1)
        {
            printf("그렇다면, 다시 설명해드리겠습니다.\n");
            explain();
        }
        else
        {
            printf("0과 1중에서만 입력해주세요...\n ");
        }
    }
}
void experience()
{
    int result;
    scanf("%d", &result);
    if (result == 0)
    {
        printf("그렇다면, 추가 설명 없이 바로 숫자야구를 시작하겠습니다!\n");
        Sleep(1000);
        printf("-----------------------------------------------------------------------\n");
        baseball();
    }
    else if (result == 1)
    {
        explain();
    }
    else
    {
        printf("0과 1중에서만 입력해주세요...\n\n");
        experience();
    }
}

int startbaseball()
{
    printf("숫자야구에 오신 것을 환영합니다!\n\n");
    Sleep(1000);
    printf("이전에 숫자야구를 해보신 적이 있나요?\n\n");
    Sleep(1000);
    printf("있다면 0을, 없다면 1을 입력해주세요.\n");
    experience();
}

int miniGameLobby(ItemList *items)
{
    char input[256];
    FILE *fp = fopen("./Minigame_data.txt", "r");
    while (fgets(input, sizeof(input), fp) != 0)
    {
    }
}