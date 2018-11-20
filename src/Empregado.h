#ifndef EMPREGADO_H
#define EMPREGADO_H

#include "Pessoa.h"
	
/** @defgroup Pessoa Pessoa
 * @{
 *
 * Classe pessoa e suas classes derivadas
 */

class Empregado :public Pessoa {
public:
	/**
	 * @brief Construtor da classe empregado que tambem serve como construtor por omissao
	 * 
	 * @param nome Nome da pessoa
	 * @param nif NIF da pessoa
	 * @param dataNasc Data de nascimento da pessoa
	 * @param morada Objeto do tipo Morada
	 * @param sal Salario do empregado
	 * @param farmaciaNome Nome da farmacia onde trabalha o empregado
	 * @param cargo Cargo do empregado
	 */
	Empregado(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada(), uint  sal = 0, string farmaciaNome = "FARMACIA_DEFAULT", string cargo = "CARGO_DEFAULT");
	/**
	 * @brief Devolve o salario do empregado
	 * 
	 * @return Salario do empregado
	 */
	uint  getSalario() const;
	/**
	 * @brief Devolve o nome da farmacia onde trabalha o empregado
	 * 
	 * @return Nome da farmacia onde trabalha o empregado
	 */
	string getNomeFarmacia() const;
	/**
	 * @brief Devolve o cargo do empregado
	 * 
	 * @return Cargo do empregado 
	 */
	string getCargo() const;
	/**
	 * @brief Devolve o numero de vendas efetuadas pelo empregado
	 * 
	 * @return Numero de vendas
	 */
	uint getNumVendas() const;
	/**
	 * @brief Devolve o numero de identificacao do empregado
	 * 
	 * @return ID do empregado
	 */
	uint getID() const;
	/**
	 * @brief Altera o salario do empregado
	 * 
	 * @param novoSalario Novo salario do empregado
	 * @return True se o salario e valido, false caso contrario
	 */
	bool setSalario(uint  novoSalario);
	/**
	 * @brief Altera a nome da farmacia onde o empregado trabalha
	 * 
	 * @param novaFarmacia Nome da nova farmacia do empregado
	 */
	void setFarmacia(string novaFarmacia);
	/**
	 * @brief Altera o cargo do empregado
	 * 
	 * @param novoCargo Novo cargo do empregado
	 */
	void setCargo(string novoCargo);
	/**
	 * @brief Imprime as informacoes do empregado num formato legivel
	 * 
	 * @param os Stream onde sao imprimidas as informacoes
	 * @return Stream onde foram imprimidas as informacoes
	 */
	ostream& print(ostream& os) const;
	/**
	 * @brief Imprime as informacoes do empregado num formato simplificado, utilizado para guardar informacoes das pessoas em ficheiro de texto
	 * 
	 * @param os Stream onde sao imprimidas as informacoes
	 * @return Stream onde foram imprimidas as informacoes
	 */
	ostream& printSimp(ostream& os) const;
	/**
	 * @brief Overload do operador <, os empregados sao comparados por NIF
	 * 
	 * @param e1 Empregado na esquerda do operador
	 * @param e2 Empregado na direita do operador
	 * @return True caso o NIF do empregado da esquerda seja menor que o NIF do da direita
	 */
	friend bool operator<(const  Empregado& e1, const Empregado & e2);
	/**
	 * @brief Overload do operador ==, os empregados sao comparados por NIF
	 * 
	 * @param e1 Empregado na esquerda do operador
	 * @param e2 Empregado na direita do operador
	 * @return True caso o NIF do empregado da esquerda seja igual ao NIF do da direita
	 */
	friend bool operator==(const  Empregado& e1, const Empregado & e2);

private:
	/**
	 * @brief Salario do empregado
	 */
	uint   salario;
	/**
	 * @brief Nome da farmacia onde o empregado trabalha
	 */
	string farmaciaNome;
	/**
	 * @brief Cargo do empregado
	 */
	string cargo;
	/**
	 * @brief Vetor de apontador para vendas que representa o historico de vendas do empregado
	 */
	vector<Venda*> historicoVendas;
	/**
	 * @brief Numero de identificacao unico do empregado
	 */
	uint ID;
	/**
	 * @brief Variavel static usada para determinar o ID de um novo empregado
	 */
	static uint currentID;
};
	

bool Empregado_SortFunc_ID_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_ID_Decrescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Salario_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Salario_Decrescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_numVendas_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_numVendas_Decrescente(Empregado* p1, Empregado* p2);


#endif // !EMPREGADO_H

