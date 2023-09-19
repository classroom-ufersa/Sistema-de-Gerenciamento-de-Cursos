#include "./alunos/alunos.c"

int main() {

    Alunos *Var_Aluno = (Alunos*)malloc(sizeof(Alunos));


    Cursos *Novo_Aluno = Matricula_Alunos(Var_Aluno);

    return 0;
}