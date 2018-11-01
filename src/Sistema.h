#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <iostream>
#include <string>
#include <vector>
#include "Cadeia.h"
#include "util.h"

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

	void gerirClientes();
	void gerirEmpregados();
};

#endif
