int getRandomValue(int maxvalue)
{
    if (maxvalue == 0)
    {
        return 0;
    }
    else
    {
        srand(time(NULL));
        return rand() % maxvalue;
    }

    return -1;
}

void gotoxy(int x, int y) // cmd 커서 이동 함수
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int makebannerbox(int colsize)
{
    if (colsize < 2)
    {
        printf("Error: Banner box column size must be bigger than 2");
        return 0;
    }
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    for (int i = 0; i < colsize - 2; i++)
    {
        printf("║                                                                      ║\n");
    }
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    return 0;
}