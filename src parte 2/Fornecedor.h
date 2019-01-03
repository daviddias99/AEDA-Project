#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <string>
#include "util.h"

#include "Encomenda.h"

typedef enum TipoFornecedor{medicamentos,produtos} TipoFornecedor;

class Fornecedor {

private:

	string nome;
	Morada morada_sede;
	list<Encomenda> encomendas_satisfeitas;
	void adicionaEncomenda(Encomenda encomenda);
	TipoFornecedor tipo;
	

public:

	Fornecedor(string nome, Morada morada_sede, TipoFornecedor tipo);
	bool satisfazEncomenda(Encomenda encomenda);
	uint getNumEncomendas() const;
	string getNome() const;
	Morada getMoradaSede() const;
	const list<Encomenda>& getEncomendasSatisfeitas() const;
	TipoFornecedor getTipo() const;
	/**
	* @brief Mostra o nome e a morada do fornecedor no ecra
	*/
	ostream& print(ostream& os) const;
	ostream& print_encomendas_resumo(ostream& os) const;
	ostream& print_resumo_lista(ostream& os) const;
	bool operator<(Fornecedor& f2);
	bool operator==(Fornecedor& f2);
};



bool fornecedor_SortFunc_Nome_Crescente(Fornecedor * f1, Fornecedor * f2);
bool fornecedor_SortFunc_Nome_Decrescente(Fornecedor * f1, Fornecedor * f2);
bool fornecedor_SortFunc_Tipo_Crescente(Fornecedor * f1, Fornecedor * f2);
bool fornecedor_SortFunc_Tipo_Decrescente(Fornecedor * f1, Fornecedor * f2);
bool fornecedor_SortFunc_NumEncomendas_Crescente(Fornecedor * f1, Fornecedor * f2);
bool fornecedor_SortFunc_NumEncomendas_Decrescente(Fornecedor * f1, Fornecedor * f2);

struct fornecedor_heap_sort_func {
	bool operator()(const Fornecedor* lhs, const Fornecedor* rhs) {
		return lhs->getNumEncomendas() < lhs->getNumEncomendas();
	}
};

#endif
