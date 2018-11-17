#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <iostream>
#include <string>
#include <vector>
#include "util.h"
#include "Cadeia.h"

using namespace std;

class Sistema {
public:
	void start();
	Sistema();
private:
	Cadeia cadeia;
	Farmacia* f;
	Cliente* c;
	Empregado* e;
	const long long MAX_STREAM_SIZE = numeric_limits<streamsize>::max();

	void menu();
	void sair();

	void menuGerencia();

	void gerirFarmacias();

	void gerirFarmacia();
	void farmacia_gerir();
	void farmacia_menuAdicionar();
	void farmacia_menuRemover();
	void farmacia_menuConsultar();
	void farmacia_adicionarProduto();
	void farmacia_adicionarEmpregado();
	void farmacia_adicionarVenda();
	void farmacia_removerProduto();
	void farmacia_removerEmpregado();
	void farmacia_consultarEmpregado();
	void farmacia_consultarStock();
	void farmacia_consultarQuantidades();
	void farmacia_consultarProduto();
	void farmacia_consultarVendas();

	void adicionarFarmacia();
	void removerFarmacia();
	void consultarFarmacias();

	void gerirClientes();
	void gerirCliente();
	void cliente_gerir();

	void adicionarCliente();
	void removerCliente();

	void gerirEmpregados();
	void gerirEmpregado();
	void adicionarEmpregado();
	void removerEmpregado();
};

#endif
