#ifndef EMPREGADO_H_
#define EMPREGADO_H_

#include <string>
#include <vector>
#include "Pessoa.h"
#include "Farmacia.h"
#include "Venda.h"
using namespace std;

class Empregado : protected Pessoa {
public:
	Empregado(unsigned int sal, Farmacia* farm, string cargo);

	unsigned int getSalario() const;
	string getNomeFarmacia() const;
	string getCargo() const;

	bool setSalario(unsigned int novoSalario);
	bool setFarmacia(Farmacia* novaFarmacia);
	bool setCargo(string novoCargo);


private:
	unsigned int salario;
	Farmacia* farmacia;
	string cargo;
	vector<Venda*> historicoVendas;
};


#endif /* SRC_EMPREGADO_H_ */
