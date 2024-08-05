/*
 * Autor: Gabriel de pádua 
 * Data: 30/07
 * Versão: 1.0.2
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */
#include "../hash/hash.h"

int main(){

	//testando o casting:
	int pesos[23];
	for(int i = 0; i < 23; i++) {
    pesos[i] = 1;
    }
	int valorAscii = Casting("a",pesos);//pesos tao valendo vezes 1;
	printf("valor de a: %d\n",valorAscii);

	//tetando agr com pesos:
	GeraPesos(pesos);
	valorAscii = Casting("a",pesos);//pesos gerados aleatoriamente 
	printf("valor de <a> com peso: %d\n",valorAscii);

	//testando hashcode
	int code = Hash_code("a",pesos);
	printf("valor de hashcode de <a> com peso: %d\n",code);

	//funcionamento das capsulas 
    pont_capsula head = NULL;

    // Insere algumas capsulas para teste
    insereCapsula(&head, "exemplo1", 1, 5);
    insereCapsula(&head, "exemplo2", 2, 3);
    insereCapsula(&head, "exemplo3", 3, 8);

    // Imprime todas as capsulas
    printf("Capsulas inseridas:\n");
    imprimeCapsulas(head);


	return 0;
}
