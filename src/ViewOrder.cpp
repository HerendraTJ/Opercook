#include <stdio.h>
#include <string.h>
#define ll long long int
#define ull unsigned long long int
#define pi 3.14159

//Dimohon nama file food history nya OrderHistory (  awas gaada capitalization >:(  )

struct Food {
	int Type;
	char Name[100];
	int Price;
	char Topping[100];
	char Calories[100];
	char Flavour[100];
	char Size[100];
	char Time[100];	
};


void ViewOrder(){
	
	Food fud[100];
	
	FILE *food = fopen ("OrderHistory.txt", "r");
	int idx = 0;
	
	while (!feof(food)){
		fscanf (food, "%d#%[^#]#%d#%[^#]#%[^#]#%[^#]#%c#%[^\n]\n", &fud[idx].Type, fud[idx].Name, &fud[idx].Price, fud[idx].Topping, fud[idx].Calories, fud[idx].Flavour, fud[idx].Size, fud[idx].Time);
		idx++;
	}
	
	if (idx <= 1){
		printf("No menu found\nPress to continue\n");
		getchar();
	}
	
	else {
		printf ("+==============================================================================================+\n");
		printf ("| No.  | Name                 | Price | Topping  | Calories | Flavour      | Size | Date       |\n");
		printf ("+==============================================================================================+\n");
		for (int i=0; i<idx; i++){
			if (fud[i].Type == 1){
				printf ("| %-4d | %-20s | %-5d | %-8s | %-8s | %-12s | %s    | %-10s |\n", i+1, fud[i].Name, fud[i].Price, fud[i].Topping, fud[i].Calories, "-", "-", fud[i].Time);
			}
			else {
				printf ("| %-4d | %-20s | %-5d | %-8s | %-8s | %-12s | %s    | %-10s |\n", i+1, fud[i].Name, fud[i].Price, "-", "-", fud[i].Flavour, fud[i].Size, fud[i].Time);
			}
		}
		printf ("+==============================================================================================+\n");
	}
	
	fclose(food);
	
}

int main(){
	ViewOrder();
	return 0;
}

