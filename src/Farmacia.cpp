#include "Farmacia.h"

Farmacia::Farmacia(string nome, Morada morada, Empregado gerente) :nome(nome), morada(morada), gerente(gerente) {}

void Farmacia::addProduto(Produto produto, int quantidade)
{
	map<Produto, int>::iterator it;
	it = stock.find(produto);
	if(it != stock.end())
		it->second += quantidade;
	else
		stock[produto] = quantidade;
}

void Farmacia::removeQuantidade(Produto produto, int quantidade)
{
	map<Produto, int>::iterator it;
	it = stock.find(produto);
	if(it != stock.end()) {
		if(it->second >= quantidade) {
			it->second -= quantidade;
			return;
		}
	}

	throw ProdutoNaoExiste(produto.getName());
}

void Farmacia::removeProduto(Produto produto)
{
	map<Produto, int>::iterator it;
	it = stock.find(produto);
	if(it != stock.end()) {
		stock.erase(it);
		return;
	}

	throw ProdutoNaoExiste(produto.getName());
}


string Farmacia::getNome() const
{
	return nome;
}

Morada Farmacia::getMorada() const
{
	return morada;
}

Empregado Farmacia::getGerente() const
{
	return gerente;
}

bool Farmacia::operator == (const Farmacia & ph1)
{
	if(this->nome == ph1.getNome()) return true;
	else return false;
}

bool Farmacia::operator < (const Farmacia & ph)
{
	if(this->nome < ph.getNome()) return true;
	else return false;
}


