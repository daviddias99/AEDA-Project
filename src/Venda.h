#ifndef VENDA_H
#define VENDA_H


#include <map>
#include <vector>
#include "Produto.h"
#include "Receita.h"



class Venda {
public:
	Venda(const Cliente & comp, const Empregado & vend);
	map<Produto, unsigned int> addReceita(const Receita & receita);
	void addProduto(const Produto &prod, unsigned int quant);
private:
	Cliente cliente;
	Empregado empregado;
	map<Produto, unsigned int> produtos;
};

#endif /* VENDA_H */
