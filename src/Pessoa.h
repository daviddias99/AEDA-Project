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



#endif
