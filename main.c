#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
    char name[128];
    int amount;
} item;

typedef struct ItemList
{
    item itemArr[256];
    int itemcount;
    int gold;
} ItemList;

typedef struct Status
{
    int hunger;
    int feeling;
    int health;
    int friendship;
} Status;

typedef struct PlayerData
{
    char playerName[128];
    char dreamCatName[128];
} PlayerData;

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

int addItem(char *itemName, int itemAmount, ItemList *itemlist)
{
    for (int i = 0; i < itemlist->itemcount; i++)
    {
        if (strcmp(itemlist->itemArr[i].name, itemName) == 0)
        {
            itemlist->itemArr[i].amount += itemAmount;
            return 0;
        }
    }

    strcpy(itemlist->itemArr[itemlist->itemcount].name, itemName);
    itemlist->itemArr[itemlist->itemcount].amount = itemAmount;
    itemlist->itemcount++;

    return 0;
}

int saveGame(ItemList *item, Status *status)
{
    FILE *fp = fopen("./savedata/items.txt", "w");
    for (int i = 0; i < item->itemcount; i++)
    {
        fprintf(fp, "%s=%d\n", item->itemArr[i].name, item->itemArr[i].amount);
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
    char temp[256];
    char itemName[128];
    int itemAmount;
    char *ptr;

    items->itemcount = 0;

    FILE *fp = fopen("./savedata/items.txt", "r");
    while (fgets(temp, sizeof(temp), fp) != 0)
    {
        ptr = strtok(temp, "="); // 데이터 형식은 이름=갯수 형식으로 작성
        strcpy(itemName, ptr);   // ex) Potato=10
        ptr = strtok(NULL, "");
        itemAmount = 0;
        for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
        {
            itemAmount *= 10;
            itemAmount += ptr[i] - '0';
        }
        addItem(itemName, itemAmount, items);
    }
    fclose(fp);

    fp = fopen("./savedata/Status_data.txt", "r"); // 상태 불러오기
    while (fgets(temp, sizeof(temp), fp) != 0)
    {
        ptr = strtok(temp, "=");
        strcpy(itemName, ptr);
        ptr = strtok(NULL, "");
        itemAmount = 0;
        for (int i = 0; (ptr[i] != 10) && (ptr[i] != 0); i++)
        {
            itemAmount *= 10;
            itemAmount += ptr[i] - '0';
        }

        switch (Check_StatName(itemName, itemAmount))
        {
        case 1:
            stats->hunger = itemAmount;
            break;
        case 2:
            stats->feeling = itemAmount;
            break;
        case 3:
            stats->health = itemAmount;
            break;
        case 4:
            stats->friendship = itemAmount;
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
    FILE *fp = fopen("./savedata/playerinfo.txt", "w"); //파일을 쓰기로 열기
    scanf("%s", temp);
    fprintf(fp, "PlayerName=%s", temp); //파일로 출력
    scanf("%s", temp);
    fprintf(fp, "DreamCatName=%s", temp); // 파일로 출력

    return 0;
}

int main()
{
    ItemList *itemlist = (ItemList *)malloc(sizeof(ItemList));
    Status *status = (Status *)malloc(sizeof(Status));
    PlayerData *playerdata = (PlayerData *)malloc(sizeof(PlayerData));
    loadGame(itemlist, status, playerdata);

    return 0;
}