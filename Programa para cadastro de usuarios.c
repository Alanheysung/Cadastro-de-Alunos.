#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nalunos 3

int nAlunos;

struct  dados{
    char nome[50];
    char matricula[20];
    float notas[4];
    int ativo;
};
struct dados alunos[Nalunos];

void menu(){
    int op;
    do{
        system("cls");
        printf("__________Menu__________\n");
        printf("1-Cadastrar Aluno.\n2-Listar Alunos.\n3-Pesquisar Aluno.\n4-Aprovados.\n5-Remover Aluno.\n0-Sair.\n");
        printf("________________________\n");
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
                pesquisar();
                    break;
            case 4:
                aprovados();
                break;
            case 5:
                remover();
                break;
        }
    }while(op!=0);

    }

void cadastrar(){

    int i, op;
    char nome[50];
    char matricula[20];
    float notas[4];

    do{
    printf("Nome: ");
    fgets(nome,sizeof(nome), stdin);
    fflush(stdin);
    printf("Matricula: ");
    fgets(matricula, sizeof(matricula), stdin);
    fflush(stdin);
    printf("Notas: \n");
    printf("1-Bimestre: ");
    scanf("%f", &notas[0]);
    printf("2-Bimestre: ");
    scanf("%f", &notas[1]);
    printf("3-Bimestre: ");
    scanf("%f", &notas[2]);
    printf("4-Bimestre: ");
    scanf("%f", &notas[3]);

    for(i=0;i<Nalunos;i++){
        if(alunos[i].ativo==0){
            alunos[i].notas[0]=notas[0];
            alunos[i].notas[1]=notas[1];
            alunos[i].notas[2]=notas[2];
            alunos[i].notas[3]=notas[3];
            strcpy(alunos[i].nome, nome);
            strcpy(alunos[i].matricula, matricula);
            alunos[i].ativo = 1;
            break;
            nAlunos++;

        }
    }
    printf("1-Continuar.\n0-Sair\n");
    scanf("%d", &op);
    fflush(stdin);
    }while(op!=0);
        }

void listar(){
    int i;
    for(i=0;i<Nalunos;i++){
        if(alunos[i].ativo>0){
            printf("Nome:%s", alunos[i].nome);
            printf("Matricula:%s", alunos[i].matricula);
            }else{
                printf("Nenhum Aluno Cadastrado!!!\n");
                break;
            }
        }
        system("pause");
        //getchar();
        //getchar();
    }

void pesquisar(){
    int i;
    char nome[50];

    printf("Digite o nome a ser pesquisado:\n");
    fgets(nome, 50, stdin);
    for(i=0;i<Nalunos;i++){
        if(strcmp(alunos[i].nome,nome)==0){
            printf("%s", alunos[i].nome);
            printf("%s", alunos[i].matricula);
            }else{
                printf("Aluno Inexistente.\n");
                break;
            }
        }
        system("pause");
        //getchar();
        //getchar();
    }

void aprovados(){
    int i;
    float media=0.0;

    for(i=0;i<Nalunos;i++){
        if(alunos[i].ativo>0){
            media=(alunos[i].notas[0]+alunos[i].notas[1]+alunos[i].notas[2]+alunos[i].notas[3])/4;

            if(media>=7){
                printf("Nome:%s", alunos[i].nome);
                printf("Matricula:%s", alunos[i].matricula);
                }else{
                    printf("Nenhum aluno aprovado.\n");
                    break;
                }
            }else{
                printf("Nenhum Aluno  Cadastrado!!!\n");
                break;
            }
        }
        system("pause");
        //getchar();
        //getchar();
    }

void remover(){
    int i;
    char nome[50];

    printf("Digite o nome a ser removido:\n");
    fgets(nome, 50, stdin);
    for(i=0;i<Nalunos;i++){
        if(strcmp(alunos[i].nome,nome)==0){
            alunos[i].ativo=0;
            printf("\nAluno removido.\n");
            }else{
                printf("Aluno Inexistente ou nao cadastrado!!!\n");
                break;
            }
        }
        system("pause");
        //getchar();
        //getchar();
    }

int main(){

    menu();

        return 0;
    }

