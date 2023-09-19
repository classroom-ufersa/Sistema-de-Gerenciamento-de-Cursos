#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "cursos.h"

#define VAGAS 15

struct alunos {
    int numero_matricula;
    int vagas;
    char alunos[50]; //não faço ideia
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
    printf("(1) Criar Curso\n");
    printf("(2) Realizar Matricula\n");
    printf("(3) Excluir Matricula\n");
    printf("(4) Listar Matriculados\n");
    printf("(5) Buscar Curso\n");
    printf("(6) Editar Matricula\n");
    printf("(7) Consultar Vagas Disponiveis Para o Curso\n");
    printf("(8) Consultar Quantitativo De Alunos em um Curso\n");
    printf("(9) Sair\n");
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

void Realizar_matricula(){
    int contador = 0, vagas = 0, resposta;

    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));

    if(Var_Alunos->vagas == VAGAS) {
        printf("Vagas preenchidas! \n");
        exit(1);
    }

    while(vagas != VAGAS) {
        printf("Digite o nome do aluno %i: \n", contador + 1);
        scanf(" %[^\n]", Var_Alunos[contador].nome);
        printf("Informe o codigo do aluno %i: \n", contador + 1);
        scanf("%d", &Var_Alunos[contador].numero_matricula);
        Var_Alunos->vagas++;
        getchar();

        printf("Deseja cadastrar mais? |1.SIM | 2.NAO| \n");
        scanf("%d", &resposta);

        vagas++;

        if(resposta == 2) {
            vagas = VAGAS;
            menu();
        } else if (resposta != 1 && resposta != 2) {
            while(resposta != 1 && resposta != 2) {
                printf("Digite 1 ou 2 \n");
                printf("Deseja cadastrar mais? |1.SIM | 2.NAO| \n");
                scanf("%d", &resposta);
            }
        }      
    }
        contador++;
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