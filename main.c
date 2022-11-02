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

int addItem(char *itemName, int itemAmount, ItemList *itemlist)
{
    for (int i = 0; i < itemlist->itemcount; i++)
    {
        if (strcmp(itemlist->itemArr[i].name, itemName))
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

int saveGame()
{
}

int loadGame(ItemList *items, Status *stats, PlayerData *playerdat)
{
    char temp[256];
    char itemName[128];
    int itemAmount;
    char *ptr;

    FILE *fp = fopen("./savedata/items.txt", "r");
    while (fgets("temp", sizeof(temp), fp) != 0)
    {
        ptr = strtok(temp, ",");
        strcpy(itemName, ptr);
        ptr = strtok(NULL, "");
        itemAmount = 0;
        for (int i = 0; ptr[i] != 0; i++)
        {
            itemAmount *= 10;
            itemAmount += ptr[i] - '0';
        }
        addItem(itemName, itemAmount, items);
    }
    fclose(fp);
}

int initGame()
{
}

int main()
{
}