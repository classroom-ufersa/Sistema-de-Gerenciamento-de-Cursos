/* #include "./alunos/alunos.c" */
#include "./cursos/cursos.c"

int main() {
    ListaMatricula *Lista = NULL;
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos)); 

    char NomeAluno[50];
    int NumeroMatricula;
    float notas[3];
    int contador = 0, SairCase = 0;
    int contador2 = 0, contador3, Vagas2 = 2;  //Vagas2 são as vagas de cada curso (que são 3 contando do 0)

    int escolha = 0;

    char Nomealuno[50], Nomecurso[50];
    int matricula, codigo;

    char NomeCurso[50];
    int CodigoCurso;
    int Vagas = 0; //limite de vagas no curso criado

    int MenuEscolha;

    do{
        system("cls");
        menu();
        scanf("%d", &MenuEscolha);
        tratativa(MenuEscolha);

        switch(MenuEscolha) {
        case 1:
            system("cls");
            escolha = 0;
            while(escolha != 2) {
                system("cls");
                int Comparar = 0;
                printf("| 1.Criar Aluno | 2. Voltar ao Menu | -> ");
                scanf("%d", &escolha);
                tratativa(escolha);
                    switch(escolha) {
                        case 1:
                            contador++;
                            Vagas++;
                            printf("Informe o nome do aluno(a) %i: ", contador);
                            scanf(" %[^\n]", NomeAluno);
                            getchar();
                            printf("Infome o numero de matricula do aluno(a) %i: ", contador);
                            scanf("%d", &NumeroMatricula);

                            Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);

                            while(Comparar == 1) {
                                system("cls");
                                Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);
                                if(Comparar == 1) {
                                    printf("Informe o numero da matricula novamente: ");
                                    scanf("%d", &NumeroMatricula);
                                    Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);
                                }
                            }

                            for(int j = 0; j < 3; j++) {
                                printf("Digite a nota %i: ", j + 1);
                                scanf("%f", &notas[j]);
                            }

                            Alunos *VarAluno = Criar_Alunos(NomeAluno, NumeroMatricula, notas);

                            if(escolha == 1) {
                            Var_Alunos = (Alunos*)realloc(Var_Alunos, (contador + 2) * sizeof(Alunos));
                            if(Var_Alunos == NULL) {
                                printf("Erro ao realocar Var_Alunos \n");
                            }
                        }

                        Var_Alunos[contador - 1] = *VarAluno;
                        break;
                    }
                    

                    /* printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                    scanf("%d", &SairCase); */

                    

                    /* if(SairCase != 1 && SairCase != 2) {
                        while(SairCase != 1 && SairCase != 2) {
                            printf("Voce digitou uma opcao invalida! \n");
                            printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                            scanf("%d", &SairCase);
                        }
                    } */
                }
                break;

            case 2:  
                system("cls");
                escolha = 0;
                while(escolha != 2) { 
                    //system("cls");
                    int Comparar = 0;
                    printf("| 1.Criar curso | 2.Voltar ao Menu | -> ");
                    scanf("%d", &escolha);
                    
                    switch(escolha) {
                        case 1:
                            contador2++;
                            printf("\nInfome a disciplina: ");
                            scanf(" %[^\n]", NomeCurso);
                            getchar();
                            printf("Informe o codigo do curso: ");
                            scanf("%d", &CodigoCurso);
                            Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                            system("cls");
                            if(Comparar == 2) {
                                printf("Disciplina criada! \n\n");
                            }
                            while(Comparar == 1) {
                                system("cls");
                                Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                                if(Comparar == 1) {
                                    printf("Codigo ja existente! \n");
                                    printf("Informe o codigo do curso novamente: \n");
                                    scanf("%d", &CodigoCurso);
                                    Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                                } 
                                if(Comparar == 2) {
                                    printf("Disciplina criada! \n");
                                }
                            }
                            Cursos *VarCursos = Criar_Cursos(NomeCurso, CodigoCurso, Vagas2);

                            if(escolha == 1) {
                                Vagas2++;
                                Var_Cursos = (Cursos*)realloc(Var_Cursos, (contador2 + 2) * sizeof(Cursos));
                                if(Var_Cursos == NULL) {
                                    printf("Realocacao de Var_Cursos falhou! \n");
                                    exit(1);
                                }
                            }

                            Var_Cursos[contador2 - 1] = *VarCursos;
                            break;
                        case 2:
                            break;  
                    }
                }
                break;
            case 3:
                escolha = 0;
                while(escolha != 2) {
                    //system("cls");
                    Imprimir_Cursos(Var_Cursos, contador2);
                    printf("\nLISTA DE ALUNOS: \n");
                    Imprimir_Alunos(Var_Alunos, contador);
                    if(contador == 0 || contador2 == 0) {
                        printf("\nDigite 2 para sair! \n");
                        scanf("%d", &escolha);
                        if(escolha != 2) {
                            while(escolha != 2) {
                                printf("\nDigite 2 para sair -> \n");
                                scanf("%d", &escolha);
                            }
                        }
                    } else {
                        escolha = 0;
                        contador3 = contador;
                        printf("Informe | 1. MATRICULA DO ALUNO | 2. SAIR DA MATRICULA |: \n");
                        scanf("%d", &escolha);

                        switch(escolha) {
                            case 1:
                                printf("Informe a matricula do aluno: ");
                                scanf("%d", &matricula);
                                break;
                            case 2:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        } 
                        if(escolha == 2) {
                            break;
                        } else {
                            escolha = 0;
                        }
                        printf("\nInforme | 1.CODIGO | 2.SAIR DA MATRICULA |: ");
                        scanf("%d", &escolha);
                        switch(escolha) {
                            case 1:
                                printf("Digite o codigo: ");
                                scanf("%d", &codigo);
                                break;    
                            case 2:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        }
                        // Procura o aluno pelo número da matrícula e o curso pelo código
                        Alunos *alunoSelecionado = NULL;
                        Cursos *cursoSelecionado = NULL;

                        for (int i = 0; i < contador3; i++) {
                            if (Var_Alunos[i].numero_matricula == matricula) {
                                alunoSelecionado = &Var_Alunos[i];
                                break;
                            }
                        }

                        for (int i = 0; i < contador3; i++) {
                            if (Var_Cursos[i].codigo == codigo) {
                                cursoSelecionado = &Var_Cursos[i];
                                break;
                            }
                        }

                        if (alunoSelecionado != NULL && cursoSelecionado != NULL) {                            
                            // Matricular o aluno no curso
                            MatricularAlunoEmCurso(alunoSelecionado, cursoSelecionado, &Lista);
                        } else {
                            printf("Aluno ou curso nao encontrado.\n");
                        }
                        /* Alunomatricula = (AlunoMatricula*)realloc(Alunomatricula, (contador3) * sizeof(AlunoMatricula));
                        if(Alunomatricula == NULL) {
                            printf("Erro ao alocar Alunomatricula! \n");
                            exit(1);
                        } 
                        Alunocurso = (AlunoCurso*)realloc(Alunocurso, (contador3) * sizeof(AlunoCurso));
                        if(Alunocurso == NULL) {
                            printf("Erro ao alocar Alunocurso! \n");
                            exit(1);
                        } */
                    } 
                } 
                
                break;

            case 4:
                system("cls");
                escolha = 0;
                char NomeAluno[30];
                int CodigoDisciplina;
                while(escolha != 2) {
                    printf("| 1.Excluir Matricula | 2. Voltar ao Menu | -> ");
                    scanf("%d", &escolha);

                    switch(escolha) {
                        case 1:
                            system("cls");
                            if(Lista == NULL) {
                                printf("Nao ha nenhuma matricula! \n");
                                break;
                            } else {
                                ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                            }
                            printf("\nInforme o Nome do Aluno: -> ");
                            scanf(" %[^\n]", NomeAluno);
                            getchar();
                            printf("Informe o Codigo do Curso: -> ");
                            scanf("%d", &CodigoDisciplina);
                            ExcluirMatricula(&Lista, NomeAluno, CodigoDisciplina);
                        break;
                        case 2:
                            break;
                        default:
                            printf("Digite uma opcao valida! \n");
                    }
                }
                break;
            case 5:
                ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
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