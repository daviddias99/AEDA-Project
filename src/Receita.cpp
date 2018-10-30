#include "Receita.h"

int Receita::numId = 0;

Receita::Receita(Cliente cliente, string nomeMedico) : cliente(cliente), nomeMedico(nomeMedico)
{
	numId++;
	numReceita = numId;
}

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

Cliente Receita::getCliente() const
{
	return cliente;
}

string Receita::getMedico() const
{
	return nomeMedico;
}
