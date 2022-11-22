

int cursor(int start, int end) // 아이템 커서 이동 기능
{
    int x = 0;
    int y = start + 1;
    while (1)
    {
        int key = getch();
        if (key == 224 && y > 2)
        {
            gotoxy(x, y);
            printf(" ");
            key = getch();
            switch (key)
            {
            case 72:
            {
                y--;
                break;
            }
            case 80:
                y++;
                break;

            default:
                break;
            }
        }
        else if (key == 13)
        {
            return y;
        }
        else if (key == 81 || key == 113)
        {
            return 0;
        }
        if (y < start)
        {
            y++;
        }
        else if (y > end)
        {
            y--;
        }
        gotoxy(x, y);
        printf(">");
    }
}

void add_line() //(임시) 줄 만들기
{
    for (int i = 0; i < 26; i++)
    {
        printf("=");
    }
    printf("\n");
}

void food()
{
    system("cls");
    add_line();
    gotoxy(10, 1);
    printf("소지품\n");
    add_line();
    printf(" 1. item 1\n");
    printf(" 2. item 2\n");
    printf(" 3. item 3\n");

    int num = cursor(3, 5);

    switch (num)
    {
    case 3:
        printf("you select item1\n");
        break;
    case 4:
        printf("you select item2\n");
        break;
    case 5:
        printf("you select item3\n");
        break;

    default:
        break;
    }

    system("pause");
}