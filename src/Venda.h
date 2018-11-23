#ifndef VENDA_H
#define VENDA_H

#include <map>
#include <vector>
#include <string>
#include "Produto.h"
#include "Medicamento.h"
#include "Receita.h"
#include "util.h"

using namespace std;

/*!
 * \file Venda.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

/** @defgroup Venda Venda
 * @{
 *
 * Classe venda 
 */


/**
 * @brief Classe que representa uma venda realizada por uma farmacia
 */
class Venda {
public:
	/**
	 * @brief Construir um objeto da classe venda 
	 * 
	 * @param cID ID do cliente
	 * @param client Nome do cliente
	 * @param eID ID do empregado
	 * @param empreg Nome do empregado
	 * @param farm Nome da farmacia onde foi realizada a venda
	 * @param time Data e hora a que foi realizada a venda, 
	 * caso nao seja indicado (valor default = ""), utiliza data e hora atuais
	 */
	Venda(uint cID, string client, uint eID, string empreg, string farm, string time = "");
	/**
	 * @brief Adiciona os produtos receitados existentes numa receita a venda, atualizando o preco total da mesma
	 * 
	 * @param receita Receita fornecida pelo cliente
	 */
	void addReceita(const Receita & receita);
	/**
	 * @brief Muda o preco total da venda para o valor passado por argumento (usado quando se le uma venda do ficheiro)
	 *
	 * @param pr Preco da venda
	 */
	void setPreco(float pr);
	/**
	 * @brief Adiciona a respetiva quantidade de um determinado produto a venda, atualizando o preco total da mesma
	 * 
	 * @param prod				Produto a adicionar
	 * @param quant				Quantidade do produto a adicionar
	 * @param vemReceitado		Verdadeiro se o produto estiver a ser adicionado atraves de uma receita (calcular descontos), falso caso contrario
	 * @param vemDeFicheiro		Verdadeiro se o produto estiver a ser adicionado atraves de um ficheiro
	 */
	void addProduto(Produto* prod, unsigned int quant, bool vemReceitado = false, bool vemDeFicheiro = false);
	/**
	 * @brief Obtem um pair com um apontador para o produto com o codigo indicado (key) e a quantiade existente (value)
	 * 
	 * @param prodId Codigo do produto
	 * @return Pair com um apontador para o produto pedido (key) e quantidade existente (value)
	 */
	pair<Produto*, uint> getProd(uint prodId);
	/**
	 * @brief Obtem um pair com um apontador para o produto com o nome pedido (key) e a quantidade existente (value)
	 * 
	 * @param nome Nome do produto
	 * @return  Pair com um apontador para o produto pedido (key) e quantidade existente (value)
	 */
	pair<Produto*, uint> getProd(string nome);
	/**
	 * @brief Remove o da venda o produto com o nome indicado, atualiza o preco
	 * 
	 * @param nome Nome do produto a remover
	 */
	void remProduto(string nome);
	/**
	 * @brief Devolve o preco total da venda
	 * 
	 * @return  Preco total da venda
	 */
	float getCusto() const;
	/**
	 * @brief Devolve o nome da farmacia onde foi realizada a venda
	 * 
	 * @return Nome da farmacia onde foi realizada a venda
	 */
	string getNomeFarm() const;
	/**
	 * @brief Devolve o nome do cliente que efetuou a compra
	 * 
	 * @return Nome do cliente que efetuou a compra
	 */
	string getNomeCliente() const;
	/**
	 * @brief Devolve o nome do empregado que efetuou a venda
	 * 
	 * @return Nome do empregado que efetuou a venda
	 */
	string getNomeEmp() const;

	/**
	 * @brief Devolve com os produtos e respetivas quantidades da venda
	 * 
	 * @return Map com apontador para produto (key) e quantidade (value)
	 */
	map<Produto*, uint>& getProdutos();
	/**
	 * @brief Imprime as informacoes da venda num formato legivel para a stream passada por argumento
	 * 
	 * @param os Stream onde queremos imprimir as informacoes
	 * @return Stream onde foram escritas as informacoes
	 */
	ostream& print(ostream& os) const;
	/**
	 * @brief Imprime as informacoes da venda no formato usado na leitura de ficheiros para a stream passada por argumento
	 * 
	 * @param os Stream onde queremos imprimir as informacoes
	 * @return Stream onde foram escritas as informacoes
	 */
	ostream& printSimp(ostream& os) const;
private:
	/**
	 * @brief Preco total da venda
	 */
	float preco;
	/**
	 * @brief Nome da farmacia onde foi realizada a venda
	 */
	const string nomeFarmacia;
	/**
	 * @brief Nome do cliente que realizou a compra
	 */
	const string nomeCliente;
	/**
	 * @brief Nome do empregado que realizou a venda
	 */
	const string nomeEmpregado;
	/**
	 * @brief Map que representa os produtos e respetivas quantidades da venda (key = apontador para produto, value = quantidade)
	 */
	map<Produto *, unsigned int> produtos;
	/**
	 * @brief Data e hora a que a venda ocorreu
	 */
	Timestamp timestamp_venda;
	/**
	 * @brief ID do empregado que realizou a venda
	 */
	const uint idEmpregado;
	/**
	 * @brief ID do cliente que realizou a compra
	 */
	const uint idCliente;
};

/** @} */

#endif /* VENDA_H */
