#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int num, soma=0;
	float media=0, cont=0;
	printf("\nDigite um numero inteiro:");
	scanf("%d", &num);
	if(num%3==0 && num!=0){
		soma=soma+num;
		cont++;
	}
	while(num!=0){
		printf("\nDigite um numero inteiro:");
		scanf("%d", &num);
		if(num%3==0 && num!=0){
			soma=soma+num;
			cont++;
		}
	}
	media=soma/cont;
	printf("\n\nA media dos numeros eh: %3.2f",media);
	printf("\n\n");
	system("pause");
	return 0;
}
