int cursor_map(int start, int end, int move) // 아이템 커서 이동 기능
{
    int count = 1;
    int y = 0;
    while (1)
    {
        int key = getch();
        if (key == 224 && count >= 1)
        {
            switch (count)
            {
            case 1:
                gotoxy(14, 8);
                printf(" ");
                break;
            case 2:
                gotoxy(36, 11);
                printf(" ");
                break;
            case 3:
                gotoxy(4, 16);
                printf(" ");
                break;

            default:
                break;
            }
            key = getch();
            switch (key)
            {
            case 72:
            {
                count--;
                break;
            }
            case 80:
                count++;
                break;

            default:
                break;
            }
        }
        else if (key == 13)
        {
            return count;
        }
        else if (key == 81 || key == 113)
        {
            return 0;
        }
        if (count < 1)
        {
            count++;
        }
        else if (count > 3)
        {
            count--;
        }

        switch (count)
        {
        case 1:
            gotoxy(14, 8);
            printf(">");
            break;
        case 2:
            gotoxy(36, 11);
            printf(">");
            break;
        case 3:
            gotoxy(4, 16);
            printf(">");
            break;
        default:
            break;
        }
    }
}

void openmap(ItemList *list, Status *status)
{
    while (1)
    {
        system("cls");
        map_banner();
        gotoxy(0, 7);
        FILE *fp = fopen("./gamedata/imgresources/map.txt", "r");

        for (int i = 0; i < 14; i++)
        {
            char str[50];
            fgets(str, 50, fp);
            printf("%s", str);
        }

        key_box(0);
        printf("[↑] 위로 이동\t");
        printf("[↓] 아래로 이동\t");
        gotoxy(68, 24);
        printf("[Q] 나가기\t");

        int num = cursor_map(6, 13, 2);

        switch (num)
        {
        case 0:
        {
            system("cls");
            return;
        }
        case 1:
        {
            system("cls");
            walking(list, status);
            break;
        }
        case 2:
            system("cls");
            miniGameLobby(list);
            break;
        case 3:
            system("cls");
            shop(list);
            break;

        default:
            break;
        }
    }
}
