#ifndef CURSOS_H
#define CURSOS_H

#include "../alunos/alunos.h"

/*Função para alocar a struct dinâmicamente*/
typedef struct listamatricula ListaMatricula;

typedef struct cursos Cursos;

typedef union aluno_curso AlunoCurso;

typedef union aluno_matricula AlunoMatricula;

/*Função para criar os cursos*/
Cursos *Criar_Cursos(char *nome, int codigo, int vagas);

void Imprimir_Cursos(Cursos *Var_Cursos, int contador2);

int CompararCodigo(Cursos *Var_Cursos, int codigo, int contador2);

void MatricularAlunoEmCurso(Alunos* aluno, Cursos* curso, ListaMatricula** lista);

void ImprimirListaMatriculas(ListaMatricula *listaMatriculas);



#endif //CURSOS_H