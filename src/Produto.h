#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
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

/** @} */

#endif /* PRODUTO_H */
