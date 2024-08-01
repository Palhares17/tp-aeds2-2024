#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef char *string;

typedef struct Capsula{
    string termo;
    //lista nó -> com ID , QUANT, P_PROX
}Capsula;

void GeraPesos(unsigned p[]);

int Casting(string termo,unsigned peso[]);

int Hash_code(string termo,unsigned peso[]);


