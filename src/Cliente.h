#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <vector>
#include "Pessoa.h"

class Cliente : protected Pessoa {
public:

	Cliente();

	bool adicionaVenda(Venda*);
	bool verHistorico();

private:
	vector<Venda*> historicoVendas;
};



#endif /* CLIENTE_H_ */
