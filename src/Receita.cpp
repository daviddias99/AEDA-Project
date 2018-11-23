#include "Receita.h"

Receita::Receita(int numReceita, string cliente, string medico, uint nifPaciente) : numReceita(numReceita), nomeCliente(cliente), nomeMedico(medico),nifPaciente(nifPaciente) {}

void Receita::addProduto(Produto* produto, uint quantidade) {

	pair<Produto*, uint> novoPar = { produto, quantidade };

	this->produtos.insert(novoPar);

}

map<Produto*, uint> Receita::getProdutos() const
{
	return produtos;
}

int Receita::getNumReceita() const {
	return numReceita;
}

string Receita::getCliente() const {
	return nomeCliente;
}

string Receita::getMedico() const {
	return nomeMedico;
}

uint Receita::getNifPaciente() const
{
	return this->nifPaciente;
}

