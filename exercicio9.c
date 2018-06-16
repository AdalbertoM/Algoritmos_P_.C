#include <stdlib.h> 

main(){ 
int x, i = 1, j; 
	printf("Calcular a tabuado do 1 ao 5.\n\n"); 
	printf("Digite o valor de 5: "); 
	scanf("%d", &x); 
	printf("\n"); 
	while(i <= x) 
	{ 
	printf("\nTabuada do: %d\n\n", i); 
	j = 1; 
	while(j <= 10) 
		{ 
		printf("%d x %d = %d\n", i, j, i*j); 
		j = j + 1; 
	} 
		i = i + 1; 
		} 
		printf("\n"); 
	system("pause"); 
}
