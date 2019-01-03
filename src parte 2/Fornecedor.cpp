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



ostream& Fornecedor::print(ostream& os) const {

	os << nome << endl << this->morada_sede;
	cout << endl << "Tipo: " << ((this->tipo == medicamentos) ? "medicamentos" : "produtos");
	cout << endl << "Numero encomendas: " << this->getNumEncomendas() << endl << endl;
	return os;
}

ostream & Fornecedor::print_encomendas_resumo(ostream & os) const
{
	list<Encomenda>::const_iterator it = this->encomendas_satisfeitas.begin();
	list<Encomenda>::const_iterator ite = this->encomendas_satisfeitas.end();

	while (it != ite) {

		Encomenda encomenda_atual = *it;

		encomenda_atual.print_resumo(os);

		it++;
	}

	return os;
}

bool Fornecedor::operator<(Fornecedor & f2)
{
	return this->nome < f2.getNome();
}

bool Fornecedor::operator==(Fornecedor & f2)
{
	return this->nome == f2.getNome();
}

bool fornecedor_SortFunc_Nome_Crescente(Fornecedor * f1, Fornecedor * f2) {

	if (f1->getNome() < f2->getNome())
		return true;
	else
		return false;
}

bool fornecedor_SortFunc_Nome_Decrescente(Fornecedor * f1, Fornecedor * f2)
{
	if (f1->getNome() > f2->getNome())
		return true;
	else
		return false;
}

bool fornecedor_SortFunc_Tipo_Crescente(Fornecedor * f1, Fornecedor * f2)
{
	if (f1->getTipo() == f2->getTipo()) {
		return f1->getNome() < f2->getNome();
	}
	else {

		if (f1->getTipo() == medicamentos && f2->getTipo() == produtos)
			return true;
		else
			return false;
	}
}

bool fornecedor_SortFunc_Tipo_Decrescente(Fornecedor * f1, Fornecedor * f2)
{
	if (f1->getTipo() == f2->getTipo()) {
		return f1->getNome() < f2->getNome();
	}
	else {

		if (f1->getTipo() == medicamentos && f2->getTipo() == produtos)
			return false;
		else
			return true;
	}
}

bool fornecedor_SortFunc_NumEncomendas_Crescente(Fornecedor * f1, Fornecedor * f2)
{
	if (f1->getNumEncomendas() == f2->getNumEncomendas())
		return f1->getNome() < f2->getNome();
	else {
		return f1->getNumEncomendas() < f2->getNumEncomendas();
	}
}

bool fornecedor_SortFunc_NumEncomendas_Decrescente(Fornecedor * f1, Fornecedor * f2)
{
	if (f1->getNumEncomendas() == f2->getNumEncomendas())
		return f1->getNome() > f2->getNome();
	else {
		return f1->getNumEncomendas() > f2->getNumEncomendas();
	}
}

