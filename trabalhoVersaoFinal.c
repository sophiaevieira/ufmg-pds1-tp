#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_POK 100 // máximo de pokémons por jogador 
#define MAX_TAM 100// tamanho máximo para limitar tamanho de strings, linhas etc no código
#define TRUE 1 // definindo 1 como verdadeiro
#define FALSE 0 // definindo 0 como falso
// estrutura para definifir o tipo pokémon : define o nome do pokémon, ataque, defesa, vida e tipo.
typedef struct {
    char nome[MAX_TAM];
    float ataque; 
    float defesa; 
    float vida; 
    char tipo[MAX_TAM];
}   POKEMON; 
// função responsável calcular bônus : 
float calculaBonus(POKEMON p1, POKEMON p2){ // calcula o bônus de ataque do jogador atual
    if ((strcmp(p1.tipo, "eletrico") == 0) && (strcmp(p2.tipo, "agua") == 0)) {
        return p1.ataque * 1.2f;   
    }
    else if ((strcmp(p1.tipo, "eletrico") == 0) && (strcmp(p2.tipo, "pedra") == 0)) {
        return p1.ataque * 0.8f;   
    }
    else if ((strcmp(p1.tipo, "agua") == 0) && (strcmp(p2.tipo, "fogo") == 0)) {
        return p1.ataque * 1.2f;   
    }
    else if ((strcmp(p1.tipo, "agua") == 0) && (strcmp(p2.tipo, "eletrico") == 0)) {
        return p1.ataque * 0.8f;   
    }
    else if ((strcmp(p1.tipo, "fogo") == 0) && (strcmp(p2.tipo, "gelo") == 0)) {
        return p1.ataque * 1.2f;   
    }
    else if ((strcmp(p1.tipo, "fogo") == 0) && (strcmp(p2.tipo, "agua") == 0)) {
        return p1.ataque * 0.8f;   
    }
    else if ((strcmp(p1.tipo, "gelo") == 0) && (strcmp(p2.tipo, "pedra") == 0)) {
        return p1.ataque * 1.2f;   
    }
    else if ((strcmp(p1.tipo, "gelo") == 0) && (strcmp(p2.tipo, "fogo") == 0)) {
        return p1.ataque * 0.8f;   
    }
    else if ((strcmp(p1.tipo, "pedra") == 0) && (strcmp(p2.tipo, "eletrico") == 0)) {
        return p1.ataque * 1.2f;   
    }
    else if ((strcmp(p1.tipo, "pedra") == 0) && (strcmp(p2.tipo, "gelo") == 0)) {
        return p1.ataque * 0.8f; 
    }
    else {
        return p1.ataque * 1.0f;
    }
}
int main(){

    FILE * arquivo; // variável para receber o arquivo
    POKEMON pokemon1[MAX_TAM] , pokemon2[MAX_TAM]; // vetores para armazenar os pokémons de cada jogador
    int jogador1; // variável que será ultilizada na lógica de turnos
    int numPok1, numPok2; // variáveis para armazenar o número de pokémons de cada jogador
    // abrindo o arquivo:
    if  ((arquivo = fopen("arquivo.txt" , "r")) == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        exit(1);
    }
    // ler o arquivo:
    // ler a primeira linha do arquivo e armazenar números de pokémons:
    fscanf(arquivo , "%d %d" , &numPok1 , &numPok2);
    printf("O jogador 1 possui %d pokémons e o jogador 2 possui %d pokémons.\n" , numPok1, numPok2);
    printf("\n");
    printf("Os pokémons do jogador 1 são:\n");
    // ler próximas linhas do arquivo e imprime dados lidos na tela (dados do jogador 1);
    for(int i = 0; i<numPok1; i++){
        fscanf(arquivo , "%s %f %f %f %s" , pokemon1[i].nome , &pokemon1[i].ataque , &pokemon1[i].defesa , &pokemon1[i].vida , pokemon1[i].tipo);
        printf("%s %.1f %.1f %.1f %s\n" , pokemon1[i].nome , pokemon1[i].ataque , pokemon1[i].defesa , pokemon1[i].vida , pokemon1[i].tipo);
    }
    printf("\n");
    printf("Os pokémons do jogador 2 são:\n");
    // ler próximas linhas do arquivo e imprime dados lidos na tela (dados do jogador 2);
    for(int i = 0; i<numPok2; i++){
        fscanf(arquivo , "%s %f %f %f %s" , pokemon2[i].nome , &pokemon2[i].ataque , &pokemon2[i].defesa , &pokemon2[i].vida , pokemon2[i].tipo);
        printf("%s %.1f %.1f %.1f %s\n" , pokemon2[i].nome , pokemon2[i].ataque , pokemon2[i].defesa , pokemon2[i].vida , pokemon2[i].tipo);
    }
    printf("\n");
    // inicializando i e j, como zero para ser ultilizado no loop while:
    int i = 0;
    int j = 0;
    int k = 0;
    float poderAtaque;
    printf("Iniciou a batalha!\n");
    // inicializando o jogador 1 como TRUE, para que ele comece a batalha:
    jogador1 = TRUE;
    while ((i < numPok1 && j < numPok2)) {
        // verifica que jogador ataca:
        if (jogador1 == TRUE) { // se a condição for verdadeira, o ataque do jogador 1 se inicia
            // calculando bônus:
            poderAtaque = calculaBonus(pokemon1[i], pokemon2[j]);           
            if (poderAtaque > pokemon2[j].defesa) { // o ataque do pokemon 1 é comparado a defesa do pokemon 2,
            //se o ataque do pokemon 1 for maior que a defesa do pokemon 2, o bloco é executado:
                pokemon2[j].vida -= (poderAtaque - pokemon2[j].defesa); // a diferença entre ataque e defesa é subtraída da vida do pokémon2
            } else { 
                // caso o ataque do jogador 1 não exceder a defesa do jogador 2:
                pokemon2[j].vida--; // é subtraída 1 ponto da vida total do pokémon 2  
            }

            if (pokemon2[j].vida <= 0) { // se a vida restante for menor ou igual à zero, o boloco é executado:
                printf("%s venceu %s\n" , pokemon1[i].nome , pokemon2[j].nome); // pokémon 1 é declarado o vencedor
                j++; // avançando para o próximo pokémon do jogador 2
            } 

            jogador1 = FALSE; // fim do turno do jogador 1
        }else{ 
            // vez do jogador 2 atacar
            // calculando bônus:
            poderAtaque = calculaBonus(pokemon2[j], pokemon1[i]);
            if (poderAtaque > pokemon1[i].defesa) { // o ataque do pokemon 2 é comparado a defesa do pokemon 1, se o ataque do pokemon 2 for maior que a defesa do pokemon 1, o bloco é executado:
                pokemon1[i].vida -= (poderAtaque - pokemon1[i].defesa); // a diferença entre ataque e defesa é subtraída da vida do pokémon1
            } else { // caso o ataque do jogador 2 não exceder a defesa do jogador 1:
                pokemon1[i].vida--; // é subtraída 1 ponto da vida total do pokémon 1
            }

            if (pokemon1[i].vida <= 0) { // se a vida restante for menor ou igual à zero, o boloco é executado:
                printf("%s venceu %s\n" , pokemon2[j].nome , pokemon1[i].nome); // pokémon 2 é declarado o vencedor
                i++; // avançando para o próximo pokémon do jogador 1
            } 
            jogador1 = TRUE; // fim do turno do jogador 1
        }
    }
      printf("\n");
      printf("Resultado da batalha:\n");

    // impressão dos resultados finais: 
    if (jogador1 == FALSE) {
        printf("O jogador 1 venceu.\n");
    } else {
        printf("O jogador 2 venceu.\n");
    }
    printf("\n");
    // imprimindo pokémons sobreviventes: 
    printf("Pokémons sobreviventes:\n");
    for (k = i; k < numPok1; k++) {
        printf("%s\n" , pokemon1[k].nome);
    }
    for (k = j; k < numPok2; k++) {
        printf("%s\n" , pokemon2[k].nome);
    }
    printf("\n");
    // imprimindo pokémons derrotados:
    printf("Pokémons derrotados:\n");
    for (k = 0; k < i; k++) {
        printf("%s\n" , pokemon1[k].nome);
    }
    for (k = 0; k < j; k++) {
        printf("%s\n" , pokemon2[k].nome);
    }
    printf("\n");

    fclose(arquivo); // fechando o arquivo ultilizado

    return 0; // finalizando o programa
}