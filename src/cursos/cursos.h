#ifndef CURSOS_H
#define CURSOS_H

#include "../alunos/alunos.h"

/*Função para alocar a struct dinâmicamente*/
typedef struct listamatricula ListaMatricula;

typedef struct cursos Cursos;

/*Função para criar os cursos*/
Cursos *Criar_Cursos(char *nome, int codigo, int vagas);

// Função para imprimir cursos
void Imprimir_Cursos(Cursos *Var_Cursos, int contador2);

// Função para comparar matriculas
int CompararCodigo(Cursos *Var_Cursos, int codigo, int contador2);

// Função para matricular aluno em um curso em uma lista
void MatricularAlunoEmCurso(Alunos* aluno, Cursos* curso, ListaMatricula** lista);

// Função para imprimir a lista
void ImprimirListaMatriculas(ListaMatricula *lista, Cursos *cursos, int contador);

// Função para excluir a matricula na lista
void ExcluirMatricula(ListaMatricula **lista, char *NomeAluno, Cursos *curso, int CodigoDisciplina);

// Função para buscar o curso
void BuscarCurso(Cursos *cursos, char *NomeCurso, int contador);

// Função para editar o nome do aluno
void EditarNomeAluno(ListaMatricula **lista, int MatriculaAlunoEditar, char *NovoNomeAluno, Alunos *aluno, int contador);

// Função para editar a matricula do aluno
void EditarMatriculaAluno(ListaMatricula **lista, int MatriculaAlunoEditar, int NovaMatriculaAluno, Alunos* aluno, int contador);

// Função para editar a nota do aluno
void EditarNotaAluno(ListaMatricula **lista, float NotaEditar, float NovaNota, int MatriculaAlunoEditar, Alunos* aluno, int contador);

// Função para imprimir vagas disponivies em um curso
void VagasDisponiveis(Cursos *curso, int contador);

// Função para imprimir a quantidade de alunos matriculados em um curso
void QntAlunosCurso(ListaMatricula **lista, int CodigoCurso);

// Função para deixar o primeiro caractere em letra maiuscula
void FormatarString(char*nomeF);

// Função para receber entradas do tipo int
void tratativa(int erro);

void LimparBuffer();

#endif //CURSOS_H