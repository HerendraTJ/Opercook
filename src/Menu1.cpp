#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "GET_NAME_PRICE.h"

void addDessert()
{

  inputName();
  inputPrice();

  int totaltime; // unstored
  int extratime; // unstored

  // Input Topping
  char topping[20]; // unstored
  int validated = 0;
  do
  {
    printf("Input the topping [\'Caramel\' | \'Honey\' | \'Syrup\'](Case Sensitive): ");
    scanf("%[^\n]", &topping);
    getchar();
    if (strcmp(topping, "Caramel") == 0)
    {
      validated = 1;
      extratime = 10;
    }
    else if (strcmp(topping, "Honey") == 0)
    {
      validated = 1;
      extratime = 15;
    }
    else if (strcmp(topping, "Syrup") == 0)
    {
      validated = 1;
      extratime = 20;
    }
  } while (validated == 0);

  // Input Calories
  double calories; // unstored
  validated = 0;
  do
  {
    printf("Insert calories [1.00 - 99.00]: ");
    scanf("%lf", &calories);
    getchar();
    if (calories >= 1.00 && calories <= 99.00)
    {
      validated = 1;
    }
  } while (validated == 0);

  // Time
  // srand(time(0));
  totaltime = ((rand() % (90 - 50 + 1)) + 50) + extratime;

  printf("\nSuccessfully added a new menu!\n");
  getchar();
  getchar();
}

void addDrink()
{

  inputName();
  inputPrice();

  int totaltime; //Unstored
  int extratime; //Unstored

  // Input Topping
  char topping[20];
  int validated = 0;
  do
  {
    printf("Input the topping [\'Mint\' | \'Mix Berry\' | \'Cheese\'](Case Sensitive): ");
    scanf("%[^\n]", &topping);
    getchar();
    if (strcmp(topping, "Mint") == 0)
    {
      validated = 1;
      extratime = 10;
    }
    else if (strcmp(topping, "Mix Berry") == 0)
    {
      validated = 1;
      extratime = 20;
    }
    else if (strcmp(topping, "Cheese") == 0)
    {
      validated = 1;
      extratime = 30;
    }
  } while (validated == 0);

  // Input Size
  char size;
  validated = 0;
  do
  {
    printf("Input the size [S | M | L](Case Sensitive): ");
    scanf("%c", &size);
    getchar();
    if (size == 'S' || size == 'M' || size == 'L')
    {
      validated = 1;
    }
  } while (validated == 0);

  // Time
  srand(time(0));
  totaltime = ((rand() % (50 - 10 + 1)) + 10) + extratime;

  printf("\nSuccessfully added a new menu!\n");
  getchar();
  getchar();
}
