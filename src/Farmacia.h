#ifndef Farmacia_H
#define Farmacia_H

#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>


#include "Empregado.h"
#include "Cliente.h"
#include "Produto.h"
#include "Medicamento.h"
#include "util.h"

using namespace std;

class Farmacia {
public:
	Farmacia(string nome, Morada Morada);
	Farmacia(string simp);
	virtual ~Farmacia();
	void addProduto(Produto *produto, int quantidade);
	bool addEmpregado(Empregado* empregado);
	void remProduto(long unsigned int codigo);
	void remEmpregado(uint ID);
	bool setGerente(Empregado* novoGerente);
	bool removeQuantidade(long unsigned int codigo, uint quantidade);
	void adicionarVenda(Venda* v1);

	string getNome() const;
	Morada getMorada() const;
	Empregado* getGerente() const;
	vector<Empregado*> getEmpregados(string nome) const;
	unsigned int getNumEmpregados() const;
	Produto* getProduto(int codigo) const;

	unsigned int getTotalProdutos() const;
	unsigned int tamanhoStock() const;
	unsigned int numEmpregados() const;
	unsigned int numVendas() const;

	bool operator == (const Farmacia & ph1) const;
	bool operator < (const Farmacia & ph1) const;

	void sortEmpregados(ord_pessoas modo);

	ostream& printSimp(ostream& os) const;
	ostream& print(ostream& os) const;
	void mostrarEmpregados() const;

	void consultarQuantidades() const;
	//void mostrarVendas() const;

	bool efetuaVenda(Empregado* empregado, Cliente* cliente, map<Produto*, unsigned int> produtos);

private:
	string nome;
	Morada morada;
	Empregado* gerente;
	vector< Empregado* > empregados;
	map< Produto *, unsigned int> stock;
	vector <Venda *> vendas;
};


bool farmacia_SortFunc_Nome_Crescente(Farmacia * f1, Farmacia * f2);
bool farmacia_SortFunc_Nome_Decrescente(Farmacia *f1, Farmacia *f2);
bool farmacia_SortFunc_TamanhoStock_Crescente(Farmacia *f1, Farmacia *f2);
bool farmacia_SortFunc_TamanhoStock_Decrescente(Farmacia *f1, Farmacia *f2);
bool farmacia_SortFunc_NumVendas_Crescente(Farmacia *f1, Farmacia *f2);
bool farmacia_SortFunc_NumVendas_Decrescente(Farmacia *f1, Farmacia *f2);

#endif
