#ifndef PERSON_H
#define PERSON_H

/** @defgroup Pessoa Pessoa
 * @{
 *
 * Classe pessoa e suas classes derivadas
 */

#include <string>
#include <vector>
#include "util.h"
#include "Venda.h"

using namespace std;

class Pessoa {
public:
	/**
	 * @brief Construtor da classe pessoa que tambem serve como construtor por omissao
	 * 
	 * @param nome				Nome da pessoa
	 * @param nif				NIF da pessoa
	 * @param dataNasc			Data de nascimento da pessoa
	 * @param morada			Objeto do tipo Morada
	 */
	Pessoa(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada());
	/**
	 * @brief Devolve o nome da pessoa
	 * 
	 * @return Nome da pessoa 
	 */
	string getNome() const;
	/**
	 * @brief Devolve o NIF da pessoa
	 * 
	 * @return Nome da pessoa
	 */
	uint  getNIF() const;
	/**
	 * @brief Devolve a morada da pessoa
	 * 
	 * @return Morada da pessoa
	 */
	Morada getMorada() const;
	/**
	 * @brief Devolve a idade da pessoa
	 * 
	 * @return Idade da pessoa 
	 */
	uint  getIdade() const;
	/**
	 * @brief Imprime as informacoes da pessoa num formato simplificado, utilizado para guardar informacoes das pessoas em ficheiro de texto
	 * 
	 * @param os Stream onde sao imprimidas as informacoes
	 * @return Stream onde foram imprimidas as informacoes
	 */
	virtual ostream& printSimp(ostream& os) const;
	/**
	 * @brief Imprime as informacoes da pessoa num formato legivel
	 * 
	 * @param os Stream onde sao imprimidas as informacoes
	 * @return Stream onde foram imprimidas as informacoes
	 */
	virtual ostream& print(ostream& os) const;
	/**
	 * @brief Altera a morada da pessoa
	 * 
	 * @param novaMorada Nova morada da pessoa
	 * @return true 
	 */
	bool setMorada(Morada novaMorada);
protected:
	/**
	 * @brief Nome da pessoa
	 */
	const string nome;
	/**
	 * @brief Data de nascimento da pessoa
	 */
	const Data dataNascimento;
	/**
	 * @brief NIF da pessoa
	 */
	const uint NIF;
	/**
	 * @brief Morada da pessoa
	 */
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
