typedef struct item
{
    char name[128];
    int amount;
    int price;
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
    int health;
    int normal; // always 7500
    int delight;
    int sadness;
    int anger;
    int friendship;
    char laststatcode[128];
    time_t updatetime;
} Status;

typedef struct PlayerData
{
    char playerName[128];
    char dreamCatName[128];
} PlayerData;

int addItem(int itemcode, int itemAmount, ItemList *itemlist)
{
    itemlist->itemArr[itemcode].amount += itemAmount;

    return 0;
}