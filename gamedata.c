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
    int feeling;
    int health;
    int friendship;
} Status;

typedef struct PlayerData
{
    char playerName[128];
    char dreamCatName[128];
} PlayerData;