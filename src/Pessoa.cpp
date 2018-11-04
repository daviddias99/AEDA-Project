#include <string>
#include "Pessoa.h"
using namespace std;


Pessoa::Pessoa(string n ,  Morada morada , uint  nif, uint ncc , uint nss , uint nus , char sex , float altura, string nacionalidade):nome(n), NIF(nif), morada(morada), NCC(ncc),NSS(nss),NUS(nus){

	this->sexo = sex;
	this->nacionalidade = nacionalidade;
	this->altura = altura;

}

string Pessoa::getNome() const
{
	return this->nome;
}

uint  Pessoa::getNIF() const
{
	return this->NIF;
}

Morada Pessoa::getMorada() const
{
	return this->morada;
}
uint Pessoa::getIdade() const
{

	Data atual = Data();
	uint anoA = atual.getAno();
	uint anoN = this->dataNascimento.getAno();
	uint mesA = atual.getMes();
	uint mesN = this->dataNascimento.getMes();
	uint diaA = atual.getDia();
	uint diaN = this->dataNascimento.getDia();

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

Empregado::Empregado(uint sal, string pharm, string pos) :salario(sal), farmaciaNome(pharm), cargo(pos)
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

bool Empregado::setCargo(string novoCargo)
{

	this->cargo = novoCargo;

	return true;
}

Cliente::Cliente()
{
}

bool Cliente::adicionaVenda(Venda * novaVenda)
{
	this->historicoVendas.push_back(novaVenda);

	return true;
}
