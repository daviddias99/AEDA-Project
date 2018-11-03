#include "Cadeia.h"

bool Cadeia::addFarmacia(Farmacia farmacia)
{
	if(procura(farmacias, farmacia) != -1) return false;

	farmacias.push_back(farmacia);

	sort(farmacias.begin(), farmacias.end());
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

bool Cadeia::addCliente(Cliente cliente)
{
	if(procura(clientes, cliente) != -1) return false;

	clientes.push_back(cliente);
	return true;
}

bool Cadeia::addClientes(const vector<Cliente> &v1)
{
	vector<Cliente>::iterator it;
	for(it = v1.begin(); it != v1.end(); it++) {
		if(!addCliente(*it)) return false;
	}
	return true;
}

bool Cadeia::addEmpregado(Empregado empregado)
{

	if(procura(empregados, empregado) != -1) return false;

	empregados.push_back(empregado);
	return true;
}

bool Cadeia::addEmpregados(const vector <Empregado > &v1)
{
	vector<Empregado>::iterator it;
		for(it = v1.begin(); it != v1.end(); it++) {
			if(!addEmpregado(*it)) return false;
		}
		return true;
}

void Cadeia::removeFarmacia(string nome)
{
	int i = procura(farmacias, nome);
	if(i != -1)
		farmacias.erase(farmacias.begin() + i);

	throw FarmaciaNaoExiste(nome);
}

void Cadeia::removeCliente(int nif)
{
	int i = procura(clientes, nif);
	if(i != -1)
		clientes.erase(clientes.begin() +i);

	throw ClienteNaoExiste(nif);
}

void Cadeia::removeEmpregado(int nif)
{
	int i = procura(empregados, nif);
	if(i != -1)
		empregados.erase(empregados.begin()+i);

	throw EmpregadoNaoExiste(nif);
}

Farmacia Cadeia::getFarmacia(string nome) const
{
	unsigned int i = procura(farmacias, nome);
	if(i != -1) return farmacias[i];

	throw FarmaciaNaoExiste(nome);
}

Cliente Cadeia::getCliente(int nif) const
{
	int i = procura(clientes, nif);
	if(i != -1) return clientes[i];

	throw ClienteNaoExiste(nif);
}

Empregado Cadeia::getEmpregado(int nif) const
{
	int i = procura(empregados, nif);
	if(i != -1) return empregados[i];

	throw EmpregadoNaoExiste(nif);
}

unsigned int Cadeia::getNumFarmacias() const
{
	return farmacias.size();
}

unsigned int Cadeia::getNumEmpregados() const
{
	return empregados.size();
}

unsigned int Cadeia::getNumClientes() const
{
	return clientes.size();
}
