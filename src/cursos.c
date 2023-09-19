#include "alunos.c"

struct cursos {
    char nome[50];
    char curso[50];
    int matricula;
    float notas[3];
    
};

Cursos *Criar_Cursos(char *nome, char *curso, int matricula, float notas[3]) {
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos));
    if(Var_Cursos == NULL) {
        printf("Variavel Var_Alunos nao foi alocada dinamicamente! \n");
        exit(1);
    }

    strcpy(Var_Cursos->nome, nome);
    strcpy(Var_Cursos->curso, curso);
    Var_Cursos->matricula = matricula;
    Var_Cursos->notas[3] = notas[3];

    return Var_Cursos;
}