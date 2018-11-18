#include "Sistema TESTE.h"

Sistema::Sistema() {}

void Sistema::start()
{
	menu();
}

void Sistema::menu()
{
	char opcao;
	cout << "MENU" << endl << endl;;

	cout << "1 - Criar nova Cadeia de Farmacias" << endl;
	cout << "2 - Carregar Cadeia de Farmacias" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao: ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		menuGerencia();
		break;
	case '2':
		break;
	case '0':
		exit(0);
		break;
	default:
		cout << "Opcao Invalida!\n";
		menu();
	}
}

void Sistema::menuGerencia()
{
	char opcao;
	this->cadeia = Cadeia();

	cout << endl << "GERIR CADEIA DE FARMACIAS" << endl;
	cout << "1 - Gerir Farmacias" << endl;
	cout << "2 - Gerir Clientes" << endl;
	cout << "3 - Gerir Empregados" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao: ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		gerirFarmacias();
		break;
	case '2':
		gerirClientes();
		break;
	case '3':
		gerirEmpregados();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!\n";
		menuGerencia();
	}
}

void Sistema::gerirFarmacias()
{
	char opcao;

	cout << endl << "GERIR FARMACIAS" << endl;
	cout << "1 - Gerir Farmacia" << endl;
	cout << "2 - Adicionar Farmacia" << endl;
	cout << "3 - Remover Farmacia" << endl;
	cout << "4 - Consultar farmacias" << endl;
	cout << "5 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		gerirFarmacia();
		break;
	case '2':
		adicionarFarmacia();
		break;
	case '3':
		removerFarmacia();
		break;
	case '4':
		consultarFarmacias();
		break;
	case '5':
		menuGerencia();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Invalid option!" << endl;
		gerirFarmacias();
	}
}

void Sistema::gerirClientes()
{
	char opcao;

	cout << endl << "GERIR CLIENTES" << endl;
	cout << "1 - Gerir Cliente" << endl;
	cout << "2 - Adicionar Cliente" << endl;
	cout << "3 - Remover Cliente" << endl;
	cout << "4 - Consultar clientes" << endl;
	cout << "5 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		gerirCliente();
		break;
	case '2':
		adicionarCliente();
		break;
	case '3':
		removerCliente();
		break;
	case '4':
		consultarClientes();
		break;
	case '5':
		menuGerencia();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Invalid option!" << endl;
		gerirClientes();
	}
}

void Sistema::gerirEmpregados()
{
	char opcao;

	cout << endl << "GERIR EMPREGADOS" << endl;
	cout << "1 - Gerir Empregado" << endl;
	cout << "2 - Adicionar Empregado" << endl;
	cout << "3 - Remover Empregado" << endl;
	cout << "4 - Consultar empregados" << endl;
	cout << "5 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		gerirEmpregado();
		break;
	case '2':
		adicionarEmpregado();
		break;
	case '3':
		removerEmpregado();
		break;
	case '4':
		consultarEmpregados();
		break;
	case '5':
		menuGerencia();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Invalid option!" << endl;
		gerirEmpregados();
	}
}

void Sistema::sair()
{
	string opcao;

	do {
		cout << "Deseja guardar os seus dados num ficheiro? (sim/nao) ";
		cin >> opcao;
		cin.ignore(MAX_STREAM_SIZE, '\n');

		if(opcao == "sim") {
			cadeia.guardarDados();
			exit(0);
		}
		else if(opcao == "nao")
			exit(0);
		else
			cout << "Resposta invalida!" << endl;

	} while (true);
}

void Sistema::consultarFarmacias()
{
	cout << endl << "CONSULTAR FARMACIAS" << endl;

	char opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - Nome - Crescente" << endl;
	cout << "1 - Nome - Decrescente" << endl;
	cout << "2 - Tamanho stock - Crescente" << endl;
	cout << "3 - Tamanho stock - Decrescente" << endl;
	cout << "4 - Numero de vendas - Crescente" << endl;
	cout << "5 - Numero de vendas - Decrescente" << endl;

	cout << "Opcao: ";
	cin >> opcao;

	cadeia.sortFarmacias(opcao);

	//cadeia.mostrarFarmacias();

	gerirFarmacias();
}

void Sistema::consultarClientes()
{
	cout << endl << "CONSULTAR CLIENTES" << endl;

	char opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - Idade - Crescente" << endl;
	cout << "1 - Idade - Decrescente" << endl;
	cout << "2 - Nome - Crescente" << endl;
	cout << "3 - Nome - Decrescente" << endl;
	cout << "4 - NIF - Crescente" << endl;
	cout << "5 - NIF - Decrescente" << endl;
	cout << "6 - Numero de Compras - Crescente" << endl;
	cout << "7 - Numero de Compras - Decrescente" << endl;

	cout << "Opcao: ";
	cin >> opcao;

	cadeia.sortClientes(opcao);

	cadeia.mostrarClientes();

	gerirClientes();
}

void Sistema::consultarEmpregados()
{
	cout << endl << "CONSULTAR EMPREGADOS" << endl;

	char opcao;

	cout << "Ordenar por: " << endl;
	cout << "0 - Idade - Crescente" << endl;
	cout << "1 - Idade - Decrescente" << endl;
	cout << "2 - Nome - Crescente" << endl;
	cout << "3 - Nome - Decrescente" << endl;
	cout << "4 - NIF - Crescente" << endl;
	cout << "5 - NIF - Decrescente" << endl;
	cout << "6 - Salario - Crescente" << endl;
	cout << "7 - Salario - Decrescente" << endl;
	cout << "8 - Numero de vendas - Crescente" << endl;
	cout << "9 - Numero de vendas - Decrescente" << endl;

	cout << "Opcao: ";
	cin >> opcao;

	cadeia.sortEmpregados(opcao);

	cadeia.mostrarEmpregados();

	gerirEmpregados();
}

void Sistema::gerirFarmacia()
{
	cout << endl << "GERIR FARMACIA" << endl;

	if(cadeia.getNumFarmacias() == 0) {
		cout << "Nenhuma farmacia nesta cadeia. Adicione uma farmacia primeiro." << endl;
		gerirFarmacias();
	}

	string nome;
	//unsigned int i;

	cout << "Nome da farmacia: ";
	getline(cin, nome);
	

	try {
		f = cadeia.getFarmacia(nome);
		farmacia_gerir();
	}
	catch(FarmaciaNaoExiste &f1)
	{
		cout << "A farmacia " << f1.getNome() << " nao existe.";
		gerirFarmacias();
	}
}

void Sistema::farmacia_gerir()
{
	cout << "FARMACIA " << f->getNome() << endl;

	char opcao;

	cout << "1 - Adicionar" << endl;
	cout << "2 - Remover" << endl;
	cout << "3 - Consultar" << endl;
	cout << "4 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		farmacia_menuAdicionar();
		break;
	case '2':
		farmacia_menuRemover();
		break;
	case '3':
		farmacia_menuConsultar();
		break;
	case '4':
		menuGerencia();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!" << endl;
		menuGerencia();
	}
}

void Sistema::farmacia_menuAdicionar()
{
	char opcao;

	cout << "1 - Adicionar venda" << endl;
	cout << "2 - Adicionar produto" << endl;
	cout << "3 - Adicionar empregado" << endl;
	cout << "4 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		farmacia_adicionarVenda();
		break;
	case '2':
		farmacia_adicionarProduto();
		break;
	case '3':
		farmacia_adicionarEmpregado();
		break;
	case '4':
		farmacia_gerir();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!" << endl;
		farmacia_menuAdicionar();
	}
}

void Sistema::farmacia_adicionarEmpregado()
{
	cout << endl << "ADICIONAR EMPREGADO" << endl;

	string nome, cargo;;
	
	string dnStr, moradaStr;
	unsigned int NIF, salario;
	//Morada morada;

	cout << "Nome: ";
	getline(cin, nome);
	cout << "NIF: ";
	cin >> NIF;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Data de Nascimento: ";
	getline(cin, dnStr);
	cout << "Morada: ";
	getline(cin, moradaStr);
	cout << "Salario: ";
	cin >> salario;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Cargo: ";
	getline(cin,cargo);

	


	Data dataNascimento = Data(dnStr);

	Empregado* newEmp = new Empregado(nome, NIF, dataNascimento, Morada(), salario, this->f->getNome(), cargo);
	this->f->addEmpregado(newEmp);
	if (cargo == "gerente") {
		this->f->setGerente(newEmp);
	}


	farmacia_menuAdicionar();
}

void Sistema::farmacia_removerProduto()
{
	cout << endl << "REMOVER PRODUTO" << endl;

	int codigo, quantidade;
	bool erro;

	cout << "Codigo do produto: ";
	cin >> codigo;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Quantidade a remover( '0' para remover a quantidade total): ";
	cin >> quantidade;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	try {
		if(quantidade == 0) {
			f->remProduto(codigo);
			cout << "Produto removido." << endl;
		}
		else {
			erro = f->removeQuantidade(codigo, quantidade);
			if(!erro) cout << "Quantidade removida;" << endl;
			else cout << "Erro! Se pretende remover a quantidade total do protudo, responda '0' a quantidade;" << endl;
		}
	} catch(ProdutoNaoExiste &p1) {
		cout << "O produto de codigo " << p1.getCodigo() << " nao existe." << endl;
	}

	farmacia_menuRemover();
}

void Sistema::farmacia_removerEmpregado()
{
	cout << endl << "REMOVER EMPREGADO" << endl;

	int nif;
	cout << "NIF: ";
	cin >> nif;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	/*
	try {
		f->remEmpregado(nif);
		cout << "Empregado removido." << endl;
	} catch (EmpregadoNaoExiste &e) {
		cout << "Nao existe nenhum empregado com o nif " << nif << ".\n";
	}
	*/
	farmacia_menuRemover();
}

void Sistema::farmacia_adicionarVenda()
{
	cout << endl << "ADICIONAR VENDA" << endl;

	//Venda* v1;

	//cin >> *v1;

	//f->adicionarVenda(v1);

	farmacia_menuAdicionar();
}

void Sistema::farmacia_menuConsultar()
{
	cout << endl << "CONSULTAR FARMACIA" << endl;

	//escreve(cout, *f, 0);

	cout << "1 - Consultar empregado" << endl;
	cout << "2 - Consultar stock" << endl;
	cout << "3 - Consultar Vendas" << endl;
	cout << "4 - Menu anterior" << endl;
	cout << "5 - Sair" << endl;

	char opcao;

	cout << "Opcao: ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		farmacia_consultarEmpregado();
		break;
	case '2':
		farmacia_consultarStock();
		break;
	case '3':
		farmacia_consultarVendas();
		break;
	case '4':
		farmacia_gerir();
		break;
	case '5':
		sair();
		break;
	default:
		cerr << "Opcao Invalida!" << endl;
		farmacia_menuConsultar();
		break;
	}
}

void Sistema::farmacia_consultarEmpregado()
{
	cout << endl << "CONSULTAR EMPREGADO" << endl;

	if(!f->numEmpregados()) {
		cout << "Nenhum empregado nesta farmacia. Adicione um primeiro." << endl;
		farmacia_menuConsultar();
	}

	string nome;

	cout << "Nome: ";
	getline(cin, nome);

	vector<Empregado*> v1 = f->getEmpregados(nome);

	if(!v1.size()) {
		cout << "Nao existe nenhum empregado com esse nome." << endl;
		farmacia_menuConsultar();
	}
	else {
		vector<Empregado*>::iterator it;
		for(it = v1.begin(); it != v1.end(); it++)
				cout << **it << endl;
	}
	farmacia_menuConsultar();
}

void Sistema::farmacia_consultarStock()
{
	cout << endl << "CONSULTAR STOCK" << endl;

	cout << "Numero de produtos diferentes: " << f->tamanhoStock() << endl;
	cout << "Numero total de produtos: " << f->getTotalProdutos() << endl << endl;

	cout << "1 - Consultar Produto" << endl;
	cout << "2 - Consultar quantidades de todos os produtos";
	cout << "3 - Menu anterior" << endl;
	cout << "4 - Sair" << endl;

	char opcao;

	cout << "Opcao: ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		farmacia_consultarProduto();
		break;
	case '2':
		farmacia_consultarQuantidades();
		break;
	case '3':
		farmacia_menuConsultar();
		break;
	case '4':
		sair();
		break;
	default:
		cerr << "Opcao invalida!" << endl;
		farmacia_consultarStock();
	}
}

void Sistema::farmacia_consultarProduto()
{
	cout << endl << "CONSULTAR PRODUTO" << endl;

	int codigo;

	cout << "Codigo: ";
	cin >> codigo;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	Produto * p1 = NULL;
	try {
		p1 = f->getProduto(codigo);
	} catch(ProdutoNaoExiste &p) {
		cout << "O produto com o codigo " << p.getCodigo() << " nao existe." << endl;
		farmacia_consultarStock();
	}

	cout << *p1;
	farmacia_consultarStock();
}

void Sistema::farmacia_consultarQuantidades()
{
	cout << endl << "CONSULTAR QUANTIDADES" << endl;

	f->consultarQuantidades();
	farmacia_consultarStock();
}

void Sistema::farmacia_consultarVendas()
{
	cout << endl << "CONSULTAR VENDAS" << endl;

	//f->mostrarVendas();

	farmacia_menuConsultar();
}

void Sistema::farmacia_menuRemover()
{
	char opcao;

	cout << "1 - Remover Produto" << endl;
	cout << "2 - Remover Empregado" << endl;
	cout << "3 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	switch (opcao) {
	case '1':
		farmacia_removerProduto();
		break;
	case '2':
		farmacia_removerEmpregado();
		break;
	case '3':
		farmacia_gerir();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!" << endl;
		farmacia_menuRemover();
	}
}

void Sistema::farmacia_adicionarProduto()
{
	cout << endl << "ADICIONAR PRODUTO" << endl;

	unsigned long int codigo;
	string nome, descricao;
	float preco, iva;
	int quantidade;

	cout << "Codigo: ";
	cin >> codigo;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Descricao: ";
	getline(cin, descricao);
	cout << "Preco: ";
	cin >> preco;
	cout << "IVA: ";
	cin >> iva;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Quantidade a adicionar: ";
	cin >> quantidade;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	Produto* p1 = new Produto(codigo, nome, descricao, preco, iva);
	f->addProduto(p1, quantidade);

	cout << "Produto adicionado" << endl;
	farmacia_menuAdicionar();
}

void Sistema::adicionarFarmacia()
{
	cout << endl << "ADICIONAR FARMACIA" << endl;

	string nome, moradaStr;

	cout << "Nome: ";
	getline(cin, nome);
	cout << "Morada: ";
	getline(cin, moradaStr);
	Morada morada = Morada(moradaStr);
	Farmacia* f = new Farmacia(nome, morada);

	if(cadeia.addFarmacia(f)) cout << "Farmacia adicionada." << endl;
	else cout << "Ja existe uma farmacia com o nome " << nome << endl;

	gerirFarmacias();
}

void Sistema::removerFarmacia()
{
	cout << endl << "REMOVER FARMACIA" << endl;

	string nome;

	cout << "Nome: ";
	getline(cin, nome);

	try {
		cadeia.removeFarmacia(nome);
		cout << "Farmacia removida." << endl;
	} catch (FarmaciaNaoExiste &f) {
		cout << "A farmacia " << f.getNome() << " nao existe." << endl;
	}

	gerirFarmacias();

}

void Sistema::gerirCliente()
{
	cout << endl << "GERIR CLIENTE" << endl;

	int nif;

	cout << "NIF: ";
	cin >> nif;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	try {
		Cliente* c = cadeia.getCliente(nif);
		//c.gerir();
	} catch (ClienteNaoExiste &c1) {
		cout << "O cliente com o nif " << c1.getNIF() << " nao existe." << endl;
		gerirClientes();
	}
}

void Sistema::adicionarCliente()
{
	cout << endl << "ADICIONAR CLIENTE" << endl;

	string nome;

	string dnStr, moradaStr;
	unsigned int NIF;
	//Morada morada;

	cout << "Nome: ";
	getline(cin, nome);
	cout << "NIF: ";
	cin >> NIF;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Data de Nascimento: ";
	getline(cin, dnStr);
	cout << "Morada: ";
	getline(cin, moradaStr);


	Data dataNascimento = Data(dnStr);

	Cliente* newCli= new Cliente(nome, NIF, dataNascimento, Morada());


	if(cadeia.addCliente(c)) cout << "Cliente adicionado." << endl;
	else cout << "O cliente " << c->getNome() << " com o nif " << c->getNIF() << " ja existe." << endl;

	gerirClientes();
}

void Sistema::removerCliente()
{
	cout << endl << "REMOVER CLIENTE" << endl;

	int nif;

	cout << "NIF: ";
	cin >> nif;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	try {
		cadeia.removeCliente(nif);
		cout << "Cliente removido" << endl;
	} catch (ClienteNaoExiste &c1) {
		cout << "O cliente com o nif " << c1.getNIF() << " nao existe." << endl;
	}

	gerirClientes();
}

void Sistema::gerirEmpregado()
{
	cout << endl << "GERIR EMPREGADO" << endl;

	int nif;

	cout << "NIF: ";
	cin >> nif;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	try {
		Empregado* e = this->cadeia.getEmpregado(nif);
		//e.gerir();
	} catch (EmpregadoNaoExiste &e1) {
		cout << "O empregado com o nif " << e1.getNIF() << " nao existe." << endl;
	}

	gerirEmpregados();
}

void Sistema::adicionarEmpregado()
{
	cout << endl << "ADICIONAR EMPREGADO" << endl;

	cout << endl << "ADICIONAR EMPREGADO" << endl;

	string nome, cargo;;

	string dnStr, moradaStr;
	unsigned int NIF, salario;
	//Morada morada;

	cout << "Nome: ";
	getline(cin, nome);
	cout << "NIF: ";
	cin >> NIF;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Data de Nascimento: ";
	getline(cin, dnStr);
	cout << "Morada: ";
	getline(cin, moradaStr);
	cout << "Salario: ";
	cin >> salario;
	cin.ignore(MAX_STREAM_SIZE, '\n');
	cout << "Cargo: ";
	cin >> cargo;
	cin.ignore(MAX_STREAM_SIZE, '\n');



	Data dataNascimento = Data(dnStr);

	Empregado* newEmp = new Empregado(nome, NIF, dataNascimento, Morada(), salario, this->f->getNome(), cargo);

	if(cadeia.addEmpregado(newEmp)) cout << "Empregado adicionado." << endl;
	else cout << "O empregado " << e->getNome() << " com o nif " << e->getNIF() << " ja existe." << endl;

	gerirEmpregados();
}

void Sistema::removerEmpregado()
{
	cout << endl << "REMOVER EMPREGADO" << endl;

	int nif;

	cout << "NIF: ";
	cin >> nif;
	cin.ignore(MAX_STREAM_SIZE, '\n');

	try {
		cadeia.removeEmpregado(nif);
		cout << "Empregado removido." << endl;
	} catch (EmpregadoNaoExiste &e1) {
		cout << "O empregado com o nif " << e1.getNIF() << " nao existe." << endl;
	}

	gerirEmpregados();
}




