#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "interaction_system.c"
#include "menus.c"

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
    FILE *fp = fopen("./savedata/playerinfo.txt", "w"); // 파일을 쓰기로 열기
    scanf("%s", temp);
    fprintf(fp, "PlayerName=%s", temp); // 파일로 출력
    scanf("%s", temp);
    fprintf(fp, "DreamCatName=%s", temp); // 파일로 출력

    return 0;
}

int getCurrentStat(char *statcode, Status *stats)
{
}

int printStatus(ItemList *list, Status *stats, PlayerData *playerdat, char *windowName)
{
    printf("사용자 이름: %s    개냥이 이름: %s\n", playerdat->playerName, playerdat->dreamCatName);
    printf("========================");
    printf("배고픔: %d%    건강: %d%    친밀도: %d%", stats->hunger, stats->health, stats->friendship);
    printf("기분: %d", stats->feeling);

    printf("========================");

    if (windowName != NULL)
    {
        printf("%s", windowName);
        printf("========================");
    }

    return 0;
}

int getRandomCharacterNum(Status *stats)
{
    char imgname[128];
    char input[128];
    FILE *fp = fopen(imgname, "r");
    fgets(input, sizeof(input), fp);
    strtok(input, "=");
    if (strcmp(input, "imgcount") == 0)
    {
        int imgcount = 0;
        strtok(NULL, "");
        for (int i = 0; input[i] != 10; i++)
        {
            imgcount *= 10;
            imgcount += input[i] - '0';
        }

        int randomimg = getRandomValue(imgcount);
        return randomimg;
    }
    else
    {
        printf("Error: Character print initilization Failed.");
        return -1;
    }

    return -1;
}

int printCharacter(int *imgnum, char *laststat, Status *stats)
{
    char currentstat[128];
    getCurrentStat(currentstat, stats);
    if ((laststat != NULL) && (strcmp(laststat, currentstat)) != 0) //기분 상태가 변경되었는지 확인
    {
        *imgnum = getRandomCharacterNum(stats);
    } // 마지막 출력으로부터 상태가 변경되어 새로운 이미지가 필요한지 판별

    int imgnumcp = *imgnum;
    int temp = 1;
    char strimgnum[128];

    while (imgnumcp % temp > 10)
    {
        temp *= 10;
    }

    for (int i = 0; temp != 1; i++)
    {
        strimgnum[i] = (imgnumcp / temp) - '0';
        imgnumcp = imgnumcp - (temp * (strimgnum[i] - '0'));
        temp /= 10;
    } // 이미지 코드 string으로 변환

    char imgname[128];
    char filedir[128] = "./catimg/";
    strcat(filedir, imgname);
    strcat(filedir, ".txt");
    FILE *catimg = fopen(filedir, "r");

    char input[128];
    int flag = 0;
    while (fgets(input, sizeof(input), catimg) != 0)
    {
        if (strcmp(input, strimgnum) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        while ((fgets(input, sizeof(input), catimg) != 0) && (strcmp(input, "END") != 0))
        {
            printf("%s", input);
        }
    }
    else
    {
        printf("Error: Image not Found");
    }

    return 0;
}

int main()
{
    ItemList *itemlist = (ItemList *)malloc(sizeof(ItemList));
    Status *status = (Status *)malloc(sizeof(Status));
    PlayerData *playerdata = (PlayerData *)malloc(sizeof(PlayerData));
    loadGame(itemlist, status, playerdata);
    printf("임시 기능\n");
    printf("먹이[F]");
    int key = getch();
    switch (key)
    {
    case 70:
        food();
        break;

    default:
        break;
    }
    return 0;
}