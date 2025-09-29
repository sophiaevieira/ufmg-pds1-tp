# Trabalho Prático - Simulação de Batalha Pokémon

**Disciplina:** Programação e Desenvolvimento de Software I (DCC-2024/1)  
**Instituição:** Departamento de Ciência da Computação (DCC) - UFMG  
**Autor:** Sophia Vieira ([sophiaevieira](https://github.com/sophiaevieira))

---

## 1. Descrição do Projeto

Este projeto consiste na implementação de um simulador de batalhas Pokémon em linguagem C. O programa lê os dados de dois times de Pokémon a partir de um arquivo de texto, executa uma batalha em turnos e, ao final, declara um vencedor com base nos resultados.

O objetivo foi aplicar conceitos fundamentais da linguagem C, como manipulação de arquivos, `structs`, e lógica de programação para criar uma aplicação funcional e organizada. A simulação implementa um sistema de batalha que considera atributos individuais de cada Pokémon (ataque, defesa, vida) e um sistema de vantagens e desvantagens entre diferentes tipos (elétrico, água, fogo, etc.), que alteram o dano em combate.

## 2. Funcionalidades Implementadas

* **Leitura de Dados via Arquivo:** O programa carrega os Pokémon e seus atributos (Nome, Ataque, Defesa, Vida e Tipo) a partir de um arquivo de entrada `arquivo.txt`, permitindo a fácil configuração dos times.
* **Sistema de Batalha por Turnos:** A lógica central do simulador gerencia uma batalha onde os jogadores atacam alternadamente. O dano é calculado com base no ataque do agressor e na defesa do alvo.
* **Vantagens e Desvantagens de Tipo:** Foi implementado um sistema que aplica um bônus de **+20%** de dano para ataques "super efetivos" (ex: Água vs. Fogo) e uma penalidade de **-20%** para ataques "não muito efetivos" (ex: Fogo vs. Água).
* **Gerenciamento de Batalha:** O programa acompanha a vida de cada Pokémon, processa as derrotas e substitui automaticamente pelo próximo Pokémon do time. A batalha termina quando um jogador perde todos os seus Pokémon.
* **Relatório Final Detalhado:** Ao final da simulação, o programa exibe um relatório completo no console, informando o jogador vencedor, a lista de Pokémon sobreviventes e a lista de todos os Pokémon que foram derrotados.

## 3. Estrutura do Código

O código foi desenvolvido em um único arquivo (`trabalhoVersaoFinal.c`) e utiliza uma estrutura principal para representar os Pokémon.

* **`struct POKEMON`**: Define o modelo para um Pokémon, armazenando seus cinco atributos essenciais:
    * `char nome[100]`
    * `float ataque`
    * `float defesa`
    * `float vida`
    * `char tipo[100]`
* **`float calculaBonus(POKEMON p1, POKEMON p2)`**: Função que determina o multiplicador de dano com base nos tipos do Pokémon atacante (`p1`) e do defensor (`p2`). Retorna o valor do ataque modificado.
* **`int main()`**: Ponto de entrada do programa. É responsável por:
    1.  Abrir e ler o arquivo `arquivo.txt`.
    2.  Carregar os dados dos Pokémon em arrays de `structs`.
    3.  Gerenciar o loop principal da batalha, controlando os turnos e os ataques.
    4.  Calcular o dano, atualizar a vida dos Pokémon e detectar derrotas.
    5.  Imprimir os resultados finais da batalha no console.

## 4. Compilação e Execução

### Pré-requisitos

* Um compilador C, como o **GCC** (GNU Compiler Collection).
* A ferramenta `make` (opcional, mas recomendada).

### Compilação

Na pasta raiz do projeto, execute o seguinte comando para compilar o código:

```bash
gcc trabalhoVersaoFinal.c -o batalha_pokemon -Wall
```
### Execução

1.  **Crie o arquivo de entrada:** Certifique-se de que existe um arquivo chamado `arquivo.txt` no mesmo diretório. O formato deve ser:

    ```
    <num_pok_jogador1> <num_pok_jogador2>
    <nome> <ataque> <defesa> <vida> <tipo>
    ... (pokémons do jogador 1)
    <nome> <ataque> <defesa> <vida> <tipo>
    ... (pokémons do jogador 2)
    ```

2.  **Execute o programa:**

    ```bash
    ./batalha_pokemon
    ```

O programa lerá o `arquivo.txt` e exibirá todo o andamento e o resultado da batalha no terminal.
