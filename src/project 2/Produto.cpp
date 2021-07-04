#include "Produto.h"


Produto::Produto(long int cod, string n, string desc, float pr, float i) : codigo(cod), nome(n), descricao(desc) {
	preco = pr;
	iva = i;
}


long unsigned int Produto::getCodigo() const {
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

float Produto::getIVA() const {
	return iva;
}

int Produto::alteraPreco(float novoPreco) {

	if (novoPreco > 0) {
		preco = novoPreco;
		return 0;
	}
	else
		return 1;
}

bool Produto::operator==(const Produto &prod) {
	return codigo == prod.codigo;
}

ostream & Produto::print(ostream & os) const
{
	os << "Nome: " << nome << "\t\tCodigo: " << codigo << endl;
	os << "Descricao: " << descricao << endl << "Preco: " << preco << "e \t\tIva: " << iva * 100 << "%" << endl;

	return os;
}

ostream& Produto::printSimp(ostream& os) const {

	os << codigo << "&" << nome << "&" << descricao << "&" << preco << "&" << iva;

	return os;
}

ostream & Produto::printListForm(ostream & os) const
{
	os << "Nome: " << setw(10) << nome;
	os << " Codigo: " << setw(6) << this->codigo;
	os << " Tipo: " << setw(15) << " produto ";

	return os;
}

