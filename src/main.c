#include "./alunos/alunos.c"

int main() {

    char NomeAluno[50];
    int NumeroMatricula;
    int contador = 0, SairCase = 0;

    char NomeCurso[50];
    int CodigoCurso;
    int Vagas; //limite de vagas no curso criado

    int MenuEscolha;

    menu();
    scanf("%d", &MenuEscolha);

    do{
        switch(MenuEscolha) {
        case 1:
            while(SairCase != 2 && Vagas <= 15) {
                printf("Informe o nome do aluno(a) %i: ", contador + 1);
                scanf(" %[^\n]", NomeAluno);
                printf("Infome o numero de matricula do aluno(a) %i: ", contador + 1);
                scanf("%d", &NumeroMatricula);
                getchar();

                Alunos *Var_Aluno = Criar_Alunos(NomeAluno, NumeroMatricula);

                printf("Infome o curso que gostaria de se matricular: ");
                scanf(" %[^\n]", NomeCurso);
                printf("Informe o codigo do curso: ");
                scanf("%d", &CodigoCurso);

                printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                scanf("%d", &SairCase);
                getchar();

                if(SairCase != 1 && SairCase != 2) {
                    while(SairCase != 1 && SairCase != 2) {
                        printf("Voce digitou uma opcao invalida! \n");
                        printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                        scanf("%d", &SairCase);
                    }
                }
                if(SairCase == 2) {
                    menu();
                } 

                contador++;
                Vagas++;
            }
            
            break;

            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6: 
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Voce digitou um opcao invalida! \n");
        }

    } while(MenuEscolha != 8);

    //Cursos *Novo_Aluno = Matricula_Alunos(Var_Aluno);

    return 0;
}