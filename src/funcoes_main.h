#ifndef FUNCOES_MAIN_H
#define FUNCOES_MAIN_H

#include "Cadeia.h"
#include "util.h"
using namespace std;

const long long MAX_STREAM_SIZE = numeric_limits<streamsize>::max();

Morada user_getMorada();
Data user_getData();
Empregado* user_getEmpregado(Cadeia& cadeia, pair<bool, string> newFOverride = { false, "nome_default" });
Cliente* uset_getCliente(Cadeia& cadeia);
Produto* user_getProduto(Farmacia& farmacia);
int getInputNumber(int limInf, int limSup);
string getInputString(string msg, string msgErr);


void showMenuInicial();
void showMenuPrincipal();

//void realizarVenda(Cadeia& cadeia);

void menuClientes(Cadeia& cadeia);
void resumoClientes(Cadeia& cadeia);
void cliente_consultarCompras(Cliente* c);
void gerirCliente(Cadeia& cadeia);

void menuEmpregados(Cadeia& cadeia);
void resumoEmpregados(Cadeia& cadeia);
void adicionarEmpregado(Cadeia& cadeia);
void removerEmpregado(Cadeia& cadeia);
void gerirEmpregado(Cadeia& cadeia);

void menuFarmacias(Cadeia& cadeia);
void resumoFarmacias(Cadeia& cadeia);
void adicionarFarmacia(Cadeia& cadeia);
void consultarFarmacia(Cadeia& cadeia);
void gerirStock(Cadeia& cadeia);
void alterarGerente(Cadeia& cadeia);
void farmacia_mudarGerente(Cadeia& farmacia);
void farmacia_consultarEmpregados(Farmacia& farmacia);
void farmacia_consultarProdutos(Farmacia& farmacia);
void farmacia_adicionarProduto(Farmacia& farmacia);
void farmacia_removerProduto(Farmacia& farmacia);

#endif
