//#include "../cursos/cursos.h"
/* Renomeia a struct */
typedef struct alunos Alunos;
/*Renomeia a struct*/
typedef struct listaalunos ListaAlunos;

/* Função para criar alunos */
Alunos *Criar_Alunos(char *nome, int numero_matricula, float notas[3]);

ListaAlunos *CriarAluno(Alunos *Var_Alunos);

void AdicionarAluno(ListaAlunos **lista, Alunos *Var_Alunos);

void ImprimirAlunos(ListaAlunos *lista);

/* Função para a criação do menu */
void menu();
