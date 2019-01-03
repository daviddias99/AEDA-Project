#include "Fornecedor.h"


Fornecedor::Fornecedor(string nome, Morada morada_sede, TipoFornecedor tipo) {

	this->nome = nome;
	this->morada_sede = morada_sede;
	this->tipo = tipo;

}

void Fornecedor::adicionaEncomenda(Encomenda encomenda)
{
	this->encomendas_satisfeitas.insert(this->encomendas_satisfeitas.begin(), encomenda);
}


bool Fornecedor::satisfazEncomenda(Encomenda encomenda)
{

	this->adicionaEncomenda(encomenda);

	return true;

}

uint Fornecedor::getNumEncomendas() const
{
	return this->encomendas_satisfeitas.size();
}

string Fornecedor::getNome()  const
{

	return this->nome;
}

Morada Fornecedor::getMoradaSede()  const
{
	return morada_sede;
}

const list<Encomenda>& Fornecedor::getEncomendasSatisfeitas() const {

	return this->encomendas_satisfeitas;
}

TipoFornecedor Fornecedor::getTipo() const
{
	return this->tipo;
}

