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

void ImprimirListaMatriculas(ListaMatricula *lista, Cursos *cursos, int contador) {
    for (int i = 0; i < contador; i++) {
        Cursos cursoAtual = cursos[i];
        ListaMatricula *NovaLista = lista;
        int Matriculados = 0; 
        int Sair = 0;

        printf("=====================\n");
        printf("Disciplina: %s\n", cursoAtual.nome);
        printf("Codigo: %d\n", cursoAtual.codigo);
        printf("=====================\n");

        while (NovaLista != NULL) {
            if (NovaLista->curso.codigo == cursoAtual.codigo) {
                printf("Nome do Aluno: %s\n", NovaLista->aluno.nome);
                printf("Matricula do Aluno: %d\n", NovaLista->aluno.numero_matricula);
                printf("Notas do Aluno:\n");
                for (int j = 0; j < 3; j++) {
                    printf("Nota %d: %.2f\n", j + 1, NovaLista->aluno.notas[j]);
                }
                printf("\n");
                Matriculados++; 
            }
            NovaLista = NovaLista->prox;
        }

        if (Matriculados == 0) {
            printf("Nao ha alunos matriculados neste curso ainda! \n");
        }

        printf("=====================\n\n");
        printf("Digite 2 para sair -> ");
        scanf("%d", &Sair);
        if(Sair != 2) {
            while(Sair != 2) {
                printf("Digite 2 para sair -> ");
                scanf("%d", &Sair);
            }
        }
    }
}

void ExcluirMatricula(ListaMatricula **lista, char *NomeAluno, int CodigoDisciplina) {
    ListaMatricula *ListaAtual = *lista;
    ListaMatricula *ListaAnterior = NULL;

    while (ListaAtual != NULL) {
        if (strcmp(ListaAtual->aluno.nome, NomeAluno) == 0 && ListaAtual->curso.codigo == CodigoDisciplina) {
            // Checa se o nome do aluno é igual ao nome do aluno digitado pelo usuário
            if (ListaAnterior == NULL) {
                // lista receba a a proxima lista caso lista anterior receba nada (null)
                *lista = ListaAtual->prox;
            } else {
                ListaAnterior->prox = ListaAtual->prox;
            }
            free(ListaAtual); // Exclui a matricula
            printf("Matricula excluida com sucesso! \n");
            return; // Sai no momento que a matricula for excluida
        }

        ListaAnterior = ListaAtual;
        ListaAtual = ListaAtual->prox;
    }

    printf("A matricula nao foi encontrada! \n");
}


void tratativa(int erro){
    char letra=erro;
    
    while(letra!='\n'){
        
        letra=getchar();

    }
    system("cls");

}

