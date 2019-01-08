#include "Empregado.h"


uint Empregado::currentID = 0;

Empregado::Empregado(uint nif ,string nome, Data dataNasc, Morada morada, uint sal, string farmaciaNome, string cargo, Data dataContratacao, Data dataDespedimento, uint mesesLigacao, int ID) : Pessoa(nome, nif, dataNasc, morada), farmaciaNome(farmaciaNome), salario(sal)
{
	this->cargo = cargo;

	mesesLigacaoAnterior = mesesLigacao;
	ultimaDataContratacao = dataContratacao;
	ultimaDataDespedimento = dataDespedimento;

	if (ID == -1) {
		this->ID = currentID;
		currentID++;
	}
	else {
		this->ID = ID;
		if (ID >=(int) currentID) {
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

void Empregado::mostrarVendas()
{
	for (size_t i = 0; i < historicoVendas.size(); i++)
		historicoVendas[i]->print(cout) << endl << endl;
}

ostream & Empregado::print(ostream & os) const
{
	os << "ID: " << ID << endl;
	Pessoa::print(os) << endl << "Farmacia: " << farmaciaNome << endl << "Cargo: " << cargo << endl << "Salario: " << salario << endl << "Numero de vendas: " << getNumVendas() << endl;

	if (this->trabalhaAtualmente()) {
		os << "Empregado com contrato." << endl;
		os << "Data de contratacao: " << ultimaDataContratacao << endl;
	}
	else {
		os << "Empregado sem contrato." << endl << "Meses de ligacao: " << mesesLigacaoAnterior;
	}

	return os;
}

ostream & Empregado::printSimp(ostream & os) const
{
	os << ID << "\\";
	Pessoa::printSimp(os);

	os << "\\" << farmaciaNome << "\\" << cargo << "\\" << salario << "\\" << mesesLigacaoAnterior << "\\" << ultimaDataContratacao << "\\" << ultimaDataDespedimento;

	return os;
}

bool Empregado::trabalhaAtualmente() const
{
	return ultimaDataDespedimento == Data::NULLData; // caso o empregado não tenha sido despedido, é porque e um trabalhador atual da farmacia
}

void Empregado::despedir()
{
	ultimaDataDespedimento = Data();
	mesesLigacaoAnterior = mesesEntre(ultimaDataContratacao, ultimaDataDespedimento);
	farmaciaNome = "";
}

void Empregado::recontratar(string farmNome, string cargo, uint sal)
{
	this->ultimaDataContratacao = Data();
	this->ultimaDataDespedimento = Data::NULLData;

	this->cargo = cargo;
	this->farmaciaNome = farmNome;
	this->salario = sal;
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
