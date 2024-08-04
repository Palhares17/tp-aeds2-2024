#include "lista.h"

/*
 * Autor: Gabriel de pádua 
 * Data: 01/08
 * Versão: 1.0.0
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */

// pont_lista criaNo(int id_doc, int qtd_aparecicao){
// 	/*vai ser criado um pontoiro de novo nó, 
// 	se ele for criado novo_no não sera nulo;*/
// 	pont_lista novo_no = (pont_lista) malloc(sizeof(Lista));
// 	if (novo_no == NULL){
// 		printf("Erro ao alocar memoria.\n");
// 		return NULL;
// 	}

// 	novo_no->idDoc = id_doc;
// 	novo_no->qtde = qtd_aparecicao;
// 	novo_no->proxDoc = NULL;
// 	return novo_no;
// }

pont_lista criaNo(int id_doc, int qtd_aparecicao) {
    pont_lista novo_no = (pont_lista) malloc(sizeof(Lista));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    novo_no->idDoc = id_doc;
    novo_no->qtde = qtd_aparecicao;
    novo_no->proxDoc = NULL;
    return novo_no;
}

//funçao que  ve se lista é esta vazia; retorna 1 se for e 0 se nao 
int vaziaounao(pont_lista Lista){
	return Lista == NULL;
}

// void imprimeLista(pont_lista Lista){
// 	pont_lista temporario = Lista;
// 	while (temporario != NULL){
// 		printf("idDoc: %d, Quantidade de aparição: %d\n",temporario->idDoc,temporario->qtde);
// 		temporario = temporario-> proxDoc;
// 	}
// 	return;
// }

void imprimeLista(pont_lista Lista) {
    pont_lista temporario = Lista;
    while (temporario != NULL) {
        printf("  Documento ID: %d, Quantidade: %d\n", temporario->idDoc, temporario->qtde);
        temporario = temporario->proxDoc;
    }
}

// void insere(pont_lista* Lista,int idDoc, int qtde){
// 	pont_lista novo_no = criaNo(idDoc,qtde);
// 	if(vaziaounao(*Lista)){
// 		*Lista = novo_no;
// 	}else{
// 		pont_lista temporario = *Lista;
// 		while (temporario->proxDoc != NULL)
// 		{
// 			temporario = temporario->proxDoc;
// 		}
// 		temporario->proxDoc = novo_no;
		
// 	}
// }

void insere(pont_lista* Lista, int idDoc, int qtde) {
    pont_lista novo_no = criaNo(idDoc, qtde);
    if (*Lista == NULL) {
        *Lista = novo_no;
    } else {
        pont_lista temporario = *Lista;
        while (temporario->proxDoc != NULL) {
            temporario = temporario->proxDoc;
        }
        temporario->proxDoc = novo_no;
    }
}

