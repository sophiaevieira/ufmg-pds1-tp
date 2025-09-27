<h1 align="center">👾 Projeto Batalha Pokémon 🏆</h1>

<p align="center">
  Simulador de batalhas Pokémon em C, desenvolvido como projeto final da disciplina de Programação e Desenvolvimento de Software I na UFMG.  
  O programa lê os dados dos times a partir de um arquivo, executa batalhas baseadas em turnos e atributos, e declara o grande campeão.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/STATUS-Finalizado-green" alt="Badge Status: Finalizado"/>
  <img src="https://img.shields.io/badge/Linguagem-C-blue" alt="Badge Linguagem: C"/>
  <img src="https://img.shields.io/badge/Licença-MIT-lightgrey" alt="Badge Licença: MIT"/>
</p>

<p align="center">
  <a href="#-visão-geral-do-projeto">Visão Geral</a> •
  <a href="#-funcionalidades">Funcionalidades</a> •
  <a href="#-tecnologias-utilizadas">Tecnologias</a> •
  <a href="#-como-rodar-o-projeto">Como Rodar</a> •
  <a href="#-estrutura-do-código">Estrutura</a> •
  <a href="#-licença">Licença</a> •
  <a href="#-autora">Autora</a>
</p>

---

## 📜 Visão Geral do Projeto

O objetivo deste trabalho foi aplicar conceitos fundamentais da linguagem C para criar uma aplicação funcional e organizada.  
A simulação inicia com a leitura de um arquivo de entrada (`arquivo.txt`), que contém os Pokémon e seus atributos:

- **Nome**
- **Ataque**
- **Defesa**
- **Vida**
- **Tipo**

A batalha ocorre em turnos, considerando as vantagens e desvantagens entre tipos. Ataques podem receber **bônus ou penalidade de 20%** no dano.  
Um Pokémon é derrotado quando sua vida chega a zero, e a partida termina quando um dos jogadores perde todos os seus Pokémon.

---

## ✨ Funcionalidades

- 🎮 **Batalha por turnos**: gerenciamento completo de ataques, danos e substituições.  
- 🔥 **Sistema de vantagens de tipo**: tipos (Água, Fogo, Pedra, Elétrico, etc.) afetam o resultado dos confrontos.  
- 📂 **Entrada via arquivo `.txt`**: configuração flexível dos times.  
- 📝 **Relatório final**: exibe o vencedor, os sobreviventes e os Pokémon derrotados.  

---

## ✔️ Tecnologias Utilizadas

- **Linguagem:** C  
- **Compilador:** GCC (GNU Compiler Collection)  
- **Controle de versão:** Git & GitHub  

---

## 🚀 Como Rodar o Projeto

### Pré-requisitos

Ter um compilador C instalado (ex.: **GCC**).

```bash
# Verificar se o GCC está instalado
gcc --version
````

### Instalação e Execução

1. Clone o repositório:

   ```bash
   git clone https://github.com/sophiaevieira/ufmg-pds1-tp.git
   ```

2. Acesse a pasta do projeto:

   ```bash
   cd ufmg-pds1-tp
   ```

3. Configure o arquivo de entrada `arquivo.txt`.
   Exemplo de formatação:

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

## 🏛️ Estrutura do Código

* **`struct POKEMON`** → modela os atributos de cada criatura.
* **`float calculaBonus(POKEMON p1, POKEMON p2)`** → calcula bônus/penalidade considerando o tipo.
* **`int main()`** → ponto de entrada, responsável por:

  * Abrir e validar o arquivo de entrada;
  * Carregar os Pokémon em arrays de `structs`;
  * Gerenciar o loop principal da batalha;
  * Exibir os resultados no console.
