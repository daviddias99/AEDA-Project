#ifndef RECEITA_H
#define RECEITA_H

#include <string>
#include <map>
#include "Produto.h"
#include "util.h"

using namespace std;

/*!
 * \file Receita.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

/** @defgroup Receita Receita
 * @{
 *
 * Classe receita 
 */

/**
 * Classe que representa as informacoes de uma receita 
 */
class Receita {
public:
	/**
	* @brief Construtor de receita
	*
	* @param numReceita Numero da receita
	* @param cliente Nome do cliente a quem a receita foi receitada
	* @param medico Nome do medico que receitou a receita
	* @param nifPaciente NIF do paciente a quem a receita foi receitada
	*/
	Receita(int numReceita, string cliente, string medico, uint nifPaciente);

	/**
	* @brief Adiciona um produto e respetiva quantidade a lista de produtos que constam na receita
	* @param produto Produto a ser adicionado a receita
	* @param quantidade Quantidade de produto a adicionar
	*/
	void addProduto(Produto* produto, uint quantidade);

	/**
	* @brief Devolve a lista de produtos que constam na receita e as suas quantidades
	* @return Lista de produtos que constam na receita
	*/
	map<Produto*, uint> getProdutos() const;

	/**
	* @brief Devolve o numero da receita
	* @return Numero da receita
	*/
	int getNumReceita() const;

	/**
	* @brief Devolve o nome do cliente a quem foi receitada a receita
	* @return Nome do cliente 
	*/
	string getCliente() const;

	/**
	* @brief Devolve o nome do medico que receitou a receita
	* @return Nome do medico
	*/
	string getMedico() const;

	/**
	* @brief Devolve o nif do paciente
	* @return NIF do paciente
	*/
	uint getNifPaciente() const;

private:
	/**
	 * @brief Numero da receita
	 */
	int numReceita;
	/**
	 * @brief Nome do paciente
	 */
	const string nomeCliente;
	/**
	 * @brief Nome do medico que passou a receita
	 */
	const string nomeMedico;
	/**
	 * @brief NIF do paciente 
	 */
	uint nifPaciente;
	/**
	 * @brief Map que representa os produtos receitados (key = apontador para produto, value = quantidade)
	 */
	map<Produto*, uint> produtos;
};

/** @} */

#endif
