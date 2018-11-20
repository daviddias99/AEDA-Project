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

Empregado* user_getEmpregado(Cadeia& cadeia, pair<bool, string> newFOverride) {

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

	if (!newFOverride.first) {
		while (true) {

			farmaciaNome = getInputString("Farmacia: ", "Nome de farmacia invalido.");

			try
			{
				cadeia.getFarmacia(farmaciaNome);
			}
			catch (FarmaciaNaoExiste& f)
			{
				cout << "Nao existe nenhuma farmacia com o nome " << f.getNome() << "." << endl;
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
	dataNascimento = user_getData();

	Empregado* newEmp = new Empregado(nome, NIF, dataNascimento, morada, salario, farmaciaNome, cargo);

	return newEmp;
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
		throw ProdutoRepetido(codigo);
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
	else  {
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

		produto = new Medicamento(codigo, nome, desc, preco, (float)iva / 100, vendidoSemRec, podeSerRec, (float) descComReceita / 100);
	}
	
	return produto;
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


	cadeia.sortClientes(id_cres);
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
			gerirEmpregado(cadeia);
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

	cadeia.sortEmpregados(id_cres);
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
			<< "| Farmacia: " << empregados_busca.at(i)->getNomeFarmacia()
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
			<< "| Salario: " << empregados_busca.at(i)->getSalario()<< endl;


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




	int opcao = -1;
	bool opcaoInvalida = true;

	do {

		cout << endl << "O que pretende alterar no empregado " << cadeia.getEmpregado(ID)->getNome() << " ?" << endl;
		cout << "1- Salario" << endl;
		cout << "2- Cargo" << endl;
		cout << "3- Morada" << endl;
		cout << "4- Farmacia" << endl;
		cout << "0- Terminar" << endl << endl;

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
					cout << "Nao existe nenhuma farmacia com o nome " << f.getNome() << "." << endl;
					continue;
				}

			} while (!farmaciaValida);
			farmaciaValida = false;

			farmaciaTemp->addEmpregado(cadeia.getEmpregado(ID));
			cadeia.getFarmacia(cadeia.getEmpregado(ID)->getNomeFarmacia())->remEmpregado(ID);
			cadeia.getEmpregado(ID)->setFarmacia(nomeFarmacia);
			

			cout << "Alterado." << endl;




			break;
		case 0:
			break;
		}

	} while (opcao != 0);


		return;
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
			alterarGerente(cadeia);
		case 0:
			continuarNesteMenu = false;
		}
	}
}

void resumoFarmacias(Cadeia& cadeia) {

	cout << endl << "RESUMO FARMACIAS" << endl << endl;
	cadeia.mostrarFarmacias();
}

void consultarFarmacia(Cadeia& cadeia) {

	cout << endl;

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
		cout << endl <<"CONSULTAR FARMACIA" << endl << endl;
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
			farmacia_consultarProdutos(*farmacia);
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

void farmacia_consultarProdutos(Farmacia & farmacia)
{
	cout << endl << "PRODUTOS" << endl << endl;
	farmacia.mostrarStock();
}

void gerirStock(Cadeia& cadeia) {

	cout << endl;

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
		cout << endl << "GERIR STOCK" << endl << endl;
		farmacia->print(cout) << endl << endl;
		cout << "1 - Consultar produtos" << endl;
		cout << "2 - Adicionar produtos" << endl;
		cout << "3 - Remover produtos" << endl;
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
			farmacia_consultarProdutos(*farmacia);
			break;
		case 2:
			farmacia_adicionarProduto(*farmacia);
			break;
		case 3:
			farmacia_removerProduto(*farmacia);
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

void alterarGerente(Cadeia & cadeia)
{
	cout << endl;

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

	string nome_novoGerente;
	uint ID;

	//get nome do empregado a remover
	cout << "Nome do novo gerente: ";
	getline(cin, nome_novoGerente);

	// get empregados com o nome dado
	vector<Empregado*> empregados_busca = farmacia->getEmpregados(nome_novoGerente);

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
				cout << "O produto com o codigo " << e.getCodigo() << " ja existe." << endl;
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

			farmacia.addProduto(produto, quantidade);
		}
		else {
			long unsigned int codigo;
			unsigned int quantidade;

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
				farmacia.addQuantidade(codigo, quantidade);
			}
			catch (ProdutoNaoExiste& e) {
				cout << "O produto com o codigo  " << e.getCodigo() << " nao existe." << endl;
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
			cout << "O produto com o codigo  " << e.getCodigo() << " nao existe." << endl;
		}
		catch (ProdutosInsuficientes& e) {
			cout << "Apenas existem " << e.getQuantidade() << " unidades do produto pedido." << endl;
		}
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

void farmacia_mudarGerente(Cadeia& farmacia)
{
	// TO DO
}
