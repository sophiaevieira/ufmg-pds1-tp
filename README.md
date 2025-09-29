# Trabalho Prático - Simulação de Batalha Pokémon

<p align="center">
  Simulador de batalhas Pokémon em C, desenvolvido como projeto final da disciplina de <strong>Programação e Desenvolvimento de Software I</strong> na UFMG.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/STATUS-Finalizado-green" alt="Status: Finalizado"/>
  <img src="https://img.shields.io/badge/Linguagem-C-blue" alt="Linguagem: C"/>
  <img src="https://img.shields.io/badge/Compilador-GCC-informational" alt="Compilador: GCC"/>
</p>

---

## 1. Visão Geral do Projeto

Este projeto consiste na implementação de um simulador de batalhas Pokémon em linguagem C. O programa lê os dados de dois times de Pokémon a partir de um arquivo de texto, executa uma batalha baseada em turnos e, ao final, declara um vencedor com base nos resultados.

O objetivo foi aplicar conceitos fundamentais da linguagem C, como manipulação de arquivos, `structs` e lógica de programação para criar uma aplicação funcional. A simulação implementa um sistema de batalha que considera atributos individuais (ataque, defesa, vida) e um sistema de vantagens e desvantagens entre tipos, que alteram o dano em combate.

## 2. Funcionalidades

-   **Leitura de Dados via Arquivo**: Carrega os Pokémon e seus atributos (Nome, Ataque, Defesa, Vida e Tipo) a partir de um arquivo `arquivo.txt`.
-   **Sistema de Batalha por Turnos**: Gerencia uma batalha onde os jogadores atacam alternadamente. O dano é calculado com base no ataque do agressor e na defesa do alvo.
-   **Vantagens e Desvantagens de Tipo**: Aplica um bônus de **+20%** de dano para ataques "super efetivos" e uma penalidade de **-20%** para ataques "não muito efetivos".
-   **Gerenciamento de Batalha**: Acompanha a vida de cada Pokémon, processa as derrotas e avança para o próximo Pokémon do time automaticamente.
-   **Relatório Final Detalhado**: Ao final da simulação, exibe um relatório completo no console, informando o vencedor, os Pokémon sobreviventes e os derrotados.

## 3. Estrutura do Código

O código foi desenvolvido em um único arquivo (`trabalhoVersaoFinal.c`) e utiliza uma estrutura principal para representar os Pokémon.

-   **`struct POKEMON`**: Define o modelo para um Pokémon, armazenando seus cinco atributos essenciais.
    ```c
    typedef struct {
        char nome[MAX_TAM];
        float ataque;
        float defesa;
        float vida;
        char tipo[MAX_TAM];
    } POKEMON;
    ```
-   **`float calculaBonus(POKEMON p1, POKEMON p2)`**: Função que determina o dano final com base nos tipos do Pokémon atacante (`p1`) e do defensor (`p2`).
-   **`int main()`**: Ponto de entrada do programa, responsável por toda a orquestração: ler o arquivo, gerenciar o loop da batalha e imprimir os resultados finais.

## 4. Como Rodar o Projeto

### Pré-requisitos

-   Um compilador C, como o **GCC** (GNU Compiler Collection).

### Passo a Passo

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/sophiaevieira/ufmg-pds1-tp.git](https://github.com/sophiaevieira/ufmg-pds1-tp.git)
    ```

2.  **Acesse a pasta do projeto:**
    ```bash
    cd ufmg-pds1-tp
    ```

3.  **Crie e edite o arquivo `arquivo.txt`**. O arquivo deve estar no mesmo diretório do executável.

    *Exemplo de `arquivo.txt`*:
    ```
    3 2
    Squirtle 10 15 15 agua
    Vulpix 15 15 15 fogo
    Onix 5 20 20 pedra
    Golem 20 5 10 pedra
    Charmander 20 15 12 fogo
    ```

4.  **Compile o código:**
    ```bash
    gcc trabalhoVersaoFinal.c -o batalha_pokemon -Wall
    ```

5.  **Execute o simulador:**
    ```bash
    ./batalha_pokemon
    ```

### Exemplo de Saída

Para o `arquivo.txt` de exemplo acima, a saída no console será:
