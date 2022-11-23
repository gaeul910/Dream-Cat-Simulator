int seeinventory(ItemList *itemlist)
{
    typedef struct Inventory
    {
        item inventoryitem[256];
        int inventorycount;
    } Inventory;
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));

    char input;
    int MAXpage = 0;
    int k = 0;
    system("cls");

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
    MAXpage = 1 + (inventory->inventorycount / 10);
    int page = k / 10;
    k = 0;
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         인벤토리 ( 1 / %d )                           ║\n", MAXpage);
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    while (1)
    {
        for (k; k < inventory->inventorycount; k++)
        {
            printf("%s : %d\n", inventory->inventoryitem[k].name, inventory->inventoryitem[k].amount);
            if (k % 9 == 0 || k == inventory->inventorycount)
            {
                if (k <= 9 && inventory->inventorycount >= 9)
                {
                    printf("[H] 다음 페이지");
                    if (kbhit() == 1)
                    {
                        input = getch();
                        if (input == 'h')
                        {
                            system("cls");
                            printf("╔══════════════════════════════════════════════════════════════════════╗\n");
                            printf("║                         인벤토리 ( %d / %d )                          ║\n", page, MAXpage);
                            printf("╚══════════════════════════════════════════════════════════════════════╝\n");
                        }
                        else
                        {
                            printf("다시 입력해주세요.");
                            input = getch();
                        }
                    }
                }
                // else if (k == inventory->inventorycount && page == 0)
                // {
                //     system("pause");
                // }
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
                                k = k - 10 - (k % 10);
                                system("cls");
                                printf("╔══════════════════════════════════════════════════════════════════════╗\n");
                                printf("║                         인벤토리 ( %d / %d )                          ║\n", page, MAXpage);
                                printf("╚══════════════════════════════════════════════════════════════════════╝\n");
                                break;
                            }
                            else
                            {
                                printf("다시 입력해주세요.");
                            }
                        }
                    }
                }
                else if (page == 0 && inventory->inventorycount <= 10)
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
                                k = k - 20;
                                system("cls");
                                printf("╔══════════════════════════════════════════════════════════════════════╗\n");
                                printf("║                         인벤토리 ( %d / %d )                          ║\n", page, MAXpage);
                                printf("╚══════════════════════════════════════════════════════════════════════╝\n");
                                break;
                            }
                            else if (input == 'h')
                            {
                                system("cls");
                                printf("╔══════════════════════════════════════════════════════════════════════╗\n");
                                printf("║                         인벤토리 ( %d / %d )                          ║\n", page, MAXpage);
                                printf("╚══════════════════════════════════════════════════════════════════════╝\n");
                                break;
                            }
                            else if (input == 'h')
                                break;
                            else
                            {
                                printf("다시 입력해주세요.\n");
                            }
                        }
                    }
                }
            }
        }
        // Sleep(1000);
    }
    free(inventory);
}