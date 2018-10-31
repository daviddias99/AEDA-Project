#include "Empregado.h"

Empregado::Empregado(unsigned int sal, Farmacia * pharm, string pos) :salario(sal), farmacia(pharm), cargo(pos) {}

unsigned int Empregado::getSalario() const
{
	return this->salario;
}

string Empregado::getNomeFarmacia() const
{
	return this->farmacia->getNome();
}

string Empregado::getCargo() const
{
	return this->cargo;
}

bool Empregado::setSalario(unsigned int novoSalario)
{
	if (novoSalario < 0)
		return false;


	this->salario = novoSalario;

	return true;
}

bool Empregado::setFarmacia(Farmacia * novaFarmacia)
{
	this->farmacia = novaFarmacia;

	return true;
}

bool Empregado::setCargo(string novoCargo)
{

	this->cargo = novoCargo;

	return true;
}




