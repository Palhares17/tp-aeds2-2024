
#include "./patricia/patricia.h"
#include "./hash/hash.h"


void MostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Pesquisar palavra\n");
    printf("2 - Mostrar relevância\n");
    printf("3 - Mostrar qtd/iddoc de todas as palavras\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {

	//inicializando arvore e Hash
	int M = 23; 
	pont_capsula heads[23] = { NULL}; 
    Apontador arvore = NULL;

    char palavra[tam];

    FILE* f[MAX_ARQUIVOS];
    char arquivos[MAX_ARQUIVOS][50];

    // Abrir o arquivo de entrada e ler os nomes dos arquivos
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Lê o número de arquivos (N) do arquivo de entrada
    int numArquivos;
    if (fscanf(entrada, "%d", &numArquivos) != 1) {
        printf("Erro ao ler o número de arquivos.\n");
        fclose(entrada);
        return 1;
    }

    // Verifica se o número de arquivos é válido
    if (numArquivos <= 0 || numArquivos > MAX_ARQUIVOS) {
        printf("Número inválido de arquivos.\n");
        fclose(entrada);
        return 1;
    }

    // Lê os nomes dos arquivos do arquivo de entrada e armazena em arquivos
    for (int i = 0; i < numArquivos; i++) {
        if (fscanf(entrada, "%s", arquivos[i]) != 1) {
            printf("Erro ao ler o nome do arquivo %d.\n", i + 1);
            fclose(entrada);
            return 1;
        }
    }

    // Fecha o arquivo de entrada
    fclose(entrada);

    // Construir o caminho para a pasta "POCs"
    char caminho[100];
    sprintf(caminho, "ArquivosEntrada/");

    // Abrir os arquivos e processar as palavras
    for (int i = 0; i < numArquivos; i++) {
        char caminhoCompleto[150] = "ArquivosEntrada/";

        strcat(caminhoCompleto, arquivos[i]);

        f[i] = fopen(caminhoCompleto, "r");

        if (f[i] == NULL) {
            printf("Erro ao abrir o arquivo %s\n", arquivos[i]);
            for (int j = 0; j < i; j++) {
                fclose(f[j]);
            }
            return 1;
        }
    }

    int idDoc = 1;
    while (idDoc <= numArquivos) {
        while (fscanf(f[idDoc - 1], "%s", palavra) == 1) {
            // Remover caracteres especiais, acentuação e pontuação
            int len = strlen(palavra);
            for (int i = 0; i < len; i++) {
                if (!isalnum((unsigned char)palavra[i])) {
                    memmove(&palavra[i], &palavra[i + 1], len - i);
                    len--;
                    i--;
                }
            }

            // Converter a palavra para minúsculas
            for (int i = 0; i < len; i++) {
                palavra[i] = tolower((unsigned char)palavra[i]);
            }

            arvore = Insere(palavra, &arvore, idDoc);
        }
        idDoc++;
    }

    // Fechar todos os arquivos abertos
    for (int i = 0; i < numArquivos; i++) {
        fclose(f[i]);
    }

    int opcao;
    do {
        MostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char termo[tam];
                printf("Digite o termo de busca: ");
                scanf("%s", termo);
                qtd_iddoc(numArquivos, arvore, termo);
                break;
            }
            case 2: {
                char termo[tam];
                printf("Digite o termo de busca: ");
                scanf("%s", termo);
                CalcularRelevancia(numArquivos, arvore, termo);
                break;
            }
            case 3: {
                ImprimirPalavras(arvore);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
