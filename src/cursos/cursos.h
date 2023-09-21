/*Função para alocar a struct dinâmicamente*/
typedef struct cursos Cursos;

/*Função para criar os cursos*/
Cursos *Criar_Cursos(char *nome, int codigo, int vagas);

Cursos *Matricula_Alunos(Alunos *Var_Aluno, Cursos *Var_Cursos, int vagas);

void imprimir(Alunos *Var_Aluno, Cursos *Var_Cursos);

