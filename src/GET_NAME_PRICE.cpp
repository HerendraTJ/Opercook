#include <stdio.h>
#include "EXTRA/EXTRA.h"

const char * inputName()
{
    static char name[5005];
    int ctrName;
    do
    {
        printf("Input the name [at least 5 characters]: ");
        scanf("%[^\n]", name);
        getchar();
        ctrName = strlen(name);
    } while (ctrName < 5 || ctrName > 5000);
    return name; //Utk masuk ke array char destinasi, strcpy(a, inputName());
}

int inputPrice()
{
    int price;
    do
    {
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &price);
    } while (price < 10 || price > 500);
    return price;

    
    
}
