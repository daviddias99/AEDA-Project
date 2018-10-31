#ifndef Farmacia_H
#define Farmacia_H

#include <string>
#include <vector>
#include <map>
#include "Cliente.h"
#include "Produto.h"
#include "Empregado.h"
#include "util.h"

using namespace std;

class Farmacia {
public:
	Farmacia(string nome, Morada Morada, Empregado gerente);
	virtual ~Farmacia();
	void addProduto(Produto produto, int quantidade);
	void removeProduto(Produto produto);
	void removeQuantidade(Produto produto, int quantidade);
	string getNome() const;
	Morada getMorada() const;
	Empregado getGerente() const;
	bool operator == (const Farmacia & ph1);
	bool operator < (const Farmacia & ph); //Ordenado alfabeticamente
private:
	string nome;
	Morada morada;
	Empregado gerente;
	vector< Empregado > empregados;
	map<Produto, int> stock;
};

#endif
