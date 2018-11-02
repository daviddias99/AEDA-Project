#include "Sistema.h"

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

	switch (opcao) {
	case '1':
		menuGerencia();
		break;
	case '2':
		carregarCadeia();
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

	cout << endl << "GERIR CADEIA DE FARMACIAS" << endl;
	cout << "1 - Gerir Farmacias" << endl;
	cout << "2 - Gerir Clientes" << endl;
	cout << "3 - Gerir Empregados" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao: ";
	cin >> opcao;

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
		exit(0);
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
	cout << "4 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;

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
	cout << "4 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;

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
	cout << "4 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;

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

void Sistema::gerirFarmacia()
{
	cout << endl << "GERIR FARMACIA" << endl;

	if(cadeia.getNumFarmacias() == 0) {
		cout << "Nenhuma farmacia nesta cadeia. Adicione uma farmacia primeiro." << endl;
		gerirFarmacias();
	}

	string nome;
	unsigned int i;

	cout << "Nome da farmacia: ";
	cin >> nome;

	try {
		Farmacia f = cadeia.getFarmacia(nome);
		f.gerir();
	}
	catch(FarmaciaNaoExiste &f1)
	{
		cout << "A farmacia " << f1.getNome() << " nao existe.";
		gerirFarmacias();
	}
}

void Sistema::adicionarFarmacia()
{
	cout << endl << "ADICIONAR FARMACIA" << endl;

	string nome;
	Morada morada;

	cout << "Nome: ";
	cin >> nome;
	cout << "Morada: ";
	cin >> morada;

	Farmacia f = Farmacia(nome, morada);

	if(cadeia.addFarmacia(f)) cout << "Farmacia adicionada." << endl;
	else cout << "Ja existe uma farmacia com o nome " << nome << endl;

	gerirFarmacias();
}

void Sistema::removerFarmacia()
{
	cout << endl << "REMOVER FARMACIA" << endl;

	string nome;

	cout << "Nome: ";
	cin >> nome;

	try {
		cadeia.removeFarmacia(nome);
		cout << "Farmacia removida." << endl;
	} catch (FarmaciaNaoExiste &f) {
		cout << "A farmacia " << f.getNome() << " nao existe." << endl;
	}

	gerirFarmacias();
}





