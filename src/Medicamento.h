#ifndef MEDICAMENTO_H_
#define MEDICAMENTO_H_

#include "Produto.h"

/*!
 * \file Medicamento.h
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
 * Classe que representa um medicamento 
 */
class Medicamento : public Produto {
public:
	/**
	* @brief Construtor da classe Medicamento
	* @param cod Codigo do medicamento
	* @param n Nome do medicamento
	* @param desc Descricao do medicamento
	* @param pr Preco do medicamento
	* @param i Iva do medicamento
	* @param vendSemRec True se e possivel vender o medicamento sem receita
	* @param pdSerRec True se o medicamento pode ser receitado
	* @param descRec Valor do desconto no caso do medicamento ser receitado
	*/
	Medicamento(unsigned long int cod, string n, string desc, float pr, float i, bool vendSemRec, bool pdSerRec, float descRec);

	/**
	* @brief Devolve o valor do desconto do medicamento quando e receitado
	* @param Valor do desconto quando e receitado
	*/
	float descontoComReceita() const;

	/**
	* @brief Indica se o medicamento pode ser receitado
	* @return Retorna true se o medicamento pode ser receitado
	*/
	bool podeSerReceitado() const;

	/**
	* @brief Indica se o medicamento pode ser vendido sem receita
	* @return Retorna true se o medicamento pode ser vendido sem receita
	*/
	bool vendidoSemReceita() const;

	/**
	* @brief Copia para um ficheiro indicado no seu argumento os atributos do objeto de forma a ser facilmente carregado
	*/
	ostream& printSimp(ostream& os) const;

	/**
	* @brief Mostra no ecra os atributos do medicamento
	*/
	ostream& print(ostream& os) const;
private:
	const bool vendidoSemRec;
	const bool podeSerRec;
	const float descComReceita;
};


#endif /* MEDICAMENTO_H_ */
