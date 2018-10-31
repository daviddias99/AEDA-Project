#include "Produto.h"

Produto::Produto(long int cod, string n, string desc, float pr) : codigo(cod), nome(n), descricao(desc) {
	preco = pr;
}

long int Produto::getCodigo() const {
	return codigo;
}

string Produto::getNome() const {
	return nome;
}

string Produto::getDesc() const {
	return descricao;
}

float Produto::getPreco() const {
	return preco;
}

int Produto::alteraPreco(float novoPreco) {

	if (novoPreco > 0) {
		preco = novoPreco;
		return 0;
	}
	else
		return 1;
}


