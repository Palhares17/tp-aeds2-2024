#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoOcorrencia {
    char string[256];
    int idDoc;
    int qtde;
} TipoOcorrencia;

typedef struct CelulaOcorrencia *Ponteiro;
typedef struct CelulaOcorrencia {
    TipoOcorrencia ocorrencia;
    Ponteiro prox;
} CelulaOcorrencia;

typedef struct Ocorrencialista {
    CelulaOcorrencia *Primeiro, *Ultimo;
} OcorrenciaLista;

void ListaOcorrenciaVazia(OcorrenciaLista *lista) {
    lista->Primeiro = (Ponteiro)malloc(sizeof(CelulaOcorrencia));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

short OcorrenciaVazia(OcorrenciaLista lista) {
    return lista.Primeiro == lista.Ultimo;
}

void InserirOcorrencia(TipoOcorrencia x, OcorrenciaLista *lista) {
    Ponteiro novaCelula = (Ponteiro)malloc(sizeof(CelulaOcorrencia));
    novaCelula->ocorrencia = x;
    novaCelula->prox = NULL;
    lista->Ultimo->prox = novaCelula;
    lista->Ultimo = novaCelula;
}

void InicializaOcorrencia(OcorrenciaLista lista) {
    OcorrenciaVazia(lista);
}

void ImprimeLista(OcorrenciaLista *lista) {
    printf("Entrou na função imprime lista\n");
    Ponteiro aux;
    aux = lista->Primeiro->prox;

    while (aux != NULL) {
        printf("%s <%d|%d>\n", aux->ocorrencia.string, aux->ocorrencia.idDoc, aux->ocorrencia.qtde);
        aux = aux->prox;
    }
}