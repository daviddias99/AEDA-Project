#include "Cadeia.h"

Cadeia::Cadeia() : nome("SEM_NOME") {}

Cadeia::Cadeia(string n) : nome(n) {}

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
	sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_NIF_Crescente);
	return true;
}

//atencao aqui
bool Cadeia::addEmpregado(Empregado* empregado)
{
	if(procura2(empregados, empregado) != -1) return false;

	empregados.push_back(empregado);
	sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_NIF_Crescente);

	size_t i = procura2(farmacias, empregado->getNomeFarmacia());

	this->farmacias.at(i)->addEmpregado(empregado);


	return true;
}

void Cadeia::removeFarmacia(string nome)
{
	int i = procura2(farmacias, nome);
	if(i != -1) {
		farmacias.erase(farmacias.begin() + i);
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Crescente);
	}
	else throw FarmaciaNaoExiste(nome);
}

void Cadeia::removeCliente(uint ID)
{
	int i = procura2(clientes, ID);
	if(i != -1) {
		clientes.erase(clientes.begin() +i);
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_NIF_Crescente);
	} 
	else throw ClienteNaoExiste(ID);
}

void Cadeia::removeEmpregado(uint ID)
{
	int i = procura2(empregados, ID);
	if(i != -1) {
		empregados.erase(empregados.begin()+i);
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_NIF_Crescente);
	}
	else throw EmpregadoNaoExiste(ID);
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

vector<Cliente*> Cadeia::getClientes(string nome) const
{
	vector<Cliente*> resultado;

	for (size_t i = 0; i < this->clientes.size(); i++) {

		if (this->clientes.at(i)->getNome() == nome) {
			resultado.push_back(this->clientes.at(i));
		}

	}

	return resultado;
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




void Cadeia::sortFarmacias(char modo)
{
	switch (modo) {
	case '1':
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Crescente);
		break;
	case '2':
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Decrescente);
		break;
	case '3':
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_TamanhoStock_Crescente);
		break;
	case '4':
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_TamanhoStock_Decrescente);
		break;
	case '5':
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_NumVendas_Crescente);
		break;
	case '6':
		sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_NumVendas_Decrescente);
		break;
	}
}

void Cadeia::sortClientes(ord_pessoas modo)
{
	switch (modo) {
	case id_cres:
		sort(clientes.begin(), clientes.end(), Cliente_SortFunc_ID_Crescente);
		break;
	case id_dec:
		sort(clientes.begin(), clientes.end(), Cliente_SortFunc_ID_Decrescente);
		break;
	case idade_cres:
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_Idade_Crescente);
		break;
	case idade_dec:
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_Idade_Decrescente);
		break;
	case nome_cres:
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_Nome_Crescente);
		break;
	case nome_dec:
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_Nome_Decrescente);
		break;
	case nif_cres:
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_NIF_Crescente);
		break;
	case nif_dec:
		sort(clientes.begin(), clientes.end(), Pessoa_SortFunc_NIF_Decrescente);
		break;
	case n_comp_cres:
		sort(clientes.begin(), clientes.end(), Cliente_SortFunc_numCompras_Crescente);
		break;
	case n_comp_dec:
		sort(clientes.begin(), clientes.end(), Cliente_SortFunc_numCompras_Decrescente);
		break;
	}
}

void Cadeia::sortEmpregados(ord_pessoas modo)
{
	switch (modo) {
	case id_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_ID_Crescente);
		break;
	case id_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_ID_Decrescente);
		break;
	case idade_cres:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Idade_Crescente);
		break;
	case idade_dec:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Idade_Decrescente);
		break;
	case nome_cres:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Nome_Crescente);
		break;
	case nome_dec:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Nome_Decrescente);
		break;
	case nif_cres:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_NIF_Crescente);
		break;
	case nif_dec:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_NIF_Decrescente);
		break;
	case n_comp_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_numVendas_Crescente);
		break;
	case n_comp_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_numVendas_Decrescente);
		break;
	case sal_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_Salario_Crescente);
		break;
	case sal_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_Salario_Decrescente);
		break;
	}
}

void Cadeia::mostrarFarmacias()
{
	for (size_t i = 0; i < farmacias.size(); i++)
		farmacias.at(i)->print(cout);

	sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Crescente);
}

void Cadeia::mostrarClientes()
{
	for (size_t i = 0; i < clientes.size(); i++)
		clientes.at(i)->print(cout);
}

void Cadeia::mostrarEmpregados()
{
	for (size_t i = 0; i < empregados.size(); i++)
		empregados.at(i)->print(cout);
}


void Cadeia::guardarDados()
{
	string nomeFichFarmacias = nome + "-farmacias.txt";

	ofstream fichFarmacias;
	fichFarmacias.open(nomeFichFarmacias);

	for (vector<Farmacia *>::const_iterator it = farmacias.begin(); it != farmacias.end(); it++) {

		(*it)->printSimp(fichFarmacias) << endl;
	}

	string nomeFichClientes = nome + "-clientes.txt";

	ofstream fichClientes;
	fichClientes.open(nomeFichClientes);

	for (vector<Cliente *>::const_iterator it = clientes.begin(); it != clientes.end(); it++) {

		(*it)->printSimp(fichClientes) << endl;
	}

	string nomeFichEmpregados = nome + "-empregados.txt";

	ofstream fichEmpregados;
	fichEmpregados.open(nomeFichEmpregados);

	for (vector<Empregado *>::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
		(*it)->printSimp(fichEmpregados) << endl;
	}
}

void Cadeia::carregarDados() {

	carregarFarmacias();

	carregarEmpregados();

	carregarClientes();
}

void Cadeia::carregarClientes()
{
}

void Cadeia::carregarEmpregados()
{
}

void Cadeia::carregarFarmacias() {


	ifstream ficheiro;
	ficheiro.open(nome + "-farmacias.txt");
	string linha;

	getline(ficheiro, linha);
	if (linha != "") {
		Farmacia * farmacia = new Farmacia(linha);
		farmacias.push_back(farmacia);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {
			Farmacia * farmacia = new Farmacia(linha);
			farmacias.push_back(farmacia);
		}
	}
}
