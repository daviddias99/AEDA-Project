#include <string>
#include "Pessoa.h"
using namespace std;


Pessoa::Pessoa(CartaoCidadao cc, Morada morada):pessoaId(cc), morada(morada){

}

string Pessoa::getNome() const
{
	return this->pessoaId.nome;
}

uint  Pessoa::getNIF() const
{
	return this->pessoaId.NIF;
}

Morada Pessoa::getMorada() const
{
	return this->morada;
}
uint Pessoa::getIdade() const
{

	Data atual = Data();
	uint anoA = atual.getAno();
	uint anoN = this->pessoaId.dataNascimento.getAno();
	uint mesA = atual.getMes();
	uint mesN = this->pessoaId.dataNascimento.getMes();
	uint diaA = atual.getDia();
	uint diaN = this->pessoaId.dataNascimento.getDia();

	uint idade = anoA - anoN;
	if (mesA < mesN)
		idade--;
	else if (mesA == mesN) {
		if (diaA < diaN)
			idade--;
	}

	return idade;

}

bool Pessoa::setMorada(Morada newMorada)
{
	this->morada = newMorada;

	return true;
}

Empregado::Empregado(CartaoCidadao cc, Morada morada, uint sal, string pharm, string pos) : Pessoa(cc,morada),salario(sal), farmaciaNome(pharm), cargo(pos)
{


}

uint Empregado::getSalario() const
{
	return this->salario;
}

string Empregado::getNomeFarmacia() const
{
	
	return this->farmaciaNome;

}

string Empregado::getCargo() const
{
	return this->cargo;
}

uint Empregado::getNumVendas()
{
	return this->historicoVendas.size();
}

bool Empregado::setSalario(uint novoSalario)
{
	if (novoSalario < 0)
		return false;


	this->salario = novoSalario;

	return true;
}

bool Empregado::setFarmacia(string  novaFarmacia)
{
	this->farmaciaNome = novaFarmacia;

	return true;
}



	return true;
}

Cliente::Cliente(CartaoCidadao cc, Morada morada): Pessoa(cc,morada)
{
}

bool Cliente::adicionaCompra(Venda * novaVenda)
{
	this->historicoCompras.push_back(novaVenda);

	return true;
}

uint Cliente::getNumCompras()
{
	return this->historicoCompras.size();
}

bool Pessoa_SortFunc_Idade_Crescente(Pessoa& p1, Pessoa& p2) {

	if (p1.getIdade() < p2.getIdade())
		return true;
	else if (p1.getIdade() == p2.getIdade())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}	
	else
		return false;
}

bool Pessoa_SortFunc_Idade_Decrescente(Pessoa& p1, Pessoa& p2) {

	if (p1.getIdade() > p2.getIdade())
		return true;
	else if (p1.getIdade() == p2.getIdade())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Pessoa_SortFunc_Nome_Crescente(Pessoa& p1, Pessoa& p2) {

	if (p1.getNome() < p2.getNome())
		return true;
	else if (p1.getNome() == p2.getNome())
	{
		if (p1.getIdade() < p2.getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Pessoa_SortFunc_Nome_Decrescente(Pessoa& p1, Pessoa& p2) {

	if (p1.getNome() > p2.getNome())
		return true;
	else if (p1.getNome() == p2.getNome())
	{
		if (p1.getIdade() < p2.getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Pessoa_SortFunc_NIF_Crescente(Pessoa& p1, Pessoa& p2) {

	if (p1.getNIF() < p2.getNIF())
		return true;
	else if (p1.getNIF() == p2.getNIF())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Pessoa_SortFunc_NIF_Decrescente(Pessoa& p1, Pessoa& p2) {

	if (p1.getNIF() > p2.getNIF())
		return true;
	else if (p1.getNIF() == p2.getNIF())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Idade_Crescente(Empregado& p1, Empregado& p2) {

	if (p1.getIdade() < p2.getIdade())
		return true;
	else if (p1.getIdade() == p2.getIdade())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Idade_Decrescente(Empregado& p1, Empregado& p2) {

	if (p1.getIdade() > p2.getIdade())
		return true;
	else if (p1.getIdade() == p2.getIdade())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Nome_Crescente(Empregado& p1, Empregado& p2) {

	if (p1.getNome() < p2.getNome())
		return true;
	else if (p1.getNome() == p2.getNome())
	{
		if (p1.getIdade() < p2.getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Nome_Decrescente(Empregado& p1, Empregado& p2) {

	if (p1.getNome() > p2.getNome())
		return true;
	else if (p1.getNome() == p2.getNome())
	{
		if (p1.getIdade() < p2.getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Empregado_SortFunc_NIF_Crescente(Empregado& p1, Empregado& p2) {

	if (p1.getNIF() < p2.getNIF())
		return true;
	else if (p1.getNIF() == p2.getNIF())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_NIF_Decrescente(Empregado& p1, Empregado& p2) {

	if (p1.getNIF() > p2.getNIF())
		return true;
	else if (p1.getNIF() == p2.getNIF())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Salario_Crescente(Empregado& p1, Empregado& p2) {

	if (p1.getSalario() < p2.getSalario())
		return true;
	else if (p1.getSalario() == p2.getSalario())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_Salario_Decrescente(Empregado& p1, Empregado& p2) {

	if (p1.getSalario() > p2.getSalario())
		return true;
	else if (p1.getSalario() == p2.getSalario())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_numVendas_Crescente(Empregado& p1, Empregado& p2) {

	if (p1.getNumVendas() < p2.getNumVendas())
		return true;
	else if (p1.getNumVendas() == p2.getNumVendas())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Empregado_SortFunc_numVendas_Decrescente(Empregado& p1, Empregado& p2) {

	if (p1.getNumVendas() > p2.getNumVendas())
		return true;
	else if (p1.getNumVendas() == p2.getNumVendas())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_Idade_Crescente(Cliente& p1, Cliente& p2) {

	if (p1.getIdade() < p2.getIdade())
		return true;
	else if (p1.getIdade() == p2.getIdade())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_Idade_Decrescente(Cliente& p1, Cliente& p2) {

	if (p1.getIdade() > p2.getIdade())
		return true;
	else if (p1.getIdade() == p2.getIdade())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_Nome_Crescente(Cliente& p1, Cliente& p2) {

	if (p1.getNome() < p2.getNome())
		return true;
	else if (p1.getNome() == p2.getNome())
	{
		if (p1.getIdade() < p2.getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_Nome_Decrescente(Cliente& p1, Cliente& p2) {

	if (p1.getNome() > p2.getNome())
		return true;
	else if (p1.getNome() == p2.getNome())
	{
		if (p1.getIdade() < p2.getIdade())
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Cliente_SortFunc_NIF_Crescente(Cliente& p1, Cliente& p2) {

	if (p1.getNIF() < p2.getNIF())
		return true;
	else if (p1.getNIF() == p2.getNIF())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_NIF_Decrescente(Cliente& p1, Cliente& p2) {

	if (p1.getNIF() > p2.getNIF())
		return true;
	else if (p1.getNIF() == p2.getNIF())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}



bool Cliente_SortFunc_numCompras_Crescente(Cliente& p1, Cliente& p2) {

	if (p1.getNumCompras() < p2.getNumCompras())
		return true;
	else if (p1.getNumCompras() == p2.getNumCompras())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Cliente_SortFunc_numCompras_Decrescente(Cliente& p1, Cliente& p2) {

	if (p1.getNumCompras() > p2.getNumCompras())
		return true;
	else if (p1.getNumCompras() == p2.getNumCompras())
	{
		if (p1.getNome() < p2.getNome())
			return true;
		else
			return false;
	}
	else
		return false;
}
