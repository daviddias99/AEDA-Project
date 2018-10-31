#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "util.h"
#include "Farmacia.h"
#include "Venda.h"

using namespace std;


class Pessoa {
public:
	Pessoa(string n, unsigned int nif, Morada morada);

	string getNome() const;
	unsigned int getNIF() const;
	Morada getMorada() const;
	unsigned int getIdade() const;

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

class Empregado :protected Pessoa {
public:
	Empregado(unsigned int sal, Farmacia* farm, string cargo);

	unsigned int getSalario() const;
	string getNomeFarmacia() const;
	string getCargo() const;

	bool setSalario(unsigned int novoSalario);
	bool setFarmacia(Farmacia* novaFarmacia);
	bool setCargo(string novoCargo);


private:
	unsigned int salario;
	Farmacia* farmacia;
	string cargo;
	vector<Venda*> historicoVendas;
};

class Cliente :protected Pessoa {
public:

	Cliente();

	bool adicionaVenda(Venda*);
	bool verHistorico();


private:
	vector<Venda*> historicoVendas;
};


#endif