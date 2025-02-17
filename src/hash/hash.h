/*
 * Autor: Gabriel de pádua 
 * Data: 30/07
 * Versão: 2.0.1
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  mudança no nome das funçoes e como funcionavam
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../lista/lista.h"

typedef char *string;

typedef struct Capsula{
    string termo;
	Lista* idDocQtd;
	struct Capsula *proxCapsula;
}Capsula;

typedef Capsula* pont_capsula;


void GeraPesos(unsigned p[]);
int Casting(string termo,unsigned peso[]);
int Hash_code(string termo,unsigned peso[]);
pont_capsula criaCapsula(string termo,int idDoc,int qtdAparicao);
void insereCapsula(pont_capsula *heap, string termo, int idDoc, int qtdAparicao);
void imprimeCapsulas(pont_capsula head);
void busca(pont_capsula heap[], char *termo, unsigned peso[]);
void imprimeAllCapsulas(pont_capsula head[],int tamanho_da_hashTable);