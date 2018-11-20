#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "util.h"
#include "Venda.h"

using namespace std;

class Pessoa {
public:
	
	//NIF- 9 
	Pessoa(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada());

	string getNome() const;
	uint  getNIF() const;
	Morada getMorada() const;
	uint  getIdade() const;

	virtual ostream& printSimp(ostream& os) const;
	virtual ostream& print(ostream& os) const;

	bool setMorada(Morada novaMorada);


protected:
	const string nome;
	const Data dataNascimento;
	const uint NIF;

	Morada morada;
};


bool Pessoa_SortFunc_Idade_Crescente(Pessoa* p1, Pessoa* p2);
bool Pessoa_SortFunc_Idade_Decrescente(Pessoa* p1, Pessoa* p2);
bool Pessoa_SortFunc_Nome_Crescente(Pessoa* p1, Pessoa* p2);
bool Pessoa_SortFunc_Nome_Decrescente(Pessoa* p1, Pessoa* p2);
bool Pessoa_SortFunc_NIF_Crescente(Pessoa* p1, Pessoa* p2);
bool Pessoa_SortFunc_NIF_Decrescente(Pessoa* p1, Pessoa* p2);


template<class T>
int procura2(vector<T>& v, T x)
{
	if (v.size() == 0) {
		return -1;
	}

	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (*v[middle] < *x)
			left = middle + 1;
		else if (*x < *v[middle])
			right = middle - 1;
		else return middle;

	}
	return -1;
}

template<class T>
int procura2seq(vector<T>& v, T x)
{
	for (size_t i = 0; i < v.size(); i++) {

		if (*v.at(i) == *x) {
			return (int) i;
		}

	}

	return -1;
}

template<class X>
int procura2(const vector<X>& v, string nome)
{
	if (v.size() == 0) {
		return -1;
	}

	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle]->getNome() < nome)
			left = middle + 1;
		else if (nome < v[middle]->getNome())
			right = middle - 1;
		else return middle;

	}
	return -1;
}

template<class X>
int procura2(const vector<X>& v, uint ID)
{
	if (v.size() == 0) {
		return -1;
	}

	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle]->getID() < ID)
			left = middle + 1;
		else if (ID < v[middle]->getID())
			right = middle - 1;
		else return middle;

	}
	return -1;
}

#endif
