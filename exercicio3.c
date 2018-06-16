#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int numero, c, p;
	printf("Informe um numero positivo:");
	scanf("%d", &numero);
   while(numero>0)
	{
		c=1;
		
		p=c+c;
	   while(p<numero)
		{
			c++;
			p=c*c;
		}
		if(p==numero)
			printf("\nO numero informado eh quadrado perfeito.\n");
		else
			printf("\nO numero informado nao eh quadrado perfeito");
			printf("\nInforme um numero positivo:");
			scanf("%d", &numero);		
	}
	printf("\n");
	system("pause");
	return 0;
}
