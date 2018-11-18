
#include "Empregado.h"

Empregado::Empregado(string nome, uint nif, Data dataNasc, Morada morada, uint sal, string farmaciaNome, string cargo) : Pessoa(nome, nif, dataNasc, morada), farmaciaNome(farmaciaNome), salario(sal)
{
	this->ID = currentID;
	currentID++;

	if ((cargo != "gerente") || (cargo != "empregado"))
		throw CargoInvalido(cargo);

}

uint Empregado::getSalario() const
{
	return this->salario;
}

string Empregado::getNomeFarmacia() const
{

	return this->farmaciaNome;

}

string Empregado::getCargo() const
{
	return this->cargo;
}

uint Empregado::getNumVendas()
{
	return this->historicoVendas.size();
}

uint Empregado::getID() const
{
	return this->ID;
}

bool Empregado::setSalario(uint novoSalario)
{
	if (novoSalario < 0)
		return false;


	this->salario = novoSalario;

	return true;
}

bool Empregado::setFarmacia(string  novaFarmacia)
{
	this->farmaciaNome = novaFarmacia;

	return true;
}

bool Empregado::setCargo(string novoCargo)
{
	this->cargo = novoCargo;

	return true;
}

ostream & Empregado::printSimp(ostream & os)
{
	os << ID << "\\";
	Pessoa::printSimp(os);

	os << "\\" << farmaciaNome << "\\" << cargo << "\\" << salario << "\\";

	for (vector<Venda*>::const_iterator it = historicoVendas.begin(); it != historicoVendas.end(); it++) {
		(*it)->printSimp(os);
	}

	return os;
}


ostream & operator<<(ostream & os, const Empregado & emp)
{
	os << "COUT DE UM EMPREGADO- WIP" << endl;

	return os;
}

uint Empregado::currentID = 0;

/*

bool Empregado_SortFunc_Idade_Crescente(Empregado* p1, Empregado* p2) {

	if (p1->getIdade() < p2->getIdade())
		return true;
	else if (p1->getIdade() == p2->getIdade())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Idade_Decrescente(Empregado* p1, Empregado* p2) {

	if (p1->getIdade() > p2->getIdade())
		return true;
	else if (p1->getIdade() == p2->getIdade())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Nome_Crescente(Empregado* p1, Empregado* p2) {

	if (p1->getNome() < p2->getNome())
		return true;
	else if (p1->getNome() == p2->getNome())
	{
		if (p1->getIdade() < p2->getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Nome_Decrescente(Empregado* p1, Empregado* p2) {

	if (p1->getNome() > p2->getNome())
		return true;
	else if (p1->getNome() == p2->getNome())
	{
		if (p1->getIdade() < p2->getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Empregado_SortFunc_NIF_Crescente(Empregado* p1, Empregado* p2) {

	if (p1->getNIF() < p2->getNIF())
		return true;
	else if (p1->getNIF() == p2->getNIF())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_NIF_Decrescente(Empregado* p1, Empregado* p2) {

	if (p1->getNIF() > p2->getNIF())
		return true;
	else if (p1->getNIF() == p2->getNIF())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}
*/

bool Empregado_SortFunc_ID_Crescente(Empregado* p1, Empregado* p2) {

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

bool Empregado_SortFunc_ID_Decrescente(Empregado* p1, Empregado* p2) {

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

bool Empregado_SortFunc_Salario_Crescente(Empregado* p1, Empregado* p2) {

	if (p1->getSalario() < p2->getSalario())
		return true;
	else if (p1->getSalario() == p2->getSalario())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Salario_Decrescente(Empregado* p1, Empregado* p2) {

	if (p1->getSalario() > p2->getSalario())
		return true;
	else if (p1->getSalario() == p2->getSalario())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_numVendas_Crescente(Empregado* p1, Empregado* p2) {

	if (p1->getNumVendas() < p2->getNumVendas())
		return true;
	else if (p1->getNumVendas() == p2->getNumVendas())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_numVendas_Decrescente(Empregado* p1, Empregado* p2) {

	if (p1->getNumVendas() > p2->getNumVendas())
		return true;
	else if (p1->getNumVendas() == p2->getNumVendas())
	{
		if (p1->getNome() < p2->getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}
