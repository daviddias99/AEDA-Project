/*!

* \file Cadeia.h
*
* \author FEUP AEDA1819 MIEIC Turma5_G1:
* \author 
* \author
* \author
*/
#ifndef CADEIA_H_
#define CADEIA_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Farmacia.h"
#include "Cliente.h"
#include "Empregado.h"
#include "Excecoes.h"
#include "util.h"


using namespace std;

class Cadeia{
public:
	/**
	* @brief Construtor por defeito da classe Cadeia
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
	* @param Farmacia farmacia a ser adicionada a lista
	* @return true se  farmacia foi adicionada com sucesso
	* false se farmacia nao foi adicionada porque esta ja existe na lista de farmacias
	*/
	bool addFarmacia(Farmacia* Farmacia);
	/**
	* @brief Adciona um cliente a lista de clientes da cadeia
	* @param cliente Apontador para o cliente a ser adicionado a lista
	* @return true se o cliente foi adicionado com sucesso
	* false se o cliente nao foi adicionado porque ja existe na lista de clientes
	*/
	bool addCliente(Cliente* cliente);
	/**
	* @brief Adiciona um empregado a lista de empregados da cadeia
	* @param empregado Apontador para o empregado a ser adicionado a lista
	* @return true se o empregado foi adicionado a lista com sucesso
	* false se o empregado nao foi adicionado porque ja existe na lista
	*/
	bool addEmpregado(Empregado* empregado);

	/**
	* @brief Remove a farmacia com o nome indicado no seu parametro da lista de farmacias
	* @param nome Nome da farmacia a ser removida
	*/
	void removeFarmacia(string nome);
	/**
	* @brief Remove o cliente com o ID indicado no seu parametro da lista de clientes
	* @param ID ID do cliente a ser removido da lista
	*/
	void removeCliente(uint ID);
	/**
	* @brief Remove o empregado com o ID inidcado no seu parametro da lista de empregados
	* @param ID ID do empregado a ser removido da lista 
	*/
	void removeEmpregado(uint ID);

	/**
	* @brief Devolve um apontador para a farmacia com o nome indicado no parametro
	* @param nome Nome da farmacia que vai ser retornada
	* @return Apontador para a farmacia com o nome indicado no parametro
	*/
	Farmacia* getFarmacia(string nome) const;

	/**
	* @brief Devolve um apontador para o cliente com o ID indicado no parametro
	* @param ID ID do cliente que vai ser retornado
	* @return Apontador para o cliente com o ID indicado no parametro
	*/
	Cliente* getCliente(uint  ID) const;

	/**
	* @brief Devolve um apontador para o empregado com o ID indicado no parametro
	* @param ID ID do empregado que vai ser retornado
	* @return Apontador para o empregado com o ID indicado no parametro
	*/
	Empregado* getEmpregado(uint ID) const;

	/**
	* @brief Devolve um vetor de apontador para clientes com o nome indicado no seu parametro
	* @param nome Nome dos clientes que vai procurar na lista de clientes da cadeia
	* @return Vetor de apontadores para objetos da classe Cliente que pertencem a cadeia e que tem o nome indicao no parametro
	*/
	vector<Cliente*> getClientes(string nome) const;

	/**
	* @brief Devolve um vetor de apontadores para empregados com o nome indicado no seu parametro
	* @param nome Nome dos empregados que vai procurar na lista de empregados da cadeia
	* @return Vetor de apontadores para objetos da classe Empregado que pertencem a cadeia e que tem o nome indicao no parametro
	*/
	vector<Empregado*> getEmpregados(string nome) const;

	/**
	* @brief Devolve o numero de farmacias da cadeia
	* @return numero de farmacias da cadeia
	*/
	unsigned int getNumFarmacias() const;
	/**
	* @brief Devolve o numero de empregados da cadeia
	* @return numero de empregados da cadeia
	*/
	unsigned int getNumEmpregados() const;
	/**
	* @brief Devolve o numero de clientes da cadeia
	* @return numero de clientes da cadeia
	*/
	unsigned int getNumClientes() const;
	/**
	* @brief Devolve o nome da cadeia
	* @return nome da cadeia
	*/
	string getNome() const;

	/**
	* @brief Ordena a lista de farmacias de acordo com o modo indicado no parametro
	* @param modo Modo em que a lista de farmacias vai ser ordenada
	*/
	void sortFarmacias(char modo);
	/**
	* @brief Ordena a lista de clientes de acordo com o modo indicado no parametro
	* @param modo Modo em que a lista de clientes vai ser ordenada
	*/
	void sortClientes(ord_pessoas modo);

	/**
	* @brief Ordena a lista de empregados de acordo com o modo indicado no parametro
	* @param modo Modo em que a lista de empregados vai ser ordenada
	*/
	void sortEmpregados(ord_pessoas modo);

	/**
	* @brief Mostra no ecra alguns memrbos-dado de todas as farmacias pertencentes a lista
	*/
	void mostrarFarmacias();
	/**
	* @brief Mostra no ecra alguns memrbos-dado de todas os clientes pertencentes a lista
	*/
	void mostrarClientes();
	/**
	* @brief Mostra no ecra alguns memrbos-dado de todas os empregados pertencentes a lista
	*/
	void mostrarEmpregados();

	/**
	* @brief guarda as informacao de todas as farmacias, empregados e clientes num fihceiro txt para que depois possa ser reutilizado
	*/
	void guardarDados();
	/**
	* @brief Carrega os dados das farmacias, empregados e clientes de um ficheiro txt e permite a continuacao da gerencia dessa cadeia carregada
	*/
	void carregarDados();
private:
	/**
	* @brief Carrega a lista de clientes do ficheiro indicado no seu parametro
	* @param ficheiro Ficheiro de entrada de onde vai ser lida a informacao dos clientes da cadeia
	*/
	void carregarClientes(ifstream& ficheiro);
	/**
	* @brief Carrega a lista de empregados do ficheiro indicado no seu parametro
	* @param ficheiro Ficheiro de entrada de onde vai ser lida a informacao dos empregados da cadeia
	*/
	void carregarEmpregados(ifstream& ficheiro);
	/**
	* @brief Carrega a lista de farmacias do ficheiro indicado no seu parametro
	* @param ficheiro Ficheiro de entrada de onde vai ser lida a informacao das farmacias da cadeia
	*/
	void carregarFarmacias(ifstream& ficheiro);

	vector< Farmacia* > farmacias; //Ordenadas por nome
	vector< Cliente* > clientes; //Ordenados por ID
	vector< Empregado* > empregados; //Ordenados por ID

	string nome;
};

#endif /* SRC_CADEIA_H_ */
