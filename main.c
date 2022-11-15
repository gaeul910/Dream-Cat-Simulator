#include "gamedata.c"
#include "displaymodule.c"
#include "interaction_system.c"
#include "menus.c"

int getRandomValue(int maxvalue)
{
    srand(time(NULL));
    return rand() % (maxvalue + 1);
}

int Check_StatName(char *StatName, int StatAmount)
{
    if (strcmp("hunger", StatName) == 0)
    {
        return 1;
    }
    else if (strcmp("feeling", StatName) == 0)
    {
        return 2;
    }
    else if (strcmp("health", StatName) == 0)
    {
        return 3;
    }
    else if (strcmp("friendship", StatName) == 0)
    {
        return 4;
    }
    else
        return 0;
}

int addItem(int itemcode, int itemAmount, ItemList *itemlist)
{
    itemlist->itemArr[itemcode].amount += itemAmount;

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
    fprintf(fp, "feeling=%d\n", status->feeling);
    fprintf(fp, "health=%d\n", status->health);
    fprintf(fp, "friendship=%d\n", status->friendship);
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

    printf("%d", sizeof(items->itemArr) / sizeof(item));

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
            stats->feeling = itemValue;
            break;
        case 3:
            stats->health = itemValue;
            break;
        case 4:
            stats->friendship = itemValue;
            break;

        default:
            break;
        }
    }
    fclose(fp);
}

int initGame()
{
    char temp[128];
    FILE *fp = fopen("./savedata/playerinfo.txt", "w"); // 파일을 쓰기로 열기
    scanf("%s", temp);
    fprintf(fp, "PlayerName=%s", temp); // 파일로 출력
    scanf("%s", temp);
    fprintf(fp, "DreamCatName=%s", temp); // 파일로 출력

    return 0;
}

int debug(ItemList *itemlist, Status *status, PlayerData *playerdat)
{
    loadGame(itemlist, status, playerdat);
    for (int i = 0; i < itemlist->itemcount; i++)
    {
        printf("[+] %s %d %d\n", itemlist->itemArr[i].name, itemlist->itemArr[i].amount, itemlist->itemArr[i].price);
    }
    saveGame(itemlist, status);

    return 0;
}

int main()
{
    ItemList *itemlist = (ItemList *)malloc(sizeof(ItemList));
    Status *status = (Status *)malloc(sizeof(Status));
    PlayerData *playerdata = (PlayerData *)malloc(sizeof(PlayerData));
    debug(itemlist, status, playerdata);

    return 0;
}