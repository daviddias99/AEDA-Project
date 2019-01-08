#include "Encomenda.h"
#include "Medicamento.h";

bool Encomenda::adicionaProduto(Produto* novoProduto, uint quantidade)
{
	if (quantidade == 0)
		return false;
	ItemListaProdutos novoItem = { novoProduto,quantidade };

	ListaProdutos::iterator iterator = find(this->listaProdutos.begin(), this->listaProdutos.end(), novoItem);

	if (iterator == listaProdutos.end()) {
		listaProdutos.insert(listaProdutos.begin(), novoItem);
		this->valorEncomenda += quantidade * novoProduto->getPreco();
	}
	else {

		iterator->second += quantidade;
		this->valorEncomenda += iterator->first->getPreco() * iterator->second;
	}
		
	return true;
}

bool Encomenda::removeProduto(Produto* produto, uint quantidade, bool removeTudo) {

	if ( (quantidade == 0) && !removeTudo)
		return false;

	ItemListaProdutos novoItem = { produto,quantidade };

	ListaProdutos::iterator iterator = find(this->listaProdutos.begin(), this->listaProdutos.end(), novoItem);

	if (iterator == listaProdutos.end())
		return true;
	else {

		if (iterator->second - quantidade <= 0) {

			this->valorEncomenda -= iterator->first->getPreco() * iterator->second;
			iterator->second = 0;
		}
		else {
			this->valorEncomenda -= iterator->first->getPreco() * quantidade;
			iterator->second -= quantidade;
		}
	}
		

	if (removeTudo || (iterator->second == 0)) {

		this->listaProdutos.erase(iterator);
		return true;
	}

	return true;
}

bool Encomenda::terminaEncomenda()
{
	if (this->listaProdutos.size() == 0)
		return false;

	this->stamp = Timestamp();
	this->terminada = true;

	return true;
}

float Encomenda::getValor() const
{

	return this->valorEncomenda;
}

string Encomenda::getNomeFarmacia()
{
	return this->farmaciaOrigem;
}

string Encomenda::getNomeFornecedor()
{
	return this->fornecedorOrigem;
}

Timestamp Encomenda::getTStamp() const
{
	if(!this->terminada)
		return Timestamp(Data(0,0,0), Time(0,0,0));

	return this->stamp;
}

uint Encomenda::getQuantidadeProdutos() const
{

	ListaProdutos::const_iterator it = this->listaProdutos.begin();
	ListaProdutos::const_iterator ite = this->listaProdutos.end();
	uint resultado = 0;

	while (it != ite) {

		resultado += it->second;
		it++;
	}

	return resultado;
}

const ListaProdutos & Encomenda::getProdutos()
{
	return this->listaProdutos;
}

void Encomenda::mudaFornecedor(string novoFornecedor)
{
	this->fornecedorOrigem = novoFornecedor;
}

ostream & Encomenda::print_resumo(ostream & os) const
{
	os << "Origem: " << this->farmaciaOrigem << endl;
	os << "Data da encomenda: " << this->stamp.getTstamp() << endl;
	os << "Numero de produtos: " << this->getQuantidadeProdutos() << " Valor: " << this->getValor() << endl;

	return os;
}

ostream & Encomenda::print_full(ostream & os) const
{
	this->print_resumo(os);
	cout << endl << "Produtos:" << endl;

	ListaProdutos::const_iterator it = this->listaProdutos.begin();
	ListaProdutos::const_iterator ite = this->listaProdutos.end();

	while(it != ite) {

		pair<Produto*, uint> atual = *it;
		atual.first->printListForm(cout) << " #Quantidade: " << atual.second << endl;

		it++;
	}

	return os;
}

ostream & Encomenda::printSimp(ostream & os) const
{
	os << farmaciaOrigem << "\\" << this->fornecedorOrigem << "\\";
	os << valorEncomenda << "\\" << this->stamp << "\\";
	
	for (ListaProdutos::const_iterator it = listaProdutos.begin(); it != listaProdutos.end(); it++) {
			
		it->first->printSimp(os);
		os << "#" << it->second << "!";
	}

	return os;
}

Encomenda::Encomenda(string nomeFarmacia, string nomeFornecedor) {

	this->terminada = false;
	this->farmaciaOrigem = nomeFarmacia;
	this->fornecedorOrigem = nomeFornecedor;
	this->stamp = Timestamp(Data(0,0,0), Time(0,0,0));
	this->valorEncomenda = 0;

}

Encomenda::Encomenda(string simp) {

	string linha = simp;
	string produtoSimp, nome_prod, desc_prod;
	float preco_prod, iva_prod, desc_receita;
	unsigned long int cod_produto;
	bool vend_sem_rec, pode_ser_rec;
	uint quant;

	this->farmaciaOrigem = linha.substr(0, linha.find_first_of('\\'));
	linha = linha.substr(linha.find_first_of('\\') + 1);

	this->fornecedorOrigem = linha.substr(0, linha.find_first_of('\\'));
	linha = linha.substr(linha.find_first_of('\\') + 1);

	this->valorEncomenda = stof(linha.substr(0, linha.find_first_of('\\')));
	linha = linha.substr(linha.find_first_of('\\') + 1);

	this->stamp = Timestamp(linha.substr(0, linha.find_first_of('\\')));
	linha = linha.substr(linha.find_first_of('\\'));
	this->terminada = true;
	if (linha != "\\") {
		while (linha != "!") {
			linha = linha.substr(1);
			produtoSimp = linha.substr(0, linha.find_first_of('#'));
			quant = stoul(linha.substr(linha.find_first_of('#') + 1, linha.find_first_of('!')));
			linha = linha.substr(linha.find_first_of('!'));

			bool isMed = false;
			if (count(produtoSimp.begin(), produtoSimp.end(), '&') > 4)
				isMed = true;

			cod_produto = stoul(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			nome_prod = produtoSimp.substr(0, produtoSimp.find_first_of('&'));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			desc_prod = produtoSimp.substr(0, produtoSimp.find_first_of('&'));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			preco_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
			produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
			iva_prod = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));


			if (!isMed) {
				this->listaProdutos.insert(listaProdutos.begin(), pair<Produto *, uint>(new Produto(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod), quant));
			}
			else {
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				vend_sem_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				pode_ser_rec = stoi(produtoSimp.substr(0, produtoSimp.find_first_of('&')));
				produtoSimp = produtoSimp.substr(produtoSimp.find_first_of('&') + 1);
				desc_receita = stof(produtoSimp.substr(0, produtoSimp.find_first_of('&')));

				this->listaProdutos.insert(listaProdutos.begin(), pair<Produto *, uint>(new Medicamento(cod_produto, nome_prod, desc_prod, preco_prod, iva_prod, vend_sem_rec, pode_ser_rec, desc_receita), quant));
			}
		}
	}
}

bool operator==(const ItemListaProdutos& p1, const ItemListaProdutos& p2) {


	return p1.first->getCodigo() == p2.first->getCodigo();
}