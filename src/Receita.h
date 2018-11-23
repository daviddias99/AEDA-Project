#ifndef RECEITA_H
#define RECEITA_H

#include <string>
#include <map>
#include "Produto.h"
#include "util.h"

using namespace std;

class Receita {
public:
	Receita(int numReceita, string cliente, string Medico, uint nifPaciente);
	void addProduto(Produto* produto, uint quantidade);
	map<Produto*, uint> getProdutos() const;
	int getNumReceita() const;
	string getCliente() const;
	string getMedico() const;
	uint getNifPaciente() const;

private:
	int numReceita;
	const string nomeCliente;
	const string nomeMedico;
	uint nifPaciente;
	map<Produto*, uint> produtos;
};

#endif
