#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USUARIO_FILE "./storage/usuario.txt"

#include "../utils/clear_command.h"
#include "../utils/printf.config.h"


char *nome= "", *meta_pessoal= "";
long double valor = 0;

int user_validate(void){
    /* 
    // Valida se existe um usuário cadastrado
    // == arquivo existente em ./storage/usuario
    // caso não exista, leva o usuário para um fluxo de cadastro
    */
    FILE * file = fopen(USUARIO_FILE, "r");

    // user not found    
    if(file == NULL){
        printf("Usuário não encontrado\n\n");    
        return 0; 
    }
    fclose(file);
    return 1;
}

int user_save(char *nome, char *meta, char *valor){
    FILE *file = fopen(USUARIO_FILE, "w");

    fprintf(file, nome);
    fprintf(file, ",");
    fprintf(file, meta);
    fprintf(file, ",");
    fprintf(file, valor);
    fprintf(file, "\n");

    fclose(file);

    return 1;
}

int user_create(void){
    char valor[100], meta_pessoal[100], nome[100]; 
    /* 
    // Responsável por cadastrar um usuário
    */
    limpar_tela();

    print("Certo, Qual o seu primeiro nome?", "green");
    scanf("%s", &nome);
    print("\nQual o sua meta de investimento?", "green");
    scanf("%s", &meta_pessoal);
    print("\nQual o seu valor acumulado atual?", "green");
    scanf("%s", &valor);

    //printf("%s - %s - %s \n", nome, meta_pessoal, valor);

    int result = user_save(nome, meta_pessoal,valor);
    if(result==1){
        menu();
        return 1;
    }
    else{
        printf("Algo deu errado com o seu cadastro, tente novamente mais tarde...\n\n");
        return 0;
    }
}
