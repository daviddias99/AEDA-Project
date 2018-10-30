#include "Cadeia.h"

bool Cadeia::addFarmacia(Farmacia farmacia)
{
	vector<Farmacia>::iterator it;

	for(it = farmacias.begin(); it != farmacias.end(); it++) {
		if(*it == farmacia) return false;
	}

	farmacias.push_back(farmacia);
	return true;
}

bool Cadeia::addFarmacias(vector <Farmacia> v1)
{
	vector<Farmacia>::iterator it;
	for(it = v1.begin(); it != v1.end(); it++) {
		if(!addFarmacia(*it)) return false;
	}

	return true;
}

bool Cadeia::addCliente(Cliente cliente);
{
	vector<Cliente>::iterator it;
	for(it = clientes.begin(); it != clientes.end(); it++) {
		if(*it == cliente) return false;
	}

	clientes.push_back(cliente);
	return true;
}
