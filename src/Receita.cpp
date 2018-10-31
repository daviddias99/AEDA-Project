#include "Receita.h"

Receita::Receita(int numReceita, Cliente cliente, string nomeMedico)
: numReceita(numReceita), cliente(cliente), nomeMedico(nomeMedico) {}

void Receita::addProduto(Produto produto, int quantidade)
{
	map<Produto, int>::iterator it;
		it = produtos.find(produto);
		if(it != produtos.end())
			it->second += quantidade;
		else
			produtos[produto] = quantidade;
}

void Receita::addProdutos(map<Produto, int> p)
{
	map<Produto, int>::iterator it;
	for (it = p.begin(); it != p.end(); it++) {
		addProduto(it->first, it->second);
	}
}

int Receita::getNumReceita() const
{
	return numReceita;
}

Cliente Receita::getCliente() const
{
	return cliente;
}

string Receita::getMedico() const
{
	return nomeMedico;
}
