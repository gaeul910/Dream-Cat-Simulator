#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "gamedatamodules.c"
#include "othermodules.c"
#include "savemodules.c"
#include "displaymodules.c"
#include "interaction_system.c"
#include "menus.c"
#include "shop.c"

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

    shop(itemlist);

    return 0;
}