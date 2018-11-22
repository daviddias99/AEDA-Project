#include "Venda.h"

Venda::Venda(uint cID, string client, uint eID, string empreg, string farm) : idCliente(cID), nomeCliente(client), idEmpregado(eID), nomeEmpregado(empreg), nomeFarmacia(farm) {

	this->timestamp_venda = Timestamp();
}

map<Produto, unsigned int> Venda::addReceita(const Receita & receita) {

	return map<Produto, unsigned int>();
}

void Venda::addProduto(Produto* prod, unsigned int quant) {

	map<Produto *, unsigned int>::iterator it;
	for (it = produtos.begin(); it != produtos.end(); it++) {
		if (*(it->first) == *prod) {
			it->second += quant;
			return;
		}
	}

	produtos[prod] = quant;
}

ostream & Venda::print(ostream & os) const
{
	os << "Farmacia: " << nomeFarmacia << endl;
	os << "Cliente - ID: " << idCliente << "     Nome: " << nomeCliente << endl;
	os << "Empregado - ID: " << idCliente << "     Nome: " << nomeCliente << endl;
	os << "Produtos: " << endl;

	for (map<Produto *, uint>::const_iterator it = produtos.begin(); it != produtos.end(); it++) {
		os << "-";
		it->first->print(cout) << "#Quantidade: " << it->second << endl << endl;
	}

	return os;
}

ostream & Venda::printSimp(ostream & os) const
{
	os << nomeFarmacia << "&" << idCliente << "&" << nomeCliente << "&" << idEmpregado << "&" <<  nomeEmpregado << "&";

	for (map<Produto *, unsigned int>::const_iterator it = produtos.begin(); it != produtos.end(); it++) {

		it->first->printSimp(os);
		os << "#" << it->second << "!";
	}
	
	return os;
}


