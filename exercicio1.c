#include <math.h>
#include <string.h>
 int main() { 
 int liminferior, limsuperior,x; 
 float soma = 0; 
 
 printf("Informe o valor do limite inferior: ");
  scanf("%d", &liminferior); printf("\nInforme o valor do limite superior: ");
   scanf("%d", &limsuperior);
   if (liminferior % 2 == 0)
   liminferior = liminferior + 2;
    else
	liminferior = liminferior + 1;
	 printf("\n\n");
	 
	
 for (x=liminferior;x <= limsuperior -1;x=x+2){
  printf("%d\t",x);
	 soma = soma + x;
	  }
	   printf("\n\n");
	   printf("Somatorio: %3.0f",soma);
	    printf("\n\n");
		 system("pause");
		  return 0;	
  }		  

