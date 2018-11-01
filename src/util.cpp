#include <string>
#include "util.h"
#include <ctime>


Morada::Morada(string rua, string codigoPostal, int porta, string cidade) :
	rua(rua), codigoPostal(codigoPostal), porta(porta), cidade(cidade) {}


Data::Data(uint dia, uint mes, uint  ano) : ano(ano), mes(mes), dia(dia) {

	if (mes > 12)
		throw DataInvalida();

	if (dia > (unsigned int)daysInMonth(mes, ano))
		throw DataInvalida();

}

string Data::getData(bool dmy)
{
	string result;

	if (dmy)
		result = this->getDia() + '/' + this->getMes() + '/' + this->getAno();
	else
		result = this->getAno() + '/' + this->getMes() + '/' + this->getDia();


	return result;
}


Data::Data() {

	time_t tempoAtual = time(NULL);

	tm* tempAtualStruct =  NULL;
	localtime_s(tempAtualStruct,&tempoAtual);

	this->ano = tempAtualStruct->tm_year;
	this->mes = tempAtualStruct->tm_mon;
	this->dia = tempAtualStruct->tm_mday;

}

uint Data::getAno() const
{
	return this->ano;
}

uint Data::getMes() const
{
	return this->mes;
}

uint Data::getDia() const
{
	return this->dia;
}

bool Data::operator<(Data & d2) const
{
	if (this->ano < d2.ano)
		return true;
	else if (this->ano == d2.ano) {

		if (this->mes < d2.mes)
			return true;
		else if (this->mes == d2.mes) {

			if (this->dia < d2.dia)
				return true;
			else return false;


		}
		else return false;
	}
	else return false;

}



Time::Time(uint hora, uint minuto, uint segundo) : hora(hora), minuto(minuto), segundo(segundo) {

	if (hora > 23)
		throw TimeInvalido();
	if (minuto > 59)
		throw TimeInvalido();
	if (segundo > 50)
		throw TimeInvalido();

}

string Time::getTime(bool mostraSegundos)
{
	string result;

	result = this->getHora() + ':' + this->getMin();

	if(mostraSegundos)
		result += ':' + this->getSeg();

	return result;
}

unsigned int Time::getHora() const
{
	return this->hora;
}

unsigned int Time::getMin() const
{
	return this->minuto;
}

unsigned int Time::getSeg() const
{
	return this->segundo;
}

Time::Time() {

	time_t tempoAtual = time(NULL);

	tm* tempAtualStruct = NULL;
	localtime_s(tempAtualStruct,&tempoAtual);

	this->hora = tempAtualStruct->tm_hour;
	this->minuto = tempAtualStruct->tm_min;
	this->segundo = tempAtualStruct->tm_sec;


}

Timestamp::Timestamp() : Data(), Time() {
}

Timestamp::Timestamp(Data data, Time time): Data(data), Time(time){
}

string Timestamp::getTstamp()
{
	string result;

	result = this->getData() + " | " + this->getTime();

	return result;
}

//This function returns true if the given year is a Leap Year and false otherwise
bool isLeap(int year)
{
	bool result = false;

	if (year % 400 == 0)
	{
		result = true;
	}
	else if ((year % 4 == 0) && (year % 10 != 0))
	{
		result = true;
	}

	return result;
}

//This functions returns an integer representing the number of days in a given month of a given year
int daysInMonth(int month, int year)
{
	int numDays;

	if ((month == 2) && isLeap(year))
		numDays = 29;
	else if ((month == 2) && !isLeap(year))
		numDays = 28;
	else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		numDays = 31;
	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		numDays = 30;
	else
		numDays = 0;

	return numDays;
}

template< class T>
int procura(const vector<T> &v, T x)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle] < x)
			left = middle + 1;
		else if (x < v[middle])
			right = middle - 1;
		else return middle;

	}
	return -1;
}

template< class T>
int procura(const vector<T*> &v, T x)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (*v[middle] < x)
			left = middle + 1;
		else if (x < *v[middle])
			right = middle - 1;
		else return middle;

	}
	return -1;
}
