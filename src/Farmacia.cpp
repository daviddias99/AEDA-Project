#include "Farmacia.h"

Farmacia::Farmacia(string nome, Morada morada, Empregado gerente) :nome(nome), morada(morada), gerente(gerente) {}

void Farmacia::addProduto(Produto produto, int quantidade)
{
	map<Produto, int>::iterator it;
	it = stock.find(produto);
	if(it != stock.end())
		it->second += quantidade;
	else
		stock[produto] = quantidade;
}

void addEmpregado(Empregado empregado)
{

}

void Farmacia::removeQuantidade(Produto produto, int quantidade)
{
	map<Produto, int>::iterator it;
	it = stock.find(produto);
	if(it != stock.end()) {
		if(it->second >= quantidade) {
			it->second -= quantidade;
			return;
		}
	}

	throw ProdutoNaoExiste(produto.getNome());
}

void Farmacia::remProduto(Produto produto)
{
	map<Produto, int>::iterator it;
	it = stock.find(produto);
	if(it != stock.end()) {
		stock.erase(it);
		return;
	}

	throw ProdutoNaoExiste(produto.getNome());

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

	Produto p1(codigo, nome, descricao, preco);
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

	int codigo;

	cout << "Codigo do produto: ";
	cin >> codigo;



}
