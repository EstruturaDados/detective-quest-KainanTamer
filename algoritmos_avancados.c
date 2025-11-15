#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sala {
    char nome[30];
    struct Sala *esquerda;
    struct Sala *direita;
};

struct Sala* criarSala(char nome[]) {
    struct Sala* nova = (struct Sala*)malloc(sizeof(struct Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void explorarMansao(struct Sala* atual) {
    if (atual == NULL) return;
    
    printf("\nVoce esta na: %s\n", atual->nome);
    
    if (atual->esquerda == NULL && atual->direita == NULL) {
        printf("Fim do caminho! Volte para o inicio.\n");
        return;
    }
    
    printf("Para onde quer ir?\n");
    if (atual->esquerda != NULL) {
        printf("E - Esquerda (%s)\n", atual->esquerda->nome);
    }
    if (atual->direita != NULL) {
        printf("D - Direita (%s)\n", atual->direita->nome);
    }
    printf("S - Sair\n");
    
    char opcao;
    printf("Sua escolha: ");
    scanf(" %c", &opcao);
    
    if (opcao == 'E' || opcao == 'e') {
        explorarMansao(atual->esquerda);
    } else if (opcao == 'D' || opcao == 'd') {
        explorarMansao(atual->direita);
    } else if (opcao == 'S' || opcao == 's') {
        printf("Saindo da exploracao...\n");
    } else {
        printf("Opcao invalida! Tente novamente.\n");
        explorarMansao(atual);
    }
}

int main() {
    printf("=== DETECTIVE QUEST ===\n");
    printf("Explore a mansao misteriosa!\n\n");
    
    // Criar salas
    struct Sala* hall = criarSala("Hall de Entrada");
    struct Sala* sala_estar = criarSala("Sala de Estar");
    struct Sala* cozinha = criarSala("Cozinha");
    struct Sala* biblioteca = criarSala("Biblioteca");
    struct Sala* quarto = criarSala("Quarto");
    struct Sala* jardim = criarSala("Jardim");
    
    // Conectar as salas
    hall->esquerda = sala_estar;
    hall->direita = cozinha;
    
    sala_estar->esquerda = biblioteca;
    sala_estar->direita = quarto;
    
    cozinha->direita = jardim;
    
    // Comecar exploracao
    explorarMansao(hall);
    
    printf("\nFim do jogo!\n");
    
    return 0;
}