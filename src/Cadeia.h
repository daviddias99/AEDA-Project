#ifndef CADEIA_H_
#define CADEIA_H_

#include <string>
#include <vector>
#include "Farmacia.h"
#include "Pessoa.h"
#include "util.h"

using namespace std;

class Cadeia{
public:
	Cadeia();
	virtual ~Cadeia();
	bool addFarmacia(Farmacia Farmacia);
	bool addFarmacias(vector <Farmacia> Farmacias);
	bool addCliente(Cliente cliente);
	bool addClientes(vector<Cliente> clientes);
	bool addEmpregado(Empregado *empregado);
	bool addEmpregados(vector <Empregado *> empregados);
	void removeFarmacia(Farmacia farmacia);
	void removeCliente(Cliente cliente);
	void removeEmpregado(Empregado empregado);
	unsigned int getNumFarmacias() const;
	unsigned int getNumEmpregados() const;
	unsigned int getNumClientes() const;
private:
	vector< Farmacia > farmacias;
	vector< Cliente > clientes;
	vector< Empregado *> empregados;
};


#endif /* SRC_CADEIA_H_ */
