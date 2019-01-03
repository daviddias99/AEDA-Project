
#ifndef CADEIA_H_
#define CADEIA_H_
/*!
 * \file Cadeia.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

 /** @defgroup Cadeia Cadeia
  * @{
  *
  * Classe cadeia
  */


#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Farmacia.h"
#include "Cliente.h"
#include "Empregado.h"
#include "Excecoes.h"
#include "Fornecedor.h"
#include "util.h"

using namespace std;

/**
 * @brief Classe que representa uma cadeia de farmacias
 */
class Cadeia {
public:
	/**
	* @brief Construtor por defeito da classe Cadeia, inicia a cadeia com o nome "SEM_NOME"
	*/
	Cadeia();
	/**
	* @brief Construtor de cadeia inicializa o parametro nome
	* @param n Nome da cadeia
	*/
	Cadeia(string n);
	/**
	* @brief Destrutor da classe Cadeia. Liberta da memoria todas as farmacias, clientes e empregados
	*/
	virtual ~Cadeia();
	/**
	* @brief Adiciona uma farmacia a lista de farmacias da cadeia
	* @param farmacia	apontador para a farmacia a ser adicionada a lista
	* @return			true se  farmacia foi adicionada com sucesso
	* false se farmacia nao foi adicionada porque esta ja existe na lista de farmacias
	*/
	bool addFarmacia(Farmacia* farmacia);
	/**
	* @brief Adciona um cliente a lista de clientes da cadeia. Mantem os clientes ordenados por ID
	* @param cliente	Apontador para o cliente a ser adicionado a lista
	* @return			true se o cliente foi adicionado com sucesso
	* false se o cliente nao foi adicionado porque ja existe na lista de clientes
	*/
	bool addCliente(Cliente* cliente);
	/**
	* @brief Adiciona um empregado a lista de empregados da cadeia e � farmacia a que pertence
	* @param empregado			Apontador para o empregado a ser adicionado a lista
	* @return					true se o empregado foi adicionado a lista com sucesso
	*							false se o empregado nao foi adicionado porque ja existe na lista
	*/
	bool addEmpregado(Empregado* empregado);


	/**
	* @brief Adiciona um fornecedor a lista de fornecedores da cadeia e a farmacia a que pertence
	* @param fornecedor			Apontador para o fornecedor a ser adicionado a lista
	* @return					true se o fornecedor foi adicionado a lista com sucesso
	*							false se o fornecedor nao foi adicionado porque ja existe na lista
	*/
	bool addFornecedor(Fornecedor* fornecedor);

	/**
	* @brief Remove a farmacia com o nome indicado no seu parametro da lista de farmacias
	* @param nome				Nome da farmacia a ser removida
	*/
	void removeFarmacia(string nome);

	/**
	* @brief Remove o cliente com o ID indicado no seu parametro da lista de clientes
	* @param ID					ID do cliente a ser removido da lista
	*/
	void removeCliente(uint ID);

	/**
	* @brief Remove o empregado com o ID inidcado no seu parametro da lista de empregados
	* @param ID					ID do empregado a ser removido da lista
	*/
	void removeEmpregado(uint ID);

	/**
	* @brief Remove o fornecedor com o nome indicado no seu parametro da lista de fornecedores
	* @param nome				Nome do fornecedor a ser removido
	*/
	void removeFornecedor(string nome);

	/**
	* @brief Devolve um apontador para a farmacia com o nome indicado no parametro
	* @param nome				Nome da farmacia que vai ser retornada
	* @return					Apontador para a farmacia com o nome indicado no parametro
	*/
	Farmacia* getFarmacia(string nome) const;
	/**
	* @brief Devolve um apontador para o cliente com o ID indicado no parametro
	* @param ID					ID do cliente que vai ser retornado
	* @return					Apontador para o cliente com o ID indicado no parametro
	*/
	Cliente* getCliente(uint  ID) const;
	/**
	* @brief Devolve um apontador para o empregado com o ID indicado no parametro
	* @param ID					ID do empregado que vai ser retornado
	* @return					Apontador para o empregado com o ID indicado no parametro
	*/
	Empregado* getEmpregado(uint ID) const;


	/**
	* @brief Devolve um apontador para o fornecedor com o nome indicado no parametro
	* @param nome				Nome do fornecedor que vai ser retornada
	* @return					Apontador para o fornecedor com o nome indicado no parametro
	*/
	Fornecedor* getFornecedor(string nome) const;

	/**
	* @brief Devolve um vetor de apontador para clientes com o nome indicado no seu parametro
	* @param nome				Nome dos clientes que vai procurar na lista de clientes da cadeia
	* @return					Vetor de apontadores para objetos da classe Cliente que pertencem a cadeia e que tem o nome indicao no parametro
	*/
	vector<Cliente*> getClientes(string nome) const;
	/**
	* @brief Devolve um vetor de apontadores para empregados com o nome indicado no seu parametro
	* @param nome				Nome dos empregados que vai procurar na lista de empregados da cadeia
	* @return					Vetor de apontadores para objetos da classe Empregado que pertencem a cadeia e que tem o nome indicao no parametro
	*/
	vector<Empregado*> getEmpregados(string nome) const;

	const vector<Fornecedor*>  getFornecedores() const;

	/**
	* @brief Devolve o numero de farmacias da cadeia
	* @return					numero de farmacias da cadeia
	*/
	unsigned int getNumFarmacias() const;
	/**
	* @brief Devolve o numero de empregados da cadeia
	* @return					numero de empregados da cadeia
	*/
	unsigned int getNumEmpregados() const;
	/**
	* @brief Devolve o numero de clientes da cadeia
	* @return					 numero de clientes da cadeia
	*/
	unsigned int getNumClientes() const;

	/**
	* @brief Devolve o numero de fornecedores da cadeia
	* @return					 numero de fornecedores da cadeia
	*/
	unsigned int getNumFornecedores() const;

	/**
	* @brief Devolve o nome da cadeia
	* @return					 nome da cadeia
	*/
	string getNome() const;

	/**
	* @brief Ordena a lista de farmacias de acordo com o modo indicado no parametro
	* @param modo				Modo em que a lista de farmacias vai ser ordenada
	*/
	void sortFarmacias(char modo);
	/**
	* @brief Ordena a lista de clientes de acordo com o modo indicado no parametro
	* @param modo				Modo em que a lista de clientes vai ser ordenada
	*/
	void sortClientes(ord_pessoas modo);

	/**
	* @brief Ordena a lista de empregados de acordo com o modo indicado no parametro
	* @param modo				Modo em que a lista de empregados vai ser ordenada
	*/
	void sortEmpregados(ord_pessoas modo);

	/**
	* @brief Ordena a lista de fornecedores de acordo com o modo indicado no parametro
	* @param modo				Modo em que a lista de fornecedores vai ser ordenada
	*/
	void sortFornecedores(ord_fornece modo);

	/**
	* @brief Mostra no ecra alguns memrbos-dado de todas as farmacias pertencentes a lista
	*/
	void mostrarFarmacias() const;
	/**
	* @brief Mostra no ecra alguns memrbos-dado de todas os clientes pertencentes a lista
	*/
	void mostrarClientes() const;
	/**
	* @brief Mostra no ecra alguns membros-dado de todas os empregados pertencentes a lista
	*/
	void mostrarEmpregados() const;
	/**
	* @brief Mostra no ecra alguns membros - dado de todas os fornecedores pertencentes a lista
	*/
	void mostraFornecedores();
	/**
	* @brief guarda as informacao de todas as farmacias, empregados e clientes num fihceiro txt para que depois possa ser reutilizado
	*/
	void guardarDados() const;
	/**
	* @brief Carrega os dados das farmacias, empregados e clientes de um ficheiro txt e permite a continuacao da gerencia dessa cadeia carregada
	*/
	void carregarDados();
private:
	/**
	* @brief Carrega a lista de clientes do ficheiro indicado no seu parametro
	* @param ficheiro			Ficheiro de entrada de onde vai ser lida a informacao dos clientes da cadeia
	*/
	void carregarClientes(ifstream& ficheiro);
	/**
	* @brief Carrega a lista de empregados do ficheiro indicado no seu parametro
	* @param ficheiro			Ficheiro de entrada de onde vai ser lida a informacao dos empregados da cadeia
	*/
	void carregarEmpregados(ifstream& ficheiro);
	/**
	* @brief Carrega a lista de farmacias do ficheiro indicado no seu parametro
	* @param ficheiro			Ficheiro de entrada de onde vai ser lida a informacao das farmacias da cadeia
	*/
	void carregarFarmacias(ifstream& ficheiro);
	/**
	* @brief Carrega as vendas do ficheiro indicado no seu parametro para o respetivos cliente, empregado e farmacia
	* @param ficheiro			Ficheiro de leitura de onde vai ser lida a informacao sobre as vendas
	*/
	void carregarVendas(ifstream& ficheiro);
	/**
	 * @brief Vector de apontadores para objetos do tipo Farmacia, ordenadas por ordem alfabetica de nome
	 */
	vector< Farmacia* > farmacias;
	/**
	 * @brief Vector de apontadores para objetos do tipo Cliente, ordenados pelo numero de ID de cada cliente
	 */
	vector< Cliente* > clientes;
	/**
	 * @brief Vector de apontadores para objetos do tipo Empregado, ordenados pelo numero de ID de cada cliente
	 */
	vector< Empregado* > empregados;

	/**
	 * @brief Vector de apontadores para objetos do tipo Fornecedor, ordenados pelo nome dos mesmos
	 */
	vector<Fornecedor* > fornecedores;

	/**
	 * @brief Nome da cadeia de farmacias
	 */
	string nome;

	// parte 2
	empregadoHashTable empregados2;
};

/** @} */

#endif /* SRC_CADEIA_H_ */
