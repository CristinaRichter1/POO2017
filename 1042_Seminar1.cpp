#include<iostream>

using namespace std;

struct Farmacie {
	char* nume;
	int nr_medicamente;
	float profit;
	char initiala_farmacista;
	char** medicamente;
};

Farmacie initializareFarmacie() {
	Farmacie f;
	//f.nume = (char*)malloc((strlen("Catena") + 1)*sizeof(char));
	f.nume = new char[strlen("Catena") + 1];
	strcpy(f.nume, "Catena");
	f.nr_medicamente = 5;
	f.profit = 200.5;
	f.initiala_farmacista = 'A';
	f.medicamente = new char*[f.nr_medicamente];
	for (int i = 0; i < f.nr_medicamente; i++) {
		f.medicamente[i] = new char[strlen("Paracetamol") + 1+1];
		char buffer[2];
		strcpy(f.medicamente[i], "Paracetamol");
		strcat(f.medicamente[i], itoa(i + 1, buffer,10));
	}
	return f;
}

void modificaProfit(Farmacie f) {
	f.profit = 300.7;
}

void modificaProfit2(Farmacie *f) {
	f->profit = 300.7;
}

void modificaProfit3(Farmacie &f) {
	f.profit = 300.7;
}

void main() {
	Farmacie farmacie;
	farmacie = initializareFarmacie();

	cout << "Farmacia " << farmacie.nume <<
		" are un profit de " << farmacie.profit << endl;

	modificaProfit3(farmacie);
	
	cout << "Farmacia " << farmacie.nume <<
		" are un profit de " << farmacie.profit << endl;

}