#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using namespace std;


class Produto {
public:
	Produto(long int code, string n, string desc, float pr);
	long int getCodigo() const;
	string getNome() const;
	string getDesc() const;
	float getPreco() const;
	int alteraPreco(float novoPreco);
private:
	const long int codigo;
	const string nome;
	const string descricao;
	float preco;
};


#endif /* PRODUTO_H */
