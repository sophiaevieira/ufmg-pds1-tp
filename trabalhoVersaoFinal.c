#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_POK 100
#define MAX_TAM 100
#define TRUE 1
#define FALSE 0

// define a estrutura para um pokemon
typedef struct {
    char nome[MAX_TAM];
    float ataque;
    float defesa;
    float vida;
    char tipo[MAX_TAM];
} POKEMON;

// calcula o bônus de ataque com base nos tipos dos pokemons
float calculaBonus(POKEMON p1, POKEMON p2) {
    if ((strcmp(p1.tipo, "eletrico") == 0) && (strcmp(p2.tipo, "agua") == 0)) {
        return p1.ataque * 1.2f;
    } else if ((strcmp(p1.tipo, "eletrico") == 0) && (strcmp(p2.tipo, "pedra") == 0)) {
        return p1.ataque * 0.8f;
    } else if ((strcmp(p1.tipo, "agua") == 0) && (strcmp(p2.tipo, "fogo") == 0)) {
        return p1.ataque * 1.2f;
    } else if ((strcmp(p1.tipo, "agua") == 0) && (strcmp(p2.tipo, "eletrico") == 0)) {
        return p1.ataque * 0.8f;
    } else if ((strcmp(p1.tipo, "fogo") == 0) && (strcmp(p2.tipo, "gelo") == 0)) {
        return p1.ataque * 1.2f;
    } else if ((strcmp(p1.tipo, "fogo") == 0) && (strcmp(p2.tipo, "agua") == 0)) {
        return p1.ataque * 0.8f;
    } else if ((strcmp(p1.tipo, "gelo") == 0) && (strcmp(p2.tipo, "pedra") == 0)) {
        return p1.ataque * 1.2f;
    } else if ((strcmp(p1.tipo, "gelo") == 0) && (strcmp(p2.tipo, "fogo") == 0)) {
        return p1.ataque * 0.8f;
    } else if ((strcmp(p1.tipo, "pedra") == 0) && (strcmp(p2.tipo, "eletrico") == 0)) {
        return p1.ataque * 1.2f;
    } else if ((strcmp(p1.tipo, "pedra") == 0) && (strcmp(p2.tipo, "gelo") == 0)) {
        return p1.ataque * 0.8f;
    } else {
        return p1.ataque * 1.0f;
    }
}

int main() {
    FILE *arquivo;
    POKEMON pokemon1[MAX_TAM], pokemon2[MAX_TAM];
    int jogador1;
    int numPok1, numPok2;
    int i = 0, j = 0, k = 0;
    float poderAtaque;

    // abertura do arquivo de entrada
    if ((arquivo = fopen("arquivo.txt", "r")) == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        exit(1);
    }

    // leitura dos dados do arquivo
    fscanf(arquivo, "%d %d", &numPok1, &numPok2);
    printf("O jogador 1 possui %d pokémons e o jogador 2 possui %d pokémons.\n", numPok1, numPok2);
    printf("\n");

    printf("Os pokémons do jogador 1 são:\n");
    for (i = 0; i < numPok1; i++) {
        fscanf(arquivo, "%s %f %f %f %s", pokemon1[i].nome, &pokemon1[i].ataque, &pokemon1[i].defesa, &pokemon1[i].vida, pokemon1[i].tipo);
        printf("%s %.1f %.1f %.1f %s\n", pokemon1[i].nome, pokemon1[i].ataque, pokemon1[i].defesa, pokemon1[i].vida, pokemon1[i].tipo);
    }
    printf("\n");

    printf("Os pokémons do jogador 2 são:\n");
    for (i = 0; i < numPok2; i++) {
        fscanf(arquivo, "%s %f %f %f %s", pokemon2[i].nome, &pokemon2[i].ataque, &pokemon2[i].defesa, &pokemon2[i].vida, pokemon2[i].tipo);
        printf("%s %.1f %.1f %.1f %s\n", pokemon2[i].nome, pokemon2[i].ataque, pokemon2[i].defesa, pokemon2[i].vida, pokemon2[i].tipo);
    }
    printf("\n");

    // início da lógica da batalha
    printf("Iniciou a batalha!\n");
    i = 0;
    j = 0;
    jogador1 = TRUE; // jogador 1 começa

    while ((i < numPok1 && j < numPok2)) {
        // verifica de quem é o turno
        if (jogador1 == TRUE) {
            poderAtaque = calculaBonus(pokemon1[i], pokemon2[j]);
            if (poderAtaque > pokemon2[j].defesa) {
                pokemon2[j].vida -= (poderAtaque - pokemon2[j].defesa);
            } else {
                pokemon2[j].vida--;
            }

            if (pokemon2[j].vida <= 0) {
                printf("%s venceu %s\n", pokemon1[i].nome, pokemon2[j].nome);
                j++; // avança para o próximo pokémon do jogador 2
            }
            jogador1 = FALSE; // passa o turno para o jogador 2
        } else {
            poderAtaque = calculaBonus(pokemon2[j], pokemon1[i]);
            if (poderAtaque > pokemon1[i].defesa) {
                pokemon1[i].vida -= (poderAtaque - pokemon1[i].defesa);
            } else {
                pokemon1[i].vida--;
            }

            if (pokemon1[i].vida <= 0) {
                printf("%s venceu %s\n", pokemon2[j].nome, pokemon1[i].nome);
                i++; // avança para o próximo pokémon do jogador 1
            }
            jogador1 = TRUE; // passa o turno para o jogador 1
        }
    }

    // impressão dos resultados finais
    printf("\n");
    printf("Resultado da batalha:\n");
    if (jogador1 == FALSE) {
        printf("O jogador 1 venceu.\n");
    } else {
        printf("O jogador 2 venceu.\n");
    }
    printf("\n");

    printf("Pokémons sobreviventes:\n");
    for (k = i; k < numPok1; k++) {
        printf("%s\n", pokemon1[k].nome);
    }
    for (k = j; k < numPok2; k++) {
        printf("%s\n", pokemon2[k].nome);
    }
    printf("\n");

    printf("Pokémons derrotados:\n");
    for (k = 0; k < i; k++) {
        printf("%s\n", pokemon1[k].nome);
    }
    for (k = 0; k < j; k++) {
        printf("%s\n", pokemon2[k].nome);
    }
    printf("\n");

    fclose(arquivo);

    return 0;
}
