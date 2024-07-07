#include "astronauta.hpp"
#include "enum/astronautaenum.hpp"

Astronauta::Astronauta(const string& cpf, const string& nome, int idade)  // Construtor da classe Astronauta
    : cpf(cpf), nome(nome), idade(idade) {}

string Astronauta::getCPF() const {  // Método que retorna o cpf do astronauta
    return cpf;
}

string Astronauta::getNome() const { // Método que retorna o nome do astronauta
    return nome;
}

int Astronauta::getIdade() const {  // Método que retorna a idade do astronauta
    return idade;
}

AstronautaEnum Astronauta::getStatus() {  // Método que retorna o status do astronauta (vivo ou morto)
    return status;
}

bool Astronauta::getDisponibilidade() {  // Método que retorna a disponibilidade do astronauta
    return dispo;
}

void Astronauta::mataAstro() {  // Método que muda o status do astronauta (vivo -> morto)
    status = MORTO;
}

void Astronauta::setDisponivel() {  // Método que muda a disponibilidade do astronauta (true or false -> true)
    dispo = true;
}

void Astronauta::setIndisponivel() {  // Método que muda a disponibilidade do astronauta (true or false -> false)
    dispo = false;
}

void Astronauta::adicionarVoo(int codigoVoo) {  // Método que adiciona o código do voo ao final da lista de voos em que já foi inserido
    historicoVoos.push_back(codigoVoo);
}

const list<int>& Astronauta::getHistoricoVoos() const {  // Método que retorna a lista de voos em que já foi inserido
    return historicoVoos;
}

void Astronauta::setHistoricoVoos(const list<int>& novoHistorico) {  // Método que atualiza a lista de voos em que já foi inserido
    historicoVoos = novoHistorico;
}