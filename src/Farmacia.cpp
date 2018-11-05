#include "Farmacia.h"

Farmacia::Farmacia(string nome, Morada morada) :nome(nome), morada(morada) {}

void Farmacia::addProduto(Produto *produto, int quantidade)
{
	map<Produto *, int>::iterator it;
	for (it = stock.begin(); it != stock.end(); it++) {
		if( *(it->first) == *produto ) {
			it->second += quantidade;
			return;
		}
	}
	stock[*produto] = quantidade;
}

bool Farmacia::addGerente(Empregado empregado)
{
	if(gerente.getNome() == "") {
		gerente = empregado;
		return true;
	}
	else return false;
}

bool Farmacia::addEmpregado(Empregado empregado)
{
	int i = procura(empregados, empregado);

	if (i != -1) {
		if(empregado.getCargo() == "gerente")
			if(!addGerente(empregado)) return false;
		empregados.push_back(empregado);
		return true;
	}
	else return false;
}

void Farmacia::remGerente()
{

}

void Farmacia::remEmpregado(int nif)
{
	int i = procura(empregados, nif);
	if( i != -1) {
		if(empregados[i].getCargo() == "gerente") remGerente();
		empregados.erase(empregados.begin() + i);
		return;
	}
	throw EmpregadoNaoExiste(nif);
}

bool Farmacia::removeQuantidade(int codigo, int quantidade)
{
	map<Produto, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if(it->first.getCodigo() == codigo) {
			if(it->second <= quantidade) {
				return true;
			}
			else {
				it->second -= quantidade;
				return false;
			}
		}
	}
	throw ProdutoNaoExiste(codigo);
}

void Farmacia::remProduto(int codigo)
{
	map<Produto *, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if( (*it->first).getCodigo() == codigo) {
			stock.erase(it);
			return;
		}
	}
	throw ProdutoNaoExiste(codigo);
}


string Farmacia::getNome() const
{
	return nome;
}

Morada Farmacia::getMorada() const
{
	return morada;
}

Empregado Farmacia::getGerente() const
{
	return gerente;
}

vector<Empregado> Farmacia::getEmpregados(string nome) const
{
	vector<Empregado> v1;
	vector<Empregado>::iterator it;

	for(it = empregados.begin(); it != empregados.end(); it++) {
		if( (*it).getNome() == nome) v1.push_back(*it);
	}

	return v1;
}

Produto* Farmacia::getProduto(int codigo) const
{
	map<Produto*, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if( (*it->first).getCodigo() == codigo)
			return (it->first);
	}
	throw ProdutoNaoExiste(codigo);
}

unsigned int Farmacia::getTotalProdutos() const
{
	int soma;
	map<Produto, int>::iterator it;
	for (it = stock.begin(); it != stock.end(); it++) {
		soma += it->second;
	}
	return soma;
}

bool Farmacia::operator == (const Farmacia & ph1)
{
	if(this->nome == ph1.getNome()) return true;
	else return false;
}

bool Farmacia::operator < (const Farmacia & ph)
{
	if(this->nome < ph.getNome()) return true;
	else return false;
}

void Farmacia::consultarQuantidades()
{
	map<Produto*, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		cout << "Nome: " << (*it->first).getNome() << "; Codigo: " << (*it->first).getCodigo() << "; Quantidade: " << it->second;
	}
}

unsigned int Farmacia::numEmpregados() const
{
	return empregados.size();
}

unsigned int Farmacia::tamanhoStock() const
{
	return stock.size();
}
