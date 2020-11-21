//
// Created by Dimas  on 14/11/20.
//

#include<stdio.h>

// Global Variable
int income = 0;
int Index;

//Dibuat 2 File agar tidak ke overwrite
struct Food {
    int Type;
    char Name[255];
    int Price;
    char Topping[255];
    char Calories[255];
    char Flavor[255];
    char Size[255];
    char Time[255];
    int Nunggu;
};

struct TEMP {
    int type;
    char name[255];
    int price;
    char topping[255];
    char callories[255];
    char flavor[255];
    char size[255];
    char time[255];
    int Nunggu;
};

Food Cooking[100];
TEMP CookingTemp[100];

void CookingProcess() {
    Index = 0;
    FILE *fptr = fopen("FOODDATA.txt", "r");
    while (!feof(fptr)) {
        fscanf(fptr, "%d#%[^#]#%d#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", &Cooking[Index].Type, Cooking[Index].Name,
               &Cooking[Index].Price, Cooking[Index].Topping, Cooking[Index].Calories, Cooking[Index].Flavor,
               Cooking[Index].Size, Cooking[Index].Time, &Cooking[Index].Nunggu);
        Index++;
    }
    fclose(fptr);

    FILE *fptr2 = fopen("TEMP.txt", "w");
    for (int i = 0; i < Index; i++) {
        Cooking[i].Nunggu -= 10;
        if (Cooking[i].Nunggu <= 0 && Index == 1) {
            fprintf(fptr, "");
            income += Cooking[i].Price;
            Cooking[i].Price = 0;
        } else if (Cooking[i].Nunggu <= 0) {
            income += Cooking[i].Price;
        } else {
            fprintf(fptr, "%d#%s#%d#%s#%s#%s#%s#%s#%d\n", Cooking[i].Type, Cooking[i].Name, Cooking[i].Price,
                    Cooking[i].Topping, Cooking[i].Calories, Cooking[i].Flavor, Cooking[i].Size, Cooking[i].Time,
                    Cooking[i].Nunggu);
        }
    }
    fclose(fptr2);

    Index = 0;
    fptr2 = fopen("TEMP.txt", "r");
    while (!feof(fptr)) {
        fscanf(fptr, "%d#%[^#]#%d#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", &Cooking[Index].Type, Cooking[Index].Name,
               &Cooking[Index].Price, Cooking[Index].Topping, Cooking[Index].Calories, Cooking[Index].Flavor,
               Cooking[Index].Size, Cooking[Index].Time, &Cooking[Index].Nunggu);
        Index++;
    }
    fclose(fptr2);

    fptr = fopen("FOODDATA.txt", "w");
    for (int i = 0; i < Index; i++) {
        if (Index == 1 && Cooking[i].Nunggu <= 0) {
            fprintf(fptr, "");
            Index = 0;
        } else {
            fprintf(fptr, "%d#%s#%d#%s#%s#%s#%s#%s#%d\n", Cooking[i].Type, Cooking[i].Name, Cooking[i].Price,
                    Cooking[i].Topping, Cooking[i].Calories, Cooking[i].Flavor, Cooking[i].Size, Cooking[i].Time,
                    Cooking[i].Nunggu);
        }
    }
    fclose(fptr);
    if (Index >= 1) {
        printf("| No  | Type                     | Name                     | Price                | Time Left     |\n");
        printf("----------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < Index; i++) {
            if (Cooking[i].Type == 1) {
                printf("| %-4d| Dessert                  | %-25s| $%-20d| %-12ds |\n", i + 1, Cooking[i].Name,
                       Cooking[i].Price, Cooking[i].Nunggu);
            } else if (Cooking[i].Type == 2) {
                printf("| %-4d| Drinks                   | %-25s| $%-20d| %-12ds |\n", i + 1, Cooking[i].Name,
                       Cooking[i].Price, Cooking[i].Nunggu);
            }
        }
        printf("\n");
    } else if (Index == 0) {
        printf("There is no Dessert or Drink on the list!\n\n");
    }
    fptr2 = fopen("TEMP.txt", "w");
    fprintf(fptr2, "");
    fclose(fptr2);
    printf("Press Enter to continue ");
    getchar();
    //system cls
}