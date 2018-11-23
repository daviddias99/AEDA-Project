#ifndef SRC_EXCECOES_H
#define SRC_EXCECOES_H

/*!
 * \file Excecoes.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

/** @defgroup Excecoes Excecoes
 * @{
 *
 * Excecoes 
 */


#include <String>
using namespace std;

/**
 * @brief Classe que representa uma excecao geral que apenas contem a informacao sobre a ocorrencia da excecao,
 *  usada para derivar nova excecoes
 */
class ExcecaoGeral {
protected:
	/**
	 * @brief Informacao sobre a excecao
	 */
	string info;
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ExcecaoGeral(string i) { info = i; }
	/**
	 * @brief Obtem informacao sobre a excecao
	 */
	string getInfo() const { return info; }
};

/**
 * @brief Excecao que ocorre quando o utilizador escolhe uma opcao invalida num menu
 * 
 */
class OpcaoInvalida: public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	OpcaoInvalida(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando um ficheiro nao e encontrado
 */
class FicheiroNaoEncontrado: public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	FicheiroNaoEncontrado(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando uma farmacia nao existe
 * 
 */
class FarmaciaNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	FarmaciaNaoExiste(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando um cliente nao existe
 * 
 */
class ClienteNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ClienteNaoExiste(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando empregado nao existe
 * 
 */
class EmpregadoNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	EmpregadoNaoExiste(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando um produto nao existe
 * 
 */
class ProdutoNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ProdutoNaoExiste(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando um produto e repetido
 * 
 */
class ProdutoRepetido : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ProdutoRepetido(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao quando ocorre quando se tenta adicionar a uma venda um numero de produtos que o stock de uma farmacia nao consegue satisfazer
 * 
 */
class ProdutosInsuficientes : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ProdutosInsuficientes(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando uma data e invalida
 * 
 */
class DataInvalida : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	DataInvalida(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando um cargo e invalido
 * 
 */
class CargoInvalido : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	CargoInvalido(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando uma morada e invalida
 * 
 */
class MoradaInvalida : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	MoradaInvalida(string i) : ExcecaoGeral(i) {}
};

/**
 * @brief Excecao que ocorre quando um hora e invalida
 * 
 */
class TimeInvalido : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	TimeInvalido(string i) : ExcecaoGeral(i) {}
};

#endif
