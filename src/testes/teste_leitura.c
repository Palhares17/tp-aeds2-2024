#include "../leitura/leitura.h"
#define M 23

int main() {
    // unsigned pesos[M];
    // for (int i = 0; i < M; i++) {
    //     pesos[i] = 1;
    // }
    // GeraPesos(pesos);

    pont_capsula vetor_de_heads[M] = {NULL};

    lerArquivos(&(vetor_de_heads[M]));

    // imprimeAllCapsulas(vetor_de_heads, M);

    return 0;
}