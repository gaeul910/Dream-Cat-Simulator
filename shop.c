void eraser(int start, int end)
{
    char Eraser[] = "                       ";
    gotoxy(0, start);
    for (int i = start; i <= end; i++)
    {
        printf("%s\n", Eraser);
    }
}

void shop_food(ItemList *itemlist)
{
    gotoxy(0, 3);
    printf(" 먹이 상점\n");
    for (int i = 1; i < 4; i++)
    {
        printf(" o %s %d\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
    }

    int num = cursor(4, 6);

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

void shop(ItemList *itemlist)
{
    while (1)
    {
        system("cls");

        add_line();
        gotoxy(10, 1);
        printf("상점(임시 인터페이스)\n");
        add_line();
        printf(" 먹이\n");
        printf(" 간식\n");
        printf(" 장난감\n");
        printf(" 기타\n");

        int num = cursor(3, 6);

        switch (num)
        {
        case 0:
        {
            return;
        }
        case 3:
        {
            eraser(3, 6);
            shop_food(itemlist);
            break;
        }
        case 4:
            printf("you select item2\n");
            break;
        case 5:
            printf("you select item3\n");
            break;
        case 6:
            printf("you select item3\n");
            break;

        default:
            break;
        }
    }
}