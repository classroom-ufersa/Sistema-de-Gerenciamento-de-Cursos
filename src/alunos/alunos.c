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