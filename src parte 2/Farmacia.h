#ifndef Farmacia_H
#define Farmacia_H

#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>


#include "Empregado.h"
#include "Cliente.h"
#include "Produto.h"
#include "Medicamento.h"
#include "Excecoes.h"
#include "Fornecedor.h"
#include "Encomenda.h"

using namespace std;

/*!
 * \file Farmacia.h
 *
 * \author FEUP AEDA1819 MIEIC Turma5_G1
 * \author David Silva
 * \author Gaspar Pinheiro
 * \author Luis Cunha
 */

 /** @defgroup Farmacia Farmacia
  * @{
  *
  * Farmacia
  */



/**
 * @brief Representa uma fila de prioridade para fornecedores. Considera-se que um fornecedor possui maior prioridade do que o outro na fila se tiver menos encomendas realizadas. Esta medida destina-se a implementar um "comercio justo" entre as farmacias e os seus fornecedores.
 * 
 */
typedef priority_queue<Fornecedor*, vector<Fornecedor*>, fornecedor_heap_sort_func> HeapFornecedores;

/**
 * @brief Representa uma fila de prioridade para produtos de uma farmacia. Os produtos com maior prioridade na fila devem ser encomendados primeiro. Assim, a prioridade na fila é dada pela quantidade do produto existente em stock.
 * 
 */
typedef priority_queue<pair<Produto*, uint>, vector<pair<Produto*, uint>>, produtos_heap_sort_func> HeapStock;

  /**
   * @brief Classe que representa uma farmacia
   *
   */
class Farmacia {
public:
	/**
	* @brief Construtor da classe Farmacia que inicializa os atributos nome e morada
	* @param nome Nome da farmacia
	* @param morada Morada da farmacia
	*/
	Farmacia(string nome, Morada morada);
	/**
	* @brief Construtor da classe farmacia que inicializa os atributos atravez do conteudo lido de um ficheiro de texto
	* @param simp String com as informacoes sobre a farmacia no formato escrito pelo programa num ficheiro de texto
	*/
	Farmacia(string simp);
	/**
	*  @brief Destrutor da classe Farmacia. Liberta da memoria o gerente, o vetor de empregados, os produtos e as vendas
	*/
	virtual ~Farmacia();
	/**
	* @brief Adiciona um produto ao stock da farmacia. Se este ja existir, e lhe adicionada a quantidade indicada no segundo parametro. (atualiza a fila de prioridade de stock)
	* @param produto Apontador para o produto que vai ser adicionado ao stock ou que vai ter um aumento da quantidade
	* @param quantidade Quantidade que vai ser adicionada de produto ao stock
	*/
	void addProduto(Produto *produto, int quantidade);
	/**
	* @brief Adiciona o empregado indicado no argumento a lista de empregados da farmacia
	* @param empregado Apontador para empregado que vai ser adicionado a lista de empregados da farmacia
	*/
	bool addEmpregado(Empregado* empregado);

	/**
	 * @brief Adiciona o fornecedor dado como argumento aos fornecedores da farmacia. (atualiza heap e vetor de fornecedores)
	 * 
	 * @param novo_fornecedor 			apontador para o fornecedor a adicionar
	 * @return true 					se o fornecedor foi adicionado
	 * @return false 					se o fornecedor nao foi adicionado ( fornecedor invalido ou ja presente na farmacia)
	 */
	bool addFornecedor(Fornecedor* novo_fornecedor);

	/**
	* @brief Remove o poduto com o codigo indicado no seu parametro completamente da lista de produtos em stock. (atualiza a fila de prioridade de produtos)
	* @param codigo Codigo do produto a ser removido
	*/
	void remProduto(long unsigned int codigo);
	/**
	* @brief Remove o empregado com o ID indicado no seu parametro da lista de empregados da farmacia
	* @param ID ID do empregado a ser removido
	*/
	void remEmpregado(uint ID);

	/**
	 * @brief Remove o fornecedor dado como argumento aos fornecedores da farmacia. (atualiza heap e vetor de fornecedores)
	 * 
	 * @param novo_fornecedor 			apontador para o fornecedor a remover
	 * @return true 					se o fornecedor foi removido
	 * @return false 					se o fornecedor nao foi removido ( nao existe na farmacia ou e invalido)
	 */
	bool removeFornecedor(Fornecedor * fornecedor);

	/**
	* @brief Troca de gerente da farmacia. O antigo gerente passa a ter o cargo de empregado e o gerente passa a ser o empregado indicado no seu parametro.
	* @param novoGerente Apontador para o empregado que vai passar a ser o gerente da farmacia.
	* @param novoCargo	 novo cago a ser atribuido ao ex-gerente
	* @return true se a troca foi realizada com sucesso
	* false se ocorreu algum problema.
	*/
	bool setGerente(Empregado* novoGerente, string novoCargo);
	/**
	* @brief Remove a quantidade indicada no segundo parametro de produto com o codigo indicado no primeiro parametro do stock da farmacia. (atualiza a fila de prioridade dos produtos)
	* Lanca uma excecao se o produto nao existe em stock
	* @param codigo Codigo do produto no qual a quantidade em stock vai ser reduzida
	* @param quantidade Quantidade de produto a diminuir ao stock
	* @return True se a quantidade foi removida com sucesso
	* False se a quantidade indicada no parametro e maior do que a quantidade de produto em stock
	*/
	void removeQuantidade(long unsigned int codigo, uint quantidade);
	/**
	* @brief Adiciona a quantidade indicada no segundo parametro de produto com o codigo indicado no primeiro argumento ao stock da farmacia. (atualiza a fila de prioridade dos produtos)
	* @param codigo Codigo do produto no qual a quantidade em stock vai ser aumentada
	* @param quantidade Quantidade de produto a aumentar ao stock
	*/
	void addQuantidade(long unsigned int codigo, uint quantidade);
	/**
	* @brief Procura no stock da farmacia pelo produto com o codigo indicado no parametro
	* @param codigo Codigo do produto a ser procurado
	* @return True se o produto foi encontrado
	* False se o produto nao existe
	*/
	bool existeProduto(unsigned long int codigo);
	/**
	* @brief Devolve o nome da farmacia
	* @return Nome da farmacia
	*/
	string getNome() const;
	/**
	* @brief Devolve a morada da farmacia
	* @return Morada da farmacia
	*/
	Morada getMorada() const;
	/**
	* @brief Devolve o gerente da farmacia
	* @return Gerente da farmacia
	*/
	Empregado* getGerente() const;
	/**
	* @brief Procura na lista de empregados da farmacia aqueles com o nome indicado no parametro
	* @param nome Nome dos empregados que vai procurar na lista de empregados da farmacia
	* @return Vetor de apontadores para empregados com o nome indicado no parametro que trabalham na farmacia
	*/
	vector<Empregado*> getEmpregados(string nome) const;

	/**
	 * @brief Retorna um vetor com os fornecedores que estao em negocio com a farmacia.
	 * 
	 * @return vector<Fornecedor*> 			fornecedores da farmacia
	 */
	vector<Fornecedor*> getFornecedores() const;

	/**
	 * @brief Retorna um apontador para o fornecedor com o nome passado com argumento. Faz throw da excecao "FornecedorNaoExiste"
	 * 
	 * @param nome 							nome do fornecedor a obter
	 * @return Fornecedor* 					apontador para o fornecedor com o nome dado.
	 */	
	Fornecedor* getFornecedor(string nome) const;

	/**
	* @brief Devolve o numero de empregados que trabalham na farmacia
	* @return Numero de empregados da farmacia
	*/
	unsigned int getNumEmpregados() const;
	/**
	* @brief Procura no stock o produto com o codigo indicado no seu parametro
	* Lanca uma excecao nao for encontrado nenhum produto com esse codigo em stock
	* @param codigo Codigo do produto a ser procurado em stock
	* @return Apontador para o produto com o codigo indicado no parametro
	*/
	pair<Produto*, unsigned int> getProduto(int codigo) const;

	/**
	* @brief Procura no stock o produto com o nome indicado no seu parametro
	* Lanca uma excecao nao for encontrado nenhum produto com esse nome em stock
	* @param nome nome do produto a ser procurado em stock
	* @return	  Apontador para o produto com o codigo indicado no parametro
	*/

	pair<Produto*, unsigned int> getProduto(string nome) const;


	/**
	 * @brief Obtem o vetor de vendas da farmacia
	 *
	 * @return Vetor de apontadores para vendas realizadas pela farmacia
	 */
	const vector<Venda *>& getVendas() const;

	/**
	* @brief Devolve o numero total de produtos em stock, incluindo os produtos repetidos
	* @return Numero total de produtos em stock
	*/
	unsigned int getTotalProdutos() const;

	/**
	 * @brief Devolve o membro privado da farmacia "fornecedoresStringFicheiro". Este membro contem os nomes dos fornecedores que estavam em negocio da farmacia aquando do carregamento desta de um ficheiro.
	 * 
	 * @return string 				valor do membro fornecedoresStringFicheiro
	 */
	string getFornecedoresStr() const;


	/**
	* @brief Devolve o numero de produtos diferentes em stock
	* @return Numero de produtos diferentes em stock
	*/
	unsigned int tamanhoStock() const;
	/**
	* @brief Devolve o numero de empregados na farmacia, incluindo o gerente
	* @return Numero de empregados da farmacia
	*/
	unsigned int numEmpregados() const;
	/**
	* @brief Devolve o numero total de vendas que foram realizadas nesta farmacia
	* @return Numero total de vendas
	*/
	unsigned int numVendas() const;

	/**
	* @brief Compara a igualdade de duas farmacia. Duas farmacias sao iguais se possuem o mesmo nome
	* @param ph1 Farmacia a ser comparada com o proprio objeto
	* @return True se as duas farmacias sao iguais. False se nao o sao
	*/
	bool operator == (const Farmacia & ph1) const;
	/**
	* @brief Compara a prioridade de duas farmacias. Uma farmacia tem prioridade sobre outra se o seu nome tiver prioridade alfabetica.
	* Se as duas farmacias tem nomes iguais, a que tem prioridade e aquela com menor tamanho de stock
	* @param ph1 Farmacia a ser comparada com o proprio objeto
	* @return True se o proprio objeto e menor que a farmacia no seu parametro
	*/
	bool operator < (const Farmacia & ph1) const;

	/**
	* @brief Ordena a lista de empregados de acordo com o modo indicado no seu parametro
	* @param modo Modo no qual a lista de empregados vai ser ordenada
	*/
	void sortEmpregados(ord_empregados modo);

	/**
	* @brief Escreve num ficheiro as informacoes relativas a farmacia para preservar esta informacao e ser posteriormente carregada.
	*/
	ostream& printSimp(ostream& os) const;

	/**
	* @brief Mostra o nome e a morada da farmacia no ecra.
	*/
	ostream& print(ostream& os) const;

	/**
	 * @brief Mostra na stream dada como argumento os fornecedores da farmacia em formato lista. Consulte a classe "Fornecedor" para obter a formatacao usada.
	 * 
	 * @param os 						stream onde a informacao e escrita
	 * @return ostream& 				mesma stream que entrada
	 */
	ostream& print_lista_fornecedores(ostream& os);

	/**
	* @brief Mostra alguns atributos de todos os empregados da farmacia no ecra
	*/
	void mostrarEmpregados() const;
	/**
	* @brief Mostra alguns atributos de todos os produtos em stock no ecra e ainda as suas quantidades
	*/
	void mostrarStock() const;

	/**
	 * @brief Mostra no ecra, em formato lista, os produtos da fila de prioridade de reabastecimento que tem stock abaixo da quantidade minima. Tambem pode ser escolhido mostrar todos os produtos.
	 * 
	 * @param quantidade_minima 				quantidade minima dos produtos a serem mostrados
	 * @param mostraTodos 						verdadeiro se for pretendido mostrar todos (neste caso o valor do primeiro argumento é irrelevante)
	 */
	void mostrarPrioridadeEncomenda_listForm(uint quantidade_minima, bool mostraTodos = false) const;

	/**
	 * @brief Mostra vendas da farmacia no ecra
	 */
	void mostrarVendas() const;
	/**
	* @brief Mostra no ecra as quantidades em stock de todos os produtos
	*/
	void consultarQuantidades() const;
	/**
	 * @brief Adiciona uma venda ao vetor de vendas da farmacia
	 */
	void addVenda(Venda* venda);

	/**
	 * @brief Constroi o heap que prioritiza os produtos conforme o stock existente.
	 * 
	 */
	void constroiFilaReabastecimento();

	/**
	 * @brief Atraves da fila de prioridade de encomendas, esta funcao repoe o stock da farmacia dos produtos que se encontram abaixo da quantidade limite dada como parametro.
	 * A nova quantidade dos produtos e definida pelo segundo argumento que, por defeito, adiciona a quantidade necessaria para a nova quantidade ser igual a quantidade minima dada.
	 * Esta funcao efetua tambem as encomendas aos fornecedores da farmacia. Conforme a reposicao possui produtos gerais e/ou medicamentos e feita uma encomenda aos fornecedores dos topos das filas de 
	 * prioridade de medicamentos e produtos, de forma a praticar "comercio justo". Retorna os nomes dos fornecedores intervenientes.
	 * 
	 * @param quantidade_limite 			produtos com uma quantidade inferior a esta sao repostos pela funcao
	 * @param quantidade_nova 				nova quantidade dos produtos repostos
	 * @return								par contendo os nomes dos fornecedores a quem foi feita a encomenda (first ou second "NULL" se houve apenas um)
	 */
	pair<string, string> repoeStock(uint quantidade_limite, int quantidade_nova = -1);

	/**
	 * @brief Efetua uma encomenda de um produto apenas, utilizando o fornecedor adequado (fornecedor com maior prioridade na fila de medicamentos ou produtos, dependendo do tipo de produto do argumento).
	 * A funcao atualiza o stock da farmacia.(Atencao: nao atualiza o heap de stock pelo que este deve ser reconstruido novamente). 
	 * 
	 * @param produto 						apontador para o produto a encomendar
	 * @param quantidade 					quantidade a encomendar
	 * @return								nome do fornecedor que satisfez a encomenda
	 */
	string efetuaEncomenda(Produto* produto, uint quantidade);

	/**
	 * @brief Esvazia a fila de prioridade de produtos
	 * 
	 */
	void esvaziaFilaReabastecimento();

	/**
	 * @brief Retorna a fila de prioridade de produtos da farmacia
	 * 
	 * @return HeapStock 
	 */
	HeapStock getFilaReabastecimento();


	/**
	 * @brief Indica se a farmacia possui algum fornecedor de medicamentos
	 * 
	 * @return true						a farmacia possui pelo menos um fornecedor de medicamentos 
	 * @return false 					a farmacia nao possui nenhum fornecedor de medicamentos
	 */
	bool temFornecedorMed();

		/**
	 * @brief Indica se a farmacia possui algum fornecedor de produtos genericos
	 * 
	 * @return true						a farmacia possui pelo menos um fornecedor de produtos genericos
	 * @return false 					a farmacia nao possui nenhum fornecedor de produtos genericos
	 */
	bool temFornecedorProd();

	//--------------------------------------------------------------------
	void despedirEmpregado(Empregado* emp);

private:
	/**
	 * @brief Nome da farmacia
	 *
	 */
	string nome;
	/**
	 * @brief Morada da farmacia
	 */
	Morada morada;
	/**
	 * @brief Apontador para o gerente da farmacia
	 */
	Empregado* gerente;
	/**
	 * @brief Vetor de apontadores para os empregados da farmacia
	 */
	//vector< Empregado* > empregados;

	empregadoHashTable empregados;

	/**
	 * @brief Map que representa o stock da farmacia (key = apontador para produto, value = quantidade)
	 *
	 */
	map< Produto *, unsigned int> stock;
	/**
	 * @brief Vetor de apontadores para vendas
	 */
	vector <Venda *> vendas;

	/**
	 * @brief Vetor que contem todos os fornecedores da farmacia
	 * 
	 */
	vector<Fornecedor*> fornecedores;

	/**
	 * @brief Heap que contem os fornecedores de medicamentos da farmacia. A prioridade no heap e definida pelo numero de encomendas que o fornecedor possui.
	 * 
	 */
	HeapFornecedores fornecedores_medicamentos;

	/**
	 * @brief Heap que contem os fornecedores de produtos da farmacia. A prioridade no heap e definida pelo numero de encomendas que o fornecedor possui.
	 * 
	 */
	HeapFornecedores fornecedores_produtos;

	/**
	 * @brief Heap que contem os produtos existentes na farmacia: A prioridade no heap e definida pela quantidade existente em stock dos produtos.
	 * 
	 */
	HeapStock prioridade_reabastecimento;

	/**
	 * @brief Guarda os nomes dos fornecedores da farmacia aquando do carregamento de um ficheiro de farmacias. 
	 * 
	 */
	string fornecedoresStringFicheiro;

};

/**
 * @brief Define o operador de menor para pares de produtos e quantidades. Um par e menor que outro se a quantidade (second do par) for maior. (destinado a definir prioridade)
 * 
 * @param p1 					par produto/quantidade
 * @param p2 					par produto/quantidade
 * @return true 				o primeiro argumento e menor que o segundo
 * @return false 				o primeiro argumento nao e menor que o segundo
 */
bool operator<(pair<Produto*, uint>& p1, pair<Produto*, uint>& p2);

/**
 * @brief Define o operador de igualdade para pares de produtos e quantidades. Os pares sao iguais se o codigo dos produtos for igual.
 * 
 * @param p1 					par produto/quantidade
 * @param p2 					par produto/quantidade
 * @return true 				os argumentos sao iguais
 * @return false 				os argumentos nao sao iguais
 */
bool operator==(pair<Produto*, uint>& p1, pair<Produto*, uint>& p2);



/**
* @brief Usada para ordenar a lista de farmacias da cadeia. Compara duas farmacias.
* @return True se a farmacia f1 tem nome menor do que a farmacia f2. Se os nomes sao iguais,
* retorna true se a farmacia f1 tem menor tamanho de stock do que a farmacia f2.
*/
bool farmacia_SortFunc_Nome_Crescente(Farmacia * f1, Farmacia * f2);

/**
* @brief Usada para ordenar a lista de farmacias da cadeia. Compara duas farmacias.
* @return True se a farmacia f1 tem nome maior do que a farmacia f2. Se os nomes sao iguais,
* retorna true se a farmacia f1 tem menor tamanho de stock do que a farmacia f2.
*/
bool farmacia_SortFunc_Nome_Decrescente(Farmacia *f1, Farmacia *f2);

/**
* @brief Usada para ordenar a lista de farmacias da cadeia. Compara duas farmacias.
* @return True se a farmacia f1 tem tamanho de stock menor do que a farmacia f2. Se os tamanhos de stock sao iguais,
* retorna true se a farmacia f1 tem menor nome do que a farmacia f2.
*/
bool farmacia_SortFunc_TamanhoStock_Crescente(Farmacia *f1, Farmacia *f2);

/**
* @brief Usada para ordenar a lista de farmacias da cadeia. Compara duas farmacias.
* @return True se a farmacia f1 tem tamanho de stock maior do que a farmacia f2. Se os tamanhos de stock sao iguais,
* retorna true se a farmacia f1 tem menor nome do que a farmacia f2.
*/
bool farmacia_SortFunc_TamanhoStock_Decrescente(Farmacia *f1, Farmacia *f2);

/**
* @brief Usada para ordenar a lista de farmacias da cadeia. Compara duas farmacias.
* @return True se a farmacia f1 tem numero de vendas menor do que a farmacia f2. Se o numeros de venas sao iguais,
* retorna true se a farmacia f1 tem menor nome do que a farmacia f2.
*/
bool farmacia_SortFunc_NumVendas_Crescente(Farmacia *f1, Farmacia *f2);

/**
* @brief Usada para ordenar a lista de farmacias da cadeia. Compara duas farmacias.
* @return True se a farmacia f1 tem numero de vendas maior do que a farmacia f2. Se o numeros de venas sao iguais,
* retorna true se a farmacia f1 tem menor nome do que a farmacia f2.
*/
bool farmacia_SortFunc_NumVendas_Decrescente(Farmacia *f1, Farmacia *f2);

/** @} */

#endif
