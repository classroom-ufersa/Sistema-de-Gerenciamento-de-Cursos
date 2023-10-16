#ifndef ALUNO_H
#define ALUNO_H

#include "../cursos/cursos.h"

/* Renomeia a struct */
typedef struct alunos Alunos;

/*Renomeia a struct*/

/* Função para criar alunos */
Alunos *Criar_Alunos(char *nome, int numero_matricula, float notas[3]);

// Função para imprimir alunos
void Imprimir_Alunos(Alunos *Var_Alunos, int contador);

// Função para comparar a matricula do aluno
int CompararMatricula(Alunos *Var_Alunos, int NumeroMatricula, int contador);

// Função para a criação do menu 
void menu();

#endif //ALUNO_H