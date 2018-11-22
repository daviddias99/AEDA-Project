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

pair<Produto*,uint> Venda::getProd(uint prodId)
{
	pair<Produto*, unsigned int> resultado = { NULL,0 };
	map<Produto*, unsigned int>::iterator it = this->produtos.begin();
	map<Produto*, unsigned int>::iterator ite = this->produtos.end();

	while (it != ite) {

		if (it->first->getCodigo() == prodId) {
			return *it;
		}

	}

	return resultado;
}

pair<Produto*, uint> Venda::getProd(string nome)
{
	pair<Produto*, unsigned int> resultado = { NULL,0 };
	map<Produto*, unsigned int>::iterator it = this->produtos.begin();
	map<Produto*, unsigned int>::iterator ite = this->produtos.end();

	while (it != ite) {

		if (it->first->getNome() == nome) {
			return *it;
		}

	}

	return resultado;
}

void Venda::remProduto(string  nome)
{
	map<Produto*, unsigned int>::iterator it = this->produtos.begin();
	map<Produto*, unsigned int>::iterator ite = this->produtos.end();

	while (it != ite) {

		if (it->first->getNome() == nome) {
			produtos.erase(it);
		}

	}

}

uint Venda::getCusto()
{
	return 0;

}

map<Produto*, uint> Venda::getProdutos()
{
	return this->produtos;
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


