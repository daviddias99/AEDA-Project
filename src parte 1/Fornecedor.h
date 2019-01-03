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

};

struct fornecedor_heap_sort_func {
	bool operator()(const Fornecedor* lhs, const Fornecedor* rhs) {
		return lhs->getNumEncomendas() < lhs->getNumEncomendas();
	}
};

#endif
