#ifndef VENDA_H
#define VENDA_H

#include "Produto.h"

class Venda {
public:
	Venda();
	void addProduto(const Produto &prod, unsigned int quant);
	void getProdutos();
private:

};

#endif /* VENDA_H */
