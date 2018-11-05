#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "util.h"
#include "Venda.h"

using namespace std;


class Pessoa {
public:
	
	//NIF- 9 NCC- 8 NSS- 11 NUS- 9
	Pessoa(CartaoCidadao cc = CartaoCidadao(), Morada morada = Morada());

	string getNome() const;
	uint  getNIF() const;
	Morada getMorada() const;
	uint  getIdade() const;

	bool setMorada(Morada novaMorada);


private:
	const string nome;
	const Data dataNascimento;
	const unsigned int NIF;
	const unsigned int NCC;
	const unsigned int NSS;
	const unsigned int NUS;
	char sexo;
	float altura;
	string nacionalidade;

	Morada morada;
};



class Empregado :public Pessoa {
public:
	Empregado(CartaoCidadao cc = CartaoCidadao(), Morada morada = Morada(), uint  sal = 0, string farmaciaNome = "FARMACIA_DEFAULT", string cargo = "CARGO_DEFAULT");

	uint  getSalario() const;
	string getNomeFarmacia() const;
	string getCargo() const;
	uint getNumVendas();

	bool setSalario(uint  novoSalario);
	bool setFarmacia(string novaFarmacia);
	bool setCargo(string novoCargo);


private:
	uint  salario;
	string farmaciaNome;
	string cargo;
	vector<Venda*> historicoVendas;
};

class Cliente :public Pessoa {
public:

	Cliente(CartaoCidadao cc = CartaoCidadao(), Morada morada = Morada());

	bool adicionaCompra(Venda*);
	uint getNumCompras();
	bool verHistorico();


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



#endif
