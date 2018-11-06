#include "Medicamento.h"

Medicamento::Medicamento(long int cod, string n, string desc, float pr, bool vendSemRec, bool pdSerRec, float descRec): Produto(cod, n, desc, pr), vendidoSemRec(vendSemRec), podeSerRec(pdSerRec), descComReceita(descRec) {
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


