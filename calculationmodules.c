time_t StatUpdate(Status *stats)
{
    time_t timepassed = time(NULL) - stats->updatetime;

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