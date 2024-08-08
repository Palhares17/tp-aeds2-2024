#include "leitura/leitura.h"
#include "util/util.h"
#define M 23



int main() {
    limpaTerminal();
    //inicializa hash
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    //Incializando patricia
    Apontador raiz = NULL;

    lerArquivos(hash, pesos, &raiz);


    //menu
    int op = 100;
    int processo = 1;



    while (op != 0)
    {
        mostrarMenu();
        scanf("%d",&op);
        switch (op){

        case 1:
            mudaCor('V');
            printf("-----------------------------------------------------------------\n");
            imprimeAllCapsulas(hash, 23);
            printf("-----------------------------------------------------------------\n");
            mudaCor('B');
            break;
        case 2:
            mudaCor('V');
            printf("-----------------------------------------------------------------\n");
            ImprimirPalavras(raiz);
            printf("-----------------------------------------------------------------\n");
            mudaCor('B');
            break;
        case 3:
            mudaCor('V');
            char termo[100];
            printf("-----------------------------------------------------------------\n");
            printf("digite o(s) termo(s) que deseja buscar na tabela hash:\n");
            scanf(" %[^\n]", termo);
            busca(vetor_de_heads, termo, pesos);
            printf("\n-----------------------------------------------------------------\n");
            mudaCor('B');
            break;
        case 4:
            mudaCor('V');
            printf("-----------------------------------------------------------------\n");
            char t[100];
            printf("digite o(s) termo(s) de busca:\n");
            scanf(" %[^\n]", t);
            qtd_iddoc(15, raiz, t);
            //compBuscaPatricia = 0;
            printf("-----------------------------------------------------------------\n");
            mudaCor('B');
            break;
        case 5: 
            mudaCor('V');
            printf("-----------------------------------------------------------------\n");
            printf("digite o(s) termo(s) para calcular a relevancia:\n");
            scanf("%s", termo);
            calcularRelevancia(15, raiz,termo);
            printf("-----------------------------------------------------------------\n");
            mudaCor('B');
            break;
        case 6:
            mudaCor('V');
            printf("-----------------------------------------------------------------\n");
            ImprimirPalavras(raiz);
            printf("-----------------------------------------------------------------\n");
            mudaCor('B');
            break;
        case 7:
            int searchHeash = 1000;
            int searchPATR = 1000 ;
            mudaCor('V');
            char procura[3000];
            //char *procura;
            printf("Qual termo deseja buscar e ver as compraçoes (Busque termos existentes)\n");
            scanf("%s",procura);
            //printf("%s",procura);
            // printf("$$$$$$$$$$$$$$$$$$");
            // busca(hash,procura,pesos);
            int ProH = buscaHashCont(hash,procura,pesos);//procura na Hash
            int ProPat  = pesquisaContandoPatr(15,raiz,procura); //procura na PATRICIA
            // printf("\n");
            // busca(hash,procura,pesos);
            // printf("\n");

            printf("\nPara realizar a busca foram feitas:\n");
            printf("\t%d comparações na Hash;\n",ProH);
            printf("\t%d comparações na PATRICIA;\n",ProPat);
            break;       
        
        default:
            break;
        }

    }



        limpaTerminal();
        limpaTerminal();
        mudaCor('G');
        printf("-----------------------------------------------------------------------\n");
        printf("Concluimos que o mais eficiente, tratando-se de termo de indexação (adicionar ou buscar)\npalavras/termos é a: ");
    if (compInsercaoHash < compInsercaoPatricia)
        printf("Hash.\n\nEla compara menos vezes ate achar o indince certo.\nComparações: HASH = %d | PATRICIA = %d.\nPortando podemos dizer que neste caso, a Hash se mostrou cerca de %2.f veses mais \neficiente em operaçoes de adicionar ou buscar\n\n", compInsercaoHash, compInsercaoPatricia,(((float)compInsercaoPatricia  / (float)compInsercaoHash)));
    else
        printf("Patricia.\nEla compara menos vezes ate achar o indince certo.\nComparações: HASH = %d | PATRICIA = %d\nPortando podemos dizer que neste caso, a Patricia se mostrou cerca de %2.f veses mais \neficiente em operaçoes de adicionar ou buscar", compInsercaoHash, compInsercaoPatricia,(((float)compInsercaoHash  /  (float)compInsercaoPatricia)));

    printf("\nMas nem tudo é melhor pra hash, ja que quando se trata de ordenação ela se mostra muito pior\nvisto que seria preciso percorre-la por completo e ordenando pra conseguir\n\n");
    printf("-----------------------------------------------------------------------\n");

    return 0;
}
