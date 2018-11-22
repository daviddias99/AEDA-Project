#include "Empregado.h"


uint Empregado::currentID = 0;

Empregado::Empregado(string nome, uint nif, Data dataNasc, Morada morada, uint sal, string farmaciaNome, string cargo, int ID) : Pessoa(nome, nif, dataNasc, morada), farmaciaNome(farmaciaNome), salario(sal)
{
	this->cargo = cargo;

	if (ID == -1) {
		this->ID = currentID;
		currentID++;
	}
	else {
		this->ID = ID;
		if ((uint) ID > currentID) {
			currentID = ID + 1;
		}
	}
}

void Empregado::decID() {
	currentID--;
}

void Empregado::addVenda(Venda * venda)
{
	historicoVendas.push_back(venda);
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

uint Empregado::getNumVendas() const 
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

void Empregado::setFarmacia(string  novaFarmacia)
{
	this->farmaciaNome = novaFarmacia;
}

void Empregado::setCargo(string novoCargo)
{
	this->cargo = novoCargo;
}

ostream & Empregado::print(ostream & os) const
{
	os << "ID: " << ID << endl;
	Pessoa::print(os) << endl << "Farmacia: " << farmaciaNome << endl << "Cargo: " << cargo << endl << "Salario: " << salario << endl << " Numero de vendas: " << getNumVendas();

	return os;
}

ostream & Empregado::printSimp(ostream & os) const
{
	os << ID << "\\";
	Pessoa::printSimp(os);

	os << "\\" << farmaciaNome << "\\" << cargo << "\\" << salario; 

	return os;
}


bool operator<(const Empregado & e1, const Empregado & e2)
{
	if (e1.getNIF() < e2.getNIF()) {
		return true;
	}
	else
		return false;
}

bool operator==(const Empregado & e1, const Empregado & e2)
{
	if (e1.getNIF() == e2.getNIF())
		return true;
	else
		return false;
}

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
