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
private:
	Cadeia cadeia;

	void menu();
	void sair();

	void menuGerencia();

	void gerirFarmacias();
	void gerirFarmacia();
	void adicionarFarmacia();
	void removerFarmacia();
	void consultarFarmacia();

	void gerirClientes();
	void gerirCliente();
	void adicionarCliente();
	void removerCliente();

	void gerirEmpregados();
	void gerirEmpregado();
	void adicionarEmpregado();
	void removerEmpregado();
};

#endif
