#include "Venda.h"

Venda::Venda(string client, string empreg) : nomeCliente(client), nomeEmpregado(empreg) {}

map<Produto, unsigned int> Venda::addReceita(const Receita & receita) {

	return map<Produto, unsigned int>();
}

void Venda::addProduto(const Produto &prod, unsigned int quant) {

}

ostream & Venda::printSimp(ostream & os)
{
	os << nomeCliente << "&" << nomeEmpregado << "&";

	for (map<Produto *, unsigned int>::const_iterator it = produtos.begin(); it != produtos.end(); it++) {

		os << "!";
		it->first->printSimp(os);
		os << "#" << it->second;
	}
	

	return os;
}


