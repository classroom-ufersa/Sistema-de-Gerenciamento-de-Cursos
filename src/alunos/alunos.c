#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "../cursos/cursos.h"

struct alunos {
    int numero_matricula;
    char nome[50];
    float notas[3];
    Cursos *cursos;
};

struct listaalunos {
    Alunos aluno;
    ListaAlunos *prox;
};

Alunos *Criar_Alunos(char *nome, int numero_matricula) {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    if(Var_Alunos == NULL) {
        printf("Erro ao alocar Var_Alunos dinamicamente! \n");
        exit(1);
    }

    strcpy(Var_Alunos->nome, nome);
    Var_Alunos->numero_matricula = numero_matricula;

    int contador;

    for(contador = 0; contador < 3; contador++) {
        Var_Alunos->notas[contador] = 0;
    }

    return Var_Alunos;
}

void menu() {
    printf("     MENU     \n");
    printf("==============================\n");
    printf("|1|. Realizar matricula \n");
    printf("|2|. Excluir matricula  \n");
    printf("|3|. Listar matriculados\n");
    printf("|4|. Buscar curso       \n");
    printf("|5|. Editar matricula   \n");
    printf("|6|. Consultar vagas disponiveis para um dado curso \n");
    printf("|7|. Consultar quantitativo de alunos em um curso   \n");
    printf("|8|. Sair \n");
    printf("==============================\n");
}