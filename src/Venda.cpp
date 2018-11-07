#include "Venda.h"

Venda::Venda(string client, string empreg) : nomeCliente(client), nomeEmpregado(empreg) {}

map<Produto, unsigned int> Venda::addReceita(const Receita & receita) {

	return map<Produto, unsigned int>();
}

void Venda::addProduto(const Produto &prod, unsigned int quant) {

}


