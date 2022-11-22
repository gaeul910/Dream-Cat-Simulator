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
#include "interaction_system.c"
#include "displaymodules.c"
#include "shop.c"
#include "menus.c"

void Cursor_view()
{
    CONSOLE_CURSOR_INFO cursorInfo = {
        0,
    };
    cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int debug(ItemList *itemlist, Status *status, PlayerData *playerdat)
{
    loadGame(itemlist, status, playerdat);
    // for (int i = 0; i < itemlist->itemcount; i++)
    // {
    //     printf("[+] %s %d %d\n", itemlist->itemArr[i].name, itemlist->itemArr[i].amount, itemlist->itemArr[i].price);
    // }
    // saveGame(itemlist, status);
    // printf("%s, %s", playerdat->playerName, playerdat->dreamCatName);
    mainMenu(itemlist, status, playerdat);
    return 0;
}

int main()
{
    system("mode con:cols=80 lines=25"); // 콘솔창 크기조절(가로,세로 증감 비율 다름 약 2:1)
    Cursor_view();
    ItemList *itemlist = (ItemList *)malloc(sizeof(ItemList));
    Status *status = (Status *)malloc(sizeof(Status));
    PlayerData *playerdata = (PlayerData *)malloc(sizeof(PlayerData));
    debug(itemlist, status, playerdata);

    return 0;
}