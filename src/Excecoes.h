#ifndef SRC_EXCECOES_H
#define SRC_EXCECOES_H

#include <String>
using namespace std;


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

class OpcaoInvalida: public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	OpcaoInvalida(string i) : ExcecaoGeral(i) {}
};

class FicheiroNaoEncontrado: public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	FicheiroNaoEncontrado(string i) : ExcecaoGeral(i) {}
};

class FarmaciaNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	FarmaciaNaoExiste(string i) : ExcecaoGeral(i) {}
};

class ClienteNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ClienteNaoExiste(string i) : ExcecaoGeral(i) {}
};

class EmpregadoNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	EmpregadoNaoExiste(string i) : ExcecaoGeral(i) {}
};

class ProdutoNaoExiste : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ProdutoNaoExiste(string i) : ExcecaoGeral(i) {}
};

class ProdutoRepetido : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ProdutoRepetido(string i) : ExcecaoGeral(i) {}
};

class ProdutosInsuficientes : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	ProdutosInsuficientes(string i) : ExcecaoGeral(i) {}
};

class DataInvalida : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	DataInvalida(string i) : ExcecaoGeral(i) {}
};

class CargoInvalido : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	CargoInvalido(string i) : ExcecaoGeral(i) {}
};

class MoradaInvalida : public ExcecaoGeral {
public:
	/**
	 * @brief Cria uma excecao com a informacao passada por argumento
	 *
	 * @param i informacao sobre a excecao
	 */
	MoradaInvalida(string i) : ExcecaoGeral(i) {}
};

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
