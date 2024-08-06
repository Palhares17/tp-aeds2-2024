#include "patricia.h"

int comparacoes = 0; // Contador global de comparações

void LerPalavra(char *p) {
    int len = strlen(p);

    // Remover caracteres especiais, acentuação e pontuação
    p[strcspn(p, ".")] = '\0';
    p[strcspn(p, ";")] = '\0';

    for (int i = 0; i < len; i++) {
        p[i] = tolower((unsigned char)p[i]);
    }
}

void Minuscula(char *p) {
    int len = strlen(p);

    for (int i = 0; i < len; i++) {
        p[i] = tolower((unsigned char)p[i]);
    }
}

void lerArquivos(Apontador *t) {
    FILE *file = fopen("entrada.txt", "r");
    char palavrasRecebidas[TAM];
    char nomesArquivos[TAM];
    char linha1[TAM_LINHA];
    char linha2[TAM_LINHA];
    char linha3[TAM_LINHA];
    int numFile = 0;

    if (file == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return;
    }

    fscanf(file, "%d", &numFile); /* Ler primeira linha */

    for (int i = 0; i < numFile; i++) {
        char arquivoCompleto[TAM] = "ArquivosEntrada/";
        int qtde = 0;
        int idDoc = 0;

        fscanf(file, "%s", nomesArquivos);
        strcat(arquivoCompleto, nomesArquivos);

        FILE *f = fopen(arquivoCompleto, "r");

        if (f == NULL) {
            perror("Erro ao abrir o arquivo");
            continue;  // Ir para o próximo arquivo na lista
        }

        /* Lendo a primeira linha */
        if (fgets(linha1, TAM_LINHA, f) == NULL) {
            perror("Erro ao ler a primeira linha");
            fclose(f);
            continue;
        }

        /* Lendo a segunda linha */
        if (fgets(linha2, TAM_LINHA, f) == NULL) {
            perror("Erro ao ler a segunda linha");
            fclose(f);
            continue;
        }

        /* Lendo a segunda linha */
        if (fgets(linha3, TAM_LINHA, f) == NULL) {
            perror("Erro ao ler a terceira linha");
            fclose(f);
            continue;
        }

        LerPalavra(linha1);
        Minuscula(linha3);

        linha2[strcspn(linha2, "\n")] = '\0';  // Remove o '\n' no final
        char *token = strtok(linha2, ";");

        while (token != NULL) {
            while (*token == ' ') token++;
            char *end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';

            LerPalavra(token);

            int idDoc = i + 1;
            qtde++;

            if (strstr(linha1, token) != NULL) {
                qtde++;
                *t = InserePatricia(token, t, idDoc, qtde);
            } else {
                *t = InserePatricia(token, t, idDoc, qtde);
            }

            if (strstr(linha3, token) != NULL) {
                qtde++;
                *t = InserePatricia(token, t, idDoc, qtde);
            } else {
                *t = InserePatricia(token, t, idDoc, qtde);
            }

            token = strtok(NULL, ";");
            qtde = 0;
        }

        fclose(f);
    }
    fclose(file);
}
char Caractere(int i, String k) {
    return k[i];
}

short EExterno(Apontador p) {
    return p->TNo == Externo;
}

short EInterno(Apontador p) {
    return p->TNo == Interno;
}

Apontador CriaNoInt(int i, Apontador *Esq, Apontador *Dir, char Caractere) {
    Apontador p;
    p = (Apontador)malloc(sizeof(TipoPatNo));
    p->TNo = Interno;
    p->NO.NInterno.Esq = *Esq;
    p->NO.NInterno.Dir = *Dir;
    p->NO.NInterno.Index = i;
    p->NO.NInterno.caractere = Caractere;
    return p;
}

Apontador CriaNoExt(String k, Apontador *t, int idDoc, int repeticao) {
    Apontador p;
    p = (Apontador)malloc(sizeof(TipoPatNo));
    p->TNo = Externo;
    p->NO.NExterno.Chave = (String)malloc((strlen(k) + 1) * sizeof(char));
    strcpy(p->NO.NExterno.Chave, k);

    p->NO.NExterno.indice_invertido = criaNo(idDoc, repeticao);

    return p;
}

Apontador InsereEntre(String k, Apontador* t, int i, char diff, int idDoc, int repeticao) {
    Apontador p;
    if (EExterno(*t)) {
        p = CriaNoExt(k, &p, idDoc, repeticao);
        if (strcmp((*t)->NO.NExterno.Chave, k) < 0) {
            return (CriaNoInt(i, t, &p, diff));
        } else {
            return (CriaNoInt(i, &p, t, diff));
        }
    } else if (i < (*t)->NO.NInterno.Index) {
        p = CriaNoExt(k, &p, idDoc, repeticao);
        if (k[i] < diff) {
            return (CriaNoInt(i, &p, t, diff));
        } else {
            return (CriaNoInt(i, t, &p, diff));
        }
    } else {
        int index = (*t)->NO.NInterno.Index;
        if (Caractere(index, k) >= (*t)->NO.NInterno.caractere) {
            (*t)->NO.NInterno.Dir = InsereEntre(k, &(*t)->NO.NInterno.Dir, i, diff, idDoc, repeticao);
        } else {
            (*t)->NO.NInterno.Esq = InsereEntre(k, &(*t)->NO.NInterno.Esq, i, diff, idDoc, repeticao);
        }
    }
    return (*t);
}

Apontador InserePatricia(String k, Apontador* t, int idDoc, int repeticao) {
    Apontador p;
    int i;
    char caractere;
    char charDiff;

    if (strlen(k) < 3) {
        return (*t);
    }

    if (*t == NULL) {
        return (CriaNoExt(k, &p, idDoc, repeticao));
    } else {
        p = *t;
        while (!EExterno(p)) {
            if (p->NO.NInterno.Index > strlen(k)) {
                caractere = k[strlen(k)];
            } else {
                caractere = Caractere(p->NO.NInterno.Index, k);
            }
            comparacoes++; // Contador de comparações
            if (caractere < p->NO.NInterno.caractere) {
                p = p->NO.NInterno.Esq;
            } else {
                p = p->NO.NInterno.Dir;
            }
        }
        if (strcasecmp(k, p->NO.NExterno.Chave) == 0) {
            if (p->NO.NExterno.indice_invertido->idDoc != idDoc) {
                InserePatricia(&p->NO.NExterno.indice_invertido, idDoc, repeticao);
            }
            return (*t);
        } else {
            i = 0;
            while (i < strlen(k) && tolower(Caractere(i, k)) == tolower(Caractere(i, p->NO.NExterno.Chave))) {
                i++;
                comparacoes++; // Contador de comparações
            }
            if (i < strlen(k)) {
                if (tolower(Caractere(i, k)) > tolower(Caractere(i, p->NO.NExterno.Chave))) {
                    charDiff = k[i];
                } else {
                    charDiff = p->NO.NExterno.Chave[i];
                }
                comparacoes++; // Contador de comparações
            } else {
                charDiff = '\0';
            }
            return InsereEntre(k, t, i, charDiff, idDoc, repeticao);
        }
    }
}
void Pesquisa(String k, Apontador t) {
    if (t == NULL) {
        printf("A árvore está vazia!!!\n");
        return;
    }
    if (EExterno(t)) {
        if (strncasecmp(k, t->NO.NExterno.Chave, strlen(k)) == 0) {
            printf("Palavra %s encontrada:\n", t->NO.NExterno.Chave);
            imprimeLista(t->NO.NExterno.indice_invertido);
            printf("\n");
        }
    } else {
        // Contagem de comparações para a busca
        int index = t->NO.NInterno.Index;
        comparacoes++; // Contador de comparações
        if (Caractere(index, k) >= t->NO.NInterno.caractere) {
            Pesquisa(k, t->NO.NInterno.Dir);
        } else {
            Pesquisa(k, t->NO.NInterno.Esq);
        }
    }
}


void ImprimirPalavras(Apontador t) {
    if (t == NULL) {
        return;
    }
    if (EExterno(t)) {
        printf("Palavra: %s ", t->NO.NExterno.Chave);
        imprimeLista(t->NO.NExterno.indice_invertido);
        printf("\n");
    } else {
        ImprimirPalavras(t->NO.NInterno.Esq);
        ImprimirPalavras(t->NO.NInterno.Dir);
    }
}

void qtd_iddoc(int numDocumentos, Apontador t, String termo) {
    if (t == NULL) {
        printf("A árvore está vazia!!!\n");
        return;
    }
    Apontador p = t;
    while (!EExterno(p)) {
        int index = p->NO.NInterno.Index;
        if (Caractere(index, termo) >= p->NO.NInterno.caractere) {
            p = p->NO.NInterno.Dir;
        } else {
            p = p->NO.NInterno.Esq;
        }
    }
    if (strncasecmp(termo, p->NO.NExterno.Chave, strlen(termo)) == 0) {
        printf("Termo '%s' encontrado:\n", p->NO.NExterno.Chave);
        imprimeLista(p->NO.NExterno.indice_invertido);
        printf("\n");
    } else {
        printf("Termo '%s' não encontrado na árvore.\n", termo);
    }
}

void CalcularRelevancia(int numDocumentos, Apontador t, String termo) {
    if (t == NULL) {
        printf("A árvore está vazia!!!\n");
        return;
    }
    int q = strlen(termo);
    int N = numDocumentos;
    Apontador p = t;
    while (!EExterno(p)) {
        int index = p->NO.NInterno.Index;
        if (Caractere(index, termo) >= p->NO.NInterno.caractere) {
            p = p->NO.NInterno.Dir;
        } else {
            p = p->NO.NInterno.Esq;
        }
    }
    if (strncasecmp(termo, p->NO.NExterno.Chave, strlen(termo)) == 0) {
        printf("Termo '%s' encontrado:\n", p->NO.NExterno.Chave);
        Lista* atual = p->NO.NExterno.indice_invertido;
        while (atual != NULL) {
            int f = atual->qtde;
            double w = (f > 0) ? f * log10((double)N / f) / q : 0;
            if (f > 0) {
                printf("Documento %d: relevância %.2f\n", atual->idDoc, w);
            }
            atual = atual->proxDoc;
        }
    } else {
        printf("Termo '%s' não encontrado na árvore.\n", termo);
    }

}
// Exemplo de uso
int main() {
    Apontador raiz = NULL;
    // Inserções e buscas
    InserePatricia("termo", &raiz, 1, 3);
    printf("Número de comparações na inserção: %d\n", comparacoes);

    comparacoes = 0; // Resetar contador antes da busca
    Pesquisa("termo", raiz);
    printf("Número de comparações na busca: %d\n", comparacoes);

    return 0;
}