#include <stdio.h>

#define MAX_CONTROLE 50
#define MAX_DADOS 500

typedef struct {
   int prim,
       pos,
       tam,
       prox;
} TipoControle;

static TipoControle controle[MAX_CONTROLE] =
   {
      { 1,  0,  3,  2},
      { 1,  3,  9,  4},
      { 0, 12, 11,  3},
      { 0, 38,  4, -1},
      { 0, 31,  7, -1},
      { 1,  0,  3,  6},
      { 0, 23, 15, -1},
      {-1, -1, -1, -1}
   };


static char dados[MAX_DADOS] = "Av Livraria Washington Senador SaraivaLuiz";

int main() {
   int varre = 0;
   while (varre < MAX_CONTROLE && controle[varre].prim != -1) {
      if (controle[varre].prim == 1) {

         int aux = varre;

         while (aux != -1) {
            int i;
            for (i = controle[aux].pos; i < controle[aux].pos + controle[aux].tam; i++)
               printf("%c", dados[i]);

            aux = controle[aux].prox;
         }
         printf("\n");
      }

      varre++;
   }



   return 0;
}
