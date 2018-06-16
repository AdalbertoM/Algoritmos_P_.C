#include<stdio.h>
#include <stdlib.h>
main(){
 int numerador, denominador;
 float divisao, S=0;
 numerador=1;
 denominador=1;
 while (numerador<=99)
 {
 divisao=(float)numerador/denominador;
 S=S+divisao;
 numerador=numerador+2;
 denominador=denominador+1;
 }
 printf ("\nO resultado calculado eh %.2f\n", S);
 system("pause");
}

