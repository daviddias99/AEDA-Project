#ifndef VENDA_H
#define VENDA_H

#include <map>
#include <vector>
#include <string>
#include "Produto.h"
#include "Receita.h"
#include "util.h"

using namespace std;


class Venda {
public:
	Venda(string client, string empreg);
	map<Produto, unsigned int> addReceita(const Receita & receita);
	void addProduto(const Produto &prod, unsigned int quant);

	ostream& printSimp(ostream& os);
private:
	const string nomeCliente;
	const string nomeEmpregado;
	map<Produto *, unsigned int> produtos;
	Timestamp timestamp_venda;
};

#endif /* VENDA_H */
