#include <stdio.h>

int
	numeros;

float
	total, numero, media;

int main () {

	numeros = 0;
	total = 0;

	printf("Informe um numero para calcular a media, ou um numero negativo para encerrar: ");
	scanf("%f", &numero);

	while (numero >= 0) {

		numeros += 1;
		total += numero;

		printf("Informe um numero para calcular a media, ou um numero negativo para encerrar: ");
		scanf("%f", &numero);

	}

	printf("O resultado da soma dos numeros informados eh: %.2f.\n", total);
	printf("No total, foram informados %d numeros.\n", numeros);

	if (numeros == 0) {

		printf("Eh necessario informar pelo menos um numero para fazer o calculo da media.\n");

	} else {

		media = total / numeros;
		printf("A media dos numeros informados eh: %.2f.\n", media);

	}

}
