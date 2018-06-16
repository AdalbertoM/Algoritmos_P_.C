#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int NUM, maior=NUM;
	printf("\nDigite um numero inteiro:");
	scanf("%d", &NUM);
	while(NUM!=0)
	{
		if(NUM>maior)
		  maior=NUM;
		   printf("\nDigite um numero inteiro:");
		   scanf("%d", &NUM);
		}	
		printf("\nO maior numero eh:  %d",maior);
		printf("\n\n");
		system("pause");
		return 0;		
}
