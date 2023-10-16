# Sistema-de-Gerenciamento-de-Cursos
# Introdução 
Um sistema de gerenciamento de cursos é uma plataforma de software projetada para auxiliar na administração, acompanhamento e disponibilização de cursos. Além disso, esses sistemas também podem facilitar a comunicação entre instrutores e alunos. Como resultado, foi desenvolvido um sistema em linguagem C para realizar essas atividades de gerenciamento.

# Descrição 
O código em questão consiste na implementação de dois Tipos Abstratos de Dados (TADs), um para cadastro de alunos e outro para cadastro de cursos. Ele utiliza listas encadeadas, arquivos, ponteiros e alocação dinâmica de memória. Além disso, o código oferece funções para realizar operações como o cadastramento de alunos, o cadastramento de cursos e a associação de alunos a cursos. Um menu interativo é fornecido para que os usuários possam escolher entre diferentes funcionalidades, como as mencionadas anteriormente, e executar as ações desejadas.

# Funções utilizadas 
* <strong>Cadastrar aluno;</strong>
 Esta função permite registrar as informações de um novo aluno no sistema, incluindo nome, matricula e notas.

* <strong>Cadastrar curso;</strong>
 Esta função permite criar cursos, como o nome do curso e seu código.
  
* <strong>Realizar matricula;</strong>
 Esta função permite inscrever alunos em cursos específicos. 

* <strong>Excluir matricula</strong>
Esta função permite a remoção de um aluno de um curso específico.

* <strong>Listar matriculados;</strong>
  Nessa função, o sistema exibe uma lista de todos os alunos matriculados em um curso específico.

* <strong>Buscar curso;</strong>
   Esta função permite aos usuários pesquisarem cursos com base em seu nome. Caso o curso procurado não exista, o sistema exibirá uma mensagem informativa, esclarecendo que o curso não está disponível. 
* <strong>Editar matricula;</strong>
 Esta função permite que os alunos façam ajustes em suas matrículas, como notas e nome.

* <strong>Consultar vagas disponíveis para um dado curso;</strong>
 Esta função fornece informações sobre o número de vagas restantes em um curso específico.

* <strong>Consultar quantitativo de alunos em um curso;</strong>
 Essa função oferece informações sobre o número total de alunos matriculados em um curso específico.

* <strong>Sair;</strong>
  Essa função permite que os usuários saiam do sistema, encerrando sua sessão ou uso da plataforma de gerenciamento de cursos.
  
# Funções importantes
  Alunos *Criar_Alunos(char *nome, int numero_matricula, float notas[3]) {<br>
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));<br>
    if(Var_Alunos == NULL) {<br>
        printf("Erro ao alocar Var_Alunos dinamicamente! \n");<br>
        exit(1);<br>
    }

    strcpy(Var_Alunos->nome, nome);<br>
    Var_Alunos->numero_matricula = numero_matricula;<br>

    for(int contador = 0; contador < 3; contador++) {<br>
        Var_Alunos->notas[contador] = notas[contador];<br>
    }<br>

    return Var_Alunos;<br>
} 

void ExcluirMatricula(ListaMatricula **lista, char *NomeAluno, Cursos *curso, int CodigoDisciplina) {<br>
    ListaMatricula *ListaAtual = *lista;<br>
    ListaMatricula *ListaAnterior = NULL;<br>

    while (ListaAtual != NULL) {
        if (strcmp(ListaAtual->aluno.nome, NomeAluno) == 0 && ListaAtual->curso.codigo == CodigoDisciplina) {
            // Checa se o nome do aluno é igual ao nome do aluno digitado pelo usuário
            if (ListaAnterior == NULL) {
                // lista receba a a proxima lista caso lista anterior receba nada (null)
                *lista = ListaAtual->prox;
            } else {
                ListaAnterior->prox = ListaAtual->prox;
            }
            free(ListaAtual); // Exclui a matricula
            printf("\nMatricula excluida com sucesso! \n");
            curso->vagas++; //recoloca a vaga que era ocupada
            return; // Sai no momento que a matricula for excluida
            //break;
        }
    ListaAnterior = ListaAtual;
        ListaAtual = ListaAtual->prox;
    }

    printf("A matricula nao foi encontrada! \n");
}



