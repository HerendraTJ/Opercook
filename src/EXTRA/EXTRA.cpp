#include<stdio.h>


int strlen(char str[])
{
    int ctr = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        ctr++;
    }
    return ctr;
}

void clearScreen(){
	for(int i = 0; i < 50; i++)
	{
		puts(" ");	
	}
}
