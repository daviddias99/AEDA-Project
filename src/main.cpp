#include <iostream>
#include "funcoes_main.h"


int main() {
	
	Cadeia cadeia;
	int opcao;
	bool continuarNesteMenu = true;
	bool opcaoInvalida;

	while (continuarNesteMenu) {
		showMenuInicial();
		
		opcaoInvalida = true;
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

		cout << endl;
		string nome = getInputString("Qual o nome da cadeia ? ", "Nome invalido.");
		cadeia = Cadeia(nome);

		// carregar dados da cadeia existente caso o utilizador o deseje
		if (opcao == 1) {
			continuarNesteMenu = false;
		}
		if (opcao == 2) {
			try {
				cadeia.carregarDados();
				continuarNesteMenu = false;
			}
			catch (FicheiroNaoEncontrado& e) {
				cout << e.getInfo() << endl << endl;
			}
		}
	}

	continuarNesteMenu = true;
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
			menuFarmacias(cadeia);
			break;
		case 2:
			menuClientes(cadeia);
			break;
		case 3:
			menuEmpregados(cadeia);
			break;
		case 4:
			realizarVenda(cadeia);
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


