#ifndef CADEIA_H_
#define CADEIA_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Farmacia.h"
#include "Pessoa.h"
#include "util.h"

using namespace std;

class Cadeia{
public:
	Cadeia();
	//Cadeia(string n);
	virtual ~Cadeia();
	bool addFarmacia(Farmacia* Farmacia);
	bool addCliente(Cliente* cliente);
	bool addEmpregado(Empregado* empregado);

	void removeFarmacia(string nome);
	void removeCliente(int clienteNIF);
	void removeEmpregado(int empregadoNIF);

	Farmacia* getFarmacia(string nome) const;
	Cliente* getCliente(int nif) const;
	Empregado* getEmpregado(int nif) const;

	unsigned int getNumFarmacias() const;
	unsigned int getNumEmpregados() const;
	unsigned int getNumClientes() const;

	void sortFarmacias(char modo);
	void sortClientes(char modo);
	void sortEmpregados(char modo);

	void mostrarFarmacias() const;

	void guardarDados();
private:
	vector< Farmacia* > farmacias; //Default: Ordenadas por nome crescente
	vector< Cliente* > clientes; //Default: Ordenados por NIF crescente
	vector< Empregado* > empregados; //Default: Ordenados por NIF crescente
	//const string nome;
};

#endif /* SRC_CADEIA_H_ */
