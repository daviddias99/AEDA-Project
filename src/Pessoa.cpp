#include <string>
#include "Pessoa.h"
using namespace std;


Pessoa::Pessoa(string n, unsigned int nif, Morada add) :nome(n), NIF(nif), morada(add) {}

string Pessoa::getNome() const
{
	return this->nome;
}

unsigned int Pessoa::getNIF() const
{
	return this->NIF;
}

Morada Pessoa::getMorada() const
{
	return this->morada;
}

bool Pessoa::setMorada(Morada newMorada)
{
	this->morada = newMorada;

	return true;
}




