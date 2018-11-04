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

Cliente::Cliente(CartaoCidadao cc, Morada morada): Pessoa(cc,morada)
{
}

bool Cliente::adicionaVenda(Venda * novaVenda)
{
	this->historicoVendas.push_back(novaVenda);

	return true;
}
