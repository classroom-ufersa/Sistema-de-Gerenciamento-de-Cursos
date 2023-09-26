#include "./alunos/alunos.h"
#include "./cursos/cursos.c"

union aluno_curso {
    char NomeCurso[50];
    int Codigo;
};

union aluno_matricula {
    char NomeAluno[50];
    int Matricula;
};

int main() {
    AlunoCurso *Alunocurso = (AlunoCurso*)malloc(sizeof(AlunoCurso));
    AlunoMatricula *Alunomatricula = (AlunoMatricula*)malloc(sizeof(AlunoMatricula));
    ListaAlunos *listaAlunos = NULL;
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos)); 

    char NomeAluno[50];
    int NumeroMatricula;
    float notas[3];
    int contador = 0, SairCase = 0;
    int contador2 = 0, contador3 = 0, Vagas2 = 0;

    int escolha = 0, escolha2 = 0;

    char NomeCurso[50];
    int CodigoCurso;
    int Vagas = 0; //limite de vagas no curso criado

    int MenuEscolha;

    do{
        system("cls");
        menu();
        scanf("%d", &MenuEscolha);

        switch(MenuEscolha) {
        case 1:
                system("cls");
                SairCase = 0;
                while(SairCase != 2) {
                    system("cls");
                    contador++;
                    Vagas++;
                    printf("Informe o nome do aluno(a) %i: ", contador);
                    scanf(" %[^\n]", NomeAluno);
                    printf("Infome o numero de matricula do aluno(a) %i: ", contador);
                    scanf("%d", &NumeroMatricula);
                    for(int j = 0; j < 3; j++) {
                        printf("Digite a nota %i: ", j + 1);
                        scanf("%f", &notas[j]);
                    }
                    getchar();

                    Alunos *VarAluno = Criar_Alunos(NomeAluno, NumeroMatricula, notas);

                    Var_Alunos[contador - 1] = *VarAluno;

                    //AdicionarAluno(&listaAlunos, VarAluno);

                    printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                    scanf("%d", &SairCase);

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
                /* if(Vagas == VAGAS) {
                    printf("Vagas cheias! \n");
                } */
                while(SairCase != 2) { 
                    contador2++;
                    Vagas2++;
                    printf("Infome a disciplina: ");
                    scanf(" %[^\n]", NomeCurso);
                    printf("Informe o codigo do curso: ");
                    scanf("%d", &CodigoCurso); 
                    getchar();

                    Cursos *VarCursos = Criar_Cursos(NomeCurso, CodigoCurso, Vagas2);

                    printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                    scanf("%d", &SairCase);

                    if(SairCase == 1) {
                        Var_Cursos = (Cursos*)realloc(Var_Cursos, (contador2 * 2) * sizeof(Cursos));
                        if(Var_Cursos == NULL) {
                            printf("Realocacao de Var_Cursos falhou! \n");
                            exit(1);
                        }
                    }

                    Var_Cursos[contador2 - 1] = *VarCursos;

                    //printf("\n\nVagas: %d, contador: %d\n", Vagas2, contador2); //pra checar o valor (pode ignorar) 

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
                escolha = 0;
                contador3 = 0;
                while(escolha != 3) {
                    system("cls");
                    Imprimir_Cursos(Var_Cursos, contador2);
                    printf("\nLISTA DE ALUNOS: \n");
                    Imprimir_Alunos(Var_Alunos, contador);
                    if(contador == 0 || contador2 == 0) {
                        printf("\nDigite 3 para sair! \n");
                        scanf("%d", &escolha);
                        if(escolha != 3) {
                            while(escolha != 3) {
                                printf("\nDigite 3 para sair! \n");
                                scanf("%d", &escolha);
                            }
                        }
                    } else {
                        escolha = 0;
                        contador3++;
                        printf("Informe | 1. ALUNO | 2. MATRICULA | 3. SAIR DA MATRICULA |: \n");
                        scanf("%d", &escolha);

                        switch(escolha) {
                            case 1:
                                printf("Informe o nome do aluno: ");
                                scanf(" %[^\n]", Alunomatricula->NomeAluno);
                                getchar();
                                break;
                            case 2:
                                printf("Informe a matricula do aluno: ");
                                scanf("%d", &Alunomatricula->Matricula);
                                break;
                            case 3:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        } 
                        if(escolha == 3) {
                            break;
                        } else {
                            escolha == 0;
                        }
                        printf("\nInforme | 1.CURSO | 2.CODIGO | 3.SAIR DA MATRICULA |: ");
                        scanf("%d", &escolha);
                        switch(escolha) {
                            case 1:
                                printf("Digite o nome: ");
                                scanf(" %[^\n]", Alunocurso->NomeCurso);
                                getchar(); 
                                break;
                            case 2:
                                printf("Digite o codigo: ");
                                scanf("%d", &Alunocurso->Codigo);
                                break;
                            case 3:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        }
                        Alunomatricula = (AlunoMatricula*)realloc(Alunomatricula, (contador3) * sizeof(AlunoMatricula));
                        if(Alunomatricula == NULL) {
                            printf("Erro ao alocar Alunomatricula! \n");
                            exit(1);
                        } 
                        Alunocurso = (AlunoCurso*)realloc(Alunocurso, (contador3) * sizeof(AlunoCurso));
                        if(Alunocurso == NULL) {
                            printf("Erro ao alocar Alunocurso! \n");
                            exit(1);
                        }
                    } 
                       
                } 
                
                break;

            case 4:
                //ImprimirAlunos(listaAlunos);
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