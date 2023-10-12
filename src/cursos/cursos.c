#include "cursos.h"
#include "../alunos/alunos.c"

#define VAGAS 3

struct cursos {
    char nome[50];
    int codigo;
    int vagas;
    ListaMatricula *alunos;
};

struct listamatricula {
    Alunos aluno;
    Cursos curso;
    ListaMatricula *prox;
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

int CompararCodigo(Cursos *Var_Cursos, int codigo, int contador2) {
    for(int i = 0; i < contador2; i++) {
        if(Var_Cursos[i].codigo == codigo) {
            return 1;
        }
    }
    return 2;
}

void MatricularAlunoEmCurso(Alunos* aluno, Cursos* curso, ListaMatricula **lista) {
    // Verifica se o curso tem vagas disponíveis
    if (curso->vagas > 0) {
        // Verifica se o aluno já está matriculado no curso
        ListaMatricula *NovaLista  = *lista;

        // Aloca espaço para a matrícula
        ListaMatricula* matricula = (ListaMatricula*)malloc(sizeof(ListaMatricula));
        if (matricula == NULL) {
            printf("Erro ao alocar memória para matrícula!\n");
            exit(1);
        }

        while (NovaLista != NULL) {
            if (NovaLista->aluno.numero_matricula == aluno->numero_matricula && NovaLista->curso.codigo == curso->codigo) {
                printf("O aluno ja esta matriculado nesta disciplina.\n");
                return;
            }
            NovaLista = NovaLista->prox;
        }

        // Preenche os dados da matrícula
        matricula->aluno = *aluno;
        matricula->curso = *curso;
        matricula->prox = NULL;

        // Adiciona a matrícula à lista de matrículas do curso
        if (*lista == NULL) {
            *lista = matricula;
        } else {
            // Percorre a lista de matrículas e insere no final
            ListaMatricula* NovaLista = *lista;
            while (NovaLista->prox != NULL) {
                NovaLista = NovaLista->prox;
            }
            NovaLista->prox = matricula;
        }

        // Decrementa o número de vagas disponíveis no curso
        curso->vagas--;

        printf("Aluno %s matriculado no curso %s.\n", aluno->nome, curso->nome);
    } else {
        printf("Desculpe, o curso %s esta lotado.\n", curso->nome);
    }
}

void ImprimirListaMatriculas(ListaMatricula *listaMatriculas) {
    ListaMatricula *temp = listaMatriculas;

    printf("=====================\n");
    printf("Lista de Matriculas:\n");
    printf("=====================\n");

    while (temp != NULL) {
        printf("Nome do Aluno: %s\n", temp->aluno.nome);
        printf("Matricula do Aluno: %d\n", temp->aluno.numero_matricula);
        printf("Notas do Aluno:\n");
        for (int i = 0; i < 3; i++) {
            printf("Nota %d: %.2f\n", i + 1, temp->aluno.notas[i]);
        }
        printf("Curso Matriculado: %s\n", temp->curso.nome);
        printf("Codigo do Curso: %d\n", temp->curso.codigo);
        printf("=====================\n");

        temp = temp->prox;
    }
}
