#ifndef Farmacia_H
#define Farmacia_H

#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>

#include "Pessoa.h"
#include "Produto.h"
#include "util.h"

using namespace std;

class Farmacia {
public:
	Farmacia(string nome, Morada Morada);
	virtual ~Farmacia();
	void addProduto(Produto *produto, int quantidade);
	bool addEmpregado(Empregado* empregado);
	void remProduto(int codigo);
	bool setGerente(Empregado* novoGerente);
	bool removeQuantidade(int codigo, uint quantidade);
	void remEmpregado(int nif);
	void adicionarVenda(Venda* v1);

	string getNome() const;
	Morada getMorada() const;
	Empregado* getGerente() const;
	vector<Empregado*> getEmpregados(string nome) const;
	Produto* getProduto(int codigo) const;

	unsigned int getTotalProdutos() const;
	unsigned int tamanhoStock() const;
	unsigned int numEmpregados() const;
	unsigned int numVendas() const;

	bool operator == (const Farmacia & ph1);
	bool operator < (const Farmacia & ph);
	friend ostream& operator<< (ostream& os, const Farmacia& f1);

	ostream& printSimp(ostream& os) const;

	void consultarQuantidades();
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
