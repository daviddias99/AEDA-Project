#include "Cadeia.h"

Cadeia::Cadeia() {}

//Cadeia::Cadeia(string n) : nome(n) {}

Cadeia::~Cadeia()
{
	for (size_t i = 0; i < this->clientes.size(); i++)
		delete this->clientes.at(i);
	for (size_t i = 0; i < this->farmacias.size(); i++)
		delete this->farmacias.at(i);
	for (size_t i = 0; i < this->empregados.size(); i++)
		delete this->empregados.at(i);
}

bool Cadeia::addFarmacia(Farmacia* farmacia)
{
	if(procura2(farmacias, farmacia) != -1) return false;

	farmacias.push_back(farmacia);

	sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Crescente);
	return true;
}

bool Cadeia::addCliente(Cliente* cliente)
{
	if(procura2(clientes, cliente) != -1) return false;

	clientes.push_back(cliente);
	sort(clientes.begin(), clientes.end(), Cliente_SortFunc_Idade_Crescente);
	return true;
}

bool Cadeia::addEmpregado(Empregado* empregado)
{
	if(procura2(empregados, empregado) != -1) return false;

	empregados.push_back(empregado);
	sort(empregados.begin(), empregados.end(), Empregado_SortFunc_Idade_Crescente);
	return true;
}

void Cadeia::removeFarmacia(string nome)
{
	int i = procura2(farmacias, nome);
	if(i != -1) {
		farmacias.erase(farmacias.begin() + i);
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Crescente);
	}

	throw FarmaciaNaoExiste(nome);
}

void Cadeia::removeCliente(int nif)
{
	int i = procura2(clientes, nif);
	if(i != -1) {
		clientes.erase(clientes.begin() +i);
		sort(clientes.begin(), clientes.end(), Cliente_SortFunc_Idade_Crescente);
	}

	throw ClienteNaoExiste(nif);
}

void Cadeia::removeEmpregado(int nif)
{
	int i = procura2(empregados, nif);
	if(i != -1) {
		empregados.erase(empregados.begin()+i);
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_Idade_Crescente);
	}


	throw EmpregadoNaoExiste(nif);
}

Farmacia* Cadeia::getFarmacia(string nome) const
{
	unsigned int i = procura2(farmacias, nome);
	if(i != -1) return farmacias[i];

	throw FarmaciaNaoExiste(nome);
}

Cliente* Cadeia::getCliente(int nif) const
{
	int i = procura2(clientes, nif);
	if(i != -1) return clientes[i];

	throw ClienteNaoExiste(nif);
}

Empregado* Cadeia::getEmpregado(int nif) const
{
	int i = procura2(empregados, nif);
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

/*
void Cadeia::carregarDados() {

	ifstream fichFarmacias;
	fichFarmacias.open("farmacias.txt");

	string linha;
	getline(fichFarmacias, linha);




}
*/

void Cadeia::guardarDados()
{
	string nomeFichFarmacias = "farmacias.txt";

	ofstream fichFarmacias;
	fichFarmacias.open(nomeFichFarmacias);

	for (vector<Farmacia *>::const_iterator it = farmacias.begin(); it != farmacias.end(); it++) {

		(*it)->printSimp(fichFarmacias) << endl;
	}

	string nomeFichClientes = "clientes.txt";

	ofstream fichClientes;
	fichClientes.open(nomeFichClientes);

	for (vector<Cliente *>::const_iterator it = clientes.begin(); it != clientes.end(); it++) {

		(*it)->printSimp(fichClientes) << endl;
	}

	string nomeFichEmpregados = "empregados.txt";

	ofstream fichEmpregados;
	fichEmpregados.open(nomeFichEmpregados);

	for (vector<Empregado *>::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
		(*it)->printSimp(fichEmpregados) << endl;
	}
}