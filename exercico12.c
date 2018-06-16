#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main(){
 int idade, cont, qtdadeOpiniaoBoa=0, somaIdade=0, qtdadeOpiniaoRuim=0;
 int ID, opiniao, IDMaisVelha;
 int idadeMaisVelha=-1;
 float mediaIdade, percentual;
 for (cont=0;cont<5;cont++)
 {
 printf ("\nInforme a sua idade: ");
 scanf ("%d", &idade);
 printf ("\nInforme o seu ID: ");
 scanf ("%d", &ID);
 printf ("\nInforme a sua opiniao(0-10): ");
 scanf ("%d", &opiniao);
 if (opiniao==10)
 qtdadeOpiniaoBoa++;
 somaIdade=somaIdade+idade;
 if (opiniao<=5)
 qtdadeOpiniaoRuim++;
 if (idade>idadeMaisVelha)
 {
 idadeMaisVelha=idade;
 IDMaisVelha=ID;
 }
 }
 printf ("\nA quantidade de respostas 10 foi de %d", qtdadeOpiniaoBoa);
 mediaIdade=(float)somaIdade/5;
 printf ("\nA média de idade das pessoas que responderam o questionário foi de %.2f", mediaIdade);
 percentual=(float)qtdadeOpiniaoRuim*100/5;
 printf ("\nA porcentagem de pessoas que responderam 5 ou menos foi de %.2f", percentual);
 printf ("\nO ID da pessoa mais velha eh %d\n", IDMaisVelha);
 system("pause");
}
