void openmap(ItemList *list)
{
    while (1)
    {
        system("cls");
        map_banner();
        gotoxy(0, 7);
        printf(" 상점\n");
        printf(" 이동2\n");
        printf(" 이동3\n");
        printf(" 이동4\n");

        gotoxy(0, 23);
        add_line();
        printf("[↑] 위로 이동\t");
        printf("[↓] 아래로 이동\t");
        gotoxy(68, 24);
        printf("[Q] 나가기\t");

        int num = cursor(7, 10);

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
        case 8:
            printf("you select item2\n");
            break;
        case 9:
            printf("you select item3\n");
            break;
        case 10:
            printf("you select item3\n");
            break;

        default:
            break;
        }
    }
}
