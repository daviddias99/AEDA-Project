#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;

// ----------Classes----------

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
	Data(uint dia,uint mes,uint ano);
	string getData(bool dmy = true);
	uint getAno() const;
	uint getMes() const;
	uint getDia() const;

private:
	uint dia;
	uint mes;
	uint ano;

};

class Time {

private:

	uint segundo;
	uint minuto;
	uint hora;

public:
	Time();
	Time(uint hora, uint minuto, uint segundo = 0);
	string getTime();
	uint getHora() const;
	uint getMin() const;
	uint getSeg() const;

};

class Timestamp: public Time, public Data {

public:

	Timestamp();
	Timestamp(Data data, Time time);
	string getTstamp();
};


// ----------Funções----------

bool isLeap(int year);
int daysInMonth(int month, int year);

template< class T>
int procura(const vector<T> &v, T x);


template< class T>
int procura(const vector<T*> &v, T x);


// ----------Exceções----------


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

class DataInvalida {

};

class TimeInvalido {

};

#endif /* SRC_UTIL_H_ */
