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
    while (fgets(fileinput, sizeof(fileinput), fp) != 0)
    {
        printf("%s\n", fileinput);
        Sleep(1500);
    }
    fclose(fp);
    experience();
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