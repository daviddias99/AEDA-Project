#ifndef RECEITA_H_
#define RECEITA_H_

#include <string>
#include <map>
#include "Pessoa.h"
#include "Produto.h"

using namespace std;

class Receita {
public:
	Receita(const int numReceita, Cliente cliente, const string nomeMedico);
	void addProduto(Produto product, int quantidade);
	void addProdutos(map<Produto, int> produtos);
	Cliente getCliente() const;
	string getMedico() const;
	virtual ~Receita();
private:
	const int numReceita;
	const Cliente cliente;
	const string nomeMedico;
	map< Produto, int> produtos;
};

#endif /* SRC_RECEIPT_H_ */
