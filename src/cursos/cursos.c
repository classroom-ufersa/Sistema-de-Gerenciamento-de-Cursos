#include "../alunos/alunos.c"
#include "cursos.h"

#define VAGAS 3

struct cursos {
    char nome[50];
    int codigo;
    int vagas;
    ListaAlunos *alunos;
};


Cursos *Criar_Cursos(char *nome, int codigo, int vagas) {
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos));
    if(Var_Cursos == NULL) {
        printf("Erro ao alocar Var_Cursos! \n");
        exit(1);
    }

    strcpy(Var_Cursos->nome, nome);
    Var_Cursos->codigo = codigo;
    Var_Cursos->vagas = vagas;

    printf("\n\nVAGAS: %d\n\n", Var_Cursos->vagas); //valor lixo

    Var_Cursos->alunos = NULL;

    return Var_Cursos;
}










