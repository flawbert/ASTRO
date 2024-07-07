#ifndef VOO_H
#define VOO_H

#include <list>
#include <string>
#include "astronauta.hpp"
#include "enum/astronautaenum.hpp"
#include "enum/vooenum.hpp"

using namespace std;

class Voo {
private:
    int codigoVoo;
    bool dispo = true;
    list<Astronauta> passageiros;
    VooEnum status = PLANEJANDO;
    string destino;

public:
    Voo(int codigo, const string& destinoNovo);

    int getCodigo() const;
    VooEnum getStatus() const;
    bool getDispo() const;
    string getDestino() const;
    void setStatus(VooEnum novoStatus);
    void setDestino(string novoDestino);
    void adicionarPassageiro(const Astronauta& astronauta);
    void lancarVoo();
    void visualizarPassageiros(const list<Astronauta>& astronautas) const;
    void removerPassageiro(const string& cpf);
    void finalizarVoo(list <Astronauta>& astronautas);
};

#endif