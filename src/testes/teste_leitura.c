#include "../leitura/leitura.h"
#define M 23

int main() {
  

	
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    lerArquivos(hash, pesos);


	// int op = 0;
	// while (op != -1)
	// {
		
	// }
	
	//imprimeCapsulas(vetor_de_heads[1]);
	imprimeAllCapsulas(hash,M);



    return 0;
}



void mostrarOp(){
	printf("1) - Ler os aquivos e construir o indece invertido na tabela hash e patricia ");
}
