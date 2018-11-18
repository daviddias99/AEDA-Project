#ifndef EMPREGADO_H
#define EMPREGADO_H

#include "Pessoa.h"
	
class Empregado :public Pessoa {
public:
	Empregado(string nome = "NOME_DEFAULT", uint nif = 0, Data dataNasc = Data(), Morada morada = Morada(), uint  sal = 0, string farmaciaNome = "FARMACIA_DEFAULT", string cargo = "CARGO_DEFAULT");

	uint  getSalario() const;
	string getNomeFarmacia() const;
	string getCargo() const;
	uint getNumVendas();
	uint getID() const;

	bool setSalario(uint  novoSalario);
	bool setFarmacia(string novaFarmacia);
	bool setCargo(string novoCargo);

	ostream& printSimp(ostream& os);

	friend ostream& operator<< (ostream& os, const Empregado& mor);
	friend bool operator<(const  Empregado& e1, const Empregado & e2)
	{
		return false;
	}

private:
	uint   salario;
	string farmaciaNome;
	string cargo;
	vector<Venda*> historicoVendas;
	uint ID;
	static uint currentID;
};
	
/*
bool Empregado_SortFunc_Idade_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Idade_Decrescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Nome_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Nome_Decrescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_NIF_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_NIF_Decrescente(Empregado* p1, Empregado* p2);
*/
bool Empregado_SortFunc_ID_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_ID_Decrescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Salario_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_Salario_Decrescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_numVendas_Crescente(Empregado* p1, Empregado* p2);
bool Empregado_SortFunc_numVendas_Decrescente(Empregado* p1, Empregado* p2);


#endif // !EMPREGADO_H

