#include "voo.hpp"
#include "cemiterio.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "enum/vooenum.hpp"
#include "astronauta.hpp"

Voo::Voo(int codigo, const string& destinoNovo) : codigoVoo(codigo), destino(destinoNovo) {}

int Voo::getCodigo() const {
    return codigoVoo;
}
VooEnum Voo::getStatus() const {
    return status;
}
bool Voo::getDispo() const {
    return dispo;
}
string Voo::getDestino() const {
    return destino;
}
void Voo::setStatus(VooEnum novoStatus) {
    status = novoStatus;
}
void Voo::setDestino(string novoDestino) {
    destino = novoDestino;
}
void Voo::adicionarPassageiro(const Astronauta& astronauta) {
    passageiros.push_back(astronauta);
}
void Voo::lancarVoo() {
    srand(time(nullptr));
    int numAleatorio = rand() % 2;
    if (numAleatorio == 0) {
        status = DESTRUIDO;
        cout << "O voo de código " << codigoVoo << " foi explodido em curso." << endl;
        for (auto& astronauta : passageiros) {
            astronauta.mataAstro();
            cout << "O astronauta " << astronauta.getNome() << " morreu. A ASTRO lamenta tal ocorrido." << endl;
            Cemiterio::adicionarMorto(astronauta);
        }
    } else {
        status = EMVOO;
        cout << "O voo de código " << codigoVoo << " está em seu curso para " << destino << endl;
    }

    dispo = false;
}

void Voo::visualizarPassageiros(const list<Astronauta>& astronautas) const {
    cout << "   Astronautas cadastrados para o voo [" << codigoVoo << "]:" << endl;

    for (const auto& astronauta : passageiros) {
        if (passageiros.empty()) {
            cout << "   Não existem astronautas cadastrados em nosso sistema." << endl;
            break;
        } else {
            cout << "   CPF: " << astronauta.getCPF() << ", Nome: " << astronauta.getNome() << ", Idade: " << astronauta.getIdade() << endl;
        }
    }
}
void Voo::removerPassageiro(const string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->getCPF() == cpf) {
            passageiros.erase(it);
            return;
        }
    }
}
void Voo::finalizarVoo(list <Astronauta>& astronautas) { 
    status = PLANEJANDO;
    dispo = true;

    cout << "O voo pousou de " << destino << endl;
    for (auto& passageiro : passageiros) {
        for (auto& astronauta : astronautas) {
            if (astronauta.getCPF() == passageiro.getCPF()) {
                astronauta.setDisponivel();
            }
        }
    }
    passageiros.clear();
}