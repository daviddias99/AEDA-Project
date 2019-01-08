#ifndef ENCOMENDA_H
#define ENCOMENDA_H

#include "Produto.h"
#include "string"
#include "util.h"
#include <list>

/*!
 * \file Encomenda.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */


/** @defgroup Encomenda Encomenda
 * @{
 *
 * Classe Encomenda. Uma encomenda representa um pedido de produtos entre um fornecedor e uma farmacia.
 */

typedef pair<Produto*, uint> ItemListaProdutos;
typedef list<ItemListaProdutos>ListaProdutos;

class Encomenda {

public:

	/**
	 * @brief Cria uma nome encomenda entre a farmacia e fornecedor dados como parametro. Quando e criada, a encomenda ainda nao se encontra terminada e a sua lista de produtos encontra-se vazia.
	 * 
	 * @param nomeFarmacia 				nome da farmacia de origem
	 * @param nomeFornecedor 			nome do fornecedor
	 */
	Encomenda(string nomeFarmacia, string nomeFornecedor);

	Encomenda(string simp);

	/**
	 * @brief Adiciona o produto dado como argumento a lista de produtos da encomenda. Se o produto ja existe na encomenda atualiza a quantidade. Atualiza tambem o valor da encomenda.
	 * 
	 * @param novoProduto 				apontador para o produto a adicionar
	 * @param quantidade 				quantidade do produto a adicionar
	 * @return true 					produto adicionado com sucesso
	 * @return false 					produto nao adicionado
	 */
	bool adicionaProduto(Produto* novoProduto, uint quantidade);

	/**
	 * @brief Remove o produto passado como argumento (ou apenas a quantidade indicada). Atualiza o valor da encomenda.
	 * 
	 * @param produto 					apontador para o produto a remover
	 * @param quantidade 				quantidade a remover do produto
	 * @param removeTudo 				verdadeiro se remove toda a quantidade existe do produto, falso se apenas a quantidade indicada
	 * @return true 					produto removido com sucesso
	 * @return false 					produto nao removido
	 */
	bool removeProduto(Produto* produto, uint quantidade, bool removeTudo = false);

	/**
	 * @brief Da a encomenda como terminada, marcando-a com o timestamp do tempo atual.
	 * 
	 * @return true 					encomenda terminada com sucesso
	 * @return false 					encomenda nao terminada
	 */
	bool terminaEncomenda();

	/**
	 * @brief Obter o valor atual da encomenda.
	 * 
	 * @return float 					valor atual da encomenda em euros
	 */
	float getValor() const;

	/**
	 * @brief Obter nome da farmacia associada a encomenda.
	 * 
	 * @return string 					nome da farmacia associada a encomenda
	 */
	string getNomeFarmacia();

	/**
	 * @brief Obter nome do fornecedor associado a encomenda.
	 * 
	 * @return string 					nome do fornecedor associado a encomenda
	 */
	string getNomeFornecedor();

	/**
	 * @brief Devolve o timestamp associado a encomenda. Se a encomenda ainda n tiver sido terminada retorna um time stamp com valor 0 em todos os campos.
	 * 
	 * @return Timestamp 				timestamp associado a encomenda
	 */
	Timestamp getTStamp() const ;

	/**
	 * @brief Retorna o numero de produtos existentes na encomenda.
	 * 
	 * @return uint 					numero de produtos existentes na lista de encomendas
	 */
	uint getQuantidadeProdutos() const;

	/**
	 * @brief Devolve a lista de produtos associada a encomenda.
	 * 		
	 * @return const ListaProdutos&		lista de produtos associada a encomenda 
	 */
	const ListaProdutos& getProdutos();

	/**
	 * @brief Altera o fornecedor associado a encomenda.
	 * 
	 * @param novoFornecedor 			nome do novo fornecedor
	 */
	void mudaFornecedor(string novoFornecedor);

	/**
	 * @brief Imprime na stream dada um resumo da encomenda. O resumo contem a farmacia de origem, a data da encomenda, a quantidade de produtos e o valor.
	 * 
	 * @param os 						stream onde o resumo e escrito
	 * @return ostream& 				stream passada como argumento
	 */
	ostream& print_resumo(ostream& os) const;

	/**
	 * @brief Imprime na stream a encomenda. Contem o resumo da encomenda e tambem a lista dos produtos.
	 * 
	 * @param os 						stream onde o resumo e escrito
	 * @return ostream& 				stream passada como argumento
	 */
	ostream& print_full(ostream& os) const;

	ostream& printSimp(ostream& os) const;


private:
	/**
	 * @brief Nome da farmacia em que a encomenda origina.
	 * 
	 */
	string farmaciaOrigem;

	/**
	 * @brief Nome do fornecedor associado a encomenda.
	 * 
	 */
	string fornecedorOrigem;
	
	/**
	 * @brief Lista de produtos associados a encomenda.
	 * 
	 */
	ListaProdutos listaProdutos;

	/**
	 * @brief Dalor dos produtos da encomenda.
	 * 
	 */
	float valorEncomenda;

	/**
	 * @brief Hora e data em que a encomenda foi terminada.
	 * 
	 */
	Timestamp stamp;

	/**
	 * @brief Determina se a encomenda foi terminada ou nao
	 * 
	 */
	bool terminada;
};

/**
 * @brief Define igualdade entre dois items da lista de produtos. Dois items sao iguais se o codigo dos produtos associados forem iguais
 * 
 * @param p1 					referencia para um produto
 * @param p2 					referencia para um produto
 * @return true 				os produtos sao iguais
 * @return false 				os produtos nao sao iguais
 */
bool operator==(const ItemListaProdutos& p1, const ItemListaProdutos& p2);

#endif
