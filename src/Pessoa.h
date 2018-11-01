#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "util.h"
//#include "Farmacia.h"
#include "Venda.h"

using namespace std;

class Farmacia;

class Pessoa {
public:
	
	//NIF- 9 NCC- 8 NSS- 11 NUS- 9

	Pessoa(string n = "NOME_DEFAULT" , Morada morada = Morada(), uint  nif = 0, uint ncc = 0, uint nss = 0, uint nus = 0, char sex = 'D', float altura = 0.00, string nacionalidade = "DFT");

	string getNome() const;
	uint  getNIF() const;
	Morada getMorada() const;
	uint  getIdade() const;

	bool setMorada(Morada novaMorada);


private:
	const string nome;
	const Data dataNascimento;
	const uint  NIF;
	const uint  NCC;
	const uint  NSS;
	const uint  NUS;
	char sexo;
	float altura;
	string nacionalidade;



	Morada morada;


};

class Empregado :public Pessoa {
public:
	Empregado(uint  sal, Farmacia* farm, string cargo);

	uint  getSalario() const;
	string getNomeFarmacia() const;
	string getCargo() const;

	bool setSalario(uint  novoSalario);
	bool setFarmacia(Farmacia* novaFarmacia);
	bool setCargo(string novoCargo);


private:
	uint  salario;
	Farmacia* farmacia;
	string cargo;
	vector<Venda*> historicoVendas;
};

class Cliente :public Pessoa {
public:

	Cliente();

	bool adicionaVenda(Venda*);
	bool verHistorico();


private:
	vector<Venda*> historicoVendas;
};


#endif