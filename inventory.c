int seeinventory(ItemList *itemlist)
{
    typedef struct Inventory
    {
        item inventoryitem[256];
        int inventorycount;
    } Inventory;
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));

    char input;
    char windowName[256];
    int MAXpage = 0;
    int k = 0;
    int currentpage = 1;
    system("cls");

    for (int i = 0; i < itemlist->itemcount; i++)
    {
        if (itemlist->itemArr[i].amount != 0)
        {
            strcpy(inventory->inventoryitem[k].name, itemlist->itemArr[i].name);
            inventory->inventoryitem[k].amount = itemlist->itemArr[i].amount;
            k++;
            inventory->inventorycount = k;
        }
    }
    MAXpage = 1 + (inventory->inventorycount / 10);
    int page = k / 10;
    k = 0;
    sprintf(windowName, "인벤토리 ( 1 / %d )", MAXpage);
    windowNameBanner(windowName);
    for (; k < inventory->inventorycount; k++)
    {
        printf("%s : %d\n", inventory->inventoryitem[k].name, inventory->inventoryitem[k].amount);
        if (k != 0 && (k % 9 == 0 || (k + 1) == inventory->inventorycount))
        {
            if (k == 9 && inventory->inventorycount > 10)
            {
                key_box(1);
                printf("[H] 다음 페이지\n[Q] 나가기\n");
                input = getch();
                if (input == 'h')
                {
                    currentpage++;
                    system("cls");
                    sprintf(windowName, "인벤토리 ( %d / %d )", currentpage, MAXpage);
                    windowNameBanner(windowName);
                }
                else if (input == 'q')
                {
                    return 0;
                }
                else
                {
                    printf("다시 입력해주세요.");
                    input = getch();
                }
            }
            else if ((k + 1) == inventory->inventorycount)
            {
                key_box(1);
                printf("[G] 이전 페이지\n[Q] 나가기");
                while (1)
                {
                    input = getch();
                    if (input == 'g')
                    {
                        currentpage--;
                        k = k - 10 - (k % 10);
                        system("cls");
                        sprintf(windowName, "인벤토리 ( %d / %d )", currentpage, MAXpage);
                        windowNameBanner(windowName);
                        break;
                    }
                    else if (input == 'q')
                    {
                        return 0;
                    }
                    else
                    {
                        printf("다시 입력해주세요.");
                    }
                }
            }
            else if (page == 0 && (k + 1) == inventory->inventorycount)
            {
                printf("[Q] 나가기");
                input = getch();
                if (input == 'q')
                {
                    return 0;
                }
            }
            else
            {
                key_box(0);
                printf("[G] 이전 페이지    [H] 다음 페이지\n[Q] 나가기");
                while (1)
                {
                    input = getch();
                    if (input == 'g')
                    {
                        currentpage--;
                        k = k - 20;
                        system("cls");
                        sprintf(windowName, "인벤토리 ( %d / %d )", currentpage, MAXpage);
                        windowNameBanner(windowName);
                        break;
                    }
                    else if (input == 'h')
                    {
                        currentpage++;
                        system("cls");
                        sprintf(windowName, "인벤토리 ( %d / %d )", currentpage, MAXpage);
                        windowNameBanner(windowName);
                        break;
                    }
                    else if (input == 'q')
                    {
                        return 0;
                    }
                    else
                    {
                        printf("다시 입력해주세요.\n");
                    }
                }
            }
        }
    }
    free(inventory);
}