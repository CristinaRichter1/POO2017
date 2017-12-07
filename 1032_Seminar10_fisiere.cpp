#include<iostream>
#include<fstream>

using namespace std;


class Arma {
private:
	char*nume;
	int nrGloante;
	float greutate;
public:

	char* get_nume() {
		return nume;
	}

	int get_nrGloante() {
		return this->nrGloante;
	}
	float get_greutate() {
		return this->greutate;
	}

	Arma() {
		this->nume = new char[strlen("Pistol") + 1];
		strcpy(this->nume, "Pistol");
		this->nrGloante = 6;
		this->greutate = 300;
	}

	Arma(char*nume, int nrGloante, float greutate) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrGloante = nrGloante;
		this->greutate = greutate;
	}
	Arma(const Arma & arma) {
		this->nume = new char[strlen(arma.nume) + 1];
		strcpy(this->nume, arma.nume);
		this->nrGloante = arma.nrGloante;
		this->greutate = arma.greutate;
	}

	Arma operator=(const Arma& arma) {
		if (this->nume) {
			delete[]this->nume;
		}
		this->nume = new char[strlen(arma.nume) + 1];
		strcpy(this->nume, arma.nume);
		this->nrGloante = arma.nrGloante;
		this->greutate = arma.greutate;

		return *this;
	}

	~Arma() {
		if (this->nume) {
			delete[]this->nume;
		}
	}

	friend ifstream& operator >> (ifstream& file, Arma & arma) {
		char buffer[20];

		file >> buffer;
		if (strlen(buffer) > 2) {
			if (arma.nume)
				delete[]arma.nume;
			arma.nume = new char[strlen(buffer) + 1];
			strcpy(arma.nume, buffer);
		}
		else {
			throw "Incorect file format";
		}
		file >> arma.nrGloante;
		file >> arma.greutate;
		return file;
	}

};

ostream& operator<<(ostream& consola, Arma arma) {
	consola << arma.get_nume() << endl;
	consola << arma.get_nrGloante() << endl;
	consola << arma.get_greutate() << endl;
	return consola;
}

ofstream& operator<<(ofstream& consola, Arma arma) {
	consola << arma.get_nume() << ",";
	consola << arma.get_nrGloante() << ",";
	consola << arma.get_greutate() << endl;
	return consola;
}



class Persoana {
private:
	int varsta;
public:
	Persoana(int varsta) {
		this->varsta = varsta;
	}
	int get_varsta() {
		return varsta;
	}
};

class Politist : public Persoana {
private:
	Arma *arma;
	float salariu;
public:
	Politist():Persoana(28) {
		this->salariu = 1450;
		this->arma = new Arma();
	}
	Politist(Arma *arma, float salariu, int varsta):Persoana(varsta) {
		this->salariu = salariu;
		this->arma = new Arma(*arma);
	}
	~Politist() {
		if (arma) {
			delete arma;
		}
	}
	Politist(const Politist& p) :Persoana(p) {
		this->salariu = p.salariu;
		this->arma = new Arma(*p.arma);
	}
	Politist operator=(const Politist& p) {
		Persoana::operator=(p);
		this->salariu = p.salariu;
		if (arma)
			delete arma;
		this->arma = new Arma(*p.arma);
		return *this;
	}
};


void main() {
	///*Arma a("MachineGun", 300, 1300);
	//ofstream f("fis ier.txt", ios::out);
	//cout << a << endl;
	//f << a<<endl;

	//f.close();*/

	//ifstream g("fisier.txt", ios::in);
	//Arma b;
	//try {
	//	g >> b;
	//	cout << b;
	//}
	//catch (char* exceptie) {
	//	cout << exceptie;
	//}

	int n = 5;
	Arma** arma = new Arma*[n];
	for (int i = 0; i < n; i++) {
		arma[i] = new Arma("Pistol", 100 * (i + 1), 10*(i + 1));
	}

	ofstream f("fisier.csv", ios::out);
	f << "Nume,Numar gloante,Greutate" << endl;
	for (int i = 0; i < n; i++) {
		f << *arma[i];
	}

	f.close();

	Arma a("MachineGun", 200, 1500);

	ofstream fb("fisier.bin", ios::binary | ios::out);
	fb.write((char*)&a, sizeof(Arma));
	fb.close();

	Arma b;
	cout << b<<endl;
	ifstream fbi("fisier.bin", ios::binary | ios::in);
	fbi.read((char*)&b, sizeof(Arma));
	cout << b;

}