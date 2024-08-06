
#include "./patricia/patricia.h"
#include "./leitura/leitura.h"
#define M 23

void MostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Pesquisar termos na Hash\n");
    printf("2 - Mostrar qtd/iddoc de todas as palavras da Hash table\n");
	printf("3 - Executar calculo de relevância da Hash");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

	
	// Incializando patricia
    Apontador raiz = NULL;

    lerArquivos(hash, pesos, raiz);

	int processo;
	printf("Esolha entre PATRICIA(1) e a HASH(2)\n");
	scanf("%d", processo);


	switch (processo) {
		case 1:
			int op = 100; 

			while (op != 0) {
				MostrarMenu();
				scanf("%d",&op);

				switch (op){
				case 1:
					printf ("digite o(s) termo(s) que deseja buscar na tabela hash:\n");
					char termo[100];
					scanf("%s",termo);
					busca(vetor_de_heads,termo,pesos);
					break;

				case 2:
					imprimeAllCapsulas(hash,23);
					break;
					
				case 3:
					CalcularRelevanciaHash(vetor_de_heads,termo,pesos, 15);
					break;
				case 0:
					printf("Voce saiu da hash\n");
				default:
					break;
				}
			}

				break;
			
			default:
				break;
		case 2:
			int op = 100; 
			
			while (op != 0) {
				MostrarMenu();
				scanf("%d",&op);

				switch (op){
				case 1:
					printf ("digite o(s) termo(s) que deseja buscar na tabela hash:\n");
					char termo[100];
					scanf("%s",termo);
					busca(vetor_de_heads,termo,pesos);
					break;

				case 2:
					imprimeAllCapsulas(hash,23);
					break;
					
				case 3:
					CalcularRelevanciaHash(vetor_de_heads,termo,pesos, 15);
					break;
				case 0:
					printf("Voce saiu da hash\n");
				default:
					break;
				}
			}
			
	}
			
	imprimeCapsulas(vetor_de_heads[1]);

	busca(vetor_de_heads,vetor_de_heads[1]->termo,pesos);

	
    return 0;
}


