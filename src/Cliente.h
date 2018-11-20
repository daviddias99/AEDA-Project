#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"

/** @defgroup Pessoa Pessoa
 * @{
 *
 * Classe pessoa e suas classes derivadas
 */

class Cliente :public Pessoa {
public:
	/**
	* @brief Construtor da classe cliente
	* @param nome Nome do cliente
	* @param nif NIF do cliente. E zero se nao for indicado
	* @param dataNasc Data de nascimento do cliente
	* @param morada Morada atual do cliente
	*/
	Cliente(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada());

	/**
	* @brief Adiciona a venda indicada no seu parametro a lista de compras do cliente
	* @param v Apontador para uma venda relizada pelo cliente
	* @return true se a venda foi adicionada com sucesso a lista de compras
	* false se ocorreu algum erro
	*/
	bool adicionaCompra(Venda* v);
	/**
	* @brief Devolve o numero de compras efetuadas pelo cliente
	* @return Numero de compras efetuadas pelo cliente
	*/
	uint getNumCompras() const;
	/**
	* @brief Devolve o membro-dado ID do cliente
	* @return ID do cliente
	*/
	uint getID() const;
	/**
	 * @brief Imprime as informacoes do cliente num formato legivel
	 * 
	 * @param os Stream onde sao imprimidas as informacoes
	 * @return Stream onde foram imprimidas as informacoes
	 */
	ostream& print(ostream& os) const;
	/**
	 * @brief Imprime as informacoes do cliente num formato simplificado, utilizado para guardar informacoes das pessoas em ficheiro de texto
	 * 
	 * @param os Stream onde sao imprimidas as informacoes
	 * @return Stream onde foram imprimidas as informacoes
	 */
	ostream& printSimp(ostream& os) const;
	/**
	* @brief Overload do operador <, os clientes sao comparados por NIF
	*
	* @param e1 Cliente na esquerda do operador
	* @param e2 Cliente na direita do operador
	* @return True caso o NIF do cliente da esquerda seja menor que o NIF do da direita
	*/
	friend bool operator<(const  Cliente& c1, const Cliente & c2);
	/**
	 * @brief Overload do operador ==, os clientes sao comparados por NIF
	 *
	 * @param e1 Cliente na esquerda do operador
	 * @param e2 Cliente na direita do operador
	 * @return True caso o NIF do cliente da esquerda seja igual ao NIF do da direita
	 */
	friend bool operator==(const  Cliente& c1, const Cliente & c2);
private:
	/**
	 * @brief Vector de apontadores para vendas, que guarda o historico de compras do cliente
	 */
	vector<Venda*> historicoCompras;
	/**
	 * @brief Numero de identificacao unico do cliente
	 */
	uint ID;
	/**
	 * @brief Variavel static utilizada para determinar o ID de um novo cliente
	 */
	static uint currentID;
};


bool Cliente_SortFunc_ID_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_ID_Decrescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_numCompras_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_numCompras_Decrescente(Cliente* p1, Cliente* p2);


#endif // !CLIENTE_H
