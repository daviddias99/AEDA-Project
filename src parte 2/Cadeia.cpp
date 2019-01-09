#include "Cadeia.h"

Cadeia::Cadeia() : nome("SEM_NOME") {}

Cadeia::Cadeia(string n) : nome(n) {}

Cadeia::~Cadeia() 
{
	set<Cliente*>::iterator it;
	for (it = clientes.begin(); it != clientes.end(); it++)
		delete (*it);

	for (size_t i = 0; i < this->farmacias.size(); i++)
		delete this->farmacias.at(i);
	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++)
		delete *it;
}

bool Cadeia::addFarmacia(Farmacia* farmacia)
{
	if(procura(farmacias, farmacia) != -1) return false;

	farmacias.push_back(farmacia);

	sort(farmacias.begin(), farmacias.end(), farmacia_SortFunc_Nome_Crescente);
	return true;
}

bool Cadeia::addCliente(Cliente* cliente)
{
	if( clientes.find(cliente) != clientes.end()) return false; //Cliente ja existe

	clientes.insert(cliente);

	clientesSort.push_back(cliente);
	sort(clientesSort.begin(), clientesSort.end(), Cliente_SortFunc_Distrito_Crescente);
	return true;
}

bool Cadeia::addEmpregado(Empregado* empregado)
{	
	if (!empregados.insert(empregado).second) return false;

	if (empregado->getNomeFarmacia() != "")
		getFarmacia(empregado->getNomeFarmacia())->addEmpregado(empregado);

	return true;
}

bool Cadeia::addFornecedor(Fornecedor * fornecedor)
{
	if (procura(fornecedores, fornecedor) != -1) return false;

	fornecedores.push_back(fornecedor);

	sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_Nome_Crescente);
	return true;
}

void Cadeia::removeFarmacia(string nome)
{
	int i = procura(farmacias, nome);
	if(i != -1) { //Farmacia encontrada
		farmacias.erase(farmacias.begin() + i);
		
	}
	else throw FarmaciaNaoExiste(nome);
}

void Cadeia::removeCliente(Cliente* cliente)
{
	clientes.erase(cliente);

	for (size_t i = 0; i < clientesSort.size(); i++) {
		if (clientesSort[i]->getNIF() == cliente->getNIF())
			clientesSort.erase(clientesSort.begin() + i);
	}
		
}

void Cadeia::removeFornecedor(string nome)
{
	int i = procura(fornecedores, nome);
	if (i != -1) { //Fornecedor encontrado 
		fornecedores.erase(fornecedores.begin() + i);

	}
	else throw FornecedorNaoExiste(nome);

}

Farmacia* Cadeia::getFarmacia(string nome) const
{
	unsigned int i = procura(farmacias, nome);
	if(i != -1) //Farmacia encontrada
		return farmacias[i]; 

	throw FarmaciaNaoExiste("Nao existe nenhuma farmacia com o nome " + nome + ".");
}

Cliente* Cadeia::getCliente(uint NIF, string nome, string distrito) const
{
	Cliente* c1 = new Cliente(nome, NIF, Data(), Morada(), distrito);
	clientesSet::iterator it = clientes.find(c1);

	if (it != clientes.end())
		return (*it);
	else 
		throw ClienteNaoExiste("O cliente com o NIF " + to_string(NIF) + " nao existe");
}

Empregado* Cadeia::getEmpregado(uint ID) const
{	
	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
		if ((*it)->getID() == ID)
			return *it;
	}

	return NULL;
}

bool Cadeia::empregadoSemContrato(long int NIF) const {

	Empregado* tmpEmp = new Empregado(NIF);


	empregadoHashTable::const_iterator it = empregados.find(tmpEmp);

	if (it == empregados.end())
		return false;

	if ((*it)->trabalhaAtualmente())
		return false;

	return true;
}

Fornecedor * Cadeia::getFornecedor(string nome) const
{
	unsigned int i = procura(fornecedores, nome);
	if (i != -1) //Fornecedor encontrada
		return fornecedores[i];

	throw FornecedorNaoExiste("Nao existe nenhum fornecedor com o nome " + nome + ".");
}

vector<Cliente*> Cadeia::getClientes(string nome) const
{
	vector<Cliente*> resultado;
	
	clientesSet::iterator it;
	for (it = clientes.begin(); it != clientes.end(); it++) {

		if ((*it)->getNome() == nome) {
			resultado.push_back(*it);
		}
	}

	return resultado;
}

vector<Empregado*> Cadeia::getEmpregados(string nome) const
{
	vector<Empregado*> resultado;

	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++) {

		if ((*it)->getNome() == nome) {
			resultado.push_back(*it);
		}

	}

	return resultado;
}

const vector<Fornecedor*>  Cadeia::getFornecedores() const {

	return this->fornecedores;
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

unsigned int Cadeia::getNumFornecedores() const
{
	return fornecedores.size();
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

void Cadeia::sortClientes(ord_clientes modo)
{
	switch (modo) {
	case distrito_cres:
		sort(clientesSort.begin(), clientesSort.end(), Cliente_SortFunc_Distrito_Crescente);
		break;
	case distrito_dec:
		sort(clientesSort.begin(), clientesSort.end(), Cliente_SortFunc_Distrito_Decrescente);
		break;
	case cliente_idade_cres:
		sort(clientesSort.begin(), clientesSort.end(), Pessoa_SortFunc_Idade_Crescente);
		break;
	case cliente_idade_dec:
		sort(clientesSort.begin(), clientesSort.end(), Pessoa_SortFunc_Idade_Decrescente);
		break;
	case cliente_nome_cres:
		sort(clientesSort.begin(), clientesSort.end(), Pessoa_SortFunc_Nome_Crescente);
		break;
	case cliente_nome_dec:
		sort(clientesSort.begin(), clientesSort.end(), Pessoa_SortFunc_Nome_Decrescente);
		break;
	case cliente_nif_cres:
		sort(clientesSort.begin(), clientesSort.end(), Pessoa_SortFunc_NIF_Crescente);
		break;
	case cliente_nif_dec:
		sort(clientesSort.begin(), clientesSort.end(), Pessoa_SortFunc_NIF_Decrescente);
		break;
	case n_comp_cres:
		sort(clientesSort.begin(), clientesSort.end(), Cliente_SortFunc_numCompras_Crescente);
		break;
	case n_comp_dec:
		sort(clientesSort.begin(), clientesSort.end(), Cliente_SortFunc_numCompras_Decrescente);
		break;
	}
}


void Cadeia::sortFornecedores(ord_fornece modo)
{
	switch (modo) {
	case nome_cres_f:
		sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_Nome_Crescente);
		break;
	case nome_dec_f:
		sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_Nome_Decrescente);
		break;
	case n_enc_cres_f:
		sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_NumEncomendas_Crescente);
		break;
	case n_enc_dec_f:
		sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_NumEncomendas_Decrescente);
		break;
	case tipo_cres_f:
		sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_Tipo_Crescente);
		break;
	case tipo_dec_f:
		sort(fornecedores.begin(), fornecedores.end(), fornecedor_SortFunc_Tipo_Decrescente);
		break;
	}
}


void Cadeia::mostrarFarmacias() const
{
	if (farmacias.size() == 0) {
		cout << "A cadeia " + nome + " ainda nao tem farmacias." << endl << endl;
		return;
	}
	for (size_t i = 0; i < farmacias.size(); i++)
		farmacias.at(i)->print(cout) << endl << endl;
}

void Cadeia::mostrarClientes() const
{
	for (size_t i = 0; i < clientesSort.size(); i++)
		clientesSort.at(i)->print(cout) << endl << endl;
}

void Cadeia::mostrarEmpregados() const
{	
	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
		(*it)->print(cout) << endl << endl;
	}
}

void Cadeia::getEmpregadosVec(vector<Empregado*>& res) const {


	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++) {

		res.push_back(*it);
	}
}

void Cadeia::getEmpregadosSemContratoVec(vector<Empregado*>& res) const {


	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
		if (! (*it)->trabalhaAtualmente())
			res.push_back(*it);
	}
}


void Cadeia::mostraFornecedores()
{
	if (fornecedores.size() == 0) {
		cout << "A cadeia " + nome + " ainda nao tem fornecedores." << endl << endl;
		return;
	}
	for (size_t i = 0; i < fornecedores.size(); i++) {

		fornecedores.at(i)->print(cout);
		cout << endl;
	}
		
}

void Cadeia::guardarDados() const
{
	string nomeFichFarmacias = nome + "-farmacias.txt";

	ofstream fichFarmacias;
	fichFarmacias.open(nomeFichFarmacias);

	for (vector<Farmacia *>::const_iterator it = farmacias.begin(); it != farmacias.end(); it++) {

		(*it)->printSimp(fichFarmacias) << endl;
	}

	fichFarmacias.close();

	string nomeFichFornecedores = nome + "-fornecedores.txt";

	ofstream fichFornecedores;
	fichFornecedores.open(nomeFichFornecedores);

	for (vector<Fornecedor *>::const_iterator it = fornecedores.begin(); it != fornecedores.end(); it++) {

		(*it)->printSimp(fichFornecedores) << endl;
	}

	fichFarmacias.close();

	string nomeFichClientes = nome + "-clientes.txt";

	ofstream fichClientes;
	fichClientes.open(nomeFichClientes);

	for (clientesSet::iterator it = clientes.begin(); it != clientes.end(); it++) {

		(*it)->printSimp(fichClientes) << endl;
	}

	fichClientes.close();

	string nomeFichEmpregados = nome + "-empregados.txt";

	ofstream fichEmpregados;
	fichEmpregados.open(nomeFichEmpregados);

	for (empregadoHashTable::const_iterator it = empregados.begin(); it != empregados.end(); it++) {
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

	ifstream fich_farm, fich_emp, fich_cli, fich_vend,fich_forn;
	fich_farm.open(nome + "-farmacias.txt");
	fich_emp.open(nome + "-empregados.txt");
	fich_cli.open(nome + "-clientes.txt");
	fich_vend.open(nome + "-vendas.txt");
	fich_forn.open(nome + "-fornecedores.txt");

	if (!(fich_farm.is_open() && fich_cli.is_open() && fich_emp.is_open() && fich_vend.is_open()))
		throw FicheiroNaoEncontrado("Ficheiros da cadeia \"" + nome + "\" nao encontrados.");


	carregarFornecedores(fich_forn);

	carregarFarmacias(fich_farm);

	carregarEmpregados(fich_emp);

	carregarClientes(fich_cli);

	carregarVendas(fich_vend);

	atribuiFornecedores();

	fich_cli.close();
	fich_farm.close();
	fich_emp.close();
	fich_vend.close();
	fich_forn.close();
}

void Cadeia::carregarClientes(ifstream& ficheiro)
{
	string linha;
	string distrito;
	string nome;
	int NIF;
	Morada morada;
	Data data;
	Cliente * novoCli;


	getline(ficheiro, linha);
	if (linha != "") {

		distrito = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nome = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		data = Data(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		NIF = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		morada = linha;
		

		novoCli = new Cliente(nome, NIF, data, morada, distrito);

		clientes.insert(novoCli);
		clientesSort.push_back(novoCli);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {

			distrito = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nome = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			data = Data(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			NIF = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			morada = linha;

			novoCli = new Cliente(nome, NIF, data, morada, distrito);

			clientes.insert(novoCli);
			clientesSort.push_back(novoCli);
		}
	}
}

void Cadeia::carregarEmpregados(ifstream& ficheiro)
{

	string linha;
	int ID;
	string nome, farmaciaNome, cargo;
	int NIF;
	uint salario, mesesLig;
	Morada morada;
	Data data, dataContr, dataDesp;
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
		salario = stoul(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		mesesLig = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		dataContr = Data(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		dataDesp = Data(linha);
		
		novoEmp = new Empregado(NIF, nome, data, morada, salario, farmaciaNome, cargo, dataContr, dataDesp, mesesLig, ID);

		addEmpregado(novoEmp);
		
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
			salario = stoul(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			mesesLig = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			dataContr = Data(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			dataDesp = Data(linha);

			novoEmp = new Empregado(NIF, nome, data, morada, salario, farmaciaNome, cargo, dataContr, dataDesp, mesesLig, ID);

			addEmpregado(novoEmp);
		
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
	int clienteNIF, idEmpregado;
	string nomeFarmacia, nomeCliente, distritoCliente, nomeEmpregado, nome_prod, desc_prod, produtoSimp;
	float preco_prod, iva_prod, desc_receita, precoVenda;
	unsigned long int cod_produto;
	bool vend_sem_rec, pode_ser_rec;
	uint quant;
	string timestamp;


	Venda * novaVenda;

	getline(ficheiro, linha);
	if (linha != "") {

		precoVenda = stof(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		timestamp = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nomeFarmacia = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		clienteNIF = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nomeCliente = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		distritoCliente = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		idEmpregado = stoi(linha.substr(0, linha.find_first_of('\\')));
		linha = linha.substr(linha.find_first_of('\\') + 1);
		nomeEmpregado = linha.substr(0, linha.find_first_of('\\'));
		linha = linha.substr(linha.find_first_of('\\'));

		novaVenda = new Venda(clienteNIF, nomeCliente, distritoCliente, idEmpregado, nomeEmpregado, nomeFarmacia, timestamp);
		novaVenda->setPreco(precoVenda);

		while (linha != "!" && linha != "\\") {
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
				novaVenda->addProduto(new Produto(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod), quant, false, true);
			}
			else {
				iva_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				vend_sem_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				pode_ser_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				desc_receita = stof(produtoSimp);

				novaVenda->addProduto(new Medicamento(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod, vend_sem_rec, pode_ser_rec, desc_receita), quant, false, true);
			}
		}

		getFarmacia(nomeFarmacia)->addVenda(novaVenda);

		try {
			getCliente(clienteNIF, nomeCliente, distritoCliente)->adicionaCompra(novaVenda);
		}
		catch (ClienteNaoExiste) {};
		

		getEmpregado(idEmpregado)->addVenda(novaVenda);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {

			precoVenda = stof(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			timestamp = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nomeFarmacia = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			clienteNIF = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nomeCliente = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			distritoCliente = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			idEmpregado = stoi(linha.substr(0, linha.find_first_of('\\')));
			linha = linha.substr(linha.find_first_of('\\') + 1);
			nomeEmpregado = linha.substr(0, linha.find_first_of('\\'));
			linha = linha.substr(linha.find_first_of('\\'));

			novaVenda = new Venda(clienteNIF, nomeCliente, distritoCliente, idEmpregado, nomeEmpregado, nomeFarmacia);
			novaVenda->setPreco(precoVenda);

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
					novaVenda->addProduto(new Produto(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod), quant, false, true);
				}
				else {
					iva_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
					produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
					vend_sem_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
					produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
					pode_ser_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
					produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
					desc_receita = stof(produtoSimp);

					novaVenda->addProduto(new Medicamento(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod, vend_sem_rec, pode_ser_rec, desc_receita), quant, false, true);
				}
			}

			getFarmacia(nomeFarmacia)->addVenda(novaVenda);

			try {
				getCliente(clienteNIF, nomeCliente, distritoCliente)->adicionaCompra(novaVenda);
			}
			catch (ClienteNaoExiste) {};

			getEmpregado(idEmpregado)->addVenda(novaVenda);
		}
	}
}

void Cadeia::carregarFornecedores(ifstream & ficheiro)
{

	string linha;

	getline(ficheiro, linha);
	if (linha != "") {
		Fornecedor * fornecedor = new Fornecedor(linha);
		fornecedores.push_back(fornecedor);
	}

	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		if (linha != "") {
			Fornecedor * fornecedor = new Fornecedor(linha);
			fornecedores.push_back(fornecedor);
		}
	}
}

void Cadeia::atribuiFornecedores()
{
	for (size_t i = 0; i < this->farmacias.size(); i++) {

		Farmacia* fAtual = this->farmacias.at(i);
		string fornecedores = fAtual->getFornecedoresStr();

		while (fornecedores != "") {

			string nomeFornecedor = fornecedores.substr(0, fornecedores.find_first_of(','));
			fAtual->addFornecedor(this->getFornecedor(nomeFornecedor));
			fornecedores = fornecedores.substr(fornecedores.find_first_of(',') + 1);

		}
		vector<Fornecedor*> forn = fAtual->getFornecedores();
		sort(forn.begin(), forn.end(), fornecedor_SortFunc_Nome_Crescente);
	}
}

void Cadeia::despedirEmpregado(long int nifEmp) {

	Empregado* tmpEmp = new Empregado(nifEmp);


	empregadoHashTable::const_iterator it = empregados.find(tmpEmp);


	if (it == empregados.end())  throw EmpregadoNaoExiste("O empregado com o nif " + to_string(nifEmp) + " nao existe.");

	tmpEmp = *it;
	empregados.erase(it);

	for (size_t i = 0; i < farmacias.size(); i++) {

		if (tmpEmp->getNomeFarmacia() == farmacias.at(i)->getNome()) {

			farmacias.at(i)->despedirEmpregado(tmpEmp);
		}
	}

	tmpEmp->despedir();

	empregados.insert(tmpEmp);
}

void Cadeia::recontratarEmpregado(long int nifEmp, string farmNome, string cargo, uint sal)
{
	Empregado* tmpEmp = new Empregado(nifEmp);


	empregadoHashTable::const_iterator it = empregados.find(tmpEmp);


	if (it == empregados.end())  throw EmpregadoNaoExiste("O empregado com o nif " + to_string(nifEmp) + " nao existe.");

	tmpEmp = *it;
	empregados.erase(it);

	for (size_t i = 0; i < farmacias.size(); i++) {

		if (farmNome == farmacias.at(i)->getNome()) {

			tmpEmp->recontratar(farmNome, cargo, sal);

			farmacias.at(i)->addEmpregado(tmpEmp);
			break;
		}	

		if (i == farmacias.size() - 1) {
			empregados.insert(tmpEmp);
			throw FarmaciaNaoExiste("Nao existe nenhuma farmacia com o nome " + farmNome + ". ");
		}
	}

	empregados.insert(tmpEmp);
}



