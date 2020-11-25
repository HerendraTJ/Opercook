#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "src/Menu1.cpp"
#include "src/Process.cpp"
#include "src/ViewOrder.cpp"

int main() {
    printf("Welcome to Opercook\n");
    printf("Total Profit : $0\n"); //Please ini variablenya gak tahu dikemanain
    printf("======================\n");
    printf("1. Add Desert or Beverage\n");
    printf("2. View Cooking Process\n");
    printf("3. View Order History\n");
    printf("4. Exit\n");
    int inputMain;
    scanf("%d", &inputMain);
    switch (inputMain) {
        case 1:
        	void addDessert();
        	void addDrink();
            break;
        case 2:
        	void CookingProcess();
        	
            break;
        case 3:
        	void ViewOrder();
            break;
        case 4:
        	return 0;
            break;
        default:

            break;
    }


    return 0;
}

