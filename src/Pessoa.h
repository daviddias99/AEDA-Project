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

	virtual ostream& printSimp(ostream& os);

	bool setMorada(Morada novaMorada);


private:
	const string nome;
	const Data dataNascimento;
	const uint NIF;

	Morada morada;
};



class Empregado :public Pessoa {
public:
	Empregado(string nome = "NOME_DEFAULT",uint nif = 0, Data dataNasc = Data(), Morada morada = Morada(), uint  sal = 0, string farmaciaNome = "FARMACIA_DEFAULT", string cargo = "CARGO_DEFAULT");

	uint  getSalario() const;
	string getNomeFarmacia() const;
	string getCargo() const;
	uint getNumVendas();

	bool setSalario(uint  novoSalario);
	bool setFarmacia(string novaFarmacia);
	bool setCargo(string novoCargo);

	ostream& printSimp(ostream& os);

	friend ostream& operator<< (ostream& os, const Empregado& mor);
	friend bool operator<(const  Empregado& e1, const Empregado & e2)
	{
		return false;
	}

private:
	uint  salario;
	string farmaciaNome;
	string cargo;
	vector<Venda*> historicoVendas;
};

class Cliente:public Pessoa {
public:

	Cliente(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada());

	bool adicionaCompra(Venda*);
	uint getNumCompras();
	bool verHistorico();

	ostream& printSimp(ostream& os);

	friend bool operator<(const Cliente & e1, const Cliente & e2)
	{
		return false;
	}

private:
	vector<Venda*> historicoCompras;
};

bool Pessoa_SortFunc_Idade_Crescente(Pessoa& p1, Pessoa& p2);
bool Pessoa_SortFunc_Idade_Decrescente(Pessoa& p1, Pessoa& p2);
bool Pessoa_SortFunc_Nome_Crescente(Pessoa& p1, Pessoa& p2);
bool Pessoa_SortFunc_Nome_Decrescente(Pessoa& p1, Pessoa& p2);
bool Pessoa_SortFunc_NIF_Crescente(Pessoa& p1, Pessoa& p2);
bool Pessoa_SortFunc_NIF_Decrescente(Pessoa& p1, Pessoa& p2);

bool Empregado_SortFunc_Idade_Crescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_Idade_Decrescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_Nome_Crescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_Nome_Decrescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_NIF_Crescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_NIF_Decrescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_Salario_Crescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_Salario_Decrescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_numVendas_Crescente(Empregado& p1, Empregado& p2);
bool Empregado_SortFunc_numVendas_Decrescente(Empregado& p1, Empregado& p2);

bool Cliente_SortFunc_Idade_Crescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_Idade_Decrescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_Nome_Crescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_Nome_Decrescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_NIF_Crescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_NIF_Decrescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_numCompras_Crescente(Cliente& p1, Cliente& p2);
bool Cliente_SortFunc_numCompras_Decrescente(Cliente& p1, Cliente& p2);





template<class T>
int procura2(vector<T>& v, T x)
{
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

template<class X>
int procura2(const vector<X>& v, string nome)
{
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
int procura2(const vector<X>& v, uint nif)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle]->getNIF() < nif)
			left = middle + 1;
		else if (nif < v[middle]->getNIF())
			right = middle - 1;
		else return middle;

	}
	return -1;
}

#endif
