#include "../leitura/leitura.h"
#define M 23

int main() {
  
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    lerArquivos(hash, pesos);

    imprimeAllCapsulas(vetor_de_heads, M);

    return 0;

    return 0;
}