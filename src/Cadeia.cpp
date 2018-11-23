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
	if(procura2(clientes, cliente) != -1) return false; //Cliente ja existe

	clientes.push_back(cliente);
	sort(clientes.begin(), clientes.end(), Cliente_SortFunc_ID_Crescente);
	return true;
}

bool Cadeia::addEmpregado(Empregado* empregado)
{
	if(procura2seq(empregados, empregado) != -1) return false; //Empregado ja existe

	empregados.push_back(empregado);
	sort(empregados.begin(), empregados.end(), Empregado_SortFunc_ID_Crescente);

	size_t i = procura2(farmacias, empregado->getNomeFarmacia());

	this->farmacias.at(i)->addEmpregado(empregado);


	return true;
}

void Cadeia::removeFarmacia(string nome)
{
	int i = procura2(farmacias, nome);
	if(i != -1) { //Farmacia encontrada
		farmacias.erase(farmacias.begin() + i);
		
	}
	else throw FarmaciaNaoExiste(nome);
}

void Cadeia::removeCliente(uint ID)
{
	int i = procura2(clientes, ID);
	if(i != -1) { //Cliente encontrado
		clientes.erase(clientes.begin() +i);
		
	} 
	else throw ClienteNaoExiste("O cliente com o ID " + to_string(ID) + " nao existe");
}

void Cadeia::removeEmpregado(uint ID)
{
	int i = procura2(empregados, ID);
	if(i != -1) { //Empregado encontrado
		empregados.erase(empregados.begin()+i);
		
	}
	else throw EmpregadoNaoExiste("O empregado com o ID " + to_string(ID) + " nao existe");
}

Farmacia* Cadeia::getFarmacia(string nome) const
{
	unsigned int i = procura2(farmacias, nome);
	if(i != -1) //Farmacia encontrada
		return farmacias[i]; 

	throw FarmaciaNaoExiste("Nao existe nenhuma farmacia com o nome " + nome + ".");
}

Cliente* Cadeia::getCliente(uint ID) const
{
	int i = procura2(clientes, ID);
	if(i != -1) //Cliente encontrado
		return clientes[i];

	throw ClienteNaoExiste("O cliente com o ID " + to_string(ID) + " nao existe");
}

Empregado* Cadeia::getEmpregado(uint ID) const
{
	int i = procura2(empregados, ID);
	if(i != -1) //Empregado encontrado
		return empregados[i];

	throw  EmpregadoNaoExiste("O empregado com o ID " + to_string(ID) + " nao existe");
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

vector<Empregado*> Cadeia::getEmpregados(string nome) const
{
	vector<Empregado*> resultado;

	for (size_t i = 0; i < this->empregados.size(); i++) {

		if (this->empregados.at(i)->getNome() == nome) {
			resultado.push_back(this->empregados.at(i));
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

string Cadeia::getNome() const
{
	return nome;
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
	if (farmacias.size() == 0) {
		cout << "A cadeia " + nome + " ainda nao tem farmacias." << endl << endl;
		return;
	}
	for (size_t i = 0; i < farmacias.size(); i++)
		farmacias.at(i)->print(cout) << endl << endl;
}

void Cadeia::mostrarClientes()
{
	for (size_t i = 0; i < clientes.size(); i++)
		clientes.at(i)->print(cout) << endl << endl;
}

void Cadeia::mostrarEmpregados()
{
	for (size_t i = 0; i < empregados.size(); i++)
		empregados.at(i)->print(cout) << endl << endl;
}


void Cadeia::guardarDados()
{
	string nomeFichFarmacias = nome + "-farmacias.txt";

	ofstream fichFarmacias;
	fichFarmacias.open(nomeFichFarmacias);

	for (vector<Farmacia *>::const_iterator it = farmacias.begin(); it != farmacias.end(); it++) {

		(*it)->printSimp(fichFarmacias) << endl;
	}

	fichFarmacias.close();

	string nomeFichClientes = nome + "-clientes.txt";

	ofstream fichClientes;
	fichClientes.open(nomeFichClientes);

	for (vector<Cliente *>::const_iterator it = clientes.begin(); it != clientes.end(); it++) {

		(*it)->printSimp(fichClientes) << endl;
	}

	fichClientes.close();

	string nomeFichEmpregados = nome + "-empregados.txt";

	ofstream fichEmpregados;
	fichEmpregados.open(nomeFichEmpregados);

	for (vector<Empregado *>::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
		(*it)->printSimp(fichEmpregados) << endl;
	}

	fichEmpregados.close();

	string nomeFichVendas = nome + "-vendas.txt";

	ofstream fichVendas;
	fichVendas.open(nomeFichVendas);

	for (vector<Farmacia *>::const_iterator it_farmacias = farmacias.begin(); it_farmacias != farmacias.end(); it_farmacias++) {

		for (vector<Venda *>::const_iterator it_vendas = (*it_farmacias)->getVendas().begin(); it_vendas != (*it_farmacias)->getVendas().end(); it_vendas++) {

			(*it_vendas)->printSimp(fichVendas) << endl;
		}
	}
}

void Cadeia::carregarDados() {

	ifstream fich_farm, fich_emp, fich_cli, fich_vend;
	fich_farm.open(nome + "-farmacias.txt");
	fich_emp.open(nome + "-empregados.txt");
	fich_cli.open(nome + "-clientes.txt");
	fich_vend.open(nome + "-vendas.txt");

	if (!(fich_farm.is_open() && fich_cli.is_open() && fich_emp.is_open() && fich_vend.is_open()))
		throw FicheiroNaoEncontrado("Ficheiros da cadeia \"" + nome + "\" nao encontrados.");

	carregarFarmacias(fich_farm);

	carregarEmpregados(fich_emp);

	carregarClientes(fich_cli);

	carregarVendas(fich_vend);

	fich_cli.close();
	fich_farm.close();
	fich_emp.close();
	fich_vend.close();
}

void Cadeia::carregarClientes(ifstream& ficheiro)
{
	string linha;
	int ID;
	string nome;
	int NIF;
	Morada morada;
	Data data;
	Cliente * novoCli;


	getline(ficheiro, linha);
	if (linha != "") {

		ID = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nome = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		data = Data(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		NIF = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		morada = linha;
		

		novoCli = new Cliente(nome, NIF, data, morada, ID);

		clientes.push_back(novoCli);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {

			ID = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nome = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			data = Data(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			NIF = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			morada = linha;

			novoCli = new Cliente(nome, NIF, data, morada, ID);

			clientes.push_back(novoCli);
		}
	}
}

void Cadeia::carregarEmpregados(ifstream& ficheiro)
{

	string linha;
	int ID;
	string nome, farmaciaNome, cargo;
	int NIF;
	uint salario;
	Morada morada;
	Data data;
	Empregado * novoEmp;


	getline(ficheiro, linha);
	if (linha != "") {

		ID = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nome = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		data = Data(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		NIF = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		morada = Morada(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		farmaciaNome = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		cargo = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		salario = stoul(linha);
		
		novoEmp = new Empregado(nome, NIF, data, morada, salario, farmaciaNome, cargo, ID);
	
		empregados.push_back(novoEmp);
		getFarmacia(novoEmp->getNomeFarmacia())->addEmpregado(novoEmp);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {
			
			ID = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nome = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			data = Data(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			NIF = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			morada = Morada(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			farmaciaNome = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			cargo = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			salario = stoul(linha);


			novoEmp = new Empregado(nome, NIF, data, morada, salario, farmaciaNome, cargo, ID);

			empregados.push_back(novoEmp);
			getFarmacia(novoEmp->getNomeFarmacia())->addEmpregado(novoEmp);
		}
	}
}

void Cadeia::carregarFarmacias(ifstream& ficheiro) {

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

void Cadeia::carregarVendas(ifstream & ficheiro)
{
	string linha;
	int idCliente, idEmpregado;
	string nomeFarmacia, nomeCliente, nomeEmpregado, nome_prod, desc_prod, produtoSimp;
	float preco_prod, iva_prod, desc_receita;
	unsigned long int cod_produto;
	bool vend_sem_rec, pode_ser_rec;
	uint quant;
	string timestamp;


	Venda * novaVenda;

	getline(ficheiro, linha);
	if (linha != "") {

		
		timestamp = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nomeFarmacia = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		idCliente = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nomeCliente = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		idEmpregado = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nomeEmpregado = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\'));

		novaVenda = new Venda(idCliente, nomeCliente, idEmpregado, nomeEmpregado, nomeFarmacia, timestamp);

		while (linha != "!" && linha != "") {
			linha = linha.substr(1);
			produtoSimp = linha.substr(0, linha.find_first_of('#'));
			quant = stoul(linha.substr(linha.find_first_of('#') + 1, linha.find_first_of('!')));
			linha = linha.substr(linha.find_first_of('!'));

			bool isMed = false;
			if (count(produtoSimp.begin(), produtoSimp.end(), '&') > 4)
				isMed = true;

			cod_produto = stoul(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			nome_prod = produtoSimp.substr(0, produtoSimp.find_first_of('&'));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			desc_prod = produtoSimp.substr(0, produtoSimp.find_first_of('&'));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			preco_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			


			if (!isMed) {
				iva_prod = stof(produtoSimp);
				novaVenda->addProduto(new Produto(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod), quant);
			}
			else {
				iva_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				vend_sem_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				pode_ser_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				desc_receita = stof(produtoSimp);

				novaVenda->addProduto(new Medicamento(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod, vend_sem_rec, pode_ser_rec, desc_receita), quant);
			}
		}

		getFarmacia(nomeFarmacia)->addVenda(novaVenda);
		getCliente(idCliente)->adicionaCompra(novaVenda);
		getEmpregado(idEmpregado)->addVenda(novaVenda);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {

			timestamp = stof(produtoSimp.substr(0, produtoSimp.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nomeFarmacia = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			idCliente = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nomeCliente = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			idEmpregado = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nomeEmpregado = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\'));

			novaVenda = new Venda(idCliente, nomeCliente, idEmpregado, nomeEmpregado, nomeFarmacia);

			while (linha != "!" && linha != "") {
				linha = linha.substr(1);
				produtoSimp = linha.substr(0, linha.find_first_of('#'));
				quant = stoul(linha.substr(linha.find_first_of('#') + 1, linha.find_first_of('!')));
				linha = linha.substr(linha.find_first_of('!'));

				bool isMed = false;
				if (count(produtoSimp.begin(), produtoSimp.end(), '&') > 4)
					isMed = true;

				cod_produto = stoul(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				nome_prod = produtoSimp.substr(0, produtoSimp.find_first_of('&'));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				desc_prod = produtoSimp.substr(0, produtoSimp.find_first_of('&'));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				preco_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);



				if (!isMed) {
					iva_prod = stof(produtoSimp);
					novaVenda->addProduto(new Produto(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod), quant);
				}
				else {
					iva_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
					produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
					vend_sem_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
					produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
					pode_ser_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
					produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
					desc_receita = stof(produtoSimp);

					novaVenda->addProduto(new Medicamento(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod, vend_sem_rec, pode_ser_rec, desc_receita), quant);
				}
			}

			getFarmacia(nomeFarmacia)->addVenda(novaVenda);
			getCliente(idCliente)->adicionaCompra(novaVenda);
			getEmpregado(idEmpregado)->addVenda(novaVenda);
		}
	}
}


