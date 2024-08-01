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
	
}

int Hash_code(string termo,unsigned peso[]){
	int code;
	code  = Casting(termo,peso) % 23;
}

