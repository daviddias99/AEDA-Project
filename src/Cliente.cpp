#include "Cliente.h"

uint Cliente::currentID = 0;

Cliente::Cliente(string nome, uint nif, Data dataNasc, Morada morada) : Pessoa(nome, nif, dataNasc, morada)
{
	this->ID = currentID;
	currentID++;

}

bool Cliente::adicionaCompra(Venda * novaVenda)
{
	this->historicoCompras.push_back(novaVenda);

	return true;
}

uint Cliente::getNumCompras() const
{
	return this->historicoCompras.size();
}

uint Cliente::getID() const
{
	return this->ID;
}


ostream & Cliente::print(ostream & os) const
{
	os << "ID: " << ID << endl;
	Pessoa::print(os) << endl << "Numero de compras: " << getNumCompras() ;

	return os;
}

ostream & Cliente::printSimp(ostream & os) const
{
	os << ID << "\\";
	Pessoa::printSimp(os);


	for (vector<Venda*>::const_iterator it = historicoCompras.begin(); it != historicoCompras.end(); it++) {
		(*it)->printSimp(os);
	}

	return os;
}

bool operator<(const Cliente & c1, const Cliente & c2)
{
	if (c1.getNIF() < c2.getNIF()) {
		return true;
	}
	else
		return false;
}

bool operator==(const Cliente & c1, const Cliente & c2)
{
	if (c1.getNIF() == c2.getNIF())
		return true;
	else
		return false;
}



bool Cliente_SortFunc_ID_Crescente(Cliente* p1, Cliente* p2) {

	if (p1->getID() < p2->getID())
		return true;
	else if (p1->getID() == p2->getID())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_ID_Decrescente(Cliente* p1, Cliente* p2) {

	if (p1->getID() > p2->getID())
		return true;
	else if (p1->getID() == p2->getID())
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
