#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "Excecoes.h"


using namespace std;

typedef unsigned int uint;

enum ord_pessoas { id_cres = 0, id_dec, idade_cres, idade_dec, nome_cres, nome_dec, nif_cres, nif_dec, n_comp_cres, n_comp_dec, sal_cres, sal_dec };

// ----------Classes----------



class Morada {

public:

	/**
	* @brief Construtor default da classe Morada, constroi o objeto com a cidade igual a SEM_CIDADE, 
	* o endere�o igual a SEM_ENDERECO e o codigo postal igual a 0000-000
	*/

	Morada();

	/**
	* @brief Construtor da classe Morada que inicia os atributos com os valores passados
	* como argumento
	*
	* @param morada			valor do atributo morada
	* @param codigoPostal	valor do atributo codigoPostal
	* @param cidade			valor do atributo cidade
	*/
	Morada(string morada, string codigoPostal, string cidade);

	/**
		LUIS VE ISTO
	*/
	Morada(string simp);

	/**
	* @brief altera o valor dos atributos do objeto para os atributos da morada dada
	*
	* @param	novaMorada			valor do atributo morada
	* @return						true se a morada foi alterada com sucesso, falso caso contraio
	*/
	bool mudaMorada(Morada novaMorada);

	/**
	* @brief Envia para uma output stream os valores dos atributos da morada com o formato
	* endere�o endl codigoPostal space cidade
	*
	* @param	os			valor do atributo morada
	* @param	mor
	* @return				true se a morada foi alterada com sucesso, falso caso contraio
	*/
	friend ostream& operator<< (ostream& os, const Morada& mor);


	/**
	 * @brief Imprime a data num formato especifico para ser guardado num ficheiro de texto
	 *
	 * @param os Stream onde e suposto imprimir a data
	 * @return
	 */
	ostream& printSimp(ostream& os) const;
private:
	/**
	 * @brief Endereco da morada
	 */
	string endereco;
	/**
	 * @brief Codigo postal
	 */
	string codigoPostal;
	/**
	 * @brief Cidade
	 */
	string cidade;
};

class Data {

public:

	/**
	* @brief Construtor default da classe Data, constroi o objeto  com a data(dia, mes
	* e ano) atual.
	*/
	Data();

	/**
	* @brief constroi a classe Data com os valores para o dia, mes e ano dados
	*
	* @param dia dia associado � data
	* @param mes mes associado � data
	* @param ano ano associado � data
	*/
	Data(uint dia,uint mes,uint ano);

	/**
	* @brief constroi a classe Data a partir de um string no formato DD-MM-YYYY em 
	* os valores de '-' podem ser um simbolo qualquer
	*
	* @param dataDMY string no formato DD-MM-YYYY
	*/
	Data(string dataDMY);


	/**
	* @brief retorna num string a data guardada, no formato DD-MM-YYYY(default) se o parametro
	* dmy � true e YYYY-MM-DD se dmy � falso
	*
	* @param	dmy	true se formato DD-MM-YYYY, falso caso YYYY-MM-DD
	* @return		string com a data no formato pretendido 
	*/
	string getData(bool dmy = true);


	/**
	* @brief retorna o ano associado ao objeto data
	*
	* @return	ano associado ao objeto data
	*/
	uint getAno() const;

	/**
	* @brief retorna o mes associado ao objeto data
	*
	* @return	mes associado ao objeto data
	*/
	uint getMes() const;

	/**
	* @brief retorna o dia associado ao objeto data
	*
	* @return	dia associado ao objeto data
	*/
	uint getDia() const;



	/**
	* @brief verifica se uma data � "menor" que a outra
	*
	* @param d2	refer�ncia para a segunda data a ser comparada
	* @return	true se a data do objeto � antes da data de d2
	*/
	bool operator < (Data& d2) const;

	/**
	* @brief envia para a stream os a data no formato DD-MM-YYYY
	*
	* @param os	refer�ncia para uma output stream
	* @param d	refer�ncia para uma data
	* @return	a output stream de argumento
	*/
	friend ostream& operator<<(ostream& os, const Data& d);

protected:
	/**
	* @brief dia associado ao presente objeto de Data
	*/
	uint dia;

	/**
	* @brief mes associado ao presente objeto de Data
	*/
	uint mes;

	/**
	* @brief ano associado ao presente objeto de Data
	*/
	uint ano;

};

class Time {

protected:

	/**
	* @brief segundo associado ao presente objeto de Time
	*/
	uint segundo;
	/**
	* @brief minuto associado ao presente objeto de Time
	*/
	uint minuto;
	/**
	* @brief hora associado ao presente objeto de Time
	*/
	uint hora;

public:

	/**
	* @brief Construtor default da classe Time, constroi o objeto  com o tempo(hora, minuto
	* e segundo) atual.
	*/
	Time();

	/**
	* @brief Constroi um objeto da classe Time a partir das informacoes contidas na string passada como argumento
	* 
	* @return string com as horas no formato HH:MM:SS
	*/
	Time(string time);


	/**
	* @brief constroi a classe Time com os valores para a hora, minuto e segundo dados
	*
	* @param hora		hora associado ao time
	* @param minuto		minuto associado ao time
	* @param segundo	segundo associado ao time
	*/
	Time(uint hora, uint minuto, uint segundo = 0);


	/*
	* @brief retorna um string com o tempo associado ao objeto no formato HH:MM:SS
	*
	* @param mostraSegundos	mostra tempo no formato HH:MM:SS se true e HH:MM se false
	* @return				string com o tempo num formato pretendido
	*/
	string getTime(bool mostraSegundos = false);

	/**
	* @brief retorna a hora associado ao objeto tempo
	*
	* @return	hora associada ao objeto tempo
	*/
	uint getHora() const;

	/**
	* @brief retorna os minutos associados ao objeto tempo
	*
	* @return	minutos associados ao objeto tempo
	*/
	uint getMin() const;

	/**
	* @brief retorna os segundos associados ao objeto tempo
	*
	* @return	segundos associados ao objeto tempo
	*/
	uint getSeg() const;

	/**
	* @brief envia para a stream os a data no formato DD-MM-YYYY
	*
	* @param os	refer�ncia para uma output stream
	* @param d	refer�ncia para uma hora
	* @return	a output stream de argumento
	*/
	friend ostream& operator<<(ostream& os, const Time& d);

};

class Timestamp: public Time, public Data {

public:
	/**
	* @brief constroi um objeto da classe Timestamp com a data e tempo atuais
	*/
	Timestamp();

	/**
	* @brief constroi um objeto da classe Timestamp com a data e tempo passados como parametro
	*
	* @param data	data associada ao Timestamp
	* @param time	tempo associado ao Timestamp
	*/
	Timestamp(Data data, Time time);

	/**
	* @brief constroi um objeto da classe Timestamp com a data e tempo que estao na string passada com argumento
	*
	* @param time	data associada ao Timestamp
	*/
	Timestamp(string time);

	/**
	* @brief retorna um string com o Timestamp no formato DD/MM//YYYY | HH:MM:SS
	*
	* @return	timestamp no formato DD/MM//YYYY | HH:MM:SS
	*/
	string getTstamp();
	/**
	* @brief envia para a stream os a data e horas no formato DD-MM-YYYY e HH:MM:SS
	*
	* @param os	refer�ncia para uma output stream
	* @param d	refer�ncia para uma timestamp
	* @return	a output stream de argumento
	*/
	friend ostream& operator<<(ostream& os, const Timestamp& d);
};


// ----------Fun��es----------

/**
* @brief verifica se o ano dado � bisexto ou nao
*
* @param	year		ano a verfificar
* @return				true se o ano e bissexto, falso caso contrario
*/
bool isLeap(int year);

/**
* @brief retorna o numero de meses de um mes de um dado ano
*
* @param	year		ano a verificar
* @param	month		mes a verificar
* @return				numero de meses de um mes de um dado ano
*/
int daysInMonth(int month, int year);

/**
* @brief verfica se o codigo postal dado � valido, isto �, se est� no formato DDDD-DDD, em que D � um digito
*
* @param	codigPostal		string com o codigo postal a verificiar
* @return					true se o codigo postal � valido, falso caso contrario
*/
bool codigoPostalValido(string codigoPostal);

/**
* @brief coloca a string dada em letras maiusculas
*
* @param	input		referencia para a string a alterar
* @return				
*/
void toUpper(string& input);




#endif /* SRC_UTIL_H_ */


