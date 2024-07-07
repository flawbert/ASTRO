#include "voo.hpp"
#include "cemiterio.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "enum/vooenum.hpp"
#include "astronauta.hpp"

Voo::Voo(int codigo, const string& destinoNovo) : codigoVoo(codigo), destino(destinoNovo) {}  // Construtor da classe Voo

int Voo::getCodigo() const {  // Método que retorna o código do voo
    return codigoVoo;
}

VooEnum Voo::getStatus() const {  // Método que retorna o status do voo (planejando, explodido, em voo)
    return status;
}

bool Voo::getDispo() const {  // Método que retorna a disponibilidade do voo
    return dispo;
}

string Voo::getDestino() const {  // Método que retorna o destino do voo
    return destino;
}

void Voo::setStatus(VooEnum novoStatus) {  // Método que muda o status do voo
    status = novoStatus;
}

void Voo::setDestino(string novoDestino) {  // Método que define o destino do voo
    destino = novoDestino;
}

void Voo::adicionarPassageiro(const Astronauta& astronauta) {  // Método que adiciona os astronautas ao final da sua lista de passageiros
    passageiros.push_back(astronauta);
}

void Voo::lancarVoo() {  // Método que lança o voo, mudando seu status e disponibilidade
    srand(time(nullptr));
    int numAleatorio = rand() % 2; // Número entre 1 e 0 para que seja aleatória a destruição do voo ou seu sucesso

    if (numAleatorio == 0) {
        status = DESTRUIDO;
        cout << "O Voo de codigo " << codigoVoo << " foi explodido." << endl;
        for (auto& astronauta : passageiros) {
            astronauta.mataAstro();
            cout << "O astronauta " << astronauta.getNome() << " morreu..." << endl;
            Cemiterio::adicionarMorto(astronauta);
        }
    } else {
        status = EMVOO;
        cout << "O Voo de codigo " << codigoVoo << " esta a caminho de " << destino << endl;
    }

    dispo = false;
}

void Voo::visualizarPassageiros(const list<Astronauta>& astronautas) const {  // Método que mostra os astronautas contidos nas sua lista de passageiros
    cout << "   Astronautas cadastrados para o voo [" << codigoVoo << "]:" << endl;

    for (const auto& astronauta : passageiros) {
        if (passageiros.empty()) {
            cout << "   Nao ha astronautas cadastrados..." << endl;
            break;
        } else {
            cout << "   CPF: " << astronauta.getCPF() << ", Nome: " << astronauta.getNome() << ", Idade: " << astronauta.getIdade() << endl;
        }
    }
}

void Voo::removerPassageiro(const string& cpf) {  // Método que retira o astronauta da sua lista de passageiros
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->getCPF() == cpf) {
            passageiros.erase(it);
            return;
        }
    }
}

void Voo::finalizarVoo(list <Astronauta>& astronautas) {  // Método que finaliza o voo, mudando seu status e disponibilidade
    status = PLANEJANDO; // definir o status do voo como planejando novamente
    dispo = true; // tornar o voo disponível novamente

    cout << "O voo pousou de " << destino << endl;

    // Marcar todos os passageiros como disponíveis novamente
    for (auto& passageiro : passageiros) {
        for (auto& astronauta : astronautas) {
            if (astronauta.getCPF() == passageiro.getCPF()) {
                astronauta.setDisponivel();
            }
        }
    }
    
    // Limpar a lista de passageiros, já que o voo foi finalizado
    passageiros.clear();
}