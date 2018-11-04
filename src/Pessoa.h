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
	Pessoa(CartaoCidadao cc, Morada morada);

	string getNome() const;
	uint  getNIF() const;
	Morada getMorada() const;
	uint  getIdade() const;

	bool setMorada(Morada novaMorada);


private:

	CartaoCidadao pessoaId;
	Morada morada;
};

class Empregado :public Pessoa {
public:
	Empregado(CartaoCidadao cc, Morada morada, uint  sal, string farmaciaNome, string cargo);

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

	Cliente(CartaoCidadao cc, Morada morada);

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