#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>


using namespace std;

typedef unsigned int uint;

// ----------Classes----------

class Morada {

public:
	Morada();
	Morada(string morada, string codigoPostal, string cidade);
	Morada(string simp);
	bool mudaMorada(Morada novaMorada);
	friend ostream& operator<< (ostream& os, const Morada& mor);
	ostream& printSimp(ostream& os) const;
private:
	string endereco;
	string codigoPostal;
	string cidade;
};

class Data {

public:
	Data();
	Data(uint dia,uint mes,uint ano);
	Data(string dataDMY);
	string getData(bool dmy = true);
	uint getAno() const;
	uint getMes() const;
	uint getDia() const;
	bool operator < (Data& d2) const;
	friend ostream& operator<<(ostream& os, const Data& d);

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
	string getTime(bool mostraSegundos = false);
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
/*
template< class T>
int procura(const vector<T> &v, T x);

template< class T>
int procura(const vector<T*> &v, T x);

template< class T>
int procura(const vector<T*> &v, T* x);

template< class T>
int procura(const vector <T> &v, string nome);

template < class T>
int procura(const vector <T> &v, int nif);

template < class T>
int procura(const vector <T*> &v, int nif);
*/

/*template< class T>
int procura2(vector<T> &v, T x);

template< class T>
int procura2(const  vector <T> &v, string nome);

template < class T>
int procura2( const vector <T> &v, int nif);*/



// ----------Exceções----------


class FarmaciaNaoExiste {
	string nome;
public:
	FarmaciaNaoExiste(string nome) {this->nome = nome;}
	string getNome() const {return nome;}
};

class ClienteNaoExiste {
	int nif;
public:
	ClienteNaoExiste(int nif) {this->nif = nif;}
	string getNIF() const {return to_string(nif);}
};

class EmpregadoNaoExiste {
	int nif;
public:
	EmpregadoNaoExiste(int nif) {this->nif = nif;}
	string getNIF() const {return to_string(nif);}
};

class ProdutoNaoExiste {
	int codigo;
public:
	ProdutoNaoExiste(int codigo) {this->codigo = codigo;}
	string getCodigo() const {return  to_string(codigo);}
};

class DataInvalida {

};

class TimeInvalido {

};

class CargoInvalido {
private:

	string cargo;

public:

	CargoInvalido(string n) { this->cargo = n; };
	string getName() { return cargo; };

};

#endif /* SRC_UTIL_H_ */


