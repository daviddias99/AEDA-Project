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
	cout << "4 - Realizar Venda" << endl;
	cout << "0 - Sair da aplicacao" << endl;
}


int getInputNumber(int limInf, int limSup)
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

		throw OpcaoInvalida("A opcao introduzida deve ser um numero entre " + to_string(limInf) + " e " + to_string(limSup) + ".");
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
	}


	morada_localidade = getInputString("-Localidade: ", "Localidade invalida");

	return Morada(morada_endereco, morada_cpostal, morada_localidade);
}

Empregado* user_getEmpregado(Cadeia& cadeia) {

	string nome;
	uint NIF;
	Data dataNascimento;
	Morada morada;
	uint salario;
	string farmaciaNome;
	string cargo;


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


	cout << "Salario: ";

	// validar input do salario
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
		cout << "Salario invalido." << endl << endl;
		cout << "Salario: ";
	}

	cin.ignore(MAX_STREAM_SIZE, '\n');


	while (true) {

		farmaciaNome = getInputString("Farmacia: ", "Nome de farmacia invalido.");

		try
		{
			cadeia.getFarmacia(farmaciaNome);
		}
		catch (FarmaciaNaoExiste& f)
		{
			cout << "Nao existe nenhuma farmacia com o nome " << f.getNome() << "." << endl;
		}
		break;
	}

	cargo = getInputString("Cargo: ", "Cargo invalido.");

	morada = user_getMorada();
	dataNascimento = user_getData();

	Empregado* newEmp = new Empregado(nome, NIF, dataNascimento, morada, salario, farmaciaNome, cargo);

	return newEmp;
}

Data user_getData() {

	Data dataNascimento;
	string data_nascimentoStr;
	bool inputValido = false;


	while (!inputValido) {

		data_nascimentoStr = getInputString("Data de nacimento: ", "Data de nascimento invalida.");
		try {

			dataNascimento = Data(data_nascimentoStr);
		}
		catch (DataInvalida& e) {
			cout << "Erro: Data de nascimento invalida, tente outra vez." << endl;
			continue;
		}

		inputValido = true;
	}


	return dataNascimento;
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
		cout << "2 - Consultar clientes" << endl;
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
			//gerirCliente();
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
	cout << "0 - ID (crescente)" << endl;
	cout << "1 - ID (decrescente)" << endl;
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


	cadeia.sortClientes((ord_pessoas)opcao);

	cadeia.mostrarClientes();

	cadeia.sortClientes(nif_cres);
}

void consultarClientes(Cadeia & cadeia)
{
	// TO DO
}

void gerirCliente(Cadeia & cadeia)
{
	// TO DO
}


//////////////////
//  EMPREGADOS  //
//////////////////

void menuEmpregados(Cadeia& cadeia)
{
	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR EMPREGADOS" << endl << endl;
		cout << "1 - Resumo empregados" << endl;
		cout << "2 - Gerir empregado" << endl;
		cout << "3 - Adicionar empregado" << endl;
		cout << "4 - Remover empregado" << endl;
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
			resumoEmpregados(cadeia);
			break;
		case 2:
			break;
		case 3:
			adicionarEmpregado(cadeia);
			break;
		case 4:
			removerEmpregado(cadeia);
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
		cout << "A cadeia \"" << cadeia.getNome() << "\" ainda nao tem empregados." << endl << endl;
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


	cadeia.sortEmpregados((ord_pessoas)opcao);

	cadeia.mostrarEmpregados();

	cadeia.sortEmpregados(nif_cres);
}

void adicionarEmpregado(Cadeia& cadeia)
{
	cout << endl << "ADICIONAR EMPREGADO" << endl << endl;

	Empregado* newEmp = user_getEmpregado(cadeia);

	if (cadeia.addEmpregado(newEmp)) {

		cout << "Empregado adicionado." << endl;
	}
	else {
		cout << "O empregado " << newEmp->getNome() << " com o nif " << newEmp->getNIF() << " ja existe." << endl;
	}
}

void removerEmpregado(Cadeia& cadeia)
{
	string nomeEmpregado;
	uint ID;

	cout << "REMOVER EMPREGADO" << endl << endl;

	//get nome do empregado a remover
	cout << "Nome do empregado: ";
	getline(cin, nomeEmpregado);

	// get empregados com o nome dado
	vector<Empregado*> empregados_busca = cadeia.getEmpregados(nomeEmpregado);

	// imprime empregados encontrados
	for (size_t i = 0; i < empregados_busca.size(); i++) {

		cout << "ID: " << empregados_busca.at(i)->getID()
			<< "| Nome: " << empregados_busca.at(i)->getNome()
			<< "| Cargo: " << empregados_busca.at(i)->getCargo() << endl;


	}

	cout << endl;

	// se não encontrar nenhum empregado com o nome dado, retorna
	if (empregados_busca.size() == 0) {

		cout << "Nao foi encontrado nenhum empregado com esse nome." << endl;
		return;
	}

	// se só existir um empregado com o nome dado, remover esse empregado
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

	// se o empregado que se tenta remover for um gerente, nao remover
	if (cadeia.getEmpregado(ID)->getCargo() == "gerente") {

		cout << "Erro: Nao pode remover o gerente de uma farmacia." << endl;
		return;

	}

	// remover empregado
	try {
		cadeia.removeEmpregado(ID);
		cout << "Cliente removido" << endl;
	}
	catch (EmpregadoNaoExiste &c1) {
		cout << "O empregado com o ID " << c1.getID() << " nao existe." << endl;
	}
}

void gerirEmpregado(Cadeia & cadeia)
{
	// TO DO
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
		//cout << "4 - Remover Farmacia" << endl;
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
			resumoFarmacias(cadeia);
			break;
		case 2:
			consultarFarmacia(cadeia);
			break;
		case 3:
			adicionarFarmacia(cadeia);
			break;
		case 4:
			//removerFarmacia();
			break;
		case 0:
			continuarNesteMenu = false;
		}
	}
}

void resumoFarmacias(Cadeia& cadeia) {

	cout << endl;
	cadeia.mostrarFarmacias();
}

void consultarFarmacia(Cadeia& cadeia) {

	Farmacia * farmacia;

	string farmaciaNome = getInputString("Nome da farmacia a abrir: ", "Nome invalido.");

	try
	{
		farmacia = cadeia.getFarmacia(farmaciaNome);
	}
	catch (FarmaciaNaoExiste& f)
	{
		cout << "Nao existe nenhuma farmacia com o nome " << f.getNome() << "." << endl;
		return;
	}


	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;
		cout << "CONSULTAR FARMACIA" << endl << endl;
		farmacia->print(cout) << endl << endl;
		cout << "Consultar: " << endl;
		cout << "1 - Empregados" << endl;
		cout << "2 - Produtos" << endl;
		cout << "3 - Vendas" << endl;
		cout << "4 - Outra farmacia" << endl;
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
			farmacia_consultarEmpregados(*farmacia);
			break;
		case 2:
			//consultaProdutos(farmacia);
			break;
		case 3:
			//consultaVendas(farmacia);
			break;
		case 4:
			cout << "Farmacia: ";
			getline(cin, farmaciaNome);

			try
			{
				farmacia = cadeia.getFarmacia(farmaciaNome);
			}
			catch (FarmaciaNaoExiste& f)
			{
				cout << "Nao existe nenhuma farmacia com o nome " << f.getNome() << "." << endl;
				return;
			}
			break;
		case 0:
			continuarNesteMenu = false;
		}
	}

}

void farmacia_consultarEmpregados(Farmacia& farmacia) {
	cout << endl << "RESUMO EMPREGADOS " << endl << endl;

	farmacia.print(cout) << endl << endl;

	if (farmacia.getNumEmpregados() == 0) {
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


	farmacia.sortEmpregados((ord_pessoas)opcao);

	farmacia.mostrarEmpregados();
}

void adicionarFarmacia(Cadeia& cadeia)
{
	cout << endl << "ADICIONAR FARMACIA" << endl << endl;

	string nome = getInputString("Nome: ", "Nome invalido. ");

	Morada morada = user_getMorada();

	Farmacia* f = new Farmacia(nome, morada);

	if (cadeia.addFarmacia(f))
		cout << "Farmacia adicionada com sucesso." << endl;
	else
		cout << "Ja existe uma farmacia com o nome " << nome << "." << endl;
}

void farmacia_mudarGerente(Cadeia& farmacia)
{
	// TO DO
}
