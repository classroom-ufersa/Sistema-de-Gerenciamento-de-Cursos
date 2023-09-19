#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "../cursos/cursos.h"

#define VAGAS_CURSOS 15

struct alunos {
    char nome[50];
    char curso[50];
    int matricula;
    float notas[3];
};

Alunos *Criar_Alunos(char *nome, char *curso, int mantricula, float notas[3]) {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    if(Var_Alunos == NULL) {
        printf("Variavel Var_Alunos nao foi alocada dinamicamente! \n");
        exit(1);
    }


    Var_Alunos->notas[0] = 0;
    Var_Alunos->notas[1] = 0;
    Var_Alunos->notas[2] = 0;

    strcpy(Var_Alunos->curso, nome);
    strcpy(Var_Alunos->curso, curso);
    Var_Alunos->matricula = mantricula;
    Var_Alunos->notas[3] = notas[3];

    return Var_Alunos;
}

void menu(){
    int escolha;
    char escolha_char;

    printf("=========================================\n");
    printf("(1) Criar Curso\n");
    printf("(2) Criar Aluni\n");
    printf("(3) Criar Matricula");
    printf("(4) Excluir Matricula\n");
    printf("(5) Listar Matriculados\n");
    printf("(6) Buscar Curso\n");
    printf("(7) Editar Matricula\n");
    printf("(8) Consultar Vagas Disponiveis Para o Curso \n");
    printf("(9) Consultar Quantitativo De Alunos em um Curso\n");
    printf("(10) Sair\n");
    printf("=========================================\n");

    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            Criar_Curso();
            break;
        case 2:
            system("cls");
            Realizar_matricula();
            break;
        case 3:
            listar_matriculados();
            break;
        case 4:
            buscar_curso();
            break;
        case 5:
            Editar_Matricula();
            break;
        case 6:
            Consultar_Vagas();
            break;
        case 7:
            Quantitativo();
            break;
        case 8:
            while((escolha_char != 's') || (escolha_char != 'S') || (escolha_char != 'n') || (escolha_char != 'N')){
                printf("REALMENTE DESEJA SAIR?\n");
                printf("(s) Sim\n(n) Não\n>> ");
                scanf("%c",&escolha_char);
                
                if((escolha_char == 's') || (escolha_char== 'S')){
                    printf("Obrigado por usar o programa!\n");
                    exit(1);
                } 
                if((escolha_char == 'n') || (escolha_char== 'N')){
                    menu();
                }
            }

            break;
        case 9:
            break;
        default:
            while(escolha!='\n'){
                escolha=getchar();
            }
            menu();
            break;

    }

}

void Criar_Curso() {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    
    printf("Informe o Nome do Curso: \n");
    //scanf(" %[^\n]", Var_Alunos->struct_cursos);

    //Cursos *CriarCurso = Criar_Cursos(NomeCurso, codigo, vagas, NomeAlunos);

}