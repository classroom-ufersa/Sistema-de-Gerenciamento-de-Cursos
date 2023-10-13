#ifndef CURSOS_H
#define CURSOS_H

#include "../alunos/alunos.h"

/*Mudando o nome da struct*/
typedef struct listamatricula ListaMatricula;

/*Mudando o nome da struct*/
typedef struct cursos Cursos;

/*Função para criar os cursos*/
Cursos *Criar_Cursos(char *nome, int codigo, int vagas);

/*Função para imprimir os cursos*/
void Imprimir_Cursos(Cursos *Var_Cursos, int contador2);

/*Função para comparar os cursos*/
int CompararCodigo(Cursos *Var_Cursos, int codigo, int contador2);

/*Função para matricular os alunos no curso*/
void MatricularAlunoEmCurso(Alunos* aluno, Cursos* curso, ListaMatricula** lista);

/*Função para listar os alunos matriculados*/
void ImprimirListaMatriculas(ListaMatricula *lista, Cursos *cursos, int contador);

/*Função para excluir matricula*/
void ExcluirMatricula(ListaMatricula **lista, char *NomeAluno, int CodigoDisciplina);

void tratativa(int erro);

void CorrecaoNome(char *nomeF);

#endif //CURSOS_H