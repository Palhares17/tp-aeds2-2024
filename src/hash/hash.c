/*
 * Autor: Gabriel de pádua 
 * Data: 30/07
 * Versão: 1.0.0
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */

#include "hash.h"

//a = N / M  onde N = nuemro de termos(46); M = tamanho da hash table(?); Alfa = fator de carga(quantas termos em lista quero ter media)

//pesos gernaod com tempo do sistema;
void GeraPesos(unsigned p[]){
  /* -Gera valores randomicos entre 1 e 10.000- */
  int i; 
  struct timeval semente;

  /* Utilizar o tempo como semente para a funcao srand() */
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

pont_capsula Cria_Capsula(string termo,int idDoc,int qtdAparicao){
	Capsula *temporaria;
	
	//temporaria nunca vai ser nula se a alocação der certo;
	temporaria = (Capsula*)malloc(sizeof(Capsula));
	if (temporaria == NULL){
		printf("Erro ao alocar memoria.\n");
		return NULL;//se falhar retorna nulo;
	}

	//preciso alocar memoria (string) pra guardar o termo
	temporaria->termo = (string)malloc(strlen(termo)+1);
	if (temporaria->termo == NULL) {
        printf("Erro ao alocar memoria para a string.\n");
        free(temporaria); // Liberar a memória da capsula
    return NULL;
	}
	strcpy(temporaria->termo,termo);//guardando o termo no campo certo.


	temporaria->No_id_doc = criaNo(idDoc,qtdAparicao);
	if (temporaria->No_id_doc == NULL)
	{
		printf("erro ao alocar memoria pra indexação do documento e suas aparições.\n");
		free(temporaria);
		return NULL;
	}
	
	temporaria->proxCapisula = NULL;
	return temporaria;
}