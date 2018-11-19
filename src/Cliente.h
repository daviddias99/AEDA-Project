#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"

class Cliente :public Pessoa {
public:

	Cliente(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada());

	bool adicionaCompra(Venda*);
	uint getNumCompras() const;
	uint getID() const;
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
