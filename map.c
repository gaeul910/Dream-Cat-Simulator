void openmap(ItemList *list)
{
    while (1)
    {
        system("cls");
        map_banner();
        gotoxy(0, 7);
        printf(" 상점\n\n");
        printf(" 미니게임\n\n");
        printf(" 이동3\n\n");
        printf(" 이동4\n\n");

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
            miniGameLobby(list);
            break;
        case 11:
            printf("you select item3\n");
            break;
        case 13:
            printf("you select item3\n");
            break;

        default:
            break;
        }
    }
}
