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

bool Cadeia::addClientes(vector<Cliente> v1)
{
	vector<Cliente>::iterator it;
	for(it = v1.begin(); it != v1.end(); it++) {
		if(!addCliente(*it)) return false;
	}
	return true;
}

bool Cadeia::addEmpregado(Empregado *empregado)
{

	if(procura(empregados, empregado) != -1) return false;

	empregados.push_back(empregado);
	return true;
}

bool Cadeia::addEmpregados(vector <Empregado *> v1)
{
	vector<Empregado*>::iterator it;
		for(it = v1.begin(); it != v1.end(); it++) {
			if(!addEmpregado(*it)) return false;
		}
		return true;
}

void Cadeia::removeFarmacia(Farmacia farmacia)
{
	int i = procura(farmacias, farmacia);
	if(i != -1)
		farmacias.erase(farmacias.begin() + i);

	throw FarmaciaNaoExiste(farmacia.getNome());
}

void Cadeia::removeCliente(Cliente cliente)
{
	int i = procura(clientes, cliente);
	if(i != -1)
		clientes.erase(clientes.begin() +i);

	throw ClienteNaoExiste(cliente.getNome());
}

void Cadeia::removeEmpregado(Empregado empregado)
{
	int i = procura(empregados, empregado);
	if(i != -1)
		empregados.erase(empregados.begin()+i);

	throw EmpregadoNaoExiste(empregado.getNome());
}

unsigned int Cadeia::procuraFarmacia(string nome) const
{

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
