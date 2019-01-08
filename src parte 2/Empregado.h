#ifndef EMPREGADO_H
#define EMPREGADO_H

#include "Pessoa.h"
#include <unordered_set>
	/*!
 * \file Empregado.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

/** @defgroup Pessoa Pessoa
 * @{
 *
 * Classe pessoa e suas classes derivadas
 */


/**
 * @brief Classe que representa um empregado
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
	 * @param dataContratacao Data em que o empregado foi contratado
	 * @param ID numero de identificacao, tem valor por omissao -1 para gerar ID automaticamente para quando se criam empregados durante a execucao do programa
	 */
	Empregado(uint nif = 0, string nome = "NOME_DEFAULT",  Data dataNasc = Data(), Morada morada = Morada(), uint  sal = 0, string farmaciaNome = "FARMACIA_DEFAULT", string cargo = "CARGO_DEFAULT",  Data dataContratacao = Data(), Data dataDespedimento = Data::NULLData, uint mesesLigacao = 0, int ID = -1);
	/**
	 *	Decrementa a variavel static currentID, usado no caso em que se criam empregados que n�o se adicionam a farmacia por ser repetido
	 */
	static void decID();
	/**
	 * @brief Adiciona uma venda ao empregado
	 */
	void addVenda(Venda* venda);
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
	 * @brief Mostra vendas do empregado
	 */
	void mostrarVendas();
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

	/**
	* @brief Verifica se um empregado é um trabalhador atual da cadeia de farmacias
	*
	* @return True caso ele esteja empregado, falso caso esteja livre
	*/
	bool trabalhaAtualmente() const;


	void despedir();

	void recontratar(string farmNome, string cargo, uint sal);

	uint getMesesLig() const;

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


	uint mesesLigacaoAnterior;

	Data ultimaDataContratacao;
	Data ultimaDataDespedimento;
};
	
/**
* @brief Usada para ordenar a lista de empregados da cadeia. Compara dois empregados
* @return True se o empregado p1 tem ID menor do que o empregado p2. Se os IDs sao iguais,
* retorna true se o empregado p1 tem menor nome do que o empregado p2
*/
bool Empregado_SortFunc_ID_Crescente(Empregado* p1, Empregado* p2);

/**
* @brief Usada para ordenar a lista de empregados da cadeia. Compara dois empregados
* @return True se o empregado p1 tem ID maior do que o empregado p2. Se os IDs sao iguais,
* retorna true se o empregado p1 tem menor nome do que o empregado p2
*/
bool Empregado_SortFunc_ID_Decrescente(Empregado* p1, Empregado* p2);

/**
* @brief Usada para ordenar a lista de empregados da cadeia. Compara dois empregados
* @return True se o empregado p1 tem salario menor do que o empregado p2. Se os salarios sao iguais,
* retorna true se o empregado p1 tem menor nome do que o empregado p2
*/
bool Empregado_SortFunc_Salario_Crescente(Empregado* p1, Empregado* p2);

/**
* @brief Usada para ordenar a lista de empregados da cadeia. Compara dois empregados
* @return True se o empregado p1 tem salario maior do que o empregado p2. Se os salarios sao iguais,
* retorna true se o empregado p1 tem menor nome do que o empregado p2
*/
bool Empregado_SortFunc_Salario_Decrescente(Empregado* p1, Empregado* p2);

/**
* @brief Usada para ordenar a lista de empregados da cadeia. Compara dois empregados
* @return True se o empregado p1 tem numero de vendas menor do que o empregado p2. Se os numeros de vendas sao iguais,
* retorna true se o empregado p1 tem menor nome do que o empregado p2
*/
bool Empregado_SortFunc_numVendas_Crescente(Empregado* p1, Empregado* p2);

/**
* @brief Usada para ordenar a lista de empregados da cadeia. Compara dois empregados
* @return True se o empregado p1 tem numero de vendas maior do que o empregado p2. Se os numeros de vendas sao iguais,
* retorna true se o empregado p1 tem menor nome do que o empregado p2
*/
bool Empregado_SortFunc_numVendas_Decrescente(Empregado* p1, Empregado* p2);

bool Empregado_SortFunc_MesesLig_Crescente(Empregado * p1, Empregado * p2);
bool Empregado_SortFunc_MesesLig_Decrescente(Empregado * p1, Empregado * p2);

/** @} */




struct empregadoHash
{
	int operator() (const Empregado* emp) const
	{
		return emp->getNIF() % 37;
	}

	bool operator() (const Empregado* emp1, const Empregado* emp2) const
	{
		return emp1->getNIF() == emp2->getNIF();
	}
};

typedef unordered_set<Empregado*, empregadoHash, empregadoHash> empregadoHashTable;




#endif // !EMPREGADO_H

