int getRandomValue(int maxvalue)
{
    if (maxvalue == 0)
    {
        return 0;
    }
    else
    {
        srand(time(NULL));
        return rand() % maxvalue;
    }

    return -1;
}