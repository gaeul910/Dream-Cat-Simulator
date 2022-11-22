#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "gamedatamodules.c"
#include "calculationmodules.c"
#include "othermodules.c"
#include "savemodules.c"
#include "displaymodules.c"
#include "inventory.c"
#include "minigames.c"
#include "interaction_system.c"
#include "shop.c"
#include "menus.c"

int debug(ItemList *itemlist, Status *status, PlayerData *playerdat)
{

    //  loadGame(itemlist, status, playerdat);
    // mainMenu(itemlist, status, playerdat);
}

int main()
{
    system("mode con:cols=100 lines=13"); // 콘솔창 크기조절(가로,세로 증감 비율 다름 약 2:1)
    ItemList *itemlist = (ItemList *)malloc(sizeof(ItemList));
    Status *status = (Status *)malloc(sizeof(Status));
    PlayerData *playerdata = (PlayerData *)malloc(sizeof(PlayerData));
    debug(itemlist, status, playerdata);

    return 0;
}