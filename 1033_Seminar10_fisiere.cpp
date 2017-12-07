#include <iostream>
#include<fstream>

using namespace std;

class Produs {
private:
	char* nume;
	int cod;

public:
	friend ifstream& operator >> (ifstream& file, Produs& p) {
		file >> p.cod;
		char buffer[20];
		file >> buffer;
		if (p.nume)
			delete[]p.nume;
		p.nume = new char[strlen(buffer) + 1];
		strcpy(p.nume, buffer);
		return file;
	}

	char* get_nume() {
		return nume;
	}
	int get_cod(){
		return cod;
	}
	Produs() {
		this->nume = new char[strlen("necunoscut")+1];
		strcpy(this->nume, "necunoscut");
		this->cod = 3;
	}
	Produs(char* nume, int cod) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->cod = cod;
	}

	Produs(const Produs& p) {
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->cod = p.cod;
	}
	Produs operator=(const Produs& p) {
		if (this->nume)
			delete[]this->nume;
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->cod = p.cod;
		return *this;
	}

	~Produs() {
		if (this->nume)
			delete[]this->nume;
	}
};

class Supermarket {
private:
	Produs**produse;
	int nrProduse;
public:
	Supermarket() {
		nrProduse = 4;
		produse = new Produs*[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			produse[i] = new Produs("Apa", 2+i);
		}
	}

	Supermarket(const Supermarket& s) {
		this->nrProduse =s.nrProduse;
		this->produse = new Produs*[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			produse[i] = new Produs(*s.produse[i]);
		}
	}
	Supermarket operator=(const Supermarket& s) {
		for (int i = 0; i < nrProduse; i++) {
			delete produse[i];
		}
		delete[]produse;

		this->nrProduse = s.nrProduse;
		this->produse = new Produs*[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			produse[i] = new Produs(*s.produse[i]);
		}
		return *this;
	}
	~Supermarket() {
		for (int i = 0; i < nrProduse; i++) {
			delete produse[i];
		}
		delete[]produse;
	}

	
};

ostream& operator<<(ostream& monitor, Produs p) {
	monitor << p.get_cod() << endl << p.get_nume() << endl;
	return monitor;
}
ofstream& operator<<(ofstream& file, Produs p) {
	file << p.get_cod() << "," << p.get_nume() << endl;
	return file;
}

void main() {

	/*Produs p;
	cout << p;

	ofstream f("fisier.txt", ios::out);
	f << p;

	f.close();

	ifstream g("fisier.txt", ios::in);
	Produs d("Ghirlanda", 8);
	cout << d << endl;
	g >> d;
	cout << d;*/

	//ofstream f("fisier.csv", ios::out);
	//Produs * produse;
	//produse = new Produs[5];
	//for (int i = 0; i < 5; i++) {
	//	f << produse[i];
	//}
	//f.close();

	Produs p("Globuri", 4);
	ofstream f("fisier.bin", ios::binary | ios::out);
	f.write((char*)&p, sizeof(Produs));
	f.close();

	ifstream g("fisier.bin", ios::binary | ios::in);
	Produs d;
	cout << d << endl;
	g.read((char*)&d, sizeof(Produs));
	cout << d << endl;
	g.close();

}