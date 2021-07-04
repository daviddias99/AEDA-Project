#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <iomanip>
#include "util.h"
using namespace std;

/*!
 * \file Produto.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

/** @defgroup Produto Produto
 * @{
 *
 * Classe produto e classe derivada medicamento 
 */

/**
 * @brief Classe que representa as informacoes de um produto
 * 
 */

class Produto {
public:
	/**
	* @brief Construtor da classe Produto. 
	* @param code Codigo do produto
	* @param n Nome do produto
	* @param desc Descricao do produto
	* @param pr Preco do produto
	* @param i Iva do produto
	*/
	Produto(long int code, string n, string desc, float pr, float i);

	/**
	* @brief Devolve o codigo do produto
	* @return Codigo do produto
	*/
	long unsigned int getCodigo() const;

	/**
	* @brief Devolve o nome do produto
	* @return Nome do produto
	*/
	string getNome() const;

	/**
	* @brief Devolve a descricao do produto
	* @return Descricao do produto
	*/
	string getDesc() const;

	/**
	* @brief Devolve o preco do produto
	* @return Preco do produto
	*/
	float getPreco() const;

	/**
	 * @brief Devolve o IVA sobre o produto
	 *
	 * @return IVA sobre o produto
	 */
	float getIVA() const;

	/**
	* @brief Altera o preco do produto para o indicado no seu argumento
	* @param novoPreco Novo preco do produto
	* @return Retorna 0 se a alteracao tiver sucesso
	* Retorna 1 se o argumento for um valor negativo
	*/
	int alteraPreco(float novoPreco);

	/**
	* @brief Compara a igualdade do proprio objeto com outro produto. Dois produtos sao iguais se tem o mesmo codigo
	* @param prod Produto a ser comparado
	* @return Retorna true se os produtos comparados tiverem o mesmo codigo. 
	* Retorna false se isso nao se verificar
	*/
	bool operator==(const Produto &prod);
	
	/**
	* @brief Mostra no ecra os atributos do objeto
	*/
	virtual ostream& print(ostream& os) const;

	/**
	* @brief Copia para um ficheiro indicado no seu argumento os atributos do objeto de forma a que essa informacao seja facilmente carregada
	*/
	virtual ostream& printSimp(ostream& os) const;

	/**
	 * @brief Mostra na stream dada o produto num formato de lista. Nome: NOME Codigo: CODIGO Tipo: produto
	 * 
	 * @param os 				stream onde a informacao sera escrita
	 * @return ostream& 		mesma stream de entrada
	 */
	virtual ostream& printListForm(ostream& os) const;


protected:
	/**
	 * @brief Codigo do produto
	 */
	const long unsigned int codigo;
	/**
	 * @brief Nome do produto
	 */
	const string nome;
	/**
	 * @brief Descricao do produto
	 */
	const string descricao;
	/**
	 * @brief Preco do produto
	 */
	float preco;
	/**
	 * @brief Imposto sobre o produto
	 */
	float iva;
};

/**
 * @brief Contem funcao usada para defenir a ordem de um par Produto-Quantidade na fila de prioridade de reabastecimento de uma farmacia.
 * Um par aparece primeiro no heap se a quantidade associada esse par e menor.
 * 
 */
struct produtos_heap_sort_func {

		/**
	 * @brief Funcao que ordena os pares produto-quantidade num heap.
	 * 
	 * @param lhs 				par 1
	 * @param rhs 				par 2
	 * @return true 			o par 1 tem maior prioridade que o par 2
	 * @return false 			o par 1 nao tem maior prioridade que o par 2
	 */
	bool operator()(const pair<Produto*, uint> lhs, const pair<Produto*, uint> rhs) {
		return lhs.second > rhs.second;
	}
};

/** @} */

#endif /* PRODUTO_H */
