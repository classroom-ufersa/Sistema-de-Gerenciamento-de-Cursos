/*Função para alocar a struct dinâmicamente*/
typedef struct cursos Cursos;

typedef union aluno_matricula AlunoMatricula;

/*Função para criar os cursos*/
Cursos *Criar_Cursos(char *nome, int codigo, int vagas);

void Imprimir_Cursos(Cursos *Var_Cursos, int contador2);



