#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
#include <list>
#include <string>
#include "enum/astronautaenum.hpp"

using namespace std;



class Astronauta {
private:
    string cpf;
    string nome;
    int idade;
    bool dispo = true;
    AstronautaEnum status = VIVO;
    list<int> historicoVoos;

public:
    Astronauta(const string& cpf, const string& nome, int idade);

    string getCPF() const;
    string getNome() const;
    int getIdade() const;
    AstronautaEnum getStatus();
    bool getDisponibilidade();
    void mataAstro();
    void setDisponivel();
    void setIndisponivel();
    void adicionarVoo(int codigoVoo);
    const list<int>& getHistoricoVoos() const;
    void setHistoricoVoos(const list<int>& novoHistorico);
};

#endif