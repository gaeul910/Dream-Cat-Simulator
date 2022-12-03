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

        int num = cursor(6, 13, 2);

        switch (num)
        {
        case 0:
        {
            system("cls");
            return;
        }
        case 7:
        {
            system("cls");
            shop(list);
            break;
        }
        case 9:
            system("cls");
            miniGameLobby(list);
            break;
        case 11:
            system("cls");
            walking(list, status);
            break;
        case 13:
            printf("you select item3\n");
            break;

        default:
            break;
        }
    }
}
