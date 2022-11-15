int getRandomValue(int maxvalue)
{
    srand(time(NULL));
    return rand() % (maxvalue + 1);
}