#ifndef CURSOS_H
#define CURSOS_H

#include "../alunos/alunos.h"

/*Função para alocar a struct dinâmicamente*/
typedef struct listamatricula ListaMatricula;

typedef struct cursos Cursos;

/*Função para criar os cursos*/
Cursos *Criar_Cursos(char *nome, int codigo, int vagas);

void Imprimir_Cursos(Cursos *Var_Cursos, int contador2);

int CompararCodigo(Cursos *Var_Cursos, int codigo, int contador2);

void MatricularAlunoEmCurso(Alunos* aluno, Cursos* curso, ListaMatricula** lista);

void ImprimirListaMatriculas(ListaMatricula *lista, Cursos *cursos, int contador);

void ExcluirMatricula(ListaMatricula **lista, char *NomeAluno, Cursos *curso, int CodigoDisciplina);

void BuscarCurso(Cursos *cursos, char *NomeCurso, int contador);

void EditarNomeAluno(ListaMatricula **lista, int MatriculaAlunoEditar, char *NovoNomeAluno, Alunos *aluno, int contador);

void EditarMatriculaAluno(ListaMatricula **lista, int MatriculaAlunoEditar, int NovaMatriculaAluno, Alunos* aluno, int contador);

void EditarNotaAluno(ListaMatricula **lista, float NotaEditar, float NovaNota, int MatriculaAlunoEditar, Alunos* aluno, int contador);

void VagasDisponiveis(Cursos *curso, int contador);

void QntAlunosCurso(ListaMatricula **lista, int CodigoCurso);

void FormatarString(char*nomeF);

void tratativa(int erro);

#endif //CURSOS_H