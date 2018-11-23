#include "Venda.h"

Venda::Venda(uint cID, string client, uint eID, string empreg, string farm, string time) : idCliente(cID), nomeCliente(client), idEmpregado(eID), nomeEmpregado(empreg), nomeFarmacia(farm) {

	preco = 0;
	if (time == "") {
		this->timestamp_venda = Timestamp();
	}
	else {
		this->timestamp_venda = Timestamp(time);
	}

}


void Venda::addReceita(const Receita & receita) {

	map<Produto*,uint> produtosReceita = receita.getProdutos();
	map<Produto*, uint>::iterator it = produtosReceita.begin();
	map<Produto*, uint>::iterator ite = produtosReceita.end();

	while (it != ite) {
		this->addProduto(it->first, it->second);
		it++;
	}
}

void Venda::setPreco(float pr) {
	preco = pr;
}

void Venda::addProduto(Produto* prod, unsigned int quant) {

	map<Produto *, unsigned int>::iterator it;
	for (it = produtos.begin(); it != produtos.end(); it++) {
		if (*(it->first) == *prod) {
			it->second += quant;
			return;
		}
	}

	preco += prod->getPreco() * (1 + prod->getIVA()) * quant;

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
		it++;
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
			return;
		}
		it++;
	}

}

float Venda::getCusto() const {
	return preco;
}

string Venda::getNomeFarm() const
{
	return nomeFarmacia;
}

string Venda::getNomeCliente() const
{
	return nomeCliente;
}

string Venda::getNomeEmp() const
{
	return nomeEmpregado;
}

map<Produto*, uint>& Venda::getProdutos()
{
	return this->produtos;
}

ostream & Venda::print(ostream & os) const
{
	os << endl << "RECIBO VENDA" << endl << endl;
	os << timestamp_venda << endl;
	os << "Farmacia: " << nomeFarmacia << endl;
	os << "Cliente - ID: " << idCliente << "     Nome: " << nomeCliente << endl;
	os << "Empregado - ID: " << idEmpregado << "     Nome: " << nomeEmpregado << endl;
	os << "Produtos: " << endl;

	for (map<Produto *, uint>::const_iterator it = produtos.begin(); it != produtos.end(); it++) {
		os << "-";
		it->first->print(cout) << "#Quantidade: " << it->second << endl << endl;
	}

	os << "Preco final: " << preco;

	return os;
}

ostream & Venda::printSimp(ostream & os) const
{
	os << preco << "\\" << timestamp_venda << "\\" << nomeFarmacia << "\\" << idCliente << "\\" << nomeCliente << "\\" << idEmpregado << "\\" << nomeEmpregado << "\\";

	for (map<Produto *, unsigned int>::const_iterator it = produtos.begin(); it != produtos.end(); it++) {

		it->first->printSimp(os);
		os << "#" << it->second << "!";
	}
	
	return os;
}


