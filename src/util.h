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
	* o endereco igual a SEM_ENDERECO e o codigo postal igual a 0000-000
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
	 * @brief Constroi um objeto do tipo morada a partir de uma string que contem as informacoes de uma morda, no formato lido de um ficheiro de texto
	 * 
	 * @param simp String que contem as informacoes da morada
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
	* @param dia dia associado a data
	* @param mes mes associado a data
	* @param ano ano associado a data
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
	* dmy a true e YYYY-MM-DD se dmy a falso
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
	* @brief verifica se uma data a "menor" que a outra
	*
	* @param d2	referencia para a segunda data a ser comparada
	* @return	true se a data do objeto e antes da data de d2
	*/
	bool operator < (Data& d2) const;

	/**
	* @brief envia para a stream os a data no formato DD-MM-YYYY
	*
	* @param os	referencia para uma output stream
	* @param d	referencia para uma data
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


// ----------Funcoes----------

/**
* @brief verifica se o ano dado e bissexto ou nao
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
* @brief verfica se o codigo postal dado e valido, isto e, se esta no formato DDDD-DDD, em que D e um digito
*
* @param	codigPostal		string com o codigo postal a verificiar
* @return					true se o codigo postal e valido, falso caso contrario
*/
bool codigoPostalValido(string codigoPostal);

/**
* @brief coloca a string dada em letras maiusculas
*
* @param	input		referencia para a string a alterar
* @return				
*/
void toUpper(string& input);

/**
 * @brief Aplica pesquisa binaria a um vetor
 * 
 * @tparam T 
 * @param v Vetor sobre o qual se pretende aplicar a pesquisa
 * @param x Elemento do vetor
 * @return Indice onde esta o elemento que se pretende procurar 
 */
template<class T>
int procura(vector<T>& v, T x)
{
	if (v.size() == 0) {
		return -1;
	}

	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (*v[middle] < *x)
			left = middle + 1;
		else if (*x < *v[middle])
			right = middle - 1;
		else return middle;

	}
	return -1;
}

/**
 * @brief Aplica pesquisa sequencial a um vetor
 * 
 * @tparam T 
 * @param v Vetor ao qual se pretende aplicar a pesquisa
 * @param x Objeto do tipo dos objetos do vetor
 * @return Indice do vetor onde esta o elemento procurado
 */
template<class T>
int procuraseq(vector<T>& v, T x)
{
	for (size_t i = 0; i < v.size(); i++) {

		if (*v.at(i) == *x) {
			return (int)i;
		}

	}

	return -1;
}

/**
 * @brief Aplica pesquisa binaria a um vetor, destina a procurar objetos pelo nome
 * 
 * @tparam X 
 * @param v Vetor sobre o qual queremos aplicar a pesquisa
 * @param nome Nome do objeto a procurar
 * @return Indice da posicao onde esta o elemento procurado
 */
template<class X>
int procura(const vector<X>& v, string nome)
{
	if (v.size() == 0) {
		return -1;
	}

	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle]->getNome() < nome)
			left = middle + 1;
		else if (nome < v[middle]->getNome())
			right = middle - 1;
		else return middle;

	}
	return -1;
}

/**
 * @brief Aplica pesquisa binaria a um vetor, destina a procurar um elemento pelo ID
 * 
 * @tparam X 
 * @param v Vetor ao qual se aplica a pesquisa binaria
 * @param ID ID do elemento que pretendemos procurar
 * @return Indice do vetor onde se encontra o elemento procurado
 */
template<class X>
int procura(const vector<X>& v, uint ID)
{
	if (v.size() == 0) {
		return -1;
	}

	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle]->getID() < ID)
			left = middle + 1;
		else if (ID < v[middle]->getID())
			right = middle - 1;
		else return middle;

	}
	return -1;
}



#endif /* SRC_UTIL_H_ */


