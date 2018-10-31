#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>

using namespace std;


class Morada {

public:
	Morada(string rua, string codigoPostal, int porta, string cidade);
	bool mudaMorada(Morada novaMorada);
private:
	string rua;
	string codigoPostal;
	int porta;
	string cidade;
};

class Data {

public:
	Data();
	Data(unsigned int dia, unsigned int mes, unsigned int ano);
	string getData();
	unsigned int getAno();
	unsigned int getMes();
	unsigned int getDia();

private:
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;

};

template< class T>
int procura(const vector<T> &v, T x)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if(v[middle] < x)
			left = middle + 1;
		else if(x < v[middle])
			right = middle - 1;
		else return middle;

	}
	return -1;
}

template< class T>
int procura(const vector<T*> &v, T x)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if(*v[middle] < x)
			left = middle + 1;
		else if(x < *v[middle])
			right = middle - 1;
		else return middle;

	}
	return -1;
}

class FarmaciaNaoExiste {
	string nome;
public:
	FarmaciaNaoExiste(string nome) {this->nome = nome;}
	string getNome() const {return nome;}
};

class ClienteNaoExiste {
	string nome;
public:
	ClienteNaoExiste(string nome) {this->nome = nome;}
	string getNome() const {return nome;}
};

class EmpregadoNaoExiste {
	string nome;
public:
	EmpregadoNaoExiste(string nome) {this->nome = nome;}
	string getNome() const {return nome;}
};

class ProdutoNaoExiste {
	string nome;
public:
	ProdutoNaoExiste(string nome) {this->nome = nome;}
	string getNome() const {return nome;}
};


#endif /* SRC_UTIL_H_ */
