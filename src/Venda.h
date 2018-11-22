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
	Venda(uint cID, string client, uint eID, string empreg, string farm);
	map<Produto, unsigned int> addReceita(const Receita & receita);
	void addProduto(Produto* prod, unsigned int quant);

	ostream& print(ostream& os) const;
	ostream& printSimp(ostream& os) const;
private:
	const string nomeFarmacia;
	const string nomeCliente;
	const string nomeEmpregado;
	map<Produto *, unsigned int> produtos;
	Timestamp timestamp_venda;
	const uint idEmpregado;
	const uint idCliente;
};

#endif /* VENDA_H */
