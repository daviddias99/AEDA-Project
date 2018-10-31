#include "Cliente.h"

Cliente::Cliente() : Pessoa() {}

bool Cliente::adicionaVenda(Venda * novaVenda)
{
	this->historicoVendas.push_back(novaVenda);

	return true;
}

