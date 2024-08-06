#include "../leitura/leitura.h"
#define M 23

void MostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Pesquisar termos na Hash\n");
    printf("2 - Mostrar qtd/iddoc çlde todas as palavras da Hash table\n");
    printf("3 - Mostrar termo por relevância na Hash table\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    // Incializando patricia
    Apontador raiz = NULL;

    lerArquivos(hash, pesos, &raiz);

    CalcularRelevanciaHash(vetor_de_heads, "bezoar", pesos, 15);

    imprimeAllCapsulas(hash, 23);

    return 0;
}
