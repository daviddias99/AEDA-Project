#include <string>
#include "Pessoa.h"
using namespace std;


Pessoa::Pessoa(string n, unsigned int nif, Morada add) :nome(n), NIF(nif), morada(add) {

}

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

Empregado::Empregado(unsigned int sal, Farmacia * pharm, string pos) :salario(sal), farmacia(pharm), cargo(pos)
{


}

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

Cliente::Cliente()
{
}

bool Cliente::adicionaVenda(Venda * novaVenda)
{
	this->historicoVendas.push_back(novaVenda);

	return true;
}
