#include <iostream>
#include "Cadeia.h"
#include "Excecoes.h"

const long long MAX_STREAM_SIZE = numeric_limits<streamsize>::max();

int getInputNumber(int limInf, int limSup);

void showMenuInicial();
void showMenuPrincipal();

//void realizarVenda(Cadeia& cadeia);

void gerirClientes(Cadeia& cadeia);
void consultarClientes(Cadeia& cadeia);
void gerirEmpregados(Cadeia& cadeia);
void consultarEmpregados(Cadeia& cadeia);
void gerirFarmacias(Cadeia& cadeia);
void consultarFarmacias(Cadeia& cadeia);
void adicionarFarmacia(Cadeia& cadeia);



int main() {

	showMenuInicial();

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

	if (opcao == 0)
		return 0;

	string nome;

	cout << "Qual o nome da cadeia ? "; cin >> nome;
	Cadeia cadeia(nome);

	// carregar dados da cadeia existente caso o utilizador o deseje
	if (opcao == 2)
		cadeia.carregarDados();


	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {

		showMenuPrincipal();

		opcaoInvalida = true;
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
			//realizarVenda(cadeia);
			break;
		case 2:
			gerirFarmacias(cadeia);
			break;
		case 3:
			gerirClientes(cadeia);
			break;
		case 4:
			gerirEmpregados(cadeia);
			break;
		case 0:
			continuarNesteMenu = false;
			break;
		}
	}

	// guardar dados em ficheiro de texto
	cadeia.guardarDados();

	return 0;
}


///////////////////////////////////////////
///////////////////////////////////////////

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

///////////////////////////////////////////

void showMenuInicial() {
	cout << "MENU INICIAL" << endl << endl;;

	cout << "1 - Criar nova Cadeia de Farmacias" << endl;
	cout << "2 - Carregar Cadeia de Farmacias" << endl;
	cout << "0 - Sair da aplicacao" << endl;
}

void showMenuPrincipal() {
	cout << endl << "MENU PRINCIPAL" << endl << endl;
	cout << "1 - Realizar Venda" << endl;
	cout << "2 - Gerir Farmacias" << endl;
	cout << "3 - Gerir Clientes" << endl;
	cout << "4 - Gerir Empregados" << endl;
	cout << "0 - Sair da aplicacao" << endl;
}

///////////////////////////////////////////
///////////////////////////////////////////

void gerirClientes(Cadeia & cadeia)
{
	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR CLIENTES" << endl << endl;
		cout << "1 - Gerir Cliente" << endl;
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
			//gerirCliente();
			break;
		case 2:
			consultarClientes(cadeia);
			break;
		case 0:
			continuarNesteMenu = false;
			break;
		}
	}
}

void consultarClientes(Cadeia & cadeia)
{
	cout << endl << "CONSULTAR CLIENTES" << endl << endl;

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
}

///////////////////////////////////////////
///////////////////////////////////////////


void gerirEmpregados(Cadeia & cadeia)
{
	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR EMPREGADOS" << endl << endl;
		cout << "1 - Consultar empregados" << endl;
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
			consultarEmpregados(cadeia);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			continuarNesteMenu = false;
			break;
		}
	}
}

void consultarEmpregados(Cadeia & cadeia) 
{
	cout << endl << "CONSULTAR CLIENTES" << endl << endl;

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
}

///////////////////////////////////////////
///////////////////////////////////////////

void gerirFarmacias(Cadeia & cadeia)
{
	bool continuarNesteMenu = true;
	while (continuarNesteMenu) {
		int opcao;

		cout << endl << "GERIR FARMACIAS" << endl << endl;
		cout << "1 - Consultar Farmacias" << endl;
		cout << "2 - Gerir Farmacia" << endl;
		cout << "3 - Adicionar Farmacia" << endl;
		cout << "4 - Remover Farmacia" << endl;
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
			consultarFarmacias(cadeia);
			break;
		case 2:
			//gerirFarmacia();
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

void consultarFarmacias(Cadeia& cadeia) {

	cadeia.mostrarFarmacias();
}

void adicionarFarmacia(Cadeia& cadeia)
{

	cout << endl << "ADICIONAR FARMACIA" << endl << endl;

	string nome, moradaStr;

	cout << "Nome: ";
	getline(cin, nome);
	cout << "Morada: ";
	getline(cin, moradaStr);
	Morada morada = Morada(moradaStr);
	Farmacia* f = new Farmacia(nome, morada);

	if (cadeia.addFarmacia(f)) cout << "Farmacia adicionada." << endl;
	else cout << "Ja existe uma farmacia com o nome " << nome << endl;
}