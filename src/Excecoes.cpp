#include "Excecoes.h"


OpcaoInvalida::OpcaoInvalida(string i = "A opcao introduzida nao e valida.") {
	info = i;
}

string OpcaoInvalida::getInfo() {
	return info;
}
