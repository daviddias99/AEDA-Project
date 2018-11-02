#ifndef RECEITA_H_
#define RECEITA_H_

#include <string>
#include <map>
#include "Pessoa.h"
#include "Produto.h"

using namespace std;

class Receita {
public:
	Receita(int numReceita, Cliente cliente, string nomeMedico);
	void addProduto(Produto produto, int quantidade);
	void addProdutos(map<Produto, int> &produtos);
	int getNumReceita() const;
	Cliente getCliente() const;
	string getMedico() const;
	virtual ~Receita();
private:
	int numReceita;
	const Cliente cliente;
	const string nomeMedico;
	map< Produto, int> produtos;
};

#endif
