#include "../alunos/alunos.c"
#include "cursos.h"

struct cursos {
    char nome[50];
    int codigo;
    int vagas;
    ListaAlunos *alunos;
};