#include "Cliente.h"

uint Cliente::currentID = 0;

Cliente::Cliente(string nome, uint nif, Data dataNasc, Morada morada, string distrito) : Pessoa(nome, nif, dataNasc, morada), distrito(distrito)
{}

bool Cliente::adicionaCompra(Venda * novaVenda)
{
	this->historicoCompras.push_back(novaVenda);

	return true;
}

void Cliente::mostrarCompras()
{
	for (size_t i = 0; i < historicoCompras.size(); i++)
		historicoCompras[i]->print(cout) << endl << endl;
}

uint Cliente::getNumCompras() const
{
	return this->historicoCompras.size();
}


string Cliente::getDistrito() const
{
	return this->distrito;
}

ostream & Cliente::print(ostream & os) const
{
	//os << "ID: " << ID << endl;
	os << "Distrito: " << this->distrito << endl;
	Pessoa::print(os) << endl << "Numero de compras: " << getNumCompras() ;

	return os;
}

ostream & Cliente::printSimp(ostream & os) const
{
	//os << ID << "\\";
	Pessoa::printSimp(os);

	return os;
}

bool operator<(const Cliente & c1, const Cliente & c2)
{
	if (c1.getDistrito() < c2.getDistrito()) {
		return true;
	}
	else if (c1.getDistrito() == c2.getDistrito()) {
		if (c1.getNome() < c2.getNome())
			return true;
		else if (c1.getNome() == c2.getNome()) {
			if (c1.getNIF() < c2.getNIF())
				return true;
		}
	}
	return false;
}

bool operator==(const Cliente & c1, const Cliente & c2)
{
	if (c1.getNIF() == c2.getNIF())
		return true;
	else
		return false;
}


bool Cliente_SortFunc_Distrito_Crescente(Cliente* p1, Cliente* p2) {

	if (p1->getDistrito() < p2->getDistrito())
		return true;
	else if (p1->getDistrito() == p2->getDistrito())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_Distrito_Decrescente(Cliente* p1, Cliente* p2) {

	if (p1->getDistrito() > p2->getDistrito())
		return true;
	else if (p1->getDistrito() == p2->getDistrito())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}


bool Cliente_SortFunc_numCompras_Crescente(Cliente* p1, Cliente* p2) {

	if (p1->getNumCompras() < p2->getNumCompras())
		return true;
	else if (p1->getNumCompras() == p2->getNumCompras())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_numCompras_Decrescente(Cliente* p1, Cliente* p2) {

	if (p1->getNumCompras() > p2->getNumCompras())
		return true;
	else if (p1->getNumCompras() == p2->getNumCompras())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}
