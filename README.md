# ASTRO - Agência de Serviços e Tecnologia em Pesquisa Espacial
Projeto da disciplina de Linguagem de Programação 1 (IMD0030), implementado em C++

## Para executar o programa
Em seu terminal, na pasta principal do projeto, execute o comando:
```
make
```
Após a compilação, execute o comando:
```
./comandodevoo
```
E o programa será iniciado.

## Pré-Requisitos
- Compilador "g++" instalado
- Sistema operacional compatível com Makefile (Linux, macOS, Windows com ambiente Unix-like como o MSYS2)

## Sobre o projeto
Este projeto simula um sistema de controle de voos de uma agência espacial fictícia chamada ASTRO (Agência de Serviços e Tecnologia em Pesquisa Espacial). O programa permite o cadastro de astronautas, voos, registro de astronautas em voos, lançamento e finalização de voos, entre outras funcionalidades relacionadas ao gerenciamento operacional de missões espaciais.

## Principais Funcionalidades
- Cadastro de Astronautas: Permite cadastrar astronautas com CPF, nome e idade, verificando restrições de idade (menor que 18 anos ou maior que 85 anos).

- Cadastro de Voos: Permite cadastrar voos com código e destino, verificando a existência prévia do código do voo.

- Registro de Astronautas em Voos: Permite adicionar astronautas a voos planejados, verificando disponibilidade e estado (vivo ou morto).

- Remoção de Astronautas de Voos: Permite remover astronautas de voos planejados, alterando sua disponibilidade.

- Listagem de Voos: Exibe todos os voos cadastrados, mostrando seu status, disponibilidade e destino, além dos astronautas registrados em cada voo.

- Lançamento e Finalização de Voos: Permite lançar e finalizar voos, alterando seu status conforme necessário.

- Menções Honrosas: Exibe astronautas falecidos durante missões, mostrando seus nomes e os voos em que participaram.



