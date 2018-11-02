#ifndef Farmacia_H
#define Farmacia_H

#include <string>
#include <vector>
#include <map>

#include "Pessoa.h"
#include "Produto.h"
#include "util.h"
#include "Sistema.h"

using namespace std;

class Farmacia : public Sistema{
public:
	Farmacia(string nome, Morada Morada, Empregado gerente);
	virtual ~Farmacia();
	void addProduto(Produto produto, int quantidade);
	void addEmpregado(Empregado empregado);
	void remProduto(Produto produto);
	void remProduto(int codigo);
	void removeQuantidade(Produto produto, int quantidade);
	string getNome() const;
	Morada getMorada() const;
	Empregado getGerente() const;
	bool operator == (const Farmacia & ph1);
	bool operator < (const Farmacia & ph); //Ordenado alfabeticamente
	void gerir();
	void adicionar();
	void remover();
	void consultar();
	void adicionarProduto();
	void adicionarEmpregado();
	void removerProduto();
	void removerEmpregado();
private:
	string nome;
	Morada morada;
	Empregado gerente;
	vector< Empregado > empregados;
	map<Produto, int> stock;
};

#endif
