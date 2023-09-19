#include "../alunos/alunos.c"
#include "cursos.h"

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

    Var_Cursos->alunos = NULL;

    return Var_Cursos;
}

Cursos *Matricula_Alunos(Alunos *Var_Aluno) {
    
}

