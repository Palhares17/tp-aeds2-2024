/*
 * Autor: Gabriel de pádua 
 * Data: 30/07
 * Versão: 1.1.0
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

//pesos gernaod com tempo do sistema;
void GeraPesos(unsigned p[]){
  //Gera valores randomicos entre 1 e 10.000
  int i; 
  struct timeval semente;

  //Utilizar o tempo como semente para a funcao srand()
  gettimeofday(&semente,NULL); 
  srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));

  for (i = 0; i < 11; i++)
     p[i] = 1 + (int) (10000.0 * rand()/(RAND_MAX + 1.0));
}

int Casting(string termo,unsigned peso[]){

	int i= 0;
	int soma = 0;


	while (termo[i] != '\0')
	{
		soma = soma + ((int)termo[i] * peso[i]);
	}

	return soma;
}

int Hash_code(string termo,unsigned peso[]){
	int code;
	code  = Casting(termo,peso) % 23;
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

    temporaria->idDocQtd = *criaNo(idDoc, qtdAparicao);
    if (&temporaria->idDocQtd == NULL) {
        printf("Erro ao alocar memoria para indexação do documento e suas aparições.\n");
        free(temporaria->termo);
        free(temporaria);
        return NULL;
    }

    temporaria->proxCapsula = NULL;
    return temporaria;
}

void insereCapsula(pont_capsula *heap, string termo, int idDoc, int qtdAparicao) {
    pont_capsula nova_capsula = criaCapsula(termo, idDoc, qtdAparicao);
    if (nova_capsula == NULL) {
        printf("Erro ao criar a nova capsula.\n");
        return;
    }

    if (*heap == NULL) {
        *heap = nova_capsula;
    } else {
        pont_capsula temporario = *heap;
        while (temporario->proxCapsula != NULL) {
            temporario = temporario->proxCapsula;
        }
        temporario->proxCapsula = nova_capsula;
    }
}

void imprimeCapsulas(pont_capsula head) {
    pont_capsula atual = head;
    while (atual != NULL) {
        printf("Termo: %s\n", atual->termo);
        imprimeLista(&atual->idDocQtd);
        atual = atual->proxCapsula;
    }
}