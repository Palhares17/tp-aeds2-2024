/*
 * Autor: Gabriel de pádua 
 * Data: 30/07
 * Versão: 1.0.0
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */
#include "../hash/hash.h"

int main(){

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
