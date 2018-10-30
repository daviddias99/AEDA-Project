#include <iostream>
#include "Cadeia.h"

using namespace std;

void menuAdicionar()
{
	char opcao;

	cout << endl << "ADICIONAR" << endl;
	cout << "1 - Adicionar Farmacia" << endl;
	cout << "2 - Adicionar Funcionario/Gerente" << endl;
	cout << "3 - Adcionar Cliente" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao: ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		adicionarFarmacia();
		break;
	case '2':
		adicionarFuncionario();
		break;
	case '3':
		adicionarCliente();
		break;
	case '0':
		exit(0);
		break;
	}
}

void menuRemover()
{
	char opcao;

	cout << endl << "REMOVER" << endl;
	cout << "1 - Remover Farmacia" << endl;
	cout << "2 - Remover Funcionario/Gerente" << endl;
	cout << "3 - Remover Cliente" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao: ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		removerFarmacia();
		break;
	case '2':
		removerFuncionario();
		break;
	case '3':
		removerCliente();
		break;
	case '0':
			exit(0);
			break;
		}
}

void menuCriar()
{
	char opcao;

	cout << endl << "CRIAR CADEIA DE FARMACIAS" << endl;
	cout << "1 - Adicionar" << endl;
	cout << "2 - Remover" << endl;
	cout << "3 - Consultar" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao: ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		menuAdicionar();
		break;
	case '2':
		menuRemover();
		break;
	case '3':
		menuConsultar();
		break;
	case '0':
		exit(0);
		break;
	default:
		cout << "Opcao Invalida!\n";
		menuCriar();
	}
}


void menu()
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
		menuCriar();
		break;
	case '2':
		//carregarCadeia();
		break;
	case '0':
		exit(0);
		break;
	default:
		cout << "Opcao Invalida!\n";
		menu();
	}
}


int main() {
	menu();
	return 0;
}



