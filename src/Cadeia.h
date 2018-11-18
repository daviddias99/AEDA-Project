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
#include "util.h"

enum ord_pessoas { id_cres = 0, id_dec, idade_cres, idade_dec, nome_cres, nome_dec, nif_cres, nif_dec, n_comp_cres, n_comp_dec, sal_cres, sal_dec };

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

	unsigned int getNumFarmacias() const;
	unsigned int getNumEmpregados() const;
	unsigned int getNumClientes() const;

	void sortFarmacias(char modo);
	
	void sortClientes(ord_pessoas modo);
	void sortEmpregados(ord_pessoas modo);

	void mostrarFarmacias();
	void mostrarClientes();
	void mostrarEmpregados();

	void guardarDados();
	void carregarDados();
private:
	void carregarClientes();
	void carregarEmpregados();
	void carregarFarmacias();

	vector< Farmacia* > farmacias; //Ordenadas por nome
	vector< Cliente* > clientes;
	vector< Empregado* > empregados; //Ordenados por nif

	string nome;
};

#endif /* SRC_CADEIA_H_ */
