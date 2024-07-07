#include <iostream>
#include <list>
#include "astronauta.hpp"
#include "voo.hpp"
#include "cemiterio.hpp"
#include "enum/astronautaenum.hpp"
#include "enum/vooenum.hpp"

using namespace std;

void opcoes() {
    list<string> opcoes;
    opcoes.push_back("***************************** ASTRO ******************************");
opcoes.push_back("***** Agência de Serviços e Tecnologia em Pesquisa Espacial  *****");
opcoes.push_back("******************************************************************");
opcoes.push_back("*                    1 - Cadastrar Astronauta                    *");
opcoes.push_back("*                    2 - Cadastrar Voo                           *");
opcoes.push_back("*                    3 - Registrar Astronautas em um Voo         *");
opcoes.push_back("*                    4 - Remover Astronautas de um Voo           *");
opcoes.push_back("*                    5 - Listar Voos                             *");
opcoes.push_back("*                    6 - Lançar Voo                              *");
opcoes.push_back("*                    7 - Finalizar Voo                           *");
opcoes.push_back("*                    8 - Listar Astronautas                      *");
opcoes.push_back("*                    9 - Menções Honrosas                        *");
opcoes.push_back("*                    0 - Sair                                    *");
opcoes.push_back("******************************************************************");


    for (const auto& frase : opcoes) {
        cout << frase << endl;
    }
    cout << endl;
}
int main(void) {

    cout << endl;

    cout << "Bem-vindo(a) ao controle de voo da ASTRO." << endl;

    int controle = 0;
    list<Astronauta> astronautas;
    list<Voo> voos;
    Cemiterio cemiterio;

    while (controle != 1) {
        cout << endl;
        opcoes();
        int op;
        cout << "Selecione uma opção: ";
        cin >> op;
        cout << endl;

        switch (op) {

            case 1: {
                string cpf, nome;
                int idade, verificacao = 0;
                cout << "CPF do astronauta: ";
                cin >> cpf;
                for (auto& astronauta : astronautas) {
                    if (astronauta.getCPF() == cpf) {
                        cout << "O CPF é inválido." << endl;
                        verificacao++;
                        break;
                    }
                }
                if ( verificacao == 1) {
                    cout << "Tente cadastrar outro astronauta" << endl;
                    break;
                }
                else {
                    cout << "Nome do astronauta: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Idade do astronauta: ";
                    cin >> idade;
                    if (idade < 18) {
                        cout << "Por ser muito novo, o astronauta não pode ser cadastrado. " << endl << "Cadastre outro astronauta" << endl;
                        break;
                    }
                    else if (idade > 85) {
                        cout << "Por ser idoso, o astronauta não pode ser cadastrado. " << endl << "Cadastre outro astronauta" << endl;
                        break;
                    }
                    else {
                        Astronauta astronauta(cpf, nome, idade);
                        cout << endl << "Astronauta cadastrado: " << endl;
                        cout << "   CPF: " << astronauta.getCPF() << endl;
                        cout << "   Nome: " <<  astronauta.getNome() << endl;
                        cout << "   Idade: " << astronauta.getIdade() << endl;
                        astronautas.push_back(astronauta);
                        break;
                    }    
                }
            }  

            case 2: {
                int numVoo, verificacao = 0;
                string destino;
                cout << "Código do voo: ";
                cin >> numVoo;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == numVoo) {
                        cout << "ERRO! Esse código é inválido. Tente novamente." << endl;
                        verificacao = 1;
                        break;
                    }
                }
                if (verificacao == 1) {
                    cout << "ERRO! Cadastre um voo diferente. " << endl;
                    break;
                }
                else {
                    cout << "Destino do voo: ";
                    cin.ignore();
                    getline(cin, destino);
                    Voo novoVoo(numVoo, destino);
                    cout << "O voo de código " << novoVoo.getCodigo() << " com destino a " << novoVoo.getDestino() <<" já esta em planejamento." << endl;
                    voos.push_back(novoVoo);

                    break;
                }
            }

            case 3: {
                cout << "Voos disponiveis (em planejamento): " << endl;

                for (const auto& voo : voos) {
                    if (voo.getStatus() == PLANEJANDO) {
                        cout << "   Voo Cod: " << voo.getCodigo() << endl;
                    }
                }
                int cod;
                cout << "Digite o código do Voo a ser adicionado Astronautas: ";
                cin >> cod;
                bool encontrado = false;
                for (auto it = voos.begin(); it != voos.end(); ++it) {
                    if (it->getCodigo() == cod && it->getStatus() == PLANEJANDO) {
                        cout << "Voo com destino a " << it->getDestino() << endl;
                        it->visualizarPassageiros(astronautas); // Passar a lista de astronautas como argumento
                        encontrado = true;
                        while (true) {
                            string cpfAstronauta;
                            cout << "Digite o CPF do astronauta a ser adicionado ao voo [0 para sair]: ";
                            cin >> cpfAstronauta;
                            if (cpfAstronauta == "0") {
                                break;
                            }
                            bool astroFind = false;
                            for (auto& astronauta : astronautas) {
                                if (astronauta.getCPF() == cpfAstronauta && astronauta.getStatus() == VIVO && astronauta.getDisponibilidade()) {
                                    it->adicionarPassageiro(astronauta); // Adicionar passageiro ao voo encontrado
                                    astronauta.adicionarVoo(it->getCodigo());
                                    astronauta.setIndisponivel();
                                    astroFind = true; // Atualizar astroFind
                                    break;
                                }
                                else if (astronauta.getCPF() == cpfAstronauta && astronauta.getStatus() == MORTO){
                                    cout << "O astronauta morreu em missão. " << endl; // Verifica se o astronauta está morto
                                }
                                else if (astronauta.getCPF() == cpfAstronauta && !astronauta.getDisponibilidade()) {
                                    cout << "Astronauta indisponível. " << endl; // Verifica se o astronauta está indisponivel
                                }
                            }
                            if (astroFind) {
                                cout << endl << "Astronauta adicionado ao voo com sucesso! " << endl << endl;
                            }
                            else {
                                cout << "O astronauta não foi localizado. " << endl;
                            }
                        }
                        break; // Sair do loop de voos
                        }
                        else if (it->getCodigo() == cod && it->getStatus() == EMVOO) {
                            cout << endl << "Não se pode adicionar astronautas nesse voo. " << endl << endl;
                            break;
                        }
                }
                if (!encontrado) {
                    cout << "ERRO! O voo encontrado!" << endl;
                }
                break;
            }

            case 4: {
                cout << "Voos disponíveis (em planejamento): " << endl;

                for (const auto& voo : voos) {
                    if (voo.getStatus() == PLANEJANDO) {
                        cout << "Código de voo: " << voo.getCodigo() << endl;
                    }
                }
                int cod;
                cout << "Digite o código do voo para remover passageiros: ";
                cin >> cod;
                bool encontrado = false;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == cod && voo.getStatus() == PLANEJANDO) {
                        encontrado = true;
                        cout << "Passageiros do voo " << cod << ":" << endl;
                        cout << endl;
                        voo.visualizarPassageiros(astronautas);
                        cout << endl;
                        while (true) {
                            string cpfAstronauta;
                            cout << "Digite o CPF do passageiro que deseja remover [0 para sair]: ";
                            cin >> cpfAstronauta;
                            if (cpfAstronauta == "0") {
                                break;
                            }
                            voo.removerPassageiro(cpfAstronauta);
                            for (auto& astronauta : astronautas) {
                                if (astronauta.getCPF() == cpfAstronauta) {
                                    astronauta.setDisponivel(); 
                                    auto& historico = astronauta.getHistoricoVoos(); 
                                    list<int> historicoModificado = historico; 
                                    historicoModificado.remove(cod);
                                    astronauta.setHistoricoVoos(historicoModificado);
                                    break;
                                }
                            }
                            cout << "Astronauta removido do Voo!" << endl;
                        }
                        break;
                    }
                    else if (voo.getCodigo() == cod && voo.getStatus() != PLANEJANDO) {
                        cout << "O voo não está disponível para adicionar astronautas. " << endl << endl;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "ERRO! Não foi encontrado!" << endl;
                }
                break;
            }

            case 5: {
                cout << "Voos cadastrados:" << endl;
                for (const auto& voo : voos) {  // O for percorre a lista de voos cadastrados
                    if (voos.empty()) {
                        cout << "Não existem voos cadastrados" << endl;
                        break;
                    }
                    else {
                        cout << "Código do Voo: " << voo.getCodigo() << endl;
                        cout << "Status do Voo: ";
                        switch (voo.getStatus()) {
                            case PLANEJANDO:
                                cout << "Em planejamento" << endl;
                                break;
                            case DESTRUIDO:
                                cout << "O voo foi explodido" << endl;
                                break;
                            case EMVOO:
                                cout << "Em voo" << endl;
                                break;
                        }

                        if (voo.getDispo()) cout << "O voo está disponível" << endl;
                        else cout << "O voo está indísponivel" << endl;

                        cout << "Destino do voo: " << voo.getDestino() << endl;
                        voo.visualizarPassageiros(astronautas);
                    }    
                }
                break;
            }

            case 6: {
                cout << "Voos disponiveis para serem lançados: " << endl;
                for (const auto& voo : voos) {
                    if (voo.getStatus() == PLANEJANDO) {
                        cout << "Código do voo: " << voo.getCodigo() << endl;
                    }
                }
                int cod;
                cout << "Insira o código do voo que será lançado: ";
                cin >> cod;
                bool encontrado = false;
                for (auto it = voos.begin(); it != voos.end(); ++it) { // Passagem por refêrencia
                    if (it->getCodigo() == cod && it->getStatus() == PLANEJANDO) {
                        it->lancarVoo();
                        encontrado = true;
                        break;
                    }
                    else if (it->getCodigo() == cod && it->getStatus() == EMVOO) {
                        cout << "O voo ja foi lancado anteriormente." << endl;
                        cout << "O voo está a caminho de  " << it->getDestino() << endl;
                        break;
                    }
                    else if (it->getCodigo() == cod && it->getStatus() == DESTRUIDO) {
                        cout << "O voo foi explodido. Perca total." << endl;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "O voo nao foi encontrado! Tente novamente!" << endl;
                }
                break;
            }

            case 7: {
                cout << "Voos disponiveis para serem finalizados: " << endl;
                for (const auto& voo : voos) {
                    if (voo.getStatus() == EMVOO) {
                        cout << "Código de Voo: " << voo.getCodigo() << endl;
                    }
                }
                cout << endl;
                int cod;
                cout << "Insira o código do voo que será finalizado: ";
                cin >> cod;
                bool encontrado = false;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == cod && voo.getStatus() == EMVOO) {
                        voo.finalizarVoo(astronautas); //Rever se está chamando a função corretamente.
                        encontrado = true;
                        cout << "O voo finalizado com sucesso!" << endl;
                        break;
                    }
                    else if (voo.getCodigo() == cod && voo.getStatus() != EMVOO ) {
                        cout << "O voo não está disponivel para finalizar." << endl;
                        break;
                    }
                }      
                if (!encontrado) {
                    cout << "O voo não foi encontrado!" << endl;
                }

                break;
            }

            case 8: {
                cout << "Astronautas Cadastrados:" << endl << endl;
                if (astronautas.empty()) {
                    cout << "Não existem astronautas cadastrados." << endl;
                }
                else {
                    for (auto& astronauta : astronautas) {
                        cout << "Nome: " << astronauta.getNome() << endl;
                        cout << "CPF: " << astronauta.getCPF() << endl;
                        cout << "Idade: " << astronauta.getIdade() << endl;
                        if (astronauta.getStatus()==VIVO){
                            if(astronauta.getDisponibilidade()){
                                cout << "Status: Disponível" << endl;
                            } else {
                                cout << "Status: Indisponível" << endl;
                            }
                        } else if (astronauta.getStatus() == MORTO){
                            cout << "Status: Morto" << endl;
                        }
                        cout << "Último voo cadastrado: ";
                        if (astronauta.getHistoricoVoos().empty()) {
                            cout << "O astronauta não foi cadastrado em nenhum voo anteriormente." << endl;
                        }
                        else {
                            cout << astronauta.getHistoricoVoos().back() << endl;
                        }
                    }
                }
                cout << endl;
                break;
            }

            case 9: {
                cout << endl << " Menções honrosas para os herois que deram sua vida voando conosco:" << endl << endl;
                
                const list<Astronauta>& astronautasMortos = Cemiterio::getAstronautasMortos();
                for (const auto& astronauta : astronautasMortos) {
                    cout << "   O astronauta " << astronauta.getNome() << " morreu em missão. A ASTRO será eternamente grata por seus serviços. " << endl;
                    cout << "   Aqui esta a lista de voos em que ele participou:" << endl;
                    cout << endl;
                    for (const auto& cods : astronauta.getHistoricoVoos()) {
                        cout << "    Voo " << cods << endl;
                    }
                    cout << endl;
                }
                cout << endl;
                break;
            }
            default:
                cout << "Saindo..." << endl;
                controle = 1;
                break;
        }
        cout << endl;
    }
    return 0;
}