
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
        printf("\n구매 완료!");
    }
    else
    {
        printf("\n돈이 더 필요해요!\n");
    }
}

void shop_food(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 먹이다옹~\n\n");
    for (int i = 1; i < 4; i++)
    {
        printf(" o %s %dG\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
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
    Sleep(700);
}

void shop_snack(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 간식이다옹~\n\n");
    for (int i = 4; i < 6; i++)
    {
        printf(" o %s %dG\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
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
    Sleep(700);
}

void shop_toy(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 장난감이다옹~\n\n");
    for (int i = 6; i < 9; i++)
    {
        printf(" o %s %dG\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
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

    Sleep(700);
}

void shop_walk(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 산책에 필수다옹~\n\n");
    for (int i = 9; i < 11; i++)
    {
        printf(" o %s %dG\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
    }

    int num = cursor(8, 12, 2);

    switch (num)
    {
    case 9:
    {
        shop_calcul(itemlist, 9);
        break;
    }
    case 11:
    {

        shop_calcul(itemlist, 10);
        break;
    }
    default:
        gotoxy(0, 15);
        break;
    }
    Sleep(700);
}

void shop_minigame(ItemList *itemlist)
{
    eraser(7, 13);
    gotoxy(0, 7);
    printf(" 미니게임에 필요하다옹~\n\n");
    for (int i = 11; i < 13; i++)
    {
        printf(" o %s %dG\n\n", itemlist->itemArr[i].name, itemlist->itemArr[i].price);
    }

    int num = cursor(8, 12, 2);

    switch (num)
    {
    case 9:
    {
        shop_calcul(itemlist, 11);
        break;
    }
    case 11:
    {

        shop_calcul(itemlist, 12);
        break;
    }

    default:
        gotoxy(0, 15);
        break;
    }

    Sleep(700);
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
        printf(" o 산책도구\n\n");
        printf(" o 미니게임\n\n");
        gotoxy(65, 22);
        printf("골드: %d", itemlist->gold);

        key_box(0);
        printf("[↑] 위로 이동\t");
        printf("[↓] 아래로 이동\t");
        gotoxy(68, 24);
        printf("[Q] 나가기\t");

        int num = cursor(6, 15, 2);

        switch (num)
        {
        case 0:
        {
            system("cls");
            return;
        }
        case 7:
        {
            eraser(7, 15);
            shop_food(itemlist);
            break;
        }
        case 9:
            eraser(7, 15);
            shop_snack(itemlist);
            break;
        case 11:
            eraser(7, 15);
            shop_toy(itemlist);
            break;
        case 13:
            eraser(7, 15);
            shop_walk(itemlist);
            break;
        case 15:
            eraser(7, 15);
            shop_minigame(itemlist);
            break;

        default:
            break;
        }
    }
}