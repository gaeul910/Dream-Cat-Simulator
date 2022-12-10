int Check_StatName(char *StatName, int StatAmount)
{
    if (strcmp("hunger", StatName) == 0)
    {
        return 1;
    }
    else if (strcmp("normal", StatName) == 0)
    {
        return 2;
    }
    else if (strcmp("delight", StatName) == 0)
    {
        return 3;
    }
    else if (strcmp("sadness", StatName) == 0)
    {
        return 4;
    }
    else if (strcmp("anger", StatName) == 0)
    {
        return 5;
    }
    else if (strcmp("friendship", StatName) == 0)
    {
        return 6;
    }
    else if (strcmp("health", StatName) == 0)
    {
        return 7;
    }
    else if (strcmp("savetime", StatName) == 0)
    {
        return 8;
    }
    else
        return 0;
}

int saveGame(ItemList *item, Status *status)
{
    FILE *fp = fopen("./savedata/items.txt", "w");
    for (int i = 0; i < item->itemcount; i++)
    {
        fprintf(fp, "%d=%d\n", i, item->itemArr[i].amount);
    }
    fclose(fp);

    fp = fopen("./savedata/Status_data.txt", "w");
    fprintf(fp, "hunger=%d\n", status->hunger);
    fprintf(fp, "normal=%d\n", status->normal);
    fprintf(fp, "delight=%d\n", status->delight);
    fprintf(fp, "sadness=%d\n", status->sadness);
    fprintf(fp, "anger=%d\n", status->anger);
    fprintf(fp, "health=%d\n", status->health);
    fprintf(fp, "friendship=%d\n", status->friendship);
    fprintf(fp, "savetime=%d", time(NULL));
    fclose(fp);

    fp = fopen("./savedata/gold.txt", "w");
    fprintf(fp, "gold=%d", item->gold);
    fclose(fp);

    return 0;
}

int loadGame(ItemList *items, Status *stats, PlayerData *playerdat)
{
    char input[256];
    int temp = 0;
    int itemValue = 0;
    char itemName[128];
    char *ptr;
    int itemcode = 0;
    items->itemcount = 0;

    for (int i = 0; i < sizeof(items->itemArr) / sizeof(item); i++)
    {
        items->itemArr[i].amount = 0;
        items->itemArr[i].price = 0;
    }

    FILE *fp = fopen("./gamedata/iteminfo.txt", "r");

    while (fgets(input, sizeof(input), fp) != 0)
    {
        ptr = strtok(input, "="); // 데이터 형식은 이름=갯수 형식으로 작성
        itemcode = 0;
        for (int i = 0; ptr[i] != 0; i++)
        {
            itemcode *= 10;
            itemcode += ptr[i] - '0';
        }

        ptr = strtok(NULL, "=");

        strcpy(items->itemArr[itemcode].name, ptr);

        ptr = strtok(NULL, "=");
        itemValue = 0;
        for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
        {
            itemValue *= 10;
            itemValue += ptr[i] - '0';
        }
        items->itemArr[itemcode].price = itemValue;

        items->itemcount++;
    }

    fp = fopen("./savedata/items.txt", "r");
    while (fgets(input, sizeof(input), fp) != 0)
    {
        ptr = strtok(input, "="); // 데이터 형식은 이름=갯수 형식으로 작성
        itemcode = 0;
        for (int i = 0; ptr[i] != 0; i++)
        {
            itemcode *= 10;
            itemcode += ptr[i] - '0';
        }

        ptr = strtok(NULL, "");
        itemValue = 0;
        for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
        {
            itemValue *= 10;
            itemValue += ptr[i] - '0';
        }
        addItem(itemcode, itemValue, items);
    }
    fclose(fp);

    fp = fopen("./savedata/Status_data.txt", "r"); // 상태 불러오기
    while (fgets(input, sizeof(input), fp) != 0)
    {
        ptr = strtok(input, "=");
        strcpy(itemName, ptr);
        ptr = strtok(NULL, "");
        itemValue = 0;
        for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
        {
            itemValue *= 10;
            itemValue += ptr[i] - '0';
        }

        switch (Check_StatName(itemName, itemValue))
        {
        case 1:
            stats->hunger = itemValue;
            break;
        case 2:
            stats->normal = itemValue;
            break;
        case 3:
            stats->delight = itemValue;
            break;

        case 4:
            stats->sadness = itemValue;
            break;
        case 5:
            stats->anger = itemValue;
            break;
        case 6:
            stats->friendship = itemValue;
            break;
        case 7:
            stats->health = itemValue;
            break;
        case 8:
            stats->updatetime = (time_t)itemValue;
            StatUpdate(stats, 0);
            break;
        default:
            break;
        }
    }
    fclose(fp);

    fp = fopen("./savedata/Player_data.txt", "r"); // 상태 불러오기
    while (fgets(input, sizeof(input), fp) != 0)
    {
        ptr = strtok(input, "=");
        strcpy(itemName, ptr);
        ptr = strtok(NULL, "");
        itemValue = 0;

        if (strcmp(itemName, "PlayerName") == 0)
        {
            strcpy(playerdat->playerName, ptr);
        }
        else if (strcmp(itemName, "CatName") == 0)
        {
            strcpy(playerdat->dreamCatName, ptr);
        }
    }
    fclose(fp);

    fp = fopen("./savedata/gold.txt", "r");
    while (fgets(input, sizeof(input), fp) != 0)
    {
        ptr = strtok(input, "=");
        strcpy(itemName, ptr);
        ptr = strtok(NULL, "");

        if (strcmp(itemName, "gold") == 0)
        {
            for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
            {
                itemValue *= 10;
                itemValue += ptr[i] - '0';
            }
            items->gold = itemValue;
        }
    }
    fclose(fp);

    stats->updatetime = time(NULL); // 추후 흘러간 시간 계산 후 마지막에 수행

    return 0;
}

int initGame(ItemList *items, Status *stats, PlayerData *playerdat, int doinit)
{
    char temp[128];
    FILE *er = fopen("./savedata/player_data.txt", "r");
    if ((er = fopen("./savedata/player_data.txt", "r")) == NULL || doinit == 1)
    {
        fclose(er);
        FILE *fp = fopen("./savedata/player_data.txt", "w"); // 파일을 쓰기로 열기
        printf("╔══════════════════════════════════════════════════════════════════════╗\n");
        printf("║             Dream-Cat-Simulator에 오신 것을 환영합니다!              ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════╝\n\n");
        printf("사용자 이름을 입력해주세요!\n");
        fgets(temp, sizeof(temp), stdin);
        strcpy(playerdat->playerName, temp);
        fprintf(fp, "PlayerName=%s", temp);
        printf("개냥이 이름을 입력해주세요!\n");
        fgets(temp, sizeof(temp), stdin);
        strcpy(playerdat->dreamCatName, temp);
        fprintf(fp, "DreamCatName=%s", temp);
        fclose(fp);
        stats->hunger = 1000;
        stats->health = 1000;
        stats->delight = 500;
        stats->normal = 750;
        stats->sadness = 0;
        stats->anger = 0;
        stats->friendship = 0;
        items->gold = 0;
        saveGame(items, stats);
        system("cls");
        return 1;
    }
    else
    {
        fclose(er);
        return 0;
    }
}

int gamereset()
{
}