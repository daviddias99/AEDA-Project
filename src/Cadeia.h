#ifndef CADEIA_H_
#define CADEIA_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Farmacia.h"
#include "Cliente.h"
#include "Empregado.h"
#include "Excecoes.h"
#include "util.h"


using namespace std;

class Cadeia{
public:
	Cadeia();
	Cadeia(string n);
	virtual ~Cadeia();
	bool addFarmacia(Farmacia* Farmacia);
	bool addCliente(Cliente* cliente);
	bool addEmpregado(Empregado* empregado);

	void removeFarmacia(string nome);
	void removeCliente(uint ID);
	void removeEmpregado(uint ID);

	Farmacia* getFarmacia(string nome) const;
	Cliente* getCliente(int nif) const;
	Empregado* getEmpregado(int nif) const;
	vector<Cliente*> getClientes(string nome) const;

	unsigned int getNumFarmacias() const;
	unsigned int getNumEmpregados() const;
	unsigned int getNumClientes() const;
	string getNome() const;

	void sortFarmacias(char modo);
	
	void sortClientes(ord_pessoas modo);
	void sortEmpregados(ord_pessoas modo);

	void mostrarFarmacias();
	void mostrarClientes();
	void mostrarEmpregados();

	void guardarDados();
	void carregarDados();
private:
	void carregarClientes(ifstream& ficheiro);
	void carregarEmpregados(ifstream& ficheiro);
	void carregarFarmacias(ifstream& ficheiro);

	vector< Farmacia* > farmacias; //Ordenadas por nome
	vector< Cliente* > clientes;
	vector< Empregado* > empregados; //Ordenados por nif

	string nome;
};

#endif /* SRC_CADEIA_H_ */
