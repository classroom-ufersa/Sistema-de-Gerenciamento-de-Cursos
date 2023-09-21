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

    Var_Cursos->alunos = NULL;

    return Var_Cursos;
}

Cursos *Matricula_Alunos(Alunos *Var_Aluno, Cursos *Var_Cursos, int vagas) {

    //printf("\n\n%d\n\n", Var_Cursos->vagas); valor lixo

    if (Var_Cursos->vagas >= VAGAS) {
        printf("Vagas cheias no curso %s!\n", Var_Cursos->nome);
        return Var_Cursos; // Retorna o curso sem fazer a matrícula
    }

     if(Var_Cursos->vagas > 0) {
        printf("\n\n%d\n\n", Var_Cursos->vagas);
    } 

    if(Var_Cursos->vagas > 0) {
        ListaAlunos *novo = (ListaAlunos*)malloc(sizeof(ListaAlunos));
        if(novo == NULL) {
            printf("A variavel novo nao foi alocada! \n");
            exit(1);
        }

        novo->aluno = *Var_Aluno;
        novo->prox = Var_Cursos->alunos;
        Var_Cursos->alunos = novo;

        printf("Aluno matriculado com sucesso no curso %s!\n", Var_Cursos->nome);

        Var_Cursos->vagas--;

        return Var_Cursos;

    } else {
        printf("Vagas cheias no curso %s!\n", Var_Cursos->nome);
        return NULL; // Retorna NULL para indicar que a matrícula não foi feita
    }
}








