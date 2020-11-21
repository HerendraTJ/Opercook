#include <stdio.h>
#include "../EXTRA/EXTRA.h"

void inputName()
{
    char name[5005];
    int ctrName;
    do
    {
        printf("Input the name [at least 5 characters]: ");
        scanf("%[^\n]", name);
        getchar();
        ctrName = strctr(name);
    } while (ctrName < 5 || ctrName > 5000);
}

void inputPrice()
{
    int price;
    do
    {
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &price);
    } while (price < 10 || price > 500);
}