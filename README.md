<h1> Trabalho Prático - Simulação de Batalha Pokémon </h1>

<p>
  Simulador de batalhas Pokémon em C, desenvolvido como projeto final da disciplina de <strong>Programação e Desenvolvimento de Software I</strong> na UFMG.  
  O programa lê os dados dos times a partir de um arquivo, executa batalhas baseadas em turnos e atributos, e declara o grande campeão.
</p>

<p>
  <img src="https://img.shields.io/badge/STATUS-Finalizado-green" alt="Status: Finalizado"/>
  <img src="https://img.shields.io/badge/Linguagem-C-blue" alt="Linguagem: C"/>
</p>

---

## Visão Geral do Projeto

O objetivo deste trabalho foi aplicar os conceitos fundamentais da linguagem **C** para criar uma aplicação funcional e organizada.  

A simulação começa com a leitura de um arquivo de entrada (`arquivo.txt`), que define os Pokémon de cada jogador com os seguintes atributos:

- **Nome**  
- **Ataque**  
- **Defesa**  
- **Vida**  
- **Tipo**

A batalha ocorre em turnos, levando em conta **vantagens e desvantagens entre tipos**. Ataques podem receber **bônus ou penalidade de 20%** no dano.  

Um Pokémon é derrotado quando sua vida chega a zero, e a partida termina quando um dos jogadores perde todos os seus Pokémon.

---

## Funcionalidades

- **Batalha por turnos**: ataques, danos e substituições automáticas.  
- **Sistema de vantagens de tipo**: Água, Fogo, Pedra, Elétrico etc. influenciam no resultado.  
- **Entrada via arquivo `.txt`**: configuração flexível dos times.  
- **Relatório final**: mostra o vencedor, sobreviventes e derrotados.  

---

## Tecnologias Utilizadas

- **Linguagem:** C  
- **Compilador:** GCC (GNU Compiler Collection)  
- **Controle de versão:** Git & GitHub  

---

## Como Rodar o Projeto

### Pré-requisitos

Um compilador C instalado (ex.: **GCC**).

```bash
# Verificar instalação do GCC
gcc --version
````

### Passo a passo

1. Clone o repositório:

   ```bash
   git clone https://github.com/sophiaevieira/ufmg-pds1-tp.git
   ```

2. Acesse a pasta do projeto:

   ```bash
   cd ufmg-pds1-tp
   ```

3. Crie ou edite o arquivo `arquivo.txt` com o formato:

   ```
   3 2
   Squirtle 10 15 15 agua
   Vulpix 15 15 15 fogo
   Onix 5 20 20 pedra
   Golem 20 5 10 pedra
   Charmander 20 15 12 fogo
   ```

4. Compile o código:

   ```bash
   gcc trabalhoVersaoFinal.c -o batalha_pokemon -Wall
   ```

5. Execute o simulador:

   ```bash
   ./batalha_pokemon
   ```

---

## Estrutura do Código

* **`struct POKEMON`** → define os atributos de cada criatura.
* **`float calculaBonus(POKEMON p1, POKEMON p2)`** → aplica bônus/penalidade conforme o tipo.
* **`int main()`** → ponto de entrada, responsável por:

  * Abrir e validar o arquivo de entrada;
  * Carregar os Pokémon em arrays de `structs`;
  * Gerenciar o loop principal da batalha;
  * Exibir os resultados no console.

---

## Exemplo de Uso

```bash
./batalha_pokemon
```

Saída esperada (exemplo simplificado):

```
Turno 1: Squirtle ataca Vulpix (dano: 12)
Vulpix resistiu! Vida restante: 3

Turno 2: Vulpix ataca Squirtle (dano: 8)
Squirtle resistiu! Vida restante: 7

...

🏆 Jogador 1 venceu a batalha!
```

---

# Autora

| [Sophia Vieira](https://github.com) |
| :--------------------------------------------------------------------------------------------------------------------------------: |
