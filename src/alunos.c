#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "cursos.h"

#define VAGAS 15

struct alunos {
    int numero_matricula;
    int vagas;
    char alunos[50];
    char nome[50];
    Cursos *struct_cursos;
};

Alunos *Criar_Alunos(int numero_matricula, int vagas, char *alunos, char *nome) {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    if(Var_Alunos == NULL) {
        printf("Variavel Var_Alunos nao foi alocada dinamicamente! \n");
        exit(1);
    }

    Var_Alunos->numero_matricula;
    Var_Alunos->vagas;
    strcpy(Var_Alunos->nome, nome);
    strcpy(Var_Alunos->alunos, alunos);

    return Var_Alunos;
}

void menu(){
    int escolha;
    char escolha_char;

    printf("=========================================\n");
    printf("(1) Realizar matricula\n");
    printf("(2) Excluir matricula\n");
    printf("(3) Listar matriculados\n");
    printf("(4) Buscar curso\n");
    printf("(5) Editar matricula\n");
    printf("(6) Consultar vagas disponíveis para curso\n");
    printf("(7) Consultar quantitativo de alunos em um curso\n");
    printf("(8) Sair\n");
    printf("=========================================\n");

    scanf("%d",&escolha);
    getchar();

    switch(escolha){
        case 1:
            // Criar uma função para cada case.
            system("cls");
            Realizar_matricula();
            break;
        case 2:
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
        default:
            while(escolha!='\n'){
                escolha=getchar();
            }
            menu();
            break;

    }

}

void Realizar_matricula(){
    Alunos *Var_Alunos;

    if(Var_Alunos->vagas == VAGAS) {
        printf("Vagas preenchidas! \n");
        exit(1);
    }

    printf("Digite o nome do aluno: \n");
    scanf(" %[^\n]", Var_Alunos->nome);
    //getchar();
    printf("Informe o codigo do aluno: \n");
    scanf("%d", &Var_Alunos->numero_matricula);
    Var_Alunos->vagas++;
    menu();

}

void listar_matriculados(){
    printf("NADA AINDA!");
    
    menu();
}

void buscar_curso(){
    printf("PESQUISAR CURSOS\n"); // CABEÇALHO
    printf("Informe o nome do curso\n>> ");
    
    menu();
}

void Editar_Matricula(){
    printf("EDIÇÃO DE MATRICULAS\n"); // CABEÇALHO
    printf("Buscar pelo nome do aluno\n>> ");

    menu();
}

void Consultar_Vagas(){
    printf("CUNSULTAR VAGAS DOS CURSOS\n"); // CABEÇALHO
    printf("Informe o nome do curso\n>> ");

    menu();
}

void Quantitativo(){
    printf("QUANTIDADE DE ALUNOS NOS CURSOS\n"); // CABEÇALHO

}