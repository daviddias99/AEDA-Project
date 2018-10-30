#ifndef CADEIA_H_
#define CADEIA_H_

#include <string>
#include <vector>
#include "Farmacia.h"
#include "Pessoa.h"

using namespace std;

class Cadeia{
public:
	Cadeia();
	virtual ~Cadeia();
	bool addFarmacia(Farmacia Farmacia);
	bool addFarmacias(vector <Farmacia> Farmacias);
	bool addCliente(Cliente cliente);
	bool addClientes(vector<Cliente> clientes);
	bool addEmpregado(Empregado empregado);
	bool addEmpregados(vector <Empregado *> empregados);
	Farmacia removeFarmacia(Farmacia farmacia);
	Farmacia removeFarmacia(string pharmacyName);
	Cliente removeCliente(Cliente cliente);
	Cliente removeCliente(string nome);
	Empregado* removeEmpregado(Empregado empregado);
	Empregado* removeEmpregado(string name);
	int getNumFarmacias() const;
	int getNumEmpregados() const;
	int getNumClientes() const;
private:
	vector< Farmacia > farmacias;
	vector< Cliente > clientes;
	vector< Empregado *> empregados;
};

#endif /* SRC_CADEIA_H_ */
