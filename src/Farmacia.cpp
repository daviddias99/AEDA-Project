#include "Farmacia.h"

Farmacia::Farmacia(string nome, Morada morada) :nome(nome), morada(morada) {}

Farmacia:: ~Farmacia()
{
	map< Produto *, int>::const_iterator it;

	delete gerente;
	for (size_t i = 0; i < this->empregados.size(); i++)
		delete this->empregados.at(i);
	for(it = stock.begin(); it != stock.end(); it++)
		delete it->first;
	for (size_t i = 0; i < this->vendas.size(); i++)
		delete this->vendas.at(i);
}

void Farmacia::addProduto(Produto *produto, int quantidade)
{
	map<Produto *, int>::iterator it;
	for (it = stock.begin(); it != stock.end(); it++) {
		if( *(it->first) == *produto ) {
			it->second += quantidade;
			return;
		}
	}

	stock[produto] = quantidade;
}

bool Farmacia::addEmpregado(Empregado* empregado)
{
	int i = procura2(empregados, empregado);

	if (i != -1) {
		/*if(empregado->getCargo() == "gerente")
			if(!addGerente(empregado)) return false;
		empregados.push_back(empregado);
		return true; */
		empregados.push_back(empregado);
		return true;
	}
	else return false;
}

void Farmacia::remEmpregado(int nif)
{
	int i = procura2(empregados, nif);
	if( i != -1) {
		if(empregados[i]->getCargo() == "gerente") 
			this->setGerente(NULL);
		Empregado * temp = empregados.at(i);
		empregados.erase(empregados.begin() + i);
		delete temp;
		return;
	}
	throw EmpregadoNaoExiste(nif);
}

bool Farmacia::removeQuantidade(int codigo, int quantidade)
{
	map<Produto*, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if(it->first->getCodigo() == codigo) {
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
			Produto* prod = it->first;
			stock.erase(it);
			delete prod;
			return;
		}
	}
	throw ProdutoNaoExiste(codigo);
}

bool Farmacia::setGerente(Empregado * novoGerente)
{
	if(this->gerente != NULL)
		this->gerente->setCargo("empregado");
	novoGerente->setCargo("gerente");
	this->gerente = novoGerente;

	return true;
}


string Farmacia::getNome() const
{
	return nome;
}

Morada Farmacia::getMorada() const
{
	return morada;
}

Empregado* Farmacia::getGerente() const
{
	return gerente;
}

vector<Empregado*> Farmacia::getEmpregados(string nome) const
{
	vector<Empregado*> v1;
	vector<Empregado*>::const_iterator it;

	for(it = empregados.begin(); it != empregados.end(); it++) {
		if( (*it)->getNome() == nome) v1.push_back(*it);
	}

	return v1;
}

Produto* Farmacia::getProduto(int codigo) const
{
	map<Produto*, int>::const_iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if( (*it->first).getCodigo() == codigo)
			return (it->first);
	}
	throw ProdutoNaoExiste(codigo);
}

unsigned int Farmacia::getTotalProdutos() const
{
	int soma = 0;
	map<Produto*, int>::const_iterator it;
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

void Farmacia::consultarQuantidades()
{
	map<Produto*, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		cout << "Nome: " << (*it->first).getNome() << "; Codigo: " << (*it->first).getCodigo() << "; Quantidade: " << it->second;
	}
}

ostream& operator<< (ostream& os, const Farmacia& f1)
{
	os << "Nome: " << f1.getNome() << endl;
	//...
}

unsigned int Farmacia::numEmpregados() const
{
	return empregados.size();
}

unsigned int Farmacia::tamanhoStock() const
{
	return stock.size();
}

bool farmacia_SortFunc_Nome_Crescente(Farmacia &f1, Farmacia &f2)
{
	if(f1.getNome() < f2.getNome())
		return true;
	else if(f1.getNome() == f2.getNome())
	{
		if(f1.tamanhoStock() < f2.tamanhoStock())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool farmacia_SortFunc_Nome_Decrescente(Farmacia &f1, Farmacia &f2)
{
	if(f1.getNome() > f2.getNome())
		return true;
	else if(f1.getNome() == f2.getNome())
	{
		if(f1.tamanhoStock() < f2.tamanhoStock())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool farmacia_SortFunc_TamanhoStock_Crescente(Farmacia &f1, Farmacia &f2)
{
	if(f1.tamanhoStock() < f2.tamanhoStock())
		return true;
	else if(f1.tamanhoStock() == f2.tamanhoStock())
	{
		if(f1.getNome() < f2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool farmacia_SortFunc_TamanhoStock_Decrescente(Farmacia &f1, Farmacia &f2)
{
	if(f1.tamanhoStock() > f2.tamanhoStock())
		return true;
	else if(f1.tamanhoStock() == f2.tamanhoStock())
	{
		if(f1.getNome() < f2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}
