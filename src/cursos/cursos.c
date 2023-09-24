#include "../alunos/alunos.c"
#include "../alunos/alunos.h"
#include "cursos.h"

#define VAGAS 3

union aluno_matricula {
    char nome[50];
    int matricula;
};


struct cursos {
    char nome[50];
    int codigo;
    int vagas;
    ListaAlunos *alunos;
    AlunoMatricula *MatriculaAluno;
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

    //printf("\n\nVAGAS: %d\n\n", Var_Cursos->vagas); //valor lixo

    Var_Cursos->alunos = NULL;

    return Var_Cursos;
}

void Imprimir_Cursos(Cursos *Var_Cursos, int contador2) {
    printf("==========================");
    printf("\nDISCIPLINAS DISPONIVEIS: \n");
    if(contador2 == 0) {
        printf("Nao ha nada cadastrado! \n");
        printf("========================\n");
    } else {
        for(int i = 0; i < contador2; i++) {
            printf("\n");
            printf("Nome da Disciplina %d: %s\n", i + 1, Var_Cursos[i].nome);
            printf("Codigo da Disciplina %d: %d\n", i + 1, Var_Cursos[i].codigo);
        }
        printf("==========================\n");
    } 
}