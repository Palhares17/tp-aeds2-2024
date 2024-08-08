
/*
 * Autor: Gabriel de Pádua
 * Data: 02/03/2023
 * Reutilização:
 * Versão: 1.0.0
 * Descrição: criação e teste
 *
 * Histórico:
 * 
 */


#include "util.h"

void mostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Imprimir todas as palavras (Hash):\n");
    printf("2 - Imprimir todas as palavras (PATRICIA):\n");
    printf("3 - Buscar po termos (Hash):\n");
    printf("4 - Buscar po termos (PATRICIA):\n");
    printf("5 - Executar calculo de relevância\n");
    printf("6 - Imprimir os indes invertido em ordem Alfabetica:\n");
    printf("7 - pesquisar por termo em ambas estruturas e ver quantia de compraçoes feitas:\n");
    printf("0 - Sair e Receber Conclusão.\n");
    printf("Escolha uma opção: ");
}

void limpaTerminal(){
    printf("\033[H\033[J"); //posiciona o cursor no inicio do terminal (posiçao \033[h) e limpa a partir dai (\033[j)
}

void espera(int segundos){
    sleep(segundos);
}

void mudaCor(char inicial){
    switch (inicial){

         //muda a cor no prieiro "" e depois reseta o terminal com o comando: \x1b[0m;

    case 'B'://BRANCO DEFAULT
        printf("\x1b[0m");
        break;
        
    case 'V'://VERMELHO
        printf("\x1b[31m");
        break;

    case 'R'://ROXO
        printf("\x1b[34m");
        break;


    case 'G'://VERDE
        printf("\x1b[32m");
        break;
    
    default:
        break;    
	}
}

void primeiraOP(){

    printf("\n:");
    printf("Escolha entre:\n");

    mudaCor('V');
    printf("\t1)HASH\n");

    mudaCor('R');
    printf("\t2)PATRICIA\n");

    mudaCor('G');
    printf("\t3)CONCLUSAO DE COMPARAÇÃO:");

}

void Press() {
    printf("Aperte enter para continuar...");
    char vazio;
    scanf("%c",&vazio);
}
