/*
 * Autor: Gabriel de pádua 
 * Data: 01/08
 * Versão: 1.0.0
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
    int idDoc;//identificação do documento;
    int qtde; //quantidade de vez que a palavra aparece;
    struct Lista *proxDoc; //ponteiro pro proximo no da lista 

} Lista;

typedef struct Lista* pont_lista;

pont_lista criaNo(int id_doc, int qtd_aparecicao);
int vaziaounao(pont_lista Lista);
void imprimeLista(pont_lista Lista);
void insere(pont_lista* Lista,int idDoc, int qtde);