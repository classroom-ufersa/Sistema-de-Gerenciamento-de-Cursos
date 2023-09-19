#include "../alunos/alunos.c"
#include "cursos.h"

struct cursos {
    char nome[40];
    int codigo;
    int vagas;
    int alunos; // alunos matriculados no curso.
    
};

Cursos *Criar_Cursos(char *nome, int codigo, int vagas, int alunos) {
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos));
    if(Var_Cursos == NULL) {
        printf("Variavel Var_Alunos nao foi alocada dinamicamente! \n");
        exit(1);
    }

    strcpy(Var_Cursos->nome, nome);
    Var_Cursos->codigo = codigo;
    Var_Cursos->vagas = vagas;
    Var_Cursos->alunos = alunos;

    return Var_Cursos;
}