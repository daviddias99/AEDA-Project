#include "Receita.h"

Receita::Receita(int numReceita, string cliente, string nomeMedico) : numReceita(numReceita), nomeCliente(cliente), nomeMedico(nomeMedico) {}

void Receita::addProduto(Produto *  produto, int quantidade) {

	map<Produto *, int>::iterator it;

	for (it = produtos.begin(); it != produtos.end(); it++) {
		if (*(it->first) == *produto) {
			it->second += quantidade;
			return;
		}
	}

	produtos[produto] = quantidade;
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
