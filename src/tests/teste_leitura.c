#include "../leitura/leitura.h"
#define M 23

int main() {

    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    printf("ATE AKI DEU");

    // Incializando patricia
    Apontador raiz = NULL;

    lerArquivosTeste(hash, pesos, &raiz);


    return 0;
}
