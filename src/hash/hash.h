#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../lista/lista.h"

typedef char *string;

typedef struct Capsula{
    string termo;
	Lista *No_id_doc;
	struct Capsula *proxCapisula;
}Capsula;

typedef Capsula* pont_capsula;

void criarHash();
void GeraPesos(unsigned p[]);
int Casting(string termo,unsigned peso[]);
int Hash_code(string termo,unsigned peso[]);
//void exibirTabela(pont_capsula no_hash);
