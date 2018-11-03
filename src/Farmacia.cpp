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
	if(gerente.nome == "") {
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
	gerente.nome = "";
	gerente.NIF = 0;
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

vector<Empregado> Farmacia::getEmpregados(string nome)
{
	vector<Empregado> v1;
	vector<Empregado>::iterator it;

	for(it = empregados.begin(); it != empregados.end(); it++) {
		if( (*it).getNome() == nome) v1.push_back(*it);
	}

	return v1;
}

Produto* Farmacia::getProduto(int codigo)
{
	map<Produto*, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		if( (*it->first).getCodigo() == codigo)
			return (it->first);
	}
	throw ProdutoNaoExiste(codigo);
}

int Farmacia::getTotalProdutos()
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

void Farmacia::gerir()
{
	cout << "FARMACIA " << nome << endl;

	char opcao;

	cout << "1 - Adicionar" << endl;
	cout << "2 - Remover" << endl;
	cout << "3 - Consultar" << endl;
	cout << "4 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		adicionar();
		break;
	case '2':
		remover();
		break;
	case '3':
		consultar();
		break;
	case '4':
		menuGerencia();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!" << endl;
		gerir();
	}
}

void Farmacia::adicionar()
{
	char opcao;

	cout << "1 - Adicionar produto" << endl;
	cout << "2 - Adicionar empregado" << endl;
	cout << "3 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		adicionarProduto();
		break;
	case '2':
		adicionarEmpregado();
		break;
	case '3':
		gerir();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!" << endl;
		adicionar();
	}
}

void Farmacia::adicionarProduto()
{
	cout << endl << "ADICIONAR PRODUTO" << endl;

	long int codigo;
	string nome, descricao;
	float preco;
	int quantidade;

	cout << "Codigo: ";
	cin >> codigo;
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Descricao: ";
	getline(cin, nome);
	cout << "Preco: ";
	cin >> preco;
	cout << "Quantidade a adicionar: ";
	cin >> quantidade;

	Produto* p1 = new Produto(codigo, nome, descricao, preco);
	addProduto(p1, quantidade);

	cout << "Produto adicionado" << endl;
	adicionar();
}

void Farmacia::adicionarEmpregado()
{
	cout << endl << "ADICIONAR EMPREGADO" << endl;

	string nome, cargo;;
	Data dataNascimento;
	unsigned int NIF, salario;
	Morada morada;
	Farmacia* farmacia;

	cout << "Nome: ";
	getline(cin, nome) >> nome;
	cout << "NIF: ";
	cin >> NIF;
	cout << "Data de Nascimento: ";
	cin >> dataNascimento;
	cout << "Salario: ";
	cin >> salario;
	cout << "Morada: ";
	cin >> morada;

	farmacia = this;

	Empregado e(nome, dataNascimento, NIF, morada, salario, farmacia, cargo);
}

void Farmacia::remover()
{
	char opcao;

	cout << "1 - Remover Produto" << endl;
	cout << "2 - Remover Empregado" << endl;
	cout << "3 - Menu anterior" << endl;
	cout << "0 - Sair da aplicacao" << endl;

	cout << "Opcao; ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		removerProduto();
		break;
	case '2':
		removerEmpregado();
		break;
	case '3':
		gerir();
		break;
	case '0':
		sair();
		break;
	default:
		cout << "Opcao Invalida!" << endl;
		remover();
	}
}

void Farmacia::removerProduto()
{
	cout << endl << "REMOVER PRODUTO" << endl;

	int codigo, quantidade;
	bool erro;

	cout << "Codigo do produto: ";
	cin >> codigo;
	cout << "Quantidade a remover( '0' para remover a quantidade total): ";
	cin >> quantidade;

	try {
		if(quantidade == 0) {
			remProduto(codigo);
			cout << "Produto removido." << endl;
		}
		else {
			erro = removeQuantidade(codigo, quantidade);
			if(!erro) cout << "Quantidade removida;" << endl;
			else cout << "Erro! Se pretende remover a quantidade total do protudo, responda '0' a quantidade;" << endl;
		}
	} catch(ProdutoNaoExiste &p1) {
		cout << "O produto de codigo " << p1.getCodigo() << " nao existe." << endl;
	}

	remover();
}

void Farmacia::removerEmpregado()
{
	cout << endl << "REMOVER EMPREGADO" << endl;

	int nif;
	cout << "NIF: ";
	cin >> nif;

	try {
		remEmpregado(nif);
		cout << "Empregado removido." << endl;
	} catch (EmpregadoNaoExiste &e) {
		cout << "Nao existe nenhum empregado com o nif " << nif << ".\n";
	}
	remover();
}

void Farmacia::consultar()
{
	cout << endl << "CONSULTAR FARMACIA" << endl;

	cout << "Nome: " << setw(4) << nome << endl;
	cout << "Morada: " << setw(4) << morada << endl;
	cout << "Gerente: " << setw(4) << "Nome: " << gerente.getNome() << endl;
	cout << setw(12) << "NIF: " << gerente.getNIF() << endl;
	cout << "Numero de empregados(incluindo gerente): " << empregados.size() << endl << endl;

	cout << "1 - Consultar empregado" << endl;
	cout << "2 - Consultar stock" << endl;
	cout << "3 - Menu anterior" << endl;
	cout << "4 - Sair" << endl;

	char opcao;

	cout << "Opcao: ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		consultarEmpregado();
		break;
	case '2':
		consultarStock();
		break;
	case '3':
		gerir();
		break;
	case '4':
		sair();
		break;
	default:
		cerr << "Opcao Invalida!" << endl;
		consultar();
		break;
	}
}

void Farmacia::consultarEmpregado()
{
	cout << endl << "CONSULTAR EMPREGADO" << endl;

	if(!empregados.size()) {
		cout << "Nenhum empregado nesta farmacia. Adicione um primeiro." << endl;
		consultar();
	}

	string name;

	cout << "Name: ";
	cin >> name;

	vector<Empregado> v1 = getEmpregados(nome);

	if(!v1.size()) {
		cout << "Nao existe nenhum empregado com esse nome." << endl;
		consultar();
	}
	else {
		vector<Empregado>::iterator it;
		for(it = v1.begin(); it != v1.end(); it++)
				cout << (*it) << endl;
	}
	consultar();
}

void Farmacia::consultarStock()
{
	cout << endl << "CONSULTAR STOCK" << endl;

	cout << "Numero de produtos diferentes: " << stock.size() << endl;
	cout << "Numero total de produtos: " << getTotalProdutos() << endl << endl;

	cout << "1 - Consultar Produto" << endl;
	cout << "2 - Consultar quantidades de todos os produtos";
	cout << "3 - Menu anterior" << endl;
	cout << "4 - Sair" << endl;

	char opcao;

	cout << "Opcao: ";
	cin >> opcao;

	switch (opcao) {
	case '1':
		consultarProduto();
		break;
	case '2':
		consultarQuantidades();
		break;
	case '3':
		consultar();
		break;
	case '4':
		sair();
		break;
	default:
		cerr << "Opcao invalida!" << endl;
		consultarStock();
	}
}

void Farmacia::consultarProduto()
{
	cout << endl << "CONSULTAR PRODUTO" << endl;

	int codigo;

	cout << "Codigo: ";
	cin >> codigo;

	Produto * p1;
	try {
		p1 = getProduto(codigo);
	} catch(ProdutoNaoExiste &p) {
		cout << "O produto com o codigo " << p.getCodigo() << " nao existe." << endl;
		consultarStock();
	}

	cout << p1;
	consultarStock();
}

void Farmacia::consultarQuantidades()
{
	map<Produto*, int>::iterator it;
	for(it = stock.begin(); it != stock.end(); it++) {
		cout << "Nome: " << (*it->first).getNome() << "; Codigo: " << (*it->first).getCodigo() << "; Quantidade: " << it->second;
	}
}
