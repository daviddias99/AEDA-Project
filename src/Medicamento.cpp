#include "Medicamento.h"

Medicamento::Medicamento(unsigned long int cod, string n, string desc, float pr, float i, bool vendSemRec, bool pdSerRec, float descRec): Produto(cod, n, desc, pr, i), vendidoSemRec(vendSemRec), podeSerRec(pdSerRec), descComReceita(descRec) {
}


float Medicamento::descontoComReceita() const {
	return descComReceita;
}

bool Medicamento::vendidoSemReceita() const {
	return vendidoSemRec;
}

bool Medicamento::podeSerReceitado() const {
	return podeSerRec;
}

ostream& Medicamento::printSimp(ostream& os) const {
	
	Produto::printSimp(os) << "&" << vendidoSemRec << "&" << podeSerRec << "&" << descComReceita;

	return os;
}

