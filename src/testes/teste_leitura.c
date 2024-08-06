#include "../leitura/leitura.h"
#define M 23


void MostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Pesquisar termos na Hash\n");
    printf("2 - Mostrar qtd/iddoc çlde todas as palavras da Hash table\n");
    printf("3 - Mostrar termo por relevância na Hash table\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
  

	
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    lerArquivos(hash, pesos);



	// int op = 100; 
	// while (op != 0)
	// {
		
	// 	MostrarMenu();
	// 	scanf("%d",&op);

	// 	switch (op){
	// 	case 1:
	// 		printf ("digite o(s) termo(s) que deseja buscar na tabela hash:\n");
	// 		char termo[100];
	// 		scanf("%s",termo);
	// 		busca(vetor_de_heads,termo,pesos);
	// 		break;

	// 	case 2:
	// 		printf("escolha como deseja que seja mostrado:\n");
	// 		printf("\tA) Ordem de indexação na tabela hash:\n");
	// 		printf("\tB) Ordem aufabetica e por IdDoc");

	// 		char opc;
	// 		scanf("%c",&opc);
	// 		if (opc == 'A')
	// 		{
	// 			imprimeAllCapsulas(hash,23);
	// 		}
	// 		if (opc == 'B')
	// 		{
	// 			continue;
	// 		}
			
			

			
		
	// 	default:
	// 		break;
	// 	}
	// }

	// imprimeCapsulas(vetor_de_heads[1]);

	// busca(vetor_de_heads,vetor_de_heads[1]->termo,pesos);

	imprimeCapsulas(vetor_de_heads);

	
    return 0;
}


