


#include<iostream>

using namespace std;

//piata

class Piata {
public:
	char* nume;
	char adresa[10];
	int nr_standuri;
	int * coduri_standuri;
	float * pret_inchiriere;

	void afisare() {
		cout << "Piata " << nume << " are " << nr_standuri << " standuri." << endl;
		for (int i = 0; i < nr_standuri; i++) {
			cout << "Standul: " << coduri_standuri[i] << " costa " << pret_inchiriere[i] << endl;
		}
	}
};

void main() {
	Piata p;
	char buffer[20];
	cin >> buffer;
	p.nume = new char[strlen(buffer) + 1];
	strcpy(p.nume, buffer);
	cin >> p.adresa;
	cin >> p.nr_standuri;
	p.coduri_standuri = new int[p.nr_standuri];
	//de discutat despre paranteze rotunde
	p.pret_inchiriere = new float[p.nr_standuri];
	for (int i = 0; i < p.nr_standuri; i++)
	{
		cout << " Codul si pretul pentru standul " << (i + 1) << ":";
		cin >> p.coduri_standuri[i];
		cin >> p.pret_inchiriere[i];
	}

	p.afisare();
	Piata* pp;
	pp = new Piata();
	pp->nume = new char[3];



}