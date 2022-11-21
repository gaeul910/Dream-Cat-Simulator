int seeinventory(ItemList *itemlist)
{
    typedef struct Inventory
    {
        item inventoryitem[256];
        int inventorycount;
    } Inventory;
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));

    char input;
    int k = 0;
    int page = k / 5;
    int MAXpage = (inventory->inventorycount / 5) + 1;
    inventory->inventorycount = 0;
    printf("===========================================\n");
    printf("             인벤토리 ( 1 / %d )             \n", page + 1);
    printf("===========================================\n");
    for (int i = 0; i < itemlist->itemcount; i++)
    {
        if (itemlist->itemArr[i].amount != 0)
        {
            strcpy(inventory->inventoryitem[k].name, itemlist->itemArr[i].name);
            // printf("%s : %d    ", itemlist->itemArr[i].name, itemlist->itemArr[i].amount);
            inventory->inventoryitem[k].amount = itemlist->itemArr[i].amount;
            k++;
            inventory->inventorycount = k;
            // printf("%s : %d\n", itemlist->itemArr[i].name, itemlist->itemArr[i].amount);
        }
    }
    for (int k = 0; k < inventory->inventorycount; k++)
    {
        printf("%s : %d\n", inventory->inventoryitem[k].name, inventory->inventoryitem[k].amount);
        if (page == 1)
        {
            printf("[H] 다음 페이지");
            if (kbhit() == 1)
            {
                input = getch();
                if (input == 'h')
                {
                    system("cls");
                    printf("===========================================\n");
                    printf("            인벤토리 ( %d / %d )       \n", page, MAXpage);
                    printf("===========================================\n");
                }
                else
                {
                    printf("다시 입력해주세요.");
                    input = getch();
                }
            }
        }
        else if (k == inventory->inventorycount)
        {
            printf("[G] 이전 페이지");
            while (1)
            {
                if (kbhit() == 1)
                {
                    input = getch();
                    if (input == 'g')
                    {
                        k = k - 5 - (k % 5);
                        system("cls");
                        printf("===========================================\n");
                        printf("            인벤토리 ( %d / %d )       \n", page, MAXpage);
                        printf("===========================================\n");
                        break;
                    }
                    else
                    {
                        printf("다시 입력해주세요.");
                    }
                }
            }
        }
        else if (page == 0)
        {
            printf("");
        }
        else
        {
            printf("[G] 이전 페이지    [H] 다음 페이지");
            while (1)
            {
                if (kbhit() == 1)
                {
                    input = getch();
                    if (input == 'g')
                    {
                        k = k - 10;
                        system("cls");
                        printf("===========================================\n");
                        printf("            인벤토리 ( %d / %d )       \n", page, MAXpage);
                        printf("===========================================\n");
                        break;
                    }
                    else if (input == 'h')
                    {
                        system("cls");
                        printf("===========================================\n");
                        printf("            인벤토리 ( %d / %d )       \n", page, MAXpage);
                        printf("===========================================\n");
                        break;
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