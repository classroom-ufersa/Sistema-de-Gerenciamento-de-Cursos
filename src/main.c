#include "./alunos/alunos.h"
#include "./cursos/cursos.c"

int main() {

    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos)); 

    char NomeAluno[50];
    int NumeroMatricula;
    float notas[3];
    int contador = 0, SairCase = 0;
    int contador2 = 0;

    char NomeCurso[50];
    int CodigoCurso;
    int Vagas = 0, Vagas2 = 0; //limite de vagas no curso criado

    int MenuEscolha;

    do{
        menu();
        scanf("%d", &MenuEscolha);

        switch(MenuEscolha) {
        case 1:
            system("cls");
            SairCase = 0;
            while(SairCase != 2) {
                contador++;
                Vagas++;
                printf("Informe o nome do aluno(a) %i: ", contador);
                scanf(" %[^\n]", NomeAluno);
                printf("Infome o numero de matricula do aluno(a) %i: ", contador);
                scanf("%d", &NumeroMatricula);
                for(int i = 0; i < 3; i++) {
                    printf("Digite a nota %i: ", i + 1);
                    scanf("%f", &notas[i]);
                }
                getchar();

                //printf("\n\nVagas: %d, contador: %d\n", Vagas, contador); //checar valores (pode ignorar)

                Alunos *VarAluno = Criar_Alunos(NomeAluno, NumeroMatricula, notas);

                printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                scanf("%d", &SairCase);

                if(SairCase == 1) {
                    Var_Alunos = (Alunos*)realloc(Var_Alunos, (contador + 1) * sizeof(Alunos));
                    if(Var_Alunos == NULL) {
                        printf("Realocacao de Var_Alunos falhou! \n");
                        exit(1);
                    }
                } 

                Var_Alunos[contador - 1] = *VarAluno;

                if(SairCase != 1 && SairCase != 2) {
                    while(SairCase != 1 && SairCase != 2) {
                        printf("Voce digitou uma opcao invalida! \n");
                        printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                        scanf("%d", &SairCase);
                    }
                }
            }
            
            break;

            case 2:  
                system("cls");
                SairCase = 0;
                if(Vagas2 == VAGAS) {
                    printf("Vagas cheias! \n");
                }
                while(SairCase != 2) {
                    contador2++;
                    Vagas2++; 
                    printf("Infome o curso que gostaria de se matricular: ");
                    scanf(" %[^\n]", NomeCurso);
                    printf("Informe o codigo do curso: ");
                    scanf("%d", &CodigoCurso); 
                    getchar();

                    Cursos *VarCursos = Criar_Cursos(NomeCurso, CodigoCurso, Vagas2);

                    printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                    scanf("%d", &SairCase);

                    if(SairCase == 1) {
                        Var_Cursos = (Cursos*)realloc(Var_Cursos, (contador2 + 10) * sizeof(Cursos));
                        if(Var_Cursos == NULL) {
                            printf("Realocacao de Var_Cursos falhou! \n");
                            exit(1);
                        }
                    }

                    Var_Cursos[contador2 - 1] = *VarCursos;

                    printf("\n\nVagas: %d, contador: %d\n", Vagas2, contador2);  

                    if(SairCase != 1 && SairCase != 2) {
                        while(SairCase != 1 && SairCase != 2) {
                            printf("Voce digitou uma opcao invalida! \n");
                            printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                            scanf("%d", &SairCase);
                        }
                    }
                }

                break;
            case 3:
                Imprimir_Alunos(Var_Alunos, contador);

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
            case 9:
                break;
            case 10:
                break;
            default:
                printf("Voce digitou um opcao invalida! \n");
        }

    } while(MenuEscolha != 10);

    // Libera a memória alocada para alunos
    free(Var_Alunos);
    free(Var_Cursos);

    return 0;
}