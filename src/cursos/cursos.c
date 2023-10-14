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
    printf("\n==========================");
    printf("\nCURSOS DISPONIVEIS: \n");
    if(contador2 == 0) {
        printf("Nao ha nada cadastrado! \n");
        printf("========================\n");
    } else {
        for(int i = 0; i < contador2; i++) {
            printf("\n");
            printf("Nome do Curso %d: %s\n", i + 1, Var_Cursos[i].nome);
            printf("Codigo do Curso %d: %d\n", i + 1, Var_Cursos[i].codigo);
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

        ListaMatricula *NovaLista  = *lista;

        ListaMatricula* matricula = (ListaMatricula*)malloc(sizeof(ListaMatricula));
        if (matricula == NULL) {
            printf("Erro ao alocar memória para matrícula!\n");
            exit(1);
        }

        while (NovaLista != NULL) {
            if (NovaLista->aluno.numero_matricula == aluno->numero_matricula && NovaLista->curso.codigo == curso->codigo) {
                printf("\n=====================================================\n");
                printf("O aluno ja esta matriculado neste curso.\n");
                printf("=====================================================\n");
                return;
            }
            NovaLista = NovaLista->prox;
        }

        matricula->aluno = *aluno;
        matricula->curso = *curso;
        matricula->prox = NULL;

        if (*lista == NULL) {
            *lista = matricula;
        } else {
            // Percorre a lista de matriculas e insere no final
            ListaMatricula* NovaLista = *lista;
            while (NovaLista->prox != NULL) {
                NovaLista = NovaLista->prox;
            }
            NovaLista->prox = matricula;
        }

        // Decrementa o número de vagas disponíveis no curso
        curso->vagas--;
        
        printf("\n=======================================\n");
        printf("Aluno %s matriculado no curso %s.\n", aluno->nome, curso->nome);
        printf("=========================================\n");
    } else {
        printf("\n=====================================\n");
        printf("Desculpe, o curso %s esta lotado.\n", curso->nome);
        printf("=======================================\n");
    }
}

void ImprimirListaMatriculas(ListaMatricula *lista, Cursos *cursos, int contador) {
    for (int i = 0; i < contador; i++) {
        Cursos cursoAtual = cursos[i];
        ListaMatricula *NovaLista = lista;
        int Matriculados = 0; 
        int Sair = 0;

        printf("=====================\n");
        printf("Curso: %s\n", cursoAtual.nome);
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
    }
}

void ExcluirMatricula(ListaMatricula **lista, char *NomeAluno, Cursos *curso, int CodigoDisciplina) {
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
            printf("\nMatricula excluida com sucesso! \n");
            curso->vagas++; //recoloca a vaga que era ocupada
            return; // Sai no momento que a matricula for excluida
            //break;
        }

        ListaAnterior = ListaAtual;
        ListaAtual = ListaAtual->prox;
    }

    printf("A matricula nao foi encontrada! \n");
}

void BuscarCurso(Cursos *cursos, char *NomeCurso, int contador) {
    for(int i = 0; i < contador; i++) {
        if(strcmp(NomeCurso, cursos->nome) == 0) {
            printf("\nCurso: %s\n", cursos[i].nome);
            printf("Codigo: %d\n", cursos[i].codigo);
            printf("\n");
        } 
    }
    if(!strcmp(NomeCurso, cursos->nome) == 0) {
        printf("\nCurso nao encontrado! \n\n");
    }
}

void EditarNomeAluno(ListaMatricula **lista, int MatriculaAlunoEditar, char *NovoNomeAluno, Alunos *aluno, int contador) {
    ListaMatricula *ListaAtual = *lista;
    int matriculaEncontrada = 0;

    while (ListaAtual != NULL) {
        if (ListaAtual->aluno.numero_matricula == MatriculaAlunoEditar) {
            // Encontrou a matrícula com o aluno a ser editado
            strcpy(ListaAtual->aluno.nome, NovoNomeAluno);
            
            for(int i = 0; i < contador; i++) {
                if(aluno[i].numero_matricula == MatriculaAlunoEditar) {
                    strcpy(aluno[i].nome, NovoNomeAluno);
                }
            }

            matriculaEncontrada = 1;
            break;
        }
        ListaAtual = ListaAtual->prox;
    }

    if (matriculaEncontrada) {
        printf("Nome do aluno atualizado com sucesso!\n");
    } else {
        printf("\nAluno nao encontrado na lista de matriculas.\n");
    }
}

void EditarMatriculaAluno(ListaMatricula **lista, int MatriculaAlunoEditar, int NovaMatriculaAluno, Alunos* aluno, int contador) {
    ListaMatricula *ListaAtual = *lista;
    int matriculaEncontrada = 0;

    //MatriculaAlunoEditar é uma variável que tô reutilizando pra fazer a comparação

    for(int i = 0; i < contador; i++) {
            if(aluno[i].numero_matricula == NovaMatriculaAluno) {
                printf("Matricula ja existente! \n");
                return;
            }
        }

    while (ListaAtual != NULL) {

        if(ListaAtual->aluno.numero_matricula == MatriculaAlunoEditar) {
            ListaAtual->aluno.numero_matricula = NovaMatriculaAluno;
        }

        for(int i = 0; i < contador; i++) {
            if(aluno[i].numero_matricula == MatriculaAlunoEditar) {
                aluno[i].numero_matricula = NovaMatriculaAluno;
            }
        }

        matriculaEncontrada = 1;
        break;

        ListaAtual = ListaAtual->prox;
    }

    if (matriculaEncontrada) {
        printf("Matricula do aluno atualizado com sucesso!\n");
    } else {
        printf("\nMatricula nao encontrada na lista de matriculas.\n");
    }
} 

void EditarNotaAluno(ListaMatricula **lista, float NotaEditar, float NovaNota, int MatriculaAlunoEditar, Alunos* aluno, int contador) {
    ListaMatricula *ListaAtual = *lista;
    int matriculaEncontrada = 0;
    int i;

    //MatriculaAlunoEditar é uma variável que tô reutilizando pra fazer a comparação

    while (ListaAtual != NULL) {
        if(ListaAtual->aluno.numero_matricula == MatriculaAlunoEditar) {  //busca qual é o aluno
             for(int i = 0; i < 3; i++) {
                if (ListaAtual->aluno.notas[i] == NotaEditar) {
                    ListaAtual->aluno.notas[i] = NovaNota;
                    matriculaEncontrada = 1;
                }
            }
        }

        for(int i = 0; i < contador; i++) {
            for(int j = 0; j < 3; j++) {
                if(aluno[i].notas[j] == NotaEditar) {
                aluno[i].notas[j] = NovaNota;
                }
            }   
        }

       // matriculaEncontrada = 1;
        //break;

        ListaAtual = ListaAtual->prox;
        i++;
    }

    if (matriculaEncontrada) {
        printf("Matricula do aluno atualizado com sucesso!\n");
    } else {
        printf("\nMatricula nao encontrada na lista de matriculas.\n");
    }
}

void VagasDisponiveis(Cursos *curso, int contador) {
    if(contador == 0) {
        printf("Nao ha nenhum curso cadastrado! \n");
    } else {
        printf("\n==========================\n");
        for(int i = 0; i < contador; i++) {
            printf("\nCurso: %s\n", curso[i].nome);
            printf("Codigo: %d\n", curso[i].codigo);
            printf("Vagas: %d\n", curso[i].vagas);
        }
        printf("\n==========================\n");
    }  
}

void QntAlunosCurso(ListaMatricula **lista, int CodigoCurso) {
    ListaMatricula *ListaAtual = *lista;
    int QntAlunos = 0;

    while (ListaAtual != NULL) {
        if (ListaAtual->curso.codigo == CodigoCurso) {
            QntAlunos++;
        }
        ListaAtual = ListaAtual->prox;
    }

    if (QntAlunos > 0) {
        printf("O curso possui %d aluno(s) matriculado(s) \n", QntAlunos);
    } else {
        printf("O curso nao possui alunos matriculados \n");
    }
}