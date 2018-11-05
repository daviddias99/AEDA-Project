#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;

// ----------Classes----------

class Morada {

public:
	Morada(string morada_linha1 = "RUA_DEFAULT", string morada_linha2 = "PORTA 0, 3º ANDAR DIREITO", string codigoPostal = "0000-000", string cidade = "CIDADE_DEFAULT");
	bool mudaMorada(Morada novaMorada);
private:
	string morada_linha1;
	string morada_linha2;
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

class CartaoCidadao {

public:

	CartaoCidadao(string n = "NOME_DEFAULT",Data dNasc = Data(), uint  nif = 0, uint ncc = 0, uint nss = 0, uint nus = 0, char sex = 'D', float altura = 0.00, string nacionalidade = "DFT");

	const string nome;
	const Data dataNascimento;
	const uint  NIF;
	const uint  NCC;
	const uint  NSS;
	const uint  NUS;
	char sexo;
	float altura;
	string nacionalidade;
};

// ----------Funções----------

bool isLeap(int year);

int daysInMonth(int month, int year);

template< class T>
int procura(const vector<T> &v, T x);

template< class T>
int procura(const vector<T*> &v, T x);

template< class T>
int procura(const vector <T> &v, string nome);

template < class T>
int procura(const vector <T> &v, int nif);


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

#endif /* SRC_UTIL_H_ */
