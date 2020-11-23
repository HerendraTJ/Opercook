#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ll long long int
#define ull unsigned long long int
#define pi 3.14159

struct Food {
	int code; // 2 buat beverage, 1 buat desert
	char name[110];
	int price;
	char topping[110]; //Dessert
	double calories; // Dessert
	
	char flavour[110]; //Drink
	char size;
	int process;

	Food *next;
	
} *head = NULL, *tail = NULL, *temp = NULL, *orderhead = NULL, *ordertail = NULL;


Food *newFood (char inputname[], int inputprice, char inputtopping[], double inputcalories, char inputflavour[], char inputsize, int inputprocess){
	Food *temp = (Food *) malloc (sizeof(Food));
	
	strcpy(temp->name, inputname);
	strcpy(temp->topping, inputtopping);
	strcpy(temp->flavour, inputflavour);
	
	temp->price = inputprice;
	temp->size = inputsize;
	temp->next = NULL;
	temp->process = inputprocess;
	temp->calories = inputcalories;
	
	
	temp->code = 2;
	if (inputcalories > 0) temp->code = 1;
	
	return temp;
	
}

void PushMenu(char inputname[], int inputprice, char inputtopping[], double inputcalories, char inputflavour[], char inputsize, int inputprocess){ //Push Head Cukup
	//Head ke tail itu process dari kecil ke besar
	
	Food *temp = newFood(inputname, inputprice, inputtopping, inputcalories, inputflavour, inputsize, inputprocess);
	if (!head){
		head = tail = NULL;
	}
	//PushHead
	else {
		temp->next = head;
		head = temp;
	}
}

void PushOrder(Food *orderup){ //Push Menu
	if (!orderhead) orderhead = ordertail = orderup;
	else {
		orderhead->next = orderup;
		orderup = orderhead; 
	}
}

void Pop(){
	//Search... jika ada yang -10 timenya, pop 
	Food *now = orderhead;
	Food *nowprev = orderhead;
	if (!now) return;
	
	//Jangan diedit... ini ngambil tanggal
	//Diambil dari https://stackoverflow.com/questions/5141960/get-the-current-time-in-c/
	time_t nowtime;
	struct tm *timenow;
	time (&nowtime);
	timenow = localtime(&nowtime);
	
	//Contoh pengambilan
	//printf ("%d-%d-%d\n",timenow->tm_mday, timenow->tm_mon+1, timenow->tm_year + 1900);
	
	FILE *files = fopen("OrderHistory.txt", "a");
	if (!files) return;
	
	while (now){
		
		now->process -= 10;
		if (now->process <= 0){
			
			//Convert 24hour ke 12hour format///////////////////////////////////
			int h = timenow->tm_hour;
			int ap = 0; //0 = am, 1 = pm 
			
			if (h == 24 || h == 0){
				h = 0;
				ap = 0;
			}
			else if (h >= 12 && h <= 23){
				ap = 1;
				h -= 12;
			}
			
			
			char date[30];
			char clock[30];
			
			sprintf (date, "%d/%02d/%02d", timenow->tm_year+1900, timenow->tm_mon+1, timenow->tm_mday);
			
			if (ap == 1){
				sprintf (clock, "%02d:%02d:%02d %s", h, timenow->tm_min, timenow->tm_sec, "PM");
			}
			else {
				sprintf (clock, "%02d:%02d:%02d %s", h, timenow->tm_min, timenow->tm_sec, "AM");
			}
			////////////////////////////////////////////////////////////////////
			
			
			if (now->code == 2){ //Beverage
				fprintf (files, "%d#%s#%d#-#-#%s#%c#%s %s\n", now->code, now->name, now->price, now->flavour, now->size, date, clock);
			}
			else { // Dessert
				fprintf (files, "%d#%s#%d#%s#%-2.2lf#-#-#%s %s\n", now->code, now->name, now->price, now->topping, now->calories, date, clock);
			}
			
			///Popping
			if (ordertail == now){
				nowprev->next = NULL;
				now = NULL;
				free(now);
				break;
			}
			else {
				nowprev->next = now->next;
				now->next = NULL;
				now = NULL;
				free(now);
			}
			now = now->next;
		}
		else {
			now = now->next;
			nowprev = nowprev->next;
		}
	}
}


int main(){
	Food *temp = newFood("Moof", 15, "Mozza", 3.9, "-", 'O', 9);
	PushOrder(temp);
	Pop();
return 0;
}

