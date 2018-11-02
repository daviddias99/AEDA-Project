#ifndef Farmacia_H
#define Farmacia_H

#include <string>
#include <vector>
#include <map>
#include <iomanip>

#include "Pessoa.h"
#include "Produto.h"
#include "util.h"
#include "Sistema.h"

using namespace std;

class Farmacia : public Sistema{
public:
	Farmacia(string nome, Morada Morada);
	virtual ~Farmacia();
	void addProduto(Produto *produto, int quantidade);
	bool addEmpregado(Empregado empregado);
	void remProduto(int codigo);
	void remGerente();
	bool addGerente(Empregado empregado);
	bool removeQuantidade(int codigo, int quantidade);
	void remEmpregado(int nif);
	string getNome() const;
	Morada getMorada() const;
	Empregado getGerente() const;
	vector<Empregado> getEmpregados(string nome);
	Produto* getProduto(int codigo);
	int getTotalProdutos();

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

	void consultarEmpregado();
	void consultarStock();
	void consultarProduto();
private:
	string nome;
	Morada morada;
	Empregado gerente;
	vector< Empregado > empregados;
	map< Produto *, int> stock;
};

#endif
