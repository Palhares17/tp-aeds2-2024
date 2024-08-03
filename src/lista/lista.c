#include "lista.h"

pont_lista criaNo(int id_doc, int qtd_aparecicao){
	/*vai ser criado um pontoiro de novo nó, 
	se ele for criado novo_no não sera nulo;*/
	pont_lista novo_no = (pont_lista) malloc(sizeof(Lista));
	if (novo_no == NULL){
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

void imprimeLista(pont_lista Lista){
	pont_lista temporario = Lista;
	while (temporario != NULL){
		printf("idDoc: %d, Quantidade de aparição: %d\n",temporario->idDoc,temporario->qtde);
		temporario = temporario-> proxDoc;
	}
	return;
}

// void Inicializa_Lista(pont_lista *no){
//     //se nao existir lista, aloco e crio uma
//     //quantidade ja se inicia com 1, pois se existe a palavra existe ao menos 1 ocorrencia
//     if (no == NULL){
//         no = (Pont_lista*) malloc(sizeof(Pont_lista));
//         (*no)->qtde = 1;
//     }
    
// }

void insere(pont_lista* Lista,int idDoc, int qtde){
	pont_lista novo_no = criaNo(idDoc,qtde);
	if(vaziaounao(*Lista)){
		*Lista = novo_no;
	}else{
		pont_lista temporario = *Lista;
		while (temporario->proxDoc != NULL)
		{
			temporario = temporario->proxDoc;
		}
		temporario->proxDoc = novo_no;
		
	}
}

