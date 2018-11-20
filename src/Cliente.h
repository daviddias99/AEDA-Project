#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"

class Cliente :public Pessoa {
public:
	/**
	* @brief Construtor da classe cliente
	* @param nome Nome do cliente
	* @param nif NIF do cliente. E zero se nao for indicado
	* @param dataNasc Data de nascimento do cliente
	* @param morada Morada atual do cliente
	*/
	Cliente(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada());

	/**
	* @brief Adiciona a venda indicada no seu parametro a lista de compras do cliente
	* @param v Apontador para uma venda relizada pelo cliente
	* @return true se a venda foi adicionada com sucesso a lista de compras
	* false se ocorreu algum erro
	*/
	bool adicionaCompra(Venda* v);

	/**
	* @brief Devolve o numero de compras efetuadas pelo cliente
	* @return Numero de compras efetuadas pelo cliente
	*/
	uint getNumCompras() const;

	/**
	* @brief Devolve o membro-dado ID do cliente
	* @return ID do cliente
	*/
	uint getID() const;

	/**
	* @brief Mostra no ecra uma lista das compras efetuadas pelo cliente
	* @return -----------------COMPLETAR----------
	*/
	bool verHistorico();

	ostream& print(ostream& os) const;
	ostream& printSimp(ostream& os) const;

	friend bool operator<(const Cliente & e1, const Cliente & e2)
	{
		return false;
	}

private:
	vector<Venda*> historicoCompras;
	uint ID;
	static uint currentID;
};

/*
bool Cliente_SortFunc_Idade_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_Idade_Decrescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_Nome_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_Nome_Decrescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_NIF_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_NIF_Decrescente(Cliente* p1, Cliente* p2);
*/
bool Cliente_SortFunc_ID_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_ID_Decrescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_numCompras_Crescente(Cliente* p1, Cliente* p2);
bool Cliente_SortFunc_numCompras_Decrescente(Cliente* p1, Cliente* p2);



#endif // !CLIENTE_H
