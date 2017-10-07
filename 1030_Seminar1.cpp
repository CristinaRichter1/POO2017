#include<iostream>

using namespace std;

struct LocMunca {
	char* departament;
	float salariu;
	char initiala_departament;
	int nr_candidati;
};

LocMunca initializareLocMunca() {
	LocMunca l;
	//l.departament = (char*)malloc(sizeof(char)*(strlen("IT") + 1));
	l.departament = new char[strlen("IT") + 1];
	strcpy(l.departament, "IT");
	l.salariu = 10000;
	l.initiala_departament = 'I';
	l.nr_candidati = 10;
	return l;
}

void modificaSalariu(LocMunca loc) {
	loc.salariu = 20000;
}
void modificaSalariu_pointer(LocMunca *loc) {
	loc->salariu = 20000;
}

void modificaSalariu_referinta(LocMunca &loc) {
	loc.salariu = 20000;
}

void main() {

	LocMunca locMunca;
	locMunca = initializareLocMunca();

	cout << "Este disponibil un loc de munca in departamentul " << 
		locMunca.departament << " cu salariul " << locMunca.salariu<<endl;
	modificaSalariu_referinta(locMunca);
	cout << "Este disponibil un loc de munca in departamentul " <<
		locMunca.departament << " cu salariul " << locMunca.salariu << endl;

}