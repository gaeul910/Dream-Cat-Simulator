time_t StatUpdate(Status *stats, int isonline)
{
    time_t timepassed = time(NULL) - stats->updatetime;
    if (isonline == 1) // for online calculation
    {
        if (timepassed >= 1)
        {
            stats->hunger -= 3 * timepassed;
            stats->sadness += 2 * timepassed;
            stats->delight -= 2 * timepassed;
            stats->anger += 1 * timepassed;

            stats->updatetime = time(NULL);

            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (isonline == 0) // for offline calculation
    {
        time_t offlinetime = timepassed / 20;
        if (offlinetime >= 1)
        {
            stats->hunger -= 3 * offlinetime;
            stats->sadness += 2 * offlinetime;
            stats->delight -= 2 * offlinetime;
            stats->anger += 1 * offlinetime;

            stats->updatetime = time(NULL) - (timepassed % 20);
            StatUpdate(stats, 0); // 나머지 시간은 온라인 시간으로 계산

            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Error: Unknown Option for StatUpdate.");
    }
    return -1;
}

int getCurrentStat(char *statcode, Status *stats)
{
    if (stats->hunger < 200)
    {
        strcpy(statcode, "hungry");
        return 0;
    }
    if (stats->normal > stats->delight && stats->normal > stats->sadness && stats->normal > stats->anger)
    {
        strcpy(statcode, "normal");
    }
    else if (stats->delight > stats->sadness && stats->delight > stats->sadness && stats->delight > stats->anger)
    {
        strcpy(statcode, "delight");
    }
    else if (stats->sadness > stats->delight && stats->sadness > stats->anger && stats->sadness > stats->anger)
    {
        strcpy(statcode, "sadness");
    }
    else if (stats->anger > stats->delight && stats->anger > stats->sadness && stats->anger > stats->normal)
    {
        strcpy(statcode, "angry");
    }

    return 0;
}

int judg_effect(char *effect)
{
    if (strcmp(effect, "hunger") == 0)
    {
        return 1;
    }
    else if (strcmp(effect, "health") == 0)
    {
        return 2;
    }
    else if (strcmp(effect, "normal") == 0)
    {
        return 3;
    }
    else if (strcmp(effect, "delight") == 0)
    {
        return 4;
    }
    else if (strcmp(effect, "sadness") == 0)
    {
        return 5;
    }
    else if (strcmp(effect, "anger") == 0)
    {
        return 6;
    }
    else if (strcmp(effect, "friendship") == 0)
    {
        return 7;
    }
    else
    {
        return 0;
    }
}

int change_rate(char *rate)
{
    int num = 0;
    int minus = 1;
    int i = 0;
    while (rate[i] != 10)
    {
        num *= 10;
        if (rate[i] >= '0' && rate[i] <= '9')
        {
            num += rate[i] - '0';
        }
        else if (rate[i] == '-')
        {
            minus = -1;
        }
        i++;
    }

    return minus * num;
}

void apply_effect(Status *stats, int type, int rate)
{
    switch (type)
    {
    case 1:
    {
        stats->hunger += rate;
        break;
    }
    case 2:
    {
        stats->health += rate;
        break;
    }
    case 3:
    {
        stats->normal += rate;
        break;
    }
    case 4:
    {
        stats->delight += rate;
        break;
    }
    case 5:
    {
        stats->sadness += rate;
        break;
    }
    case 6:
    {
        stats->anger += rate;
        break;
    }
    case 7:
    {
        stats->friendship += rate;
        break;
    }
    default:
        break;
    }
}
