/*
=======================================================
UNIVERSIDADE FEDERAL DA FRONTEIRA SUL

TRABALHO FINAL DA MATÉRIA DA ALGORITIMOS E PROGRAMAÇÃO
CAIXA ELETRÔNICO

Adalberto Marques da Costa

CHAPECÓ
DEZEMBRO - 2015
=======================================================
*/

# include "stdio.h"
# include "string.h"
#include "string.h" //MANIPULAÇÃO DE STRINGS
# include "dos.h"

int n=200,i;

//INICIALIZAÇÃO DAS NOTAS EM CAIXA
static int caixa [2][6] = {100, 50, 20, 10,  5,  2,//LINHA DO VALOR DAS NOTAS
                            20, 20, 20, 20, 20, 20};//QUANTIDADE DE NOTAS POR TIPO

struct cliente {
       char nome[20];
       char sobrenome[20];
       char cpf[12];
       char conta[6];
       char agencia[6];
       char senha[6];
       float saldo;
       int opsaque;
       int optransf;
       float movimentosaque;
       float movimentotransf;
       }
       usuario[20];


/*****************************************/

int validacpf(char cpf[12]){
	char icpf[12];
	int i,somador=0,digito1,result1,result2,digito2,valor;
	//Efetua a conversao de array de char para um array de int.
	for(i=0;i<11;i++){
		icpf[i]=cpf[i]-48;
	}
	//PRIMEIRO DIGITO.
	for(i=0;i<9;i++){
		somador+=icpf[i]*(10-i);
	}
	result1=somador%11;
	if( (result1==0) || (result1==1) ){
		digito1=0;
	}else{
		digito1 = 11-result1;
	}
	//SEGUNDO DIGITO.
	somador=0;
	for(i=0;i<10;i++){
		somador+=icpf[i]*(11-i);
	}
	valor=(somador/11)*11;
	result2=somador-valor;
	if( (result2==0) || (result2==1) ){
		digito2=0;
	}else{
		digito2=11-result2;
	}
	//RESULTADOS DA VALIDACAO.
	if((digito1==icpf[9]) && (digito2==icpf[10])){
		return(0);
	}else{
		printf("\t\t\tCPF INVALIDO\n");
		return(1);
	}
}

int numconta(int num){
	int cod,cod1,conta,n1,n2,n3,n4;
	n1=num/1000;
	n2=(num%1000)/100;
	n3=((num%1000)%100)/10;
	n4=((num%100)%50)%10;
	cod=n1*9+n2*8+n3*7+n4*6;
	if(cod<10){
	   cod=cod*10;
	}
	cod1=cod%11;
	if(cod1==10){
	   cod1=0;
	}
	conta=n1*10000+n2*1000+n3*100+n4*10+cod1;
	return(conta);
}

cadastrarCliente (){
   int i,a,resposta;
    printf ("\n\t\t\t======================\t\t\t\n");
    printf ("\n\t\t\t CADASTRO DE CLIENTES \n");
    printf ("\n\t\t\t======================\t\t\t\n");
     printf ("\n Quantos clientes deseja cadastrar? \n");
     scanf ("%d", &n);


  for (i=0;i<n;i++)
    {
    puts ("");
    printf ("\n *-- NOME--* \n");
    scanf ("%s", &usuario[i].nome);
    printf ("\n *-- SOBRENOME--* \n");
    scanf ("%s", &usuario[i].sobrenome);
    do{
	    printf ("\n *--CPF--* \n ");
	    scanf ("%s", &usuario[i].cpf);
	    resposta=validacpf(usuario[i].cpf);
	}while(resposta!=0);
    printf ("\n *--AGENCIA--* \n ");
    scanf ("%s", &usuario[i].agencia);
    do{
	    printf ("\n *--NUMERO DA CONTA--* \n ");
	    scanf ("%s", &usuario[i].conta);
	    resposta=atoi(usuario[i].conta);
	    if(resposta<1000 || resposta>9999){
	    	resposta==1;
	    	printf("\t\t\tNumero invalido\n");
		}else{
			resposta=numconta(resposta);
			sprintf(usuario[i].conta,"%i",resposta);
			printf("\n\t\tConta gerada com sucesso %s\n",usuario[i].conta);
			resposta=0;
		}
	}while(resposta!=0);
    printf ("\n *--SENHA--* \n ");
    scanf ("%s", &usuario[i].senha);

    usuario[i].saldo = 0;
    usuario[i].opsaque=0;
    usuario[i].optransf=0;
    usuario[i].movimentosaque=0;
    usuario[i].movimentotransf=0;
    printf ("\n\n *-- Operacao realizada com sucesso !!!--*\n");
    }
    system("pause");
 }

/*****************************************************/

deposito (){
    int a,b,c,x;
    float dep;
    char agn[6], conta[6], senha[6];

    printf ("\n\t\t\t============\t\t\t\n");
    printf ("\n\t\t\t  DEPOSITO \n");
    printf ("\n\t\t\t============\t\t\t\n");

    printf ("\n *--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn);
    printf ("\n *--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);

    for (i=0;i<n;i++)
    {
        a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);
        if  ( (a == 0) && (b == 0) )
        {
          x=1;
          printf ("\n CLIENTE : %s", usuario[i].nome) ;
          printf ("\n CPF : %s", usuario[i].cpf) ;
          printf ("\n\n *--QUANTIDADE DO DEPOSITO--*");
          scanf ("%f", &dep) ;
          if (dep > 0)
          {
            usuario[i].saldo = usuario[i].saldo + dep;
            printf("\n\t\t Deposito feito com sucesso\n");
          }
          else
          {
          printf ("\n\a *-- ERRO: O DEPOSITO TEM QUE SER POSITIVO --* ");
          }
               }

     }
     if(x!=1)
     printf ("\n\a\a *-- ERRO: DADOS INCORRETOS ! --*");
     system("pause");
}
/**************************************************/
consultaSaldo (){
     char agn[6], conta[6], senha[6];
     int a,b,c,x;

     printf ("\n\t\t\t========\t\t\t\n");
     printf ("\n\t\t\t SALDO \n");
     printf ("\n\t\t\t========\t\t\t\n");

    printf ("\n *--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn);
    printf ("\n *--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);
    printf ("\n *--DIGITE A SUA SENHA--* ");
    scanf ("%s", &senha);

    for (i=0;i<n;i++)
    {

        a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);
        c = strcmp(senha,usuario[i].senha);
        if  ( (a == 0) && (b == 0)  && (c == 0) )
        {
          x=1;
          printf ("\n CLIENTE : %s", usuario[i].nome) ;
          printf ("\n CPF : %s", usuario[i].cpf) ;
          printf ("\n\n *--SEU SALDO E : %.2f reais --*\n", usuario[i].saldo) ;
        }
       }
    if (x!=1)
    {
    printf ("\n\a\a *-- ERRO: DADOS INCORRETOS ! --*");
    }
    system("pause");
}
/***********************************************/
transfere (){
   char agn[6], conta[6], senha[6],agn2[6],conta2[6];
    int a,b,c,d,e,j,x,l;
    float val;

    printf ("\n\t\t\t================\t\t\t\n");
    printf ("\n\t\t\t  TRANSFERENCIA \n");
    printf ("\n\t\t\t================\t\t\t\n");

    printf ("\n*--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn);
    printf ("\n*--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);
    printf ("\n *--DIGITE A SUA SENHA--*: ");
    scanf ("%s", &senha);
    for (i=0;i<n;i++)
    {

        a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);
        c = strcmp(senha,usuario[i].senha);
        if  (   (a == 0) && (b == 0)  && (c == 0)  )
        {
         l=1;
          printf ("\n CLIENTE : %s", usuario[i].nome) ;
          printf ("\n CPF : %s", usuario[i].cpf) ;
          break;
        }
      if (l != 1){
      printf ("\a\a*-- ERRO: DADOS INCORRETOS ! --*");
      printf ("\n\n AGUARDE...");

      system ("cls");
      main();
      }
    }
    printf ("\n*--DIGITE A AGENCIA DO BENEFICIADO--* ");
    scanf ("%s", &agn2);
    printf ("\n*--NUMERO DA CONTA DO BENEFICIADO--* ");
    scanf ("%s", &conta2);

          for (j=1;j<=n;j++)
          {
            d = strcmp(agn2,usuario[j].agencia);
            e = strcmp(conta2,usuario[j].conta);
               if  ((d == 0) && (e == 0))
               {

               printf ("\n *--CLIENTE BENEFICIADO--* %s", usuario[j].nome) ;

               printf ("\n*--VALOR DA TRANSFERENCIA--*");
               scanf ("%f", &val);
                if(val>0){
                	if (usuario[i].saldo >= val){
                		if(usuario[i].optransf<3){
                			if(usuario[i].movimentotransf+val<500){
			                    usuario[j].saldo = usuario[j].saldo + val;
			                    usuario[i].saldo = usuario[i].saldo - val;
			                    usuario[i].movimentotransf+=val;
			                    usuario[i].optransf++;
			                    printf("\n\tSeu saldo atual e %.2f\n\n",usuario[i].saldo);
			                }else{
			                	printf("\n\t\tERRO VALOR MAXIMO JA TRANSFERIDO");
			                }
	                    }else{
	                    	printf("\n\t\t ERRO OPERACOES TOTAL ATINGIDA");
	                    }
                    }else{
                    	printf ("\a\a *-- ERRO: SALDO INSUFICIENTE! --*");
                    }
                }else{
                	printf("\n\t\t VLOR INVALIDO\n");
				}
        	}
        }
  	system("pause");

}
/***********************************************/
saque (){
    int a,b,c,x;
    float saq;
    char agn[6], conta[6], senha[6];

    printf ("\n\t\t\t========\t\t\t\n");
    printf ("\n\t\t\t SAQUE \n");
    printf ("\n\t\t\t========\t\t\t\n");

    printf ("\n *--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn);
    printf ("\n *--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);

    for (i=1;i<=n;i++)
    {
        a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);
        if  ( (a == 0) && (b == 0) )
        {
          printf ("\n CLIENTE : %s", usuario[i].nome) ;
          printf ("\n CPF : %s", usuario[i].cpf) ;
          printf ("\n\n*--VALOR DA RETIRADA--*");
          scanf ("%f", &saq) ;
          if ((saq > 0) && (saq <= usuario[i].saldo) )
          {
            x=1;
            usuario[i].saldo = usuario[i].saldo - saq;
          }
        }
     }
     if (x != 1){
           printf ("\n\a\a *-- ERRO: SALDO INSUFICIENTE ! --*");
           }
      printf ("\n\n*-- AGUARDE... --*");

}


menu (){
printf ("\n\t\t\t===========================\t\t\t\n");
printf ("\n\t\t\tSELECIONE A OPCAO DESEJADA...\t\t\t\n");
printf ("\n\t\t\t===========================\t\t\t\n");
puts ("");
puts ("\t\t\t1 - NOVO CLIENTE\n") ;
puts ("\t\t\t2 - DEPOSITO\n") ;
puts ("\t\t\t3 - CONSULTA SALDO\n") ;
puts ("\t\t\t4 - TRANSFERENCIA\n") ;
puts ("\t\t\t5 - RETIRADA\n");
puts ("\t\t\t6 - SAIR\n");
printf ("\n\t\t\t===========================\t\t\t\n");
     }
main()
{
int op;

menu ();
scanf ("%d", &op);
 switch (op)
 {
    case 1:
    system ("cls") ;
    cadastrarCliente ();
    system ("cls");
    main();
    case 2:
    system ("cls") ;
    deposito ();
    system ("cls");
    main();
    case 3:
    system ("cls") ;
    consultaSaldo ();
    system ("cls");
    main();
    case 4:
    system ("cls") ;
    transfere();
    system ("cls");
    main();
    case 5:
    system ("cls") ;
    saque ();
    system ("cls");
    main();
    break;

 }
getch();
}
