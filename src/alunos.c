#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "cursos.h"

#define VAGAS 15

struct alunos {
    int codigo;
    int vagas;
    char alunos[50];
    char nome[50];
};

Alunos *Criar_Alunos(int codigo, int vagas, char *alunos, char *nome) {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    if(Var_Alunos == NULL) {
        printf("Variavel Var_Alunos nao foi alocada dinamicamente! \n");
        exit(1);
    }

    Var_Alunos->codigo;
    Var_Alunos->vagas;
    strcpy(Var_Alunos->nome, nome);
    strcpy(Var_Alunos->alunos, alunos);

    return Var_Alunos;
}
