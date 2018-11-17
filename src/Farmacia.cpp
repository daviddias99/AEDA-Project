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
	map<Produto *, unsigned int>::iterator it;
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

bool Farmacia::removeQuantidade(int codigo, uint quantidade)
{
	map<Produto*, unsigned int>::iterator it;
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
	map<Produto *, unsigned int>::iterator it;
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

void Farmacia::adicionarVenda(Venda* v1)
{
	vendas.push_back(v1);
}

string Farmacia::getNome() const
{
	return nome;
}

Morada* Farmacia::getMorada() const
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
	map<Produto*, unsigned int>::const_iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if( (*it->first).getCodigo() == codigo)
			return (it->first);
	}
	throw ProdutoNaoExiste(codigo);
}

unsigned int Farmacia::getTotalProdutos() const
{
	int soma = 0;
	map<Produto*, unsigned int>::const_iterator it;
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
	map<Produto*, unsigned int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		cout << "Nome: " << (*it->first).getNome() << "; Codigo: " << (*it->first).getCodigo() << "; Quantidade: " << it->second;
	}
}

ostream& escreve (ostream& os, const Farmacia& f1, int modo) //Modo = 0 -> Ecra; Modo = 1 -> Ficheiro txt
{
	os << "Nome: " << f1.getNome() << endl;
	os << "Morada: " << f1.getMorada() << endl;

	if(modo == 0) {
		os << "Numero de Empregados: " << f1.numEmpregados() << endl;
		os << "Tamanho Stock: " << f1.tamanhoStock() << endl;
		os << "Numero de Vendas: " << f1.numVendas() << endl;
	}
	else if(modo == 1) {
		for(size_t i = 0; i < f1.empregados.size(); i++)
			os << f1.empregados.at(i) << endl;
		map<Produto*, int>::iterator it;
		for(it = f1.stock.begin(); it != f1.stock.end(); it++)
			os << (*it->first) << endl << it->second;
		for (size_t i = 0; i < f1.vendas.size(); i++)
			os << f1.vendas.at(i) << endl;
	}

	return os;
}

unsigned int Farmacia::numEmpregados() const
{
	return empregados.size();
}

unsigned int Farmacia::tamanhoStock() const
{
	return stock.size();
}

unsigned int Farmacia::numVendas() const
{
	return vendas.size();
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

ostream& Farmacia::printSimp(ostream& os) const {

	os << nome << "\\";
	morada.printSimp(os);
	os << "\\";
	
	for (map<Produto *, unsigned int>::const_iterator it = stock.begin(); it != stock.end(); it++) {

		os << "!";
		it->first->printSimp(os);
		os << "#" << it->second;
	}

	os << "\\" << endl;

	return os;
}

bool farmacia_SortFunc_NumVendas_Crescente(Farmacia &f1, Farmacia &f2)
{
	if(f1.numVendas() > f2.numVendas())
		return true;
	else if(f1.numVendas() == f2.numVendas())
	{
		if(f1.getNome() < f2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool farmacia_SortFunc_NumVendas_Decrescente(Farmacia &f1, Farmacia &f2)
{
	if(f1.numVendas() < f2.numVendas())
		return true;
	else if(f1.numVendas() == f2.numVendas())
	{
		if(f1.getNome() < f2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}
