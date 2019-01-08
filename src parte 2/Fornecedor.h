#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <string>
#include "util.h"

#include "Encomenda.h"

/*!
 * \file Fornecedor.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */


/** @defgroup Fornecedor Fornecedor
 * @{
 *
 * Classe Fornecedor. Um fornecedor representa uma entidade que atende encomendas efetuadas por farmacias. Um fornecedor pode fornecer medicamentos ou produtos gerais.
 */

/**
 * @brief Tipo do fornecedor em questao.
 * 
 */	
typedef enum TipoFornecedor{medicamentos			///< Fornecedor de medicamentos.
							,produtos				///< Fornecedor de produtos gerais.
							} TipoFornecedor;

class Fornecedor {

private:

	/**
	 * @brief Nome do fornecedor.
	 * 
	 */
	string nome;

	/**
	 * @brief Morada da sede do fornecedor.
	 * 
	 */
	Morada morada_sede;

	/**
	 * @brief Vetor das encomendas satisfeitas pelo fornecedor.
	 * 
	 */
	vector<Encomenda> encomendas_satisfeitas;

	/**
	 * @brief Tipo de fornecedor.
	 * 
	 */
	TipoFornecedor tipo;
	
	/**
	 * @brief Adiciona a a encomenda ao vetor de encomendas satisfeitas.
	 * 
	 * @param encomenda 			Encomenda a adicionar.
	 */
	void adicionaEncomenda(Encomenda encomenda);


public:

	/**
	 * @brief Cria um novo objeto Fornecedor com os parametros indicados.
	 * 
	 * @param nome 					Nome do fornecedor.
	 * @param morada_sede 			Morada da sede do fornecedor.
	 * @param tipo 					Tipo do fornecedor(medicamentos ou produtos).
	 */
	Fornecedor(string nome, Morada morada_sede, TipoFornecedor tipo);

	Fornecedor(string simp);

	/**
	 * @brief Adiciona a a encomenda ao vetor de encomendas satisfeitas.
	 * 
	 * @param encomenda 			Encomenda a adicionar.
	 * @return true 				Encomenda satisfeita com sucesso.
	 * @return false 				Encomenda nao satisfeita.
	 */
	bool satisfazEncomenda(Encomenda encomenda);

	/**
	 * @brief Retorna o numero de encomendas satisfeitas pelo fornecedor.
	 * 
	 * @return uint 				Numero de encomendas satisfeitas pelo fornecedor.
	 */
	uint getNumEncomendas() const;

	/**
	 * @brief Obter o nome do fornecedor.
	 * 
	 * @return string 				Nome do fornecedor.
	 */
	string getNome() const;

	/**
	 * @brief Morada da sede do fornecedor.
	 * 
	 * @return Morada 				Morada da sede do fornecedor.
	 */
	Morada getMoradaSede() const;

	/**
	 * @brief Obter vetor de encomendas satisfeitas.
	 * 
	 * @return const vector<Encomenda>& 	Vetor de encomendas satisfeitas pelo fornecedor.
	 */
	const vector<Encomenda>& getEncomendasSatisfeitas() const;

	/**
	 * @brief Obter o tipo do fornecedor (medicamentos ou produtos).
	 * 
	 * @return TipoFornecedor 				Tipo do fornecedor.
	 */
	TipoFornecedor getTipo() const;

	/**
	 * @brief Obter as encomendas realizadas numa determinada data.
	 * 
	 * @param data 							Data das encomendas.
	 * @return vector<Encomenda> 			Encomendas realizadas nada data dada.
	 */
	vector<Encomenda> getEncomendas(Data data) const;


	vector<Encomenda> getEncomendas(string farmacia) const;

	/**
	 * @brief Imprime na stream dada o fornecedor. E imprimido apenas o seu nome, morada, tipo e numero de encomendas.
	 * 
	 * @param os 							Stream onde o fornecedor vai ser escrito.
	 * @return ostream& 					Stream de argumento.
	 */
	ostream& print(ostream& os) const;

	/**
	 * @brief Imprime as encomendas do fornecedor de forma resumida. (ver Encomenda::print_resumo)
	 * 
	 * @param os 							Stream onde a informacao vai ser escrita.	
	 * @return ostream& 					Stream de argumento.
	 */
	ostream& print_encomendas_resumo(ostream& os) const;

	/**
	 * @brief Imprime o resumo do fornecedor da mesma forma que Fornecedor::print mas apenas numa linha.
	 * 
	 * @param os 							Stream onde a informacao vai ser escrita.
	 * @return ostream& 					Stream de argumento.
	 */
	ostream& print_resumo_lista(ostream& os) const;

	ostream& printSimp(ostream& os) const;

	/**
	 * @brief Compara dois fornecedores. Um fornecedor e menor que outro se o seu nome for menor alfabeticamente.
	 * 
	 * @param f2 							Fornecedor
	 * @return true 						Fornecedor 1 menor que Fornecedor 2
	 * @return false 						Fornecedor 1 nao e menor que Fornecedor 2
	 */
	bool operator<(Fornecedor& f2);

	/**
	 * @brief Compara dois fornecedores. Um fornecedor e igual a outro se o seu nome for igual alfabeticamente.
	 * 
	 * @param f2 							Fornecedor
	 * @return true 						Fornecedor 1 igual a Fornecedor 2
	 * @return false 						Fornecedor 1 nao e igual a Fornecedor 2
	 */
	bool operator==(Fornecedor& f2);
};


/**
 * @brief Usada para ordenar as listas de fornecedores de uma cadeia. Compara dois fornecedores.
 * 
 * @param f1 					Fornecedor 1.
 * @param f2 					Fornecedor 2.
 * @return 						True se o fornecedor 1 tem um nome menor que o fornecedor 2. Falso caso contrario.	
 */
bool fornecedor_SortFunc_Nome_Crescente(Fornecedor * f1, Fornecedor * f2);

/**
 * @brief Usada para ordenar as listas de fornecedores de uma cadeia. Compara dois fornecedores.
 * 
 * @param f1 					Fornecedor 1.
 * @param f2 					Fornecedor 2.
 * @return 						True se o fornecedor 1 tem um nome maior que o fornecedor 2. Falso caso contrario.	
 */
bool fornecedor_SortFunc_Nome_Decrescente(Fornecedor * f1, Fornecedor * f2);

/**
 * @brief Usada para ordenar as listas de fornecedores de uma cadeia. Compara dois fornecedores.
 * 
 * @param f1 					Fornecedor 1.
 * @param f2 					Fornecedor 2.
 * @return 						True se o fornecedor 1 tem um tipo menor que o fornecedor 2. Falso caso contrario.	
 */
bool fornecedor_SortFunc_Tipo_Crescente(Fornecedor * f1, Fornecedor * f2);

/**
 * @brief Usada para ordenar as listas de fornecedores de uma cadeia. Compara dois fornecedores.
 * 
 * @param f1 					Fornecedor 1.
 * @param f2 					Fornecedor 2.
 * @return 						True se o fornecedor 1 tem um tipo maior que o fornecedor 2. Falso caso contrario.	
 */
bool fornecedor_SortFunc_Tipo_Decrescente(Fornecedor * f1, Fornecedor * f2);

/**
 * @brief Usada para ordenar as listas de fornecedores de uma cadeia. Compara dois fornecedores.
 * 
 * @param f1 					Fornecedor 1.
 * @param f2 					Fornecedor 2.
 * @return 						True se o fornecedor 1 tem menos encomendas realizadas que o fornecedor 2. Falso caso contrario.	
 */
bool fornecedor_SortFunc_NumEncomendas_Crescente(Fornecedor * f1, Fornecedor * f2);

/**
 * @brief Usada para ordenar as listas de fornecedores de uma cadeia. Compara dois fornecedores.
 * 
 * @param f1 					Fornecedor 1.
 * @param f2 					Fornecedor 2.
 * @return 						True se o fornecedor 1 tem mais encomendas realizadas que o fornecedor 2. Falso caso contrario.	
 */
bool fornecedor_SortFunc_NumEncomendas_Decrescente(Fornecedor * f1, Fornecedor * f2);

/**
 * @brief Struct usada para definir a ordem dos fornecedores no heap de fornecedores. Um fornecedor aparece primeiro se tem menos encomendas realizadas.
 * 
 */
struct fornecedor_heap_sort_func {
	bool operator()(const Fornecedor* lhs, const Fornecedor* rhs) {
		return lhs->getNumEncomendas() > rhs->getNumEncomendas();
	}
};

#endif
