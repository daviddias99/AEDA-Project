#include <string>
#include "util.h"
#include <ctime>


Morada::Morada(string rua, string codigoPostal, int porta, string cidade) :
	rua(rua), codigoPostal(codigoPostal), porta(porta), cidade(cidade) {}


Data::Data(unsigned int dia, unsigned int mes, unsigned int ano) {

	this->ano = ano;
	this->mes = mes;
	this->dia = dia;
}

unsigned int Data::getAno()
{
	return this->ano;
}

unsigned int Data::getMes()
{
	return this->mes;
}

unsigned int Data::getDia()
{
	return this->dia;
}

Data::Data() {

	time_t tempoAtual = time(NULL);

	tm* tempAtualStruct = localtime(&tempoAtual);

	this->ano = tempAtualStruct->tm_year;
	this->mes = tempAtualStruct->tm_mon;
	this->dia = tempAtualStruct->tm_mday;

}