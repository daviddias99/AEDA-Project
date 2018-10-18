#ifndef SRC_CHAIN_H_
#define SRC_CHAIN_H_

#include <string>
#include <vector>

using namespace std;

class Chain {
public:
	Chain();
	virtual ~Chain();
	bool addPharmacy(Pharmacy pharmacy);
	bool addClient(Client client);
	bool addEmployee(Employee empolyee);
	bool removePharmacy(Pharmacy pharmacy);
	bool removePharmacy(string pharmacyName);
	bool removeClient(Client client);
	bool removeClient(string clientName);
	int getNumPharmacies() const;
	int getNumEmployees() const;
	int getNumClients() const;
private:
	vector< Farmacia > farmacias;
	vector< Cliente > clientes;
	vector< Funcionario> funcionarios;
};

#endif /* SRC_CHAIN_H_ */
