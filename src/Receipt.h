#ifndef SRC_RECEIPT_H_
#define SRC_RECEIPT_H_

class Receipt {
public:
	Receipt();
	virtual ~Receipt();
private:
	const int receiptNumber;
	const Client client;
	const string doctorName;
	map< Product, int> products;
};

#endif /* SRC_RECEIPT_H_ */
