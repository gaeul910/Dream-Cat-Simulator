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

int removeEnter(char *input)
{
    int i = 0;
    for (i = 0; input[i] != 10 && input[i] != 0; i++)
    {
        continue;
    }
    if (input[i] == 10)
    {
        input[i] = 0;
        return 1;
    }
    else if (input[i] == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }

    return -1;
}

void add_line() // 줄 만들기
{
    for (int i = 1; i < 80; i++)
    {
        printf("═");
    }
    printf("\n");
}

void key_box(int position)
{
    gotoxy(0, 23 - position);
    add_line();
}

void eraser(int start, int end)
{
    char Eraser[] = "                                                                               ";
    gotoxy(0, start);
    for (int i = start; i <= end; i++)
    {
        printf("%s\n", Eraser);
    }
}

int fileprint(char *filedir)
{
    char input[256];
    FILE *fp = fopen(filedir, "r");
    if (fp == NULL)
    {
        printf("Error: File does not exist.");
        return -1;
    }
    while (fgets(input, sizeof(input), fp) != 0)
    {
        printf("%s", input);
    }

    return 0;
}