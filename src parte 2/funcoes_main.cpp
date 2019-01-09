#include "funcoes_main.h"

void showMenuInicial() {
	cout << "MENU INICIAL" << endl << endl;;

	cout << "1 - Criar nova Cadeia de Farmacias" << endl;
	cout << "2 - Carregar Cadeia de Farmacias" << endl;
	cout << "0 - Sair da aplicacao" << endl;
}

void showMenuPrincipal() {
	cout << endl << "MENU PRINCIPAL" << endl << endl;
	cout << "1 - Gerir Farmacias" << endl;
	cout << "2 - Gerir Clientes" << endl;
	cout << "3 - Gerir Empregados" << endl;
	cout << "4 - Gerir Fornecedores" << endl;
	cout << "5 - Realizar Venda" << endl;
	cout << "0 - Sair da aplicacao" << endl;
}

int getInputNumber(int limInf, int limSup, bool showLimSup)
{
	int number;

	if (!(cin >> number) || number < limInf || number > limSup)
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		if (showLimSup)
			throw OpcaoInvalida("A opcao introduzida deve ser um numero entre " + to_string(limInf) + " e " + to_string(limSup) + ".");
		else
			throw OpcaoInvalida("A opcao introduzida deve ser um numero superior a " + to_string(limInf) + ".");
	}

	cin.ignore(MAX_STREAM_SIZE, '\n'); // ignora o que sobra no input buffer para nao entrar em conflito com a funcao getline

	return number;
}

Morada user_getMorada() {

	string morada_endereco, morada_cpostal, morada_localidade;
	Morada morada;
	bool inputValido = false;

	cout << "Morada: " << endl;
	morada_endereco = getInputString("-Endereco:  ", "Endereco invalido");

	// validar input do codigo postal
	while (!inputValido) {

		morada_cpostal = getInputString("-Codigo postal: ", "Codigo postal invalido");

		if (codigoPostalValido(morada_cpostal)) {
			inputValido = true;
		}
		else cout << "Codigo postal invalido!" << endl;
	}


	morada_localidade = getInputString("-Localidade: ", "Localidade invalida");

	return Morada(morada_endereco, morada_cpostal, morada_localidade);
}

Empregado* user_getEmpregado(Cadeia& cadeia, pair<bool, string> newFOverride) {

	string nome;
	long int NIF;
	Data dataNascimento, dataContratacao;
	Morada morada;
	int salario;
	string farmaciaNome;
	string cargo;


	nome = getInputString("Nome: ", "Nome invalido.");

	cout << "NIF: ";

	// validar input do NIF
	while (!(cin >> NIF) || (NIF < 100000000 || NIF > 999999999))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "NIF invalido." << endl << endl;
		cout << "NIF: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');


	cout << "Salario: ";

	// validar input do salario
	while (!(cin >> salario) || salario < 0)
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}
		cout << "Salario invalido." << endl << endl;
		cout << "Salario: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');

	if (!newFOverride.first) {
		while (true) {

			farmaciaNome = getInputString("Farmacia: ", "Nome de farmacia invalido.");

			try
			{
				cadeia.getFarmacia(farmaciaNome);
			}
			catch (FarmaciaNaoExiste& f)
			{
				cout << f.getInfo() << endl;
				continue;
			}
			break;
		}

		cargo = getInputString("Cargo: ", "Cargo invalido.");
	}
	else {

		cargo = "gerente";
		farmaciaNome = newFOverride.second;

	}


	morada = user_getMorada();
	dataNascimento = user_getData("Data de nascimento (DD/MM/AAAA): ", "Data de nascimento invalida.", true);

	dataContratacao = user_getData("Data de contracao (DD/MM/AAAA): ", "Data invalida.", false);

	Empregado* newEmp = new Empregado((long unsigned int) NIF, nome,  dataNascimento, morada, (uint)salario, farmaciaNome, cargo, dataContratacao);

	return newEmp;
}

Cliente* user_getCliente()
{
	string nome;
	uint NIF;
	Data dataNascimento;
	Morada morada;
	string distrito;

	nome = getInputString("Nome: ", "Nome invalido.");

	cout << "NIF: ";

	// validar input do NIF
	while (!(cin >> NIF))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "NIF: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');

	cout << "Distrito: ";
	getline(cin, distrito);

	morada = user_getMorada();
	dataNascimento = user_getData("Data de nascimento (DD/MM/AAAA): ", "Data de nascimento invalida.", true);

	Cliente* newCliente = new Cliente(nome, NIF, dataNascimento, morada, distrito);

	return newCliente;
}

Produto* user_getProduto(Farmacia& farmacia) {

	string nome, desc;
	float preco;
	int iva;
	long int codigo;
	int opcao;
	bool vendidoSemRec;
	bool podeSerRec;
	int descComReceita;
	Produto* produto;

	cout << "Categoria: " << endl;
	cout << "1 - Produto generico" << endl;
	cout << "2 - Medicamento" << endl;

	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Opcao: ";
			opcao = getInputNumber(0, 9);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	cout << endl << "Codigo: ";

	// validar input do codigo
	while (!(cin >> codigo))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "Codigo: ";
	}
	cin.ignore(MAX_STREAM_SIZE, '\n');

	if (farmacia.existeProduto(codigo)) {
		throw ProdutoRepetido("O produto com o codigo " + to_string(codigo) + " ja existe.");
	}

	nome = getInputString("Nome: ", "Nome invalido.");
	desc = getInputString("Descricao: ", "Descricao invalida.");

	cout << "Preco: ";

	// validar input do codigo
	while (!(cin >> preco))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "Preco: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');

	opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "IVA (%): ";
			iva = getInputNumber(0, 100);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	if (opcao == 1) {
		produto = new Produto(codigo, nome, desc, preco, (float)iva / 100);
	}
	else {
		opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Pode ser receitado (1 - sim, 0 - nao): ";
				podeSerRec = getInputNumber(0, 1);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Pode ser vendido sem receita medica (1 - sim, 0 - nao): ";
				vendidoSemRec = getInputNumber(0, 1);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		if (podeSerRec) {
			opcaoInvalida = true;
			while (opcaoInvalida) {

				try {
					cout << "Desconto com receita medica (%): ";
					descComReceita = getInputNumber(0, 100);
				}
				catch (OpcaoInvalida& opIn) {
					cout << opIn.getInfo() << endl;
					continue;
				}

				opcaoInvalida = false;
			}
		}
		else
			descComReceita = 0;

		produto = new Medicamento(codigo, nome, desc, preco, (float)iva / 100, vendidoSemRec, podeSerRec, (float)descComReceita / 100);
	}

	return produto;
}


Fornecedor* user_getFornecedor() {

	string nome;
	Morada morada;
	TipoFornecedor tipo;

	nome = getInputString("Nome: ", "Nome invalido.");
	morada = user_getMorada();

	string tipoStr;

	cout << "-Tipo de fornecedor (medicamentos ou produtos): ";
	getline(cin, tipoStr);

	while (cin.eof() || (tipoStr != "medicamentos" && tipoStr != "produtos"))
	{
		if (cin.eof())
			cin.clear();

		cout << "ERRO:Tipo invalido." << endl << endl;
		cout << "-Tipo de fornecedor (medicamentos ou produtos):";
		getline(cin, tipoStr);
	}

	(tipoStr == "medicamentos") ? (tipo = medicamentos) : (tipo = produtos);


	Fornecedor* newFr = new Fornecedor(nome, morada, tipo);

	return newFr;

}

Data user_getData(string pergunta, string respErro, bool nasc) {


	if (!nasc) {

		cout << pergunta;

		int opcao = 0;
		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Deseja introduzir a data atual ? (0 - nao, 1 - sim) ";
				opcao = getInputNumber(0, 1);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		if (opcao) {
			return Data();
		}
	}

	Data data;
	string dataStr;
	bool inputValido = false;


	while (!inputValido) {

		dataStr = getInputString(pergunta, respErro);

		try {
			data = Data(dataStr);
		}
		catch (DataInvalida& e) {
			cout << e.getInfo() << endl;
			continue;
		}

		inputValido = true;
	}


	return data;
}

string getInputString(string msg, string msgErr)
{
	string name;

	cout << msg;
	getline(cin, name);

	while (cin.eof())
	{
		if (cin.eof())
			cin.clear();
		else
			cin.ignore(MAX_STREAM_SIZE, '\n');

		cout << msgErr << endl << endl;
		cout << msg;
		getline(cin, name);
	}

	return name;
}

void realizarVenda(Cadeia & cadeia)
{
	string farmaciaNome, nomeEmpregado, nomeCliente;
	bool farmaciaValida = false;
	Farmacia* farmacia = NULL;
	Empregado* empregado;
	Cliente* cliente;
	uint ID, NIF;
	string distrito;


	cout << endl << "REALIZAR VENDA" << endl << endl;

	if (cadeia.getNumFarmacias() == 0) {

		cout << "Adicione uma farmacia antes de realizar uma venda." << endl;
		return;
	}



	// GET FARMACIA
	do {

		cout << "Em que farmacia pretende realizar a venda: ";
		getline(cin, farmaciaNome);

		try
		{
			farmacia = cadeia.getFarmacia(farmaciaNome);
		}
		catch (FarmaciaNaoExiste& f)
		{
			cout << f.getInfo() << endl << endl;
			continue;
		}

		farmaciaValida = true;

	} while (!farmaciaValida);

	// GET EMPREGADO
	cout << "Que empregado realiza a venda: ";
	getline(cin, nomeEmpregado);

	// get empregados com o nome dado
	vector<Empregado*> empregados_busca = farmacia->getEmpregados(nomeEmpregado);

	// imprime empregados encontrados
	if (empregados_busca.size() == 1) {
		for (size_t i = 0; i < empregados_busca.size(); i++) {

			cout << "ID: " << empregados_busca.at(i)->getID()
				<< "| Nome: " << empregados_busca.at(i)->getNome()
				<< "| Cargo: " << empregados_busca.at(i)->getCargo() << endl;


		}
	}


	cout << endl;

	// se nao encontrar nenhum empregado com o nome dado na farmacia, retorna
	if (empregados_busca.size() == 0) {

		cout << "Nao foi encontrado nenhum empregado com esse nome na Farmacia " << farmaciaNome << "." << endl;
		return;
	}

	// se so existir um empregado com o nome dado usar esse empregado na venda
	// caso contrario, pedir o ID do empregado 
	if (empregados_busca.size() != 1) {

		// get ID da pessoa
		cout << "ID: ";

		while (!(cin >> ID))
		{
			if (cin.eof())
			{
				cin.clear();
			}
			else
			{
				cin.clear();
				cin.ignore(MAX_STREAM_SIZE, '\n');
			}

			cout << "ID: ";
		}

		cin.ignore(MAX_STREAM_SIZE, '\n');

		// verificar se o ID dado pertence a alguma das pessoas com o nome dado
		for (size_t i = 0; i < empregados_busca.size(); i++) {

			if (empregados_busca.at(i)->getID() == ID) {
				break;
			}
			if (i == empregados_busca.size() - 1) {

				cout << "Nao existe nenhum empregado com esse par Nome/ID." << endl;
				return;

			}
		}


	}
	else {

		ID = empregados_busca.at(0)->getID();
	}

	empregado = cadeia.getEmpregado(ID);

	// GET CLIENTE

	//get nome do cliente
	cout << "Nome do cliente (se for um cliente novo deixe em branco): ";
	getline(cin, nomeCliente);

	if (nomeCliente.size() != 0) {

		//Get distrito
		cout << "Distrito de residencia do cliente: ";
		getline(cin, distrito);

		//Get NIF
		cout << "NIF do cliente: ";

		// validar input do NIF
		while (!(cin >> NIF))
		{
			if (cin.eof())
			{
				cin.clear();
			}
			else
			{
				cin.clear();
				cin.ignore(MAX_STREAM_SIZE, '\n');
			}

			cout << "NIF: ";
		}

		try {
			cliente = cadeia.getCliente(NIF, nomeCliente, distrito);
		}
		catch (ClienteNaoExiste &c1) {
			cout << c1.getInfo() << "Deseja adicionar um cliente novo (S/N)? ";
			string userChoice;

			getline(cin, userChoice);
			cout << endl;
			toUpper(userChoice);

			if ((userChoice == "S") || (userChoice == "SIM")) {
				cliente = user_getCliente();
			}
			else if ((userChoice == "N") || (userChoice == "NAO")) {

				return;
			}
			else
				return;


		}
	}
	else {

		cliente = user_getCliente();
	}

	if (cadeia.addCliente(cliente))
		cout << "Cliente adicionado com sucesso!" << endl;
	else
		cout << "Cliente ja existe." << endl;

	//criar uma nova venda
	Venda* venda = new Venda(cliente->getNIF(), cliente->getNome(), cliente->getDistrito(), empregado->getID(), empregado->getNome(), farmacia->getNome());

	//GET PRODUTOS

	user_getProdutos(farmacia, venda);
	cout << "Preco final: " << venda->getCusto() << " euros" << endl;
	cout << "Finalizar venda(S/N)? ";
	string userChoice;
	getline(cin, userChoice);
	cout << endl;
	toUpper(userChoice);

	if ((userChoice == "S") || (userChoice == "SIM")) {

		// adicionar a venda a farmacia
		farmacia->addVenda(venda);

		map<Produto*, uint>tempProd_map;
		tempProd_map = venda->getProdutos();
		map<Produto*, uint>::iterator it = tempProd_map.begin();
		map<Produto*, uint>::iterator ite = tempProd_map.end();

		// atualizar as quantidades do stock da farmacia
		while (it != ite) {
			farmacia->removeQuantidade(it->first->getCodigo(), it->second);
			it++;
		}
		cout << endl << "Venda efetuada." << endl;

		try
		{
			cadeia.getCliente(cliente->getNIF(), cliente->getNome(), cliente->getDistrito());
		}
		catch (const ClienteNaoExiste &c1)
		{
			cadeia.addCliente(cliente);
		}

		cliente->adicionaCompra(venda);
		empregado->addVenda(venda);

	}
	else if ((userChoice == "N") || (userChoice == "NAO")) {

		delete cliente;
		delete venda;
		return;
	}

}

void user_addReceita(Farmacia* farmacia, Venda* venda) {

	string nomeReceita;
	ifstream ficheiro;
	cout << "Numero da receita: ";
	getline(cin, nomeReceita);
	ficheiro.open(nomeReceita + ".txt");

	if (!ficheiro.is_open()) {

		cout << "Receita nao encontrada." << endl;
		return;
	}

	string tempString;
	string nomePaciente;
	string nomeMedico;
	string receitaNumStr;
	string nifPacienteStr;
	uint prodId, quantidade;
	getline(ficheiro, tempString);
	getline(ficheiro, tempString);
	getline(ficheiro, tempString);
	receitaNumStr = tempString.substr(tempString.find_first_of(" ") + 1);
	getline(ficheiro, tempString);
	nomePaciente = tempString.substr(tempString.find_first_of(" ") + 1);
	getline(ficheiro, tempString);
	nifPacienteStr = tempString.substr(tempString.find_first_of(" ") + 1);
	getline(ficheiro, tempString);
	getline(ficheiro, tempString);
	nomeMedico = tempString.substr(tempString.find_first_of(" ") + 1);
	getline(ficheiro, tempString);
	getline(ficheiro, tempString);
	getline(ficheiro, tempString);
	getline(ficheiro, tempString);

	if (venda->getNomeCliente() != nomePaciente) {

		cout << "Esta receita nao e sua." << endl;
		return;
	}


	Receita receita = Receita(stoi(receitaNumStr), nomePaciente, nomeMedico, stoi(nifPacienteStr));

	getline(ficheiro, tempString);
	while (tempString != "--") {

		istringstream iss(tempString);
		iss >> prodId;
		iss.ignore();
		iss.ignore();
		iss >> quantidade;
		pair<Produto*, uint>produtoTemp = farmacia->getProduto(prodId);

		if (produtoTemp.first == NULL) {
			cout << "A farmacia nao consegue satisfazer a receita." << endl;
			return;
		}
		uint quantExistente;
		if (venda->getProd(produtoTemp.first->getCodigo()).first == NULL)
			quantExistente = 0;
		else
			quantExistente = venda->getProd(produtoTemp.first->getCodigo()).second;

		if (produtoTemp.second - quantExistente < quantidade) {
			cout << "A farmacia nao consegue satisfazer a receita." << endl;
			return;
		}

		receita.addProduto(produtoTemp.first, quantidade);
		getline(ficheiro, tempString);
	}


	ficheiro.close();

	venda->addReceita(receita);

	return;
}

void user_getProdutos(Farmacia* farmacia, Venda* venda) {

	int opcao, quantExistente;
	string nomeProduto;
	pair<Produto*, uint> produtoTemp;
	map<Produto*, uint>::iterator it, ite;
	map<Produto*, uint>::const_iterator cit, cite;
	uint quantidade;
	map<Produto*, uint> tempProd_map;
	Medicamento* mediTemp;

	do {
		cout << endl;
		cout << "PRODUTOS: " << endl << endl;
		cout << "1- Adicionar produto" << endl;
		cout << "2- Adicionar medicamento nao sujeito a receita " << endl;
		cout << "3- Adicionar receita" << endl;
		cout << "4- Ver lista da compra" << endl;
		cout << "5- Remover da lista da compra" << endl;
		cout << "0- Sair" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 5);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:

			cout << endl;
			cout << "-Adicionar produto- " << endl << endl;

			cout << "Nome do produto: ";
			getline(cin, nomeProduto);

			try
			{
				produtoTemp = farmacia->getProduto(nomeProduto);
			}
			catch (ProdutoNaoExiste& p1)
			{
				cout << p1.getInfo() << endl;
				break;
			}

			mediTemp = dynamic_cast<Medicamento*> (produtoTemp.first);

			if (mediTemp != NULL) {
				cout << "O produto " << produtoTemp.first->getNome() << " e um medicamento." << endl;
				break;
			}


			cout << "Produto: " << produtoTemp.first->getNome() << " Quantidade disponivel: " << produtoTemp.second << " Preco: " << produtoTemp.first->getPreco() << endl;


			opcaoInvalida = true;
			while (opcaoInvalida) {

				try {

					if (venda->getProd(produtoTemp.first->getCodigo()).first == NULL)
						quantExistente = 0;
					else
						quantExistente = venda->getProd(produtoTemp.first->getCodigo()).second;

					cout << "Quantidade: ";
					quantidade = getInputNumber(1, produtoTemp.second - quantExistente);
				}
				catch (OpcaoInvalida& opIn) {
					cout << opIn.getInfo() << endl;
					continue;
				}

				opcaoInvalida = false;
			}

			cout << endl;

			produtoTemp.second = quantidade;
			venda->addProduto(produtoTemp.first, produtoTemp.second);



			cout << "Produto adicionado a compra." << endl;
			break;
		case 2:

			cout << endl;
			cout << "-Adicionar medicamento- " << endl << endl;

			cout << "Nome do medicamento: ";
			getline(cin, nomeProduto);

			try
			{
				produtoTemp = farmacia->getProduto(nomeProduto);
			}
			catch (ProdutoNaoExiste& p1)
			{
				cout << p1.getInfo() << endl;
				break;
			}

			mediTemp = dynamic_cast<Medicamento*> (produtoTemp.first);

			if (mediTemp == NULL) {
				cout << "O produto " << produtoTemp.first->getNome() << " nao e um medicamento." << endl;
				break;
			}

			if (!mediTemp->vendidoSemReceita()) {

				cout << "O medicamento " << produtoTemp.first->getNome() << "  e um sujeito a receita." << endl;
				break;
			}

			if (venda->getProd(produtoTemp.first->getCodigo()).first == NULL)
				quantExistente = 0;
			else
				quantExistente = venda->getProd(produtoTemp.first->getCodigo()).second;

			cout << "Medicamento: " << produtoTemp.first->getNome() << " Quantidade disponivel: " << produtoTemp.second - quantExistente << " Preco: " << produtoTemp.first->getPreco() << endl;

			opcaoInvalida = true;
			while (opcaoInvalida) {

				try {
					cout << "Quantidade: ";
					quantidade = getInputNumber(1, produtoTemp.second - quantExistente);
				}
				catch (OpcaoInvalida& opIn) {
					cout << opIn.getInfo() << endl;
					continue;
				}

				opcaoInvalida = false;
			}
			cout << endl;

			produtoTemp.second = quantidade;
			venda->addProduto(produtoTemp.first, produtoTemp.second);

			cout << "Medicamento adicionado a compra." << endl;
			break;

		case 3:

			cout << endl;
			cout << "-Adicionar Receita- " << endl << endl;
			user_addReceita(farmacia, venda);

			break;
		case 4:

			cout << endl;
			cout << "-Lista de compra- " << endl << endl;

			tempProd_map = venda->getProdutos();
			it = tempProd_map.begin();
			ite = tempProd_map.end();

			while (it != ite) {

				cout << "Nome: " << setw(10) << it->first->getNome() << " | Quantidade: " << it->second << endl;
				it++;
			}
			cout << "TOTAL: " << venda->getCusto() << endl << endl;

			break;
		case 5:

			cout << endl;
			cout << "-Remover produto- " << endl << endl;

			tempProd_map = venda->getProdutos();
			it = tempProd_map.begin();
			ite = tempProd_map.end();

			while (it != ite) {

				cout << "Nome: " << setw(10) << it->first->getNome() << " | Quantidade: " << it->second << endl;
				it++;
			}
			cout << endl;


			opcaoInvalida = true;
			while (opcaoInvalida) {
				cout << endl << "Nome do medicamento: ";
				getline(cin, nomeProduto);

				if (venda->getProd(nomeProduto).first == NULL)
					continue;
				else
					venda->remProduto(nomeProduto);

				opcaoInvalida = false;
			}

			cout << "Produto removido." << endl;

			break;
		case 0:

			break;
		}


	} while (opcao != 0);


}

////////////////
//  CLIENTES  //
////////////////

void menuClientes(Cadeia& cadeia)
{
	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR CLIENTES" << endl << endl;
		cout << "1 - Resumo Clientes" << endl;
		cout << "2 - Gerir cliente" << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 2);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			resumoClientes(cadeia);
			break;
		case 2:
			gerirCliente(cadeia);
			break;
		case 0:
			continuarNesteMenu = false;
			break;
		}
	}
}

void resumoClientes(Cadeia& cadeia)
{
	cout << endl << "RESUMO CLIENTES" << endl << endl;

	int opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - Distrito (crescente)" << endl;
	cout << "1 - Distrito (decrescente)" << endl;
	cout << "2 - idade (crescente)" << endl;
	cout << "3 - idade (decrescente)" << endl;
	cout << "4 - nome (crescente)" << endl;
	cout << "5 - nome (decrescente)" << endl;
	cout << "6 - NIF (crescente)" << endl;
	cout << "7 - NIF (decrescente)" << endl;
	cout << "8 - numero de compras (crescente)" << endl;
	cout << "9 - numero de compras (decrescente)" << endl;

	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Opcao: ";
			opcao = getInputNumber(0, 9);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	cadeia.sortClientes((ord_clientes)opcao);
	cadeia.mostrarClientes();
}

void cliente_consultarCompras(Cliente* c)
{
	cout << endl << "CONSULTAR COMPRAS" << endl;

	c->mostrarCompras();

}

void gerirCliente(Cadeia & cadeia)
{
	string nomeCliente, distrito;
	Morada morada;
	Cliente* cliente;
	uint NIF;

	cout << endl << "GERIR CLIENTE" << endl << endl;

	//get nome do cliente a remover
	cout << "Nome do cliente: ";
	getline(cin, nomeCliente);

	//Get distrito
	cout << "Distrito de residencia atual do cliente: ";
	getline(cin, distrito);

	//Get NIF
	cout << "NIF do cliente: ";

	// validar input do NIF
	while (!(cin >> NIF))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "NIF: ";
	}

	try {
		cliente = cadeia.getCliente(NIF, nomeCliente, distrito);
	}
	catch (ClienteNaoExiste & c1) {
		cout << c1.getInfo() << endl;
		return;
	}

	int opcao = -1;
	bool opcaoInvalida = true;

	do {

		cout << endl << "O que pretende em relacao ao cliente  " << cliente->getNome() << " ?" << endl;
		cout << "1 - Alterar Distrito" << endl;
		cout << "2 - Alterar Morada" << endl;
		cout << "3 - Consultar Compras" << endl;
		cout << "4 - Remover" << endl;
		cout << "0 - Terminar" << endl << endl;

		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 4);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}
		opcaoInvalida = true;
		cout << endl;

		switch (opcao) {

		case 1:

			cout << "Novo distrito de residencia: ";
			getline(cin, distrito);

			cliente->setDistrito(distrito);
			cout << "Alterado." << endl;

			break;
		case 2:

			morada = user_getMorada();
			cliente->setMorada(morada);
			cout << "Alterado." << endl;

			break;
		case 3:
			cliente_consultarCompras(cliente);
			break;
		case 4:
			cadeia.removeCliente(cliente);
			cout << "Removido." << endl;

			return;
		case 0:
			break;
		}

	} while (opcao != 0);

}


//////////////////
//  EMPREGADOS  //
//////////////////

void menuEmpregados(Cadeia& cadeia)
{
	bool continuarNesteMenu = true;

	if (cadeia.getNumFarmacias() == 0) {

		cout << "Adicione uma farmacia antes de gerir empregados." << endl;
		return;

	}


	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR EMPREGADOS" << endl << endl;
		cout << "1 - Resumo empregados" << endl;
		cout << "2 - Gerir empregado" << endl;
		cout << "3 - Adicionar empregado" << endl;
		cout << "4 - Despedir empregado" << endl;
		cout << "5 - Consultar empregados  s/ contrato" << endl;
		cout << "6 - Recontratar empregado" << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 5);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			resumoEmpregados(cadeia);
			break;
		case 2:
			gerirEmpregado(cadeia);
			break;
		case 3:
			adicionarEmpregado(cadeia);
			break;
		case 4:
			despedirEmpregado(cadeia);
			break;
		case 5:
			consultarEmpregadosSemContrato(cadeia);
			break;
		case 6:
			recontratarEmpregado(cadeia);
			break;					
		case 0:
			continuarNesteMenu = false;
			break;
		}
	}
}

void resumoEmpregados(Cadeia& cadeia)
{
	cout << endl << "RESUMO EMPREGADOS" << endl << endl;


	if (cadeia.getNumEmpregados() == 0) {
		cout << "A cadeia \"" << cadeia.getNome() << "\" ainda nao tem empregados." << endl;
		return;
	}

	int opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - ID (crescente)" << endl;
	cout << "1 - ID (decrescente)" << endl;
	cout << "2 - idade (crescente)" << endl;
	cout << "3 - idade (decrescente)" << endl;
	cout << "4 - nome (crescente)" << endl;
	cout << "5 - nome (decrescente)" << endl;
	cout << "6 - NIF (crescente)" << endl;
	cout << "7 - NIF (decrescente)" << endl;
	cout << "8 - numero de vendas (crescente)" << endl;
	cout << "9 - numero de vendas (decrescente)" << endl;
	cout << "10 - salario (crescente)" << endl;
	cout << "11 - salario (decrescente)" << endl;
	cout << "12 - meses de ligacao (crescente)" << endl;
	cout << "13 - meses de ligacao (decrescente)" << endl;


	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Opcao: ";
			opcao = getInputNumber(0, 13);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	cout << endl << endl;

	vector<Empregado*> emps;
	cadeia.getEmpregadosVec(emps);
	sortEmpregados(emps, (ord_empregados) opcao);

	for (size_t i = 0; i < emps.size(); i++) {
		emps.at(i)->print(cout);
	}
}

void adicionarEmpregado(Cadeia& cadeia)
{
	cout << endl << "ADICIONAR EMPREGADO" << endl << endl;

	Empregado* newEmp = user_getEmpregado(cadeia);

	if (cadeia.addEmpregado(newEmp)) {

		cout << "Empregado adicionado." << endl;
	}
	else {
		Empregado::decID();
		cout << "O empregado com o nif " << newEmp->getNIF() << " ja existe." << endl;
	}
}

void despedirEmpregado(Cadeia& cadeia)
{
	string nomeEmpregado;
	uint NIF;

	cout << "DESPEDIR EMPREGADO" << endl << endl;
	

	cout << "NIF do empregado a despedir: ";

	while (!(cin >> NIF) || (NIF < 100000000 || NIF > 999999999))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "NIF invalido." << endl << endl;
		cout << "NIF do empregado a despedir: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');


	// remover empregado
	try {
		cadeia.despedirEmpregado(NIF);
		cout << "Empregado despedido" << endl;
	}
	catch (EmpregadoNaoExiste &c1) {
		cout << c1.getInfo() << endl;
	}
}

void consultarEmpregadosSemContrato(Cadeia& cadeia) {

	cout << endl << "RESUMO EMPREGADOS" << endl << endl;

	vector<Empregado*> emps;
	cadeia.getEmpregadosVec(emps);

	if (emps.size() == 0) {
		cout << "A cadeia \"" << cadeia.getNome() << "\" nao tem empregados sem contrato." << endl;
		return;
	}

	int opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - ID (crescente)" << endl;
	cout << "1 - ID (decrescente)" << endl;
	cout << "2 - idade (crescente)" << endl;
	cout << "3 - idade (decrescente)" << endl;
	cout << "4 - nome (crescente)" << endl;
	cout << "5 - nome (decrescente)" << endl;
	cout << "6 - NIF (crescente)" << endl;
	cout << "7 - NIF (decrescente)" << endl;
	cout << "8 - numero de vendas (crescente)" << endl;
	cout << "9 - numero de vendas (decrescente)" << endl;
	cout << "10 - salario (crescente)" << endl;
	cout << "11 - salario (decrescente)" << endl;
	cout << "12 - meses de ligacao (crescente)" << endl;
	cout << "13 - meses de ligacao (decrescente)" << endl;


	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Opcao: ";
			opcao = getInputNumber(0, 13);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	cout << endl << endl;

	sortEmpregados(emps, (ord_empregados)opcao);

	for (size_t i = 0; i < emps.size(); i++) {
		emps.at(i)->print(cout);
	}
}

void recontratarEmpregado(Cadeia& cadeia) {

	cout << endl << "RECONTRATAR EMPREGADO" << endl << endl;

	long int NIF;
	string farmaciaNome;
	string cargo;
	int salario;

	


	cout << "NIF: ";

	// validar input do NIF
	while (!(cin >> NIF) || (NIF < 100000000 || NIF > 999999999))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}

		cout << "NIF invalido." << endl << endl;
		cout << "NIF: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');

	if (!cadeia.empregadoSemContrato(NIF)) {
		cout << "Nao existe um empregado sem contrato com esse nome." << endl;
	}

	

	while (true) {

		farmaciaNome = getInputString("Farmacia: ", "Nome de farmacia invalido.");

		try
		{
			cadeia.getFarmacia(farmaciaNome);
		}
		catch (FarmaciaNaoExiste& f)
		{
			cout << f.getInfo() << endl;
			continue;
		}
		break;
	}

	cargo = getInputString("Cargo: ", "Cargo invalido.");


	cout << "Salario: ";

	// validar input do salario
	while (!(cin >> salario) || salario < 0)
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}
		cout << "Salario invalido." << endl << endl;
		cout << "Salario: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');


	cadeia.recontratarEmpregado(NIF, farmaciaNome, cargo, salario);

}

void gerirEmpregado(Cadeia & cadeia)
{
	string nomeEmpregado;
	uint ID;
	uint salario;
	string cargo, nomeFarmacia;
	Farmacia* farmaciaTemp = NULL;
	Morada morada;
	bool farmaciaValida = false;


	cout << "GERIR EMPREGADO" << endl << endl;

	//get nome do empregado a remover
	cout << "Nome do empregado: ";
	getline(cin, nomeEmpregado);

	// get empregados com o nome dado
	vector<Empregado*> empregados_busca = cadeia.getEmpregados(nomeEmpregado);

	// imprime empregados encontrados
	for (size_t i = 0; i < empregados_busca.size(); i++) {

		cout << "ID: " << empregados_busca.at(i)->getID()
			<< "| Nome: " << empregados_busca.at(i)->getNome()
			<< "| Farmacia: " << empregados_busca.at(i)->getNomeFarmacia()
			<< "| Cargo: " << empregados_busca.at(i)->getCargo()
			<< "| Salario: " << empregados_busca.at(i)->getSalario() << endl;
	}

	cout << endl;

	// se nao encontrar nenhum empregado com o nome dado, retorna
	if (empregados_busca.size() == 0) {

		cout << "Nao foi encontrado nenhum empregado com esse nome." << endl;
		return;
	}

	if (empregados_busca.size() != 1) {

		// get ID da pessoa
		cout << "ID: ";

		while (!(cin >> ID))
		{
			if (cin.eof())
			{
				cin.clear();
			}
			else
			{
				cin.clear();
				cin.ignore(MAX_STREAM_SIZE, '\n');
			}

			cout << "ID: ";
		}

		cin.ignore(MAX_STREAM_SIZE, '\n');

		// verificar se o ID dado pertence a alguma das pessoas com o nome dado
		for (size_t i = 0; i < empregados_busca.size(); i++) {

			if (empregados_busca.at(i)->getID() == ID) {
				break;
			}
			if (i == empregados_busca.size() - 1) {

				cout << "Nao existe nenhum empregado com esse par Nome/ID." << endl;
				return;

			}
		}

	}
	else {

		ID = empregados_busca.at(0)->getID();
	}


	int opcao = -1;
	bool opcaoInvalida = true;

	do {

		cout << endl << "O que pretende alterar no empregado " << cadeia.getEmpregado(ID)->getNome() << " ?" << endl;
		cout << "1- Salario" << endl;
		cout << "2- Cargo" << endl;
		cout << "3- Morada" << endl;
		cout << "4- Farmacia" << endl;
		cout << "5- Consultar vendas" << endl;
		cout << "0- Terminar" << endl << endl;

		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 5);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}
		opcaoInvalida = true;
		cout << endl;

		switch (opcao) {
		case 1:


			cout << "Novo Salario: ";
			while (!(cin >> salario))
			{
				if (cin.eof())
				{
					cin.clear();
				}
				else
				{
					cin.clear();
					cin.ignore(MAX_STREAM_SIZE, '\n');
				}

				cout << "Novo Salario: ";
			}

			cin.ignore(MAX_STREAM_SIZE, '\n');

			cadeia.getEmpregado(ID)->setSalario(salario);

			cout << "Alterado." << endl;


			break;
		case 2:

			if (cadeia.getEmpregado(ID)->getCargo() == "gerente") {

				cout << "Nao pode alterar o cargo de um gerente." << endl;
				break;
			}


			do {
				cout << "Novo cargo: ";
				getline(cin, cargo);

				if (cargo == "gerente") {

					cout << "Nao pode definir um novo gerente aqui." << endl;
				}

			} while (cargo == "gerente");


			cadeia.getEmpregado(ID)->setCargo(cargo);

			cout << "Alterado." << endl;

			break;
		case 3:

			morada = user_getMorada();
			cadeia.getEmpregado(ID)->setMorada(morada);
			cout << "Alterado." << endl;

			break;
		case 4:

			if (cadeia.getEmpregado(ID)->getCargo() == "gerente") {


				cout << "Nao pode alterar a farmacia de um gerente." << endl;
				break;
			}



			do {

				cout << "Nova farmacia: ";
				getline(cin, nomeFarmacia);

				try
				{
					farmaciaTemp = cadeia.getFarmacia(nomeFarmacia);
					break;
				}
				catch (FarmaciaNaoExiste& f)
				{
					cout << f.getInfo() << endl;
					continue;
				}

			} while (!farmaciaValida);
			farmaciaValida = false;

			farmaciaTemp->addEmpregado(cadeia.getEmpregado(ID));
			cadeia.getFarmacia(cadeia.getEmpregado(ID)->getNomeFarmacia())->remEmpregado(ID);
			cadeia.getEmpregado(ID)->setFarmacia(nomeFarmacia);


			cout << "Alterado." << endl;




			break;
		case 5:
			cadeia.getEmpregado(ID)->mostrarVendas();
		case 0:
			break;
		}

	} while (opcao != 0);


	return;
}

//////////////////
// FORNECEDORES //
//////////////////

void menuFornecedores(Cadeia& cadeia) {

	bool continuarNesteMenu = true;


	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR FORNECEDORES" << endl << endl;
		cout << "1 - Resumo fornecedores" << endl;
		cout << "2 - Adicionar fornecedor" << endl;
		cout << "3 - Consultar fornecedor" << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 3);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			resumoFornecedores(cadeia);
			break;
		case 2:
			adicionarFornecedor(cadeia);
			break;
		case 3:
			consultarFornecedor(cadeia);
			break;

		case 0:
			continuarNesteMenu = false;
			break;
		}
	}
}

void resumoFornecedores(Cadeia& cadeia)
{
	cout << endl << "RESUMO FORNECEDORES" << endl << endl;

	if (cadeia.getNumFornecedores() == 0) {
		cout << "A cadeia \"" << cadeia.getNome() << "\" ainda nao tem fornecedores." << endl;
		return;
	}

	int opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - nome (crescente)" << endl;
	cout << "1 - nome (decrescente)" << endl;
	cout << "2 - numero de encomendas (crescente)" << endl;
	cout << "3 - numero de encomendas (decrescente)" << endl;
	cout << "4 - tipo (crescente)" << endl;
	cout << "5 - tipo (decrescente)" << endl;


	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Opcao: ";
			opcao = getInputNumber(0, 5);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	cout << endl << endl;

	cadeia.sortFornecedores((ord_fornece)opcao);

	cadeia.mostraFornecedores();

	cadeia.sortFornecedores(nome_cres_f);
}

void adicionarFornecedor(Cadeia& cadeia)
{
	cout << endl << "ADICIONAR FORNECEDOR" << endl << endl;

	Fornecedor* newFr = user_getFornecedor();

	if (cadeia.addFornecedor(newFr)) {

		cout << "Fornecedor adicionado." << endl;
	}
	else {
		cout << "O fornecedor com o nome " << newFr->getNome() << " ja existe." << endl;
	}
}

void consultarFornecedor(Cadeia& cadeia) {

	cout << endl;

	if (cadeia.getNumFornecedores() == 0) {

		cout << "A cadeia " << cadeia.getNome() << " ainda nao tem fornecedores." << endl;
		return;
	}

	Fornecedor * fornecedor;

	string fornecedorNome = getInputString("Nome do fornecedor que pretende consultar: ", "Nome invalido.");

	try
	{
		fornecedor = cadeia.getFornecedor(fornecedorNome);
	}
	catch (FornecedorNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}


	fornecedor->print(cout) << endl << endl;


	bool continuarNesteMenu = true;

	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "CONSULTAR FORNECEDOR" << endl << endl;
		fornecedor->print(cout) << endl;
		cout << "1 - Resumo encomendas" << endl;
		cout << "2 - Consultar encomendas por data" << endl;
		cout << "3 - Consultar encomendas por farmacia" << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 3);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			cout << endl << "Resumo das encomendas: " << endl << endl;
			fornecedor->print_encomendas_resumo(cout);
			break;
		case 2:
			fornecedor_consultarEncomendaData(*fornecedor);
			break;
		case 3:
			fornecedor_consultarEncomendaFarmacia(*fornecedor);
		case 0:
			continuarNesteMenu = false;
			break;
		}
	}

}

void fornecedor_consultarEncomendaData(Fornecedor & fornecedor)
{
	if (fornecedor.getNumEncomendas() == 0) {

		cout << "O fornecedor " << fornecedor.getNome() << " ainda nao tem encomendas." << endl;
		return;
	}


	Data dataEncomendas = user_getData( "Consultar encomendas do dia: " , "Data invalida.", false);
	vector<Encomenda> encomendas = fornecedor.getEncomendas(dataEncomendas);

	if (encomendas.empty()) {

		cout << "Nao existem encomendas nessa data." << endl;
		return;
	}

	cout << endl;
	for (int i = 0; i < encomendas.size(); i++) {


		encomendas.at(i).print_full(cout);

		cout << endl;
	}

}

void fornecedor_consultarEncomendaFarmacia(Fornecedor & fornecedor)
{
	if (fornecedor.getNumEncomendas() == 0) {

		cout << "O fornecedor " << fornecedor.getNome() << " ainda nao tem encomendas." << endl;
		return;
	}


	string nomeFarmacia = getInputString("Consultar encomendas da farmacia: ", "farmacia invalida");
	vector<Encomenda> encomendas = fornecedor.getEncomendas(nomeFarmacia);

	if (encomendas.empty()) {

		cout << "Nao existem encomendas dessa farmacia." << endl;
		return;
	}

	cout << endl;
	for (int i = 0; i < encomendas.size(); i++) {


		encomendas.at(i).print_full(cout);

		cout << endl;
	}

}

/////////////////
//  FARMACIAS  //
/////////////////

void menuFarmacias(Cadeia& cadeia)
{
	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR FARMACIAS" << endl << endl;
		cout << "1 - Resumo Farmacias" << endl;
		cout << "2 - Consultar Farmacia" << endl;
		cout << "3 - Adicionar Farmacia" << endl;
		cout << "4 - Gerir stock" << endl;
		cout << "5 - Alterar gerente" << endl;
		cout << "6 - Adicionar fornecedor " << endl;
		cout << "7 - Remover fornecedor " << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 7);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			resumoFarmacias(cadeia);
			break;
		case 2:
			consultarFarmacia(cadeia);
			break;
		case 3:
			adicionarFarmacia(cadeia);
			break;
		case 4:
			gerirStock(cadeia);
			break;
		case 5:
			farmacia_alterarGerente(cadeia);
			break;
		case 6:
			farmacia_adicionarFornecedor(cadeia);
			break;
		case 7:
			farmacia_removerFornecedor(cadeia);
			break;
		case 0:
			continuarNesteMenu = false;
		}
	}
}

void resumoFarmacias(Cadeia& cadeia) {

	cout << endl << "RESUMO FARMACIAS" << endl << endl;

	if (cadeia.getNumFarmacias() == 0) {

		cout << "A cadeia " << cadeia.getNome() << " ainda nao tem farmacias." << endl;
		return;
	}

	cadeia.mostrarFarmacias();
}

void consultarFarmacia(Cadeia& cadeia) {

	cout << endl;

	if (cadeia.getNumFarmacias() == 0) {

		cout << "A cadeia " << cadeia.getNome() << " ainda nao tem farmacias." << endl;
		return;
	}

	Farmacia * farmacia;

	string farmaciaNome = getInputString("Nome da farmacia a abrir: ", "Nome invalido.");

	try
	{
		farmacia = cadeia.getFarmacia(farmaciaNome);
	}
	catch (FarmaciaNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}


	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;
		cout << endl << "CONSULTAR FARMACIA" << endl << endl;
		farmacia->print(cout) << endl << endl;
		cout << "Consultar: " << endl;
		cout << "1 - Empregados" << endl;
		cout << "2 - Produtos" << endl;
		cout << "3 - Vendas" << endl;
		cout << "4 - Fornecedores" << endl;
		cout << "5 - Outra farmacia" << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 5);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			farmacia_consultarEmpregados(*farmacia);
			break;
		case 2:
			farmacia_consultarProdutos(*farmacia);
			break;
		case 3:
			farmacia_consultarVendas(*farmacia);
			break;
		case 5:
			cout << "Farmacia: ";
			getline(cin, farmaciaNome);

			try
			{
				farmacia = cadeia.getFarmacia(farmaciaNome);
			}
			catch (FarmaciaNaoExiste& f)
			{
				cout << f.getInfo() << endl;
				return;
			}
			break;
		case 4:
			farmacia_consultaFornecedores(*farmacia);
			break;
		case 0:
			continuarNesteMenu = false;
		}
	}

}

void farmacia_consultarEmpregados(Farmacia& farmacia) {

	cout << endl << "RESUMO EMPREGADOS " << endl << endl;

	farmacia.print(cout) << endl << endl;

	/*if (farmacia.getNumEmpregados() == 0) {
		cout << "A farmacia ainda nao tem empregados." << endl << endl;
		return;
	}

	int opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - ID (crescente)" << endl;
	cout << "1 - ID (decrescente)" << endl;
	cout << "2 - idade (crescente)" << endl;
	cout << "3 - idade (decrescente)" << endl;
	cout << "4 - nome (crescente)" << endl;
	cout << "5 - nome (decrescente)" << endl;
	cout << "6 - NIF (crescente)" << endl;
	cout << "7 - NIF (decrescente)" << endl;
	cout << "8 - numero de vendas (crescente)" << endl;
	cout << "9 - numero de vendas (decrescente)" << endl;
	cout << "10 - salario (crescente)" << endl;
	cout << "11 - salario (decrescente)" << endl;


	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Opcao: ";
			opcao = getInputNumber(0, 11);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}


	farmacia.sortEmpregados((ord_empregados)opcao); */

	farmacia.mostrarEmpregados();

	//farmacia.sortEmpregados(id_cres);
}

void farmacia_consultarProdutos(Farmacia & farmacia)
{
	cout << endl << "PRODUTOS" << endl << endl;
	farmacia.mostrarStock();
}

void gerirStock(Cadeia& cadeia) {

	cout << endl;

	if (cadeia.getNumFarmacias() == 0) {

		cout << "A cadeia " << cadeia.getNome() << " ainda nao tem farmacias." << endl;
		return;
	}

	Farmacia * farmacia;

	string farmaciaNome = getInputString("Nome da farmacia a abrir: ", "Nome invalido.");

	try
	{
		farmacia = cadeia.getFarmacia(farmaciaNome);
	}
	catch (FarmaciaNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}

	bool continuarNesteMenu = true;

	if (!farmacia->temFornecedorMed()) {

		cout << "Por favor adicione um fornecedor de medicamentos antes de adicionar medicamentos." << endl;
		continuarNesteMenu = false;
	}

	if (!farmacia->temFornecedorProd()) {
		cout << "Por favor adicione um fornecedor de produtos antes de adicionar produtos." << endl;
		continuarNesteMenu = false;
	}



	while (continuarNesteMenu) {
		int opcao;
		cout << endl << "GERIR STOCK" << endl << endl;
		farmacia->print(cout) << endl << endl;
		cout << "1 - Consultar produtos" << endl;
		cout << "2 - Adicionar produtos" << endl;
		cout << "3 - Remover produtos" << endl;
		cout << "4 - Repor stock" << endl;
		cout << "5 - Outra farmacia" << endl;
		cout << "0 - Menu anterior" << endl;

		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 4);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		switch (opcao) {
		case 1:
			farmacia_consultarProdutos(*farmacia);
			break;
		case 2:
			farmacia_adicionarProduto(*farmacia);
			break;
		case 3:
			farmacia_removerProduto(*farmacia);
			break;
		case 4:
			farmacia_reposicaoStock(*farmacia);
			break;
		case 5:
			cout << "Farmacia: ";
			getline(cin, farmaciaNome);

			try
			{
				farmacia = cadeia.getFarmacia(farmaciaNome);
			}
			catch (FarmaciaNaoExiste& f)
			{
				cout << f.getInfo() << endl;
				return;
			}
			break;
		case 0:
			continuarNesteMenu = false;
		}
	}

}

void farmacia_reposicaoStock(Farmacia& farmacia) {

	cout << endl << "REPOR STOCK" << endl << endl;

	int quantidade_minima;
	bool opcaoInvalida = true;
	while (opcaoInvalida) {

		try {
			cout << "Repor produtos com quantidade inferiores a: ";
			quantidade_minima = getInputNumber(0, 9999);
		}
		catch (OpcaoInvalida& opIn) {
			cout << opIn.getInfo() << endl;
			continue;
		}

		opcaoInvalida = false;
	}

	farmacia.constroiFilaReabastecimento();
	cout << "Produtos a repor:" << endl << endl;
	farmacia.mostrarPrioridadeEncomenda_listForm((uint)quantidade_minima);
	cout << endl << endl;

	cout << "Efetuar reposicao? ";

	string userChoice;

	getline(cin, userChoice);
	cout << endl;
	toUpper(userChoice);

	if ((userChoice == "S") || (userChoice == "SIM")) {

		int quantidade_nova;
		opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Nova quantidade dos produtos: ";
				quantidade_nova = getInputNumber(quantidade_minima, 9999,false);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		pair<string,string> fornecedoresIntervenientes = farmacia.repoeStock(quantidade_minima, quantidade_nova);
		cout << "Encomenda efetuada." << endl;

		if (fornecedoresIntervenientes.first == "NULL")
			cout << "Encomenda satisfeita pelo fornecedor " << fornecedoresIntervenientes.second << "." << endl;
		else if (fornecedoresIntervenientes.second == "NULL")
			cout << "Encomenda satisfeita pelo fornecedor " << fornecedoresIntervenientes.first << "." << endl;
		else
			cout << "Encomenda satisfeita pelo fornecedor " << fornecedoresIntervenientes.first << " e " << fornecedoresIntervenientes.second  << "." << endl;


	}
	else if ((userChoice == "N") || (userChoice == "NAO")) {

		cout << "Encomenda cancelada." << endl;
	}
	else
		cout << "Encomenda cancelada." << endl;

}

void farmacia_alterarGerente(Cadeia & cadeia)
{
	if (cadeia.getNumFarmacias() == 0) {

		cout << "Adicione uma farmacia primeiro." << endl;
		return;

	}

	cout << endl;

	Farmacia * farmacia;

	string farmaciaNome = getInputString("Nome da farmacia a abrir: ", "Nome invalido.");


	try
	{
		farmacia = cadeia.getFarmacia(farmaciaNome);
	}
	catch (FarmaciaNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}

	string nome_novoGerente;
	uint ID;

	//get nome do empregado a remover
	nome_novoGerente = getInputString("Nome do novo gerente: ", "Nome invalido.");

	// get empregados com o nome dado
	vector<Empregado*> empregados_busca = farmacia->getEmpregados(nome_novoGerente);

	// imprime empregados encontrados
	for (size_t i = 0; i < empregados_busca.size(); i++) {

		cout << "ID: " << empregados_busca.at(i)->getID()
			<< "| Nome: " << empregados_busca.at(i)->getNome()
			<< "| Cargo: " << empregados_busca.at(i)->getCargo() << endl;

	}

	cout << endl;

	// se nao encontrar nenhum empregado com o nome dado, retorna
	if (empregados_busca.size() == 0) {

		cout << "Nao foi encontrado nenhum empregado com esse nome." << endl;
		return;
	}

	// se s� existir um empregado com o nome dado, remover esse empregado
	// caso contrario, pedir o ID do empregado a remover
	if (empregados_busca.size() != 1) {

		// get ID da pessoa
		cout << "ID: ";

		while (!(cin >> ID))
		{
			if (cin.eof())
			{
				cin.clear();
			}
			else
			{
				cin.clear();
				cin.ignore(MAX_STREAM_SIZE, '\n');
			}

			cout << "ID: ";
		}

		cin.ignore(MAX_STREAM_SIZE, '\n');

		// verificar se o ID dado pertence a alguma das pessoas com o nome dado
		for (size_t i = 0; i < empregados_busca.size(); i++) {

			if (empregados_busca.at(i)->getID() == ID) {
				break;
			}
			if (i == empregados_busca.size() - 1) {

				cout << "Nao existe nenhum empregado com esse par Nome/ID." << endl;
				return;

			}
		}


	}
	else {

		ID = empregados_busca.at(0)->getID();
	}

	if (cadeia.getEmpregado(ID)->getCargo() == "gerente") {

		cout << "O empregado escolhido ja e um gerente." << endl;
		return;
	}

	string novo_Cargo;

	//getnome do cargo da pessoa que deixou de ser gerente
	cout << "Qual o novo cargo a atribuir ao gerente atual: ";
	getline(cin, novo_Cargo);

	farmacia->setGerente(cadeia.getEmpregado(ID), novo_Cargo);

	cout << endl << "Gerente da farmacia " << farmacia->getNome() << " alterado com sucesso." << endl;


}

void farmacia_consultarVendas(Farmacia & farmacia)
{
	cout << endl << "VENDAS" << endl << endl;

	farmacia.mostrarVendas();
}

void farmacia_adicionarProduto(Farmacia& farmacia) {

	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {

		cout << endl << "ADICIONAR PRODUTOS" << endl << endl;
		cout << "1 - Produto existente (adicionar quantidade) " << endl;
		cout << "2 - Novo produto " << endl;
		cout << "0 - Menu anterior" << endl;

		int opcao;
		bool opcaoInvalida = true;
		while (opcaoInvalida) {

			try {
				cout << "Opcao: ";
				opcao = getInputNumber(0, 2);
			}
			catch (OpcaoInvalida& opIn) {
				cout << opIn.getInfo() << endl;
				continue;
			}

			opcaoInvalida = false;
		}

		cout << endl;

		Produto* produto;

		if (opcao == 0) {
			continuarNesteMenu = false;
		}
		else if (opcao == 2) {

			try {
				produto = user_getProduto(farmacia);
			}
			catch (ProdutoRepetido &e) {
				cout << e.getInfo() << endl;
				continue;
			}

			uint quantidade;
			cout << "Qual a quantidade a adicionar? ";

			// validar input do codigo
			while (!(cin >> quantidade))
			{
				if (cin.eof())
				{
					cin.clear();
				}
				else
				{
					cin.clear();
					cin.ignore(MAX_STREAM_SIZE, '\n');
				}

				cout << "Qual a quantidade a adicionar? ";
			}
			cin.ignore(MAX_STREAM_SIZE, '\n');

			string fornecedor = farmacia.efetuaEncomenda(produto, quantidade);
			cout << "Encomenda satisfeita pelo fornecedor " << fornecedor << "." << endl;
		}
		else {
			long unsigned int codigo;
			unsigned int quantidade;
			farmacia.constroiFilaReabastecimento();
			cout << "Qual o codigo do produto? ";

			// validar input do codigo
			while (!(cin >> codigo))
			{
				if (cin.eof())
				{
					cin.clear();
				}
				else
				{
					cin.clear();
					cin.ignore(MAX_STREAM_SIZE, '\n');
				}

				cout << "Qual o codigo do produto? ";
			}
			cin.ignore(MAX_STREAM_SIZE, '\n');


			pair<Produto*, uint> topoPrioridade = farmacia.getFilaReabastecimento().top();
			try {
				uint quantidadeEx = farmacia.getProduto(codigo).second;

				if (quantidadeEx > topoPrioridade.second) {

					cout << "Existem outros produtos que necessitam ser encomendados primeiro." << endl;
					break;
				}



			}
			catch (ProdutoNaoExiste& e) {
				cout << e.getInfo() << endl;
				break;
			}





			cout << "Qual a quantidade a adicionar? ";

			// validar input do codigo
			while (!(cin >> quantidade))
			{
				if (cin.eof())
				{
					cin.clear();
				}
				else
				{
					cin.clear();
					cin.ignore(MAX_STREAM_SIZE, '\n');
				}

				cout << "Qual a quantidade a adicionar? ";
			}
			cin.ignore(MAX_STREAM_SIZE, '\n');

			try {
				pair<Produto*,uint> produto_encomendar = farmacia.getProduto(codigo);
				string fornecedor = farmacia.efetuaEncomenda(produto_encomendar.first, quantidade);
				cout << "Encomenda satisfeita pelo fornecedor " << fornecedor << "." << endl;
			}
			catch (ProdutoNaoExiste& e) {
				cout << e.getInfo() << endl;
			}
		}

	}

}

void farmacia_removerProduto(Farmacia & farmacia)
{
	cout << endl << "REMOVER PRODUTOS" << endl << endl;
	cout << "Codigo do produto a remover: ";

	long unsigned int codigo;
	unsigned int quantidade;

	// validar input do codigo
	while (!(cin >> codigo))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}
		cout << "Codigo do produto a remover: ";
	}
	cin.ignore(MAX_STREAM_SIZE, '\n');


	cout << "Quantidade a remover: ";

	// validar input do codigo
	while (!(cin >> quantidade))
	{
		if (cin.eof())
		{
			cin.clear();
		}
		else
		{
			cin.clear();
			cin.ignore(MAX_STREAM_SIZE, '\n');
		}
		cout << "Qual a quantidade a adicionar? ";
	}
	cin.ignore(MAX_STREAM_SIZE, '\n');

	try {
		farmacia.removeQuantidade(codigo, quantidade);
	}
	catch (ProdutoNaoExiste& e) {
		cout << e.getInfo() << endl;
	}
	catch (ProdutosInsuficientes& e) {
		cout << e.getInfo() << endl;
	}
}

void farmacia_adicionarFornecedor(Cadeia & cadeia)
{
	if (cadeia.getNumFarmacias() == 0) {

		cout << "Adicione uma farmacia primeiro." << endl;
		return;

	}

	cout << endl;

	Farmacia * farmacia;

	string farmaciaNome = getInputString("Nome da farmacia a abrir: ", "Nome invalido.");


	try
	{
		farmacia = cadeia.getFarmacia(farmaciaNome);
	}
	catch (FarmaciaNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}

	farmacia->print(cout);
	cout << endl << endl;

	vector<Fornecedor *> fornecedores = cadeia.getFornecedores();

	for (size_t i = 0; i < fornecedores.size(); i++) {

		Fornecedor* atual = fornecedores.at(i);

		atual->print_resumo_lista(cout);

	}
	cout << endl;

	string fornecedorNome = getInputString("Nome do fornecedor a adicionar: ", "Nome invalido.");
	Fornecedor * fornecedor;

	try
	{
		fornecedor = cadeia.getFornecedor(fornecedorNome);
	}
	catch (FornecedorNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}

	if (farmacia->addFornecedor(fornecedor))
		cout << "Adicionado." << endl;
	else
		cout << "Erro a adicionar fornecedor" << endl;
}

void farmacia_removerFornecedor(Cadeia & cadeia)
{
	if (cadeia.getNumFarmacias() == 0) {

		cout << "Adicione uma farmacia primeiro." << endl;
		return;

	}

	cout << endl;

	Farmacia * farmacia;

	string farmaciaNome = getInputString("Nome da farmacia a abrir: ", "Nome invalido.");


	try
	{
		farmacia = cadeia.getFarmacia(farmaciaNome);
	}
	catch (FarmaciaNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}

	farmacia->print(cout);
	cout << endl;

	vector<Fornecedor *> fornecedores = farmacia->getFornecedores();

	for (size_t i = 0; i < fornecedores.size(); i++) {

		Fornecedor* atual = fornecedores.at(i);

		atual->print_resumo_lista(cout);

	}
	cout << endl;

	string fornecedorNome = getInputString("Nome do fornecedor a remover: ", "Nome invalido.");
	Fornecedor * fornecedor;

	try
	{
		fornecedor = farmacia->getFornecedor(fornecedorNome);
	}
	catch (FornecedorNaoExiste& f)
	{
		cout << f.getInfo() << endl;
		return;
	}

	farmacia->removeFornecedor(fornecedor);

	cout << "Removido." << endl;

}

void farmacia_consultaFornecedores(Farmacia& farmacia) {

	cout << endl << " --- Fornecedores da Farmacia " << farmacia.getNome() << " ---" << endl;
	farmacia.print_lista_fornecedores(cout);
	cout << endl;
}

void adicionarFarmacia(Cadeia& cadeia)
{
	Empregado* newEmp;
	cout << endl << "ADICIONAR FARMACIA" << endl << endl;

	string nome = getInputString("Nome: ", "Nome invalido. ");

	Morada morada = user_getMorada();

	Farmacia* f = new Farmacia(nome, morada);

	if (!cadeia.addFarmacia(f)) {

		cout << "Ja existe uma farmacia com o nome " << nome << "." << endl;
		return;
	}

	cout << endl << "-- Adicionar um gerente " << endl << endl;

	do {

		pair<bool, string> ovRide = { true, nome };
		newEmp = user_getEmpregado(cadeia, ovRide);

	} while (!cadeia.addEmpregado(newEmp));


	cout << endl << "Gerente adicionado, farmacia criada." << endl;

}

void sortEmpregados(vector<Empregado*>& empregados, ord_empregados modo)
{
	switch (modo) {
	case id_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_ID_Crescente);
		break;
	case id_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_ID_Decrescente);
		break;
	case empregado_idade_cres:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Idade_Crescente);
		break;
	case empregado_idade_dec:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Idade_Decrescente);
		break;
	case empregado_nome_cres:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Nome_Crescente);
		break;
	case empregado_nome_dec:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_Nome_Decrescente);
		break;
	case empregado_nif_cres:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_NIF_Crescente);
		break;
	case empregado_nif_dec:
		sort(empregados.begin(), empregados.end(), Pessoa_SortFunc_NIF_Decrescente);
		break;
	case n_vendas_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_numVendas_Crescente);
		break;
	case n_vendas_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_numVendas_Decrescente);
		break;
	case sal_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_Salario_Crescente);
		break;
	case sal_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_Salario_Decrescente);
		break;
	case meses_lig_cres:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_MesesLig_Crescente);
		break;
	case meses_lig_dec:
		sort(empregados.begin(), empregados.end(), Empregado_SortFunc_MesesLig_Decrescente);
		break;
	}
}


