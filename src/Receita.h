#ifndef RECEITA_H
#define RECEITA_H

#include <string>
#include <map>
#include "Produto.h"

using namespace std;

class Receita {
public:
	Receita(int numReceita, string cliente, string Medico);
	void addProduto(Produto * produto, int quantidade);
	int getNumReceita() const;
	string getCliente() const;
	string getMedico() const;
private:
	int numReceita;
	const string nomeCliente;
	const string nomeMedico;
	map<Produto *, int> produtos;
};

#endif
