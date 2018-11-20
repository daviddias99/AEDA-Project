#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>


using namespace std;

typedef unsigned int uint;

enum ord_pessoas { id_cres = 0, id_dec, idade_cres, idade_dec, nome_cres, nome_dec, nif_cres, nif_dec, n_comp_cres, n_comp_dec, sal_cres, sal_dec };

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

bool codigoPostalValido(string codigoPostal);

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
	uint ID;
public:
	ClienteNaoExiste(uint ID) {this->ID = ID;}
	string getID() const {return to_string(ID);}
};

class EmpregadoNaoExiste {
	uint ID;
public:
	EmpregadoNaoExiste(uint ID) {this->ID = ID;}
	string getID() const {return to_string(ID);}
};

class ProdutoNaoExiste {
	int codigo;
public:
	ProdutoNaoExiste(int codigo) {this->codigo = codigo;}
	string getCodigo() const {return  to_string(codigo);}
};

class ProdutoRepetido {
	int codigo;
public:
	ProdutoRepetido(int codigo) { this->codigo = codigo; }
	string getCodigo() const { return  to_string(codigo); }
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

class MoradaInvalida {

private:

	string reason;
public:

	MoradaInvalida(string reason):reason(reason){}
	string getReason() { return reason; }

};

#endif /* SRC_UTIL_H_ */


