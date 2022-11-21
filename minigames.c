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
