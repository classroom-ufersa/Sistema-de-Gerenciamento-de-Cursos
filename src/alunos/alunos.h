/* Renomeia a struct */
typedef struct alunos Alunos;
/*Renomeia a struct*/
typedef struct listaalunos ListaAlunos;

/* Função para criar alunos */
Alunos *Criar_Alunos(char *nome, int numero_matricula, float notas[3]);

void Imprimir_Alunos(Alunos *Var_Alunos, int contador);

/* Função para a criação do menu */
void menu();
