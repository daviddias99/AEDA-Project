#include <string>
#include "Pessoa.h"
using namespace std;



Pessoa::Pessoa(string nome, uint nif, Data dataNasc, Morada morada): nome(nome), NIF(nif),dataNascimento(dataNasc),morada(morada)
{
}

string Pessoa::getNome() const
{
	return this->nome;
}

uint  Pessoa::getNIF() const
{
	return this->NIF;
}

Morada Pessoa::getMorada() const
{
	return this->morada;
}

uint Pessoa::getIdade() const
{

	Data atual = Data();
	uint anoA = atual.getAno();
	uint anoN = this->dataNascimento.getAno();
	uint mesA = atual.getMes();
	uint mesN = this->dataNascimento.getMes();
	uint diaA = atual.getDia();
	uint diaN = this->dataNascimento.getDia();

	uint idade = anoA - anoN;
	if (mesA < mesN)
		idade--;
	else if (mesA == mesN) {
		if (diaA < diaN)
			idade--;
	}

	return idade;

}

ostream& Pessoa::printSimp(ostream & os) const
{
	os << nome << "\\" << dataNascimento << "\\" << NIF << "\\";
	morada.printSimp(os);

	return os;
}
 
ostream & Pessoa::print(ostream & os) const
{
	os << nome << endl << "Data de nascimento: " << dataNascimento << endl << "NIF: " << NIF << endl << morada;

	return os;
}

bool Pessoa::setMorada(Morada newMorada)
{
	this->morada = newMorada;

	return true;
}








bool Pessoa_SortFunc_Idade_Crescente(Pessoa* p1, Pessoa* p2) {

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

bool Pessoa_SortFunc_Idade_Decrescente(Pessoa* p1, Pessoa* p2) {

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

bool Pessoa_SortFunc_Nome_Crescente(Pessoa* p1, Pessoa* p2) {

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

bool Pessoa_SortFunc_Nome_Decrescente(Pessoa* p1, Pessoa* p2) {

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
bool Pessoa_SortFunc_NIF_Crescente(Pessoa* p1, Pessoa* p2) {

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

bool Pessoa_SortFunc_NIF_Decrescente(Pessoa* p1, Pessoa* p2) {

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




