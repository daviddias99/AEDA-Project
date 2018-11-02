#ifndef CADEIA_H_
#define CADEIA_H_

#include <string>
#include <vector>
#include <algorithm>

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
	bool addClientes(const vector<Cliente> &clientes);
	bool addEmpregado(Empregado empregado);
	bool addEmpregados(const vector <Empregado > &empregados);
	void removeFarmacia(string nome);
	void removeCliente(int clienteNIF);
	void removeEmpregado(int empregadoNIF);
	Farmacia getFarmacia(string nome) const;
	Cliente getCliente(string nome) const;
	Empregado getEmpregado(string nome) const;
	unsigned int getNumFarmacias() const;
	unsigned int getNumEmpregados() const;
	unsigned int getNumClientes() const;
	void guardarDados();
private:
	vector< Farmacia > farmacias; //Ordenadas por nome
	vector< Cliente > clientes;
	vector< Empregado > empregados; //Ordenados por nif
};


#endif /* SRC_CADEIA_H_ */
