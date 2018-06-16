#include <stdio.h>
#include <stdlib.h>
main()
{
      int num, i;
      i = 0;
      printf("Digite um numero. \n");
      scanf("%d", &num);
      
      while (i < 10)
      {
            i++;
          printf("\n %4d X %2d = %4d", num, i, i * num);
          }
      
      printf("\n\n\n");
     system("PAUSE");
      }
