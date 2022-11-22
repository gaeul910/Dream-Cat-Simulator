void eraser(int start, int end)
{
    char Eraser[] = "                                            ";
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
    case 4:
    {
        int how_many;
        gotoxy(0, 7);
        printf("구매 갯수 : ");
        scanf("%d", &how_many);
        addItem(1, how_many, itemlist);
        if (itemlist->gold >= (itemlist->itemArr[1].price * how_many))
        {
            itemlist->gold -= (itemlist->itemArr[1].price * how_many);
            printf("추가 완료");
        }
        else
        {
            printf("돈이 더 필요해요!\n");
        }
        break;
    }
    case 5:
    {
        int how_many;
        gotoxy(0, 7);
        printf("구매 갯수 : ");
        scanf("%d", &how_many);
        addItem(2, how_many, itemlist);
        if (itemlist->gold >= (itemlist->itemArr[2].price * how_many))
        {
            itemlist->gold -= (itemlist->itemArr[2].price * how_many);
            printf("추가 완료");
        }
        else
        {
            printf("돈이 더 필요해요!\n");
        }
        break;
    }
    case 6:
    {
        int how_many;
        gotoxy(0, 7);
        printf("구매 갯수 : ");
        scanf("%d", &how_many);
        addItem(3, how_many, itemlist);
        if (itemlist->gold >= (itemlist->itemArr[3].price * how_many))
        {
            itemlist->gold -= (itemlist->itemArr[3].price * how_many);
            printf("추가 완료");
        }
        else
        {
            printf("돈이 더 필요해요!\n");
        }
        break;
    }

    default:
        gotoxy(0, 7);
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
        printf("상점\n");
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
            system("cls");
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