#include "Farmacia.h"

string Farmacia::getNome() const
{
	return nome;
}

bool Farmacia::operator == (const Farmacia & ph1)
{
	if(this->nome == ph1.getNome()) return true;
	else return false;
}

