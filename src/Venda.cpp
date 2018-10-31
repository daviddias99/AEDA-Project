#include "Venda.h"

Venda::Venda(const Cliente & comp, const Empregado & vend) {
	cliente = comp;
	empregado = vend;
}

map<Produto, unsigned int> Venda::addReceita(const Receita & receita);

void Venda::addProduto(const Produto &prod, unsigned int quant);


