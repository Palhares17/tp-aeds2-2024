/*
 * Autor: Gabriel de pádua
 * Data: 30/07
 * Versão: 2.1.0
 * Descrição: criação e teste
 *
 * Histórico:
 *  alteração no nome das funçoes  e suas funcionalidades
 */

#include "hash.h"

/*
a = N / M  onde
Alfa = fator de carga (quantas termos em lista quero ter media)
N = nuemro de termos(46);
M = tamanho da hash table(?);
*/

int compInsercaoHash = 0;
int conpBuscaHash = 0;

// pesos gernaod com tempo do sistema;
void GeraPesos(unsigned p[]) {
    // Gera valores randomicos entre 1 e 10.000
    int i;
    struct timeval semente;

    // Utilizar o tempo como semente para a funcao srand()
    gettimeofday(&semente, NULL);
    srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));

    for (i = 0; i < 11; i++)
        p[i] = 1 + (int)(500.0 * rand() / (RAND_MAX + 1.0));
}

int Casting(string termo, unsigned peso[]) {
    int i = 0;
    unsigned long long soma = 0;  // Usar unsigned long long para evitar overflow

    while (termo[i] != '\0') {
        soma += ((unsigned long long)termo[i] * peso[i]);
        i++;
    }

    return (int)soma;  // Cast para int ao retornar
}

int Hash_code(string termo, unsigned peso[]) {
    int code;
    code = Casting(termo, peso) % 23;
    return code;
}

pont_capsula criaCapsula(string termo, int idDoc, int qtdAparicao) {
    pont_capsula temporaria = (pont_capsula)malloc(sizeof(Capsula));
    if (temporaria == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    temporaria->termo = (string)malloc(strlen(termo) + 1);
    if (temporaria->termo == NULL) {
        printf("Erro ao alocar memoria para a string.\n");
        free(temporaria);
        return NULL;
    }
    strcpy(temporaria->termo, termo);

    temporaria->idDocQtd = criaNo(idDoc, qtdAparicao);
    if (temporaria->idDocQtd == NULL) {
        printf("Erro ao alocar memoria para indexação do documento e suas aparições.\n");
        free(temporaria->termo);
        free(temporaria);
        return NULL;
    }

    temporaria->proxCapsula = NULL;
    return temporaria;
}
//ate aqui tudo ok;
pont_capsula verificaExis(pont_capsula *heap, string termo) {
    pont_capsula atual = *heap;
    while (atual != NULL) {
        if (strcmp(atual->termo, termo) == 0) {
            return atual;
        }
        atual = atual->proxCapsula;
    }
    return NULL;
}

void insereCapsula(pont_capsula *heap, string termo, int idDoc, int qtdAparicao) {
    // Verificar por uma capsula existente com o termo
    pont_capsula capsula_existente = verificaExis(heap, termo);
    
    if (capsula_existente != NULL) {
        // Se a capsula existir, insere o novo idDoc e qtde na lista de idDocQtd
        insere(&(capsula_existente->idDocQtd), idDoc, qtdAparicao);
    } else {
        // Se a capsula não existir, cria uma nova capsula
        pont_capsula nova_capsula = criaCapsula(termo, idDoc, qtdAparicao);
        if (nova_capsula == NULL) {
            printf("Erro ao criar a nova capsula.\n");
            return;
        }

        // Inserir a nova capsula no heap
        if (*heap == NULL) {
            *heap = nova_capsula;
        } else {
            pont_capsula temporario = *heap;
            while (temporario->proxCapsula != NULL) {
                temporario = temporario->proxCapsula;
                compInsercaoHash++;
            }
            temporario->proxCapsula = nova_capsula;
        }
    }
}

void imprimeCapsulas(pont_capsula head /*linha da tabela hash*/) {
    pont_capsula atual = head;
    while (atual != NULL) {
        printf("%s ", atual->termo);
        imprimeLista(atual->idDocQtd);
        atual = atual->proxCapsula;
        printf("\n");
    }
}

void imprimeAllCapsulas(pont_capsula head[], int tamanho_da_hashTable) {
    for (int i = 0; i < tamanho_da_hashTable; i++) {
        imprimeCapsulas(head[i]);
    }
}

void busca(pont_capsula heap[], char termo[300], unsigned peso[]) {
    
    
    int codigo = Hash_code(termo, peso);

    printf("TERMO NA BUSCA: %s\n", termo);
    printf("HASH CODE NA PESQUISA: %d\n", codigo);

    pont_capsula temporario = heap[codigo];

    // Enquanto não encontrar o termo ou chegar ao final da lista encadeada
    while (temporario != NULL && strcmp(termo, temporario->termo) != 0) {
        temporario = temporario->proxCapsula;
        compInsercaoHash ++;

    }

    if (temporario != NULL && strcmp(termo, temporario->termo) == 0) {
        printf("Termo encontrado na Hash Table.\n");
        printf("%s ", temporario->termo);
        imprimeLista(temporario->idDocQtd);
    } else {
        printf("Termo não encontrado\n");
    }
}

int buscaHashCont(pont_capsula heap[], string termo, unsigned peso[]) {
    int compBuscaHash = 0;

    int codigo = Hash_code(termo, peso);

    printf("TERMO NA BUSCA: %s\n", termo);
    printf("HASH CODE NA PESQUISA: %d\n", codigo);

    pont_capsula temporario = heap[codigo];

    // Enquanto não encontrar o termo ou chegar ao final da lista encadeada
    while (temporario != NULL && strcmp(termo, temporario->termo) != 0) {
        temporario = temporario->proxCapsula;
        compBuscaHash++;
    }

    if (temporario != NULL && strcmp(termo, temporario->termo) == 0) {
        printf("Termo encontrado na Hash Table.\n");
        printf("%s ", temporario->termo);
        imprimeLista(temporario->idDocQtd);
        compBuscaHash++; //pois se achar de primeira tambem conta como verificado
    } else {
        printf("Termo não encontrado\n");
    }

    return compBuscaHash;
}
