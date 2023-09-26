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

Alunos *Criar_Alunos(char *nome, int numero_matricula, float notas[3]) {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    if(Var_Alunos == NULL) {
        printf("Erro ao alocar Var_Alunos dinamicamente! \n");
        exit(1);
    }

    strcpy(Var_Alunos->nome, nome);
    Var_Alunos->numero_matricula = numero_matricula;

    for(int contador = 0; contador < 3; contador++) {
        Var_Alunos->notas[contador] = notas[contador];
    }

    return Var_Alunos;
} 

void Imprimir_Alunos(Alunos *Var_Alunos, int contador) {
    int Sair = 0;
    if(contador == 0) {
        printf("Nada foi cadastrado! \n");
    }
    if(Var_Alunos != NULL) {
        
        for(int i = 0; i < contador; i++) {
            printf("\n");
            printf("Nome: %s\n", Var_Alunos[i].nome);
            printf("Matricula: %d\n", Var_Alunos[i].numero_matricula);
            for(int j = 0; j < 3; j++) {
                printf("Nota %d: %.f\n", i + 1, Var_Alunos[i].notas[j]);
            }
        } 
    }
}

ListaAlunos *CriarAluno(Alunos *Var_Alunos) {
    ListaAlunos *novo = (ListaAlunos*)malloc(sizeof(ListaAlunos));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o aluno!\n");
        exit(1);
    }
    novo->aluno = *Var_Alunos;
    novo->prox = NULL;
    return novo;
}

void AdicionarAluno(ListaAlunos **lista, Alunos *Var_Alunos) {
    ListaAlunos *novo = CriarAluno(Var_Alunos);
    novo->prox = *lista;
    *lista = novo;
}

void ImprimirAlunos(ListaAlunos *lista) {
    if (lista == NULL) {
        printf("\nNenhum aluno cadastrado!\n");
    } else {

        int i = 1;
        ListaAlunos *atual = lista;

        while (atual != NULL) {
            Alunos aluno = atual->aluno;
            printf("Aluno %d:\n", i);
            printf("Nome: %s\n", aluno.nome);
            printf("Matricula: %d\n", aluno.numero_matricula);
            printf("Notas: %.2f, %.2f, %.2f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2]);
            printf("\n");
            atual = atual->prox;
            i++;
        }
    }
}

void menu() {
    printf("     MENU     \n");
    printf("==============================\n");
    printf("|1|. Cadastrar Aluno    \n");
    printf("|2|. Cadastrar Curso    \n");
    printf("|3|. Realizar matricula \n");
    printf("|4|. Excluir matricula  \n");
    printf("|5|. Listar matriculados\n");
    printf("|6|. Buscar curso       \n");
    printf("|7|. Editar matricula   \n");
    printf("|8|. Consultar vagas disponiveis para um dado curso \n");
    printf("|9|. Consultar quantitativo de alunos em um curso   \n");
    printf("|10|. Sair \n");
    printf("==============================\n");
}