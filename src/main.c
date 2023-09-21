#include "./alunos/alunos.h"
#include "./cursos/cursos.c"

int main() {

    char NomeAluno[50];
    int NumeroMatricula;
    int contador = 0, SairCase = 0;

    char NomeCurso[50];
    int CodigoCurso;
    int Vagas = 0; //limite de vagas no curso criado

    int MenuEscolha;

    do{
        menu();
        scanf("%d", &MenuEscolha);

        switch(MenuEscolha) {
        case 1:
            SairCase = 0;
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
                getchar();

                printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                scanf("%d", &SairCase);

                contador++;
                Vagas++;

                Cursos *Var_Cursos = Criar_Cursos(NomeCurso, CodigoCurso, Vagas);

                if(SairCase != 1 && SairCase != 2) {
                    while(SairCase != 1 && SairCase != 2) {
                        printf("Voce digitou uma opcao invalida! \n");
                        printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                        scanf("%d", &SairCase);
                    }
                }
                if(SairCase == 2) {
                    
                }

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

    return 0;
}