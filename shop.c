
void shop_calcul(ItemList *list, int item_code)
{
    int how_many;
    gotoxy(0, 15);
    printf("구매 갯수 : ");
    scanf("%d", &how_many);
    addItem(item_code, how_many, list);
    if (list->gold >= (list->itemArr[item_code].price * how_many))
    {
        list->gold -= (list->itemArr[item_code].price * how_many);
        printf("추가 완료");
    }
    else
    {
        printf("돈이 더 필요해요!\n");
    }
}

void shop_food(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 먹이 상점\n\n");
    for (int i = 1; i < 4; i++)
    {
        printf(" o %s %d\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
    }

    int num = cursor(8, 14, 2);

    switch (num)
    {
    case 9:
    {
        shop_calcul(itemlist, 1);
        break;
    }
    case 11:
    {

        shop_calcul(itemlist, 2);
        break;
    }
    case 13:
    {
        shop_calcul(itemlist, 3);
        break;
    }

    default:
        gotoxy(0, 15);
        break;
    }

    system("pause");
}

void shop_snack(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 간식 상점\n\n");
    for (int i = 4; i < 6; i++)
    {
        printf(" o %s %d\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
    }

    int num = cursor(8, 12, 2);

    switch (num)
    {
    case 9:
    {
        shop_calcul(itemlist, 4);
        break;
    }
    case 11:
    {

        shop_calcul(itemlist, 5);
        break;
    }

    default:
        gotoxy(0, 15);
        break;
    }

    system("pause");
}

void shop_toy(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 간식 상점\n\n");
    for (int i = 6; i < 9; i++)
    {
        printf(" o %s %d\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
    }

    int num = cursor(8, 14, 2);

    switch (num)
    {
    case 9:
    {
        shop_calcul(itemlist, 6);
        break;
    }
    case 11:
    {

        shop_calcul(itemlist, 7);
        break;
    }
    case 13:
    {
        shop_calcul(itemlist, 8);
    }

    default:
        gotoxy(0, 15);
        break;
    }

    system("pause");
}

void shop(ItemList *itemlist)
{
    while (1)
    {
        system("cls");

        shop_banner();
        gotoxy(0, 7);
        printf(" o 먹이\n\n");
        printf(" o 간식\n\n");
        printf(" o 장난감\n\n");
        printf(" o 기타\n\n");

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
            eraser(7, 10);
            shop_food(itemlist);
            break;
        }
        case 9:
            eraser(7, 10);
            shop_snack(itemlist);
            break;
        case 11:
            eraser(7, 10);
            shop_toy(itemlist);
            break;
        case 13:
            printf("you select item3\n");
            break;

        default:
            break;
        }
    }
}