void shop()
{

    add_line();
    gotoxy(10, 1);
    printf("상점(임시 인터페이스)\n");
    add_line();
    printf(" 먹이\n");
    printf(" 간식\n");
    printf(" 장난감\n");
    printf(" 기타\n");

    int num = cursor();

    switch (num)
    {
    case 3:
        food();
        break;
    case 4:
        printf("you select item2\n");
        break;
    case 5:
        printf("you select item3\n");
        break;
    case 6:
        printf("you select item3\n");
        break;

    default:
        break;
    }
}