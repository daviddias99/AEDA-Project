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

	bool adicionaVenda(Venda*);
	bool verHistorico();


private:
	vector<Venda*> historicoVendas;
};


#endif