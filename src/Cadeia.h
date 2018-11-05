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
	bool addCliente(Cliente cliente);
	bool addEmpregado(Empregado empregado);
	void removeFarmacia(string nome);
	void removeCliente(int clienteNIF);
	void removeEmpregado(int empregadoNIF);
	Farmacia getFarmacia(string nome) const;
	Cliente getCliente(int nif) const;
	Empregado getEmpregado(int nif) const;
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
