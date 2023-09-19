#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "cursos.h"

#define VAGAS 15

struct alunos {
    int codigo;
    int vagas;
    char alunos[50];
    char nome[50];
};

Alunos *Criar_Alunos(int codigo, int vagas, char *alunos, char *nome) {
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    if(Var_Alunos == NULL) {
        printf("Variavel Var_Alunos nao foi alocada dinamicamente! \n");
        exit(1);
    }

    Var_Alunos->codigo;
    Var_Alunos->vagas;
    strcpy(Var_Alunos->nome, nome);
    strcpy(Var_Alunos->alunos, alunos);

    return Var_Alunos;
}

void menu(){
int escolha;

printf("(1) Realizar matricula\n");
printf("(2) Excluir matricula\n");
printf("(3) Listar matriculados\n");
printf("(4) Buscar curso\n");
printf("(5) Editar matricula\n");
printf("(6) Consultar vagas disponíveis para curso\n");
printf("(7) Consultar quantitativo de alunos em um curso\n");
printf("(8) Sair\n");

scanf("%d",&escolha);

switch(escolha){
    case 1:
        // Criar uma função para cada case.
        system("clear");
        Realizar_matricula();
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
        menu();
        break;

}

}

void Realizar_matricula(){

    printf("Digite o nome do aluno\n>> ");
    scanf("%[^\n]",);
   
    

}
