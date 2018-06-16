#include <stdio.h>
#include <math.h>
int main(){
	int num,num1,p;
	num1=1;
	printf("Digite um numero:");
	scanf("%d", &num);
	p=num1*(num1+1)*(num1+2);
	while(p<num){
		num1++;
		p=num1*(num1+1)*(num1+2);
	}	
	if(p==num)
	  printf("\nEh triangular.");
	else
	  printf("\nNao eh triangular.");
	  printf("\n");
	system("pause");
	return 0;  
} 
