# Project1-AEDA-T5G1

-----Intended Features-----

-Load and store;
-consultar a lista de clientes/funcionarios/vendas e assim;
-realizar vendas;
-adicionar clientes(quando fazem a primeira compra);
-gerir stock (adicionar e remover medicamentos);
-aplicar algoritmos de pesquisa e de ordenação;
-ordenar pessoas por ordem alfabetica;
-adicionar outros "modos" de ordenação
-mostrar fatura

-----Estrutura-----

Class Cadeia
	Atributos: 
		lista Farmacia
		lista funcionarios
		lista clientes      (criar um unico vetor: vector< Pessoa *> para guardar funcionarios e clientes??)

Class Farmacia:
	Atributos:
		nome
		morada
		gerente
		lista funcionarios
		lista Produtos

Class Pessoa:
	Atributos:
		nome
		morada
		nº contribuinte
		
Class Funcionario : public/protected Pessoa
	Atributos:
		salario
		nome farmacia em que trabalha
		cargo na farmacia

Class Cliente : public/protected Pessoa
	Atributos:
		historial (lista Compras)

Class Receita:
	Attributos:
		numero da receita
		Cliente
		nome medico
		lista produtos

Class Venda:
	Atributos:
		Receita
		lista produtos
		data e hora
		valor total

Class Produto:
	Atributos:
		codigo
		nome
		preco
		descricao

Class Medicamento: public/protected Produto
	Atributos:
		bool pode_ser_receitado
		taxa de desconto quando é receitado
		bool pode_ser_vendido_sem_receita
