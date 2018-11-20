#ifndef MEDICAMENTO_H_
#define MEDICAMENTO_H_

#include "Produto.h"

class Medicamento : public Produto {
public:
	Medicamento(unsigned long int cod, string n, string desc, float pr, float i, bool vendSemRec, bool pdSerRec, float descRec);
	float descontoComReceita() const;
	bool podeSerReceitado() const;
	bool vendidoSemReceita() const;
	ostream& printSimp(ostream& os) const;
	ostream& print(ostream& os) const;
private:
	const bool vendidoSemRec;
	const bool podeSerRec;
	const float descComReceita;
};


#endif /* MEDICAMENTO_H_ */
