#include<iostream>

using namespace std;

class Zoo {
private:
	char* nume;
	int nrSpecii;
	float pret;
	int* nrAnimaleSpecie;
	bool* carnivor;

public:

	Zoo() {
		this->nume = NULL;
		this->nrSpecii = 0;
		this->pret = 0;
		this->nrAnimaleSpecie = NULL;
		this->carnivor = NULL;
	}

	Zoo(char* nume, int nrSpecii, float pret, int* nrAnimaleSpecie, bool * carnivor) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrSpecii = nrSpecii;
		this->pret = pret;
		this->nrAnimaleSpecie = new int[nrSpecii];
		for (int i = 0;i < nrSpecii;i++) {
			this->nrAnimaleSpecie[i] = nrAnimaleSpecie[i];
		}
		this->carnivor = new bool[nrSpecii];
		for (int i = 0;i < nrSpecii;i++) {
			this->carnivor[i] = carnivor[i];
		}
	}

	Zoo(char* nume, int nrSpecii) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrSpecii = nrSpecii;
		this->pret = 0;
		this->nrAnimaleSpecie = new int[nrSpecii];
		this->carnivor = new bool[nrSpecii];
		for (int i = 0;i < nrSpecii;i++) {
			this->nrAnimaleSpecie[i] = 0;
			this->carnivor[i] = false;
		};
	}
	~Zoo() {
		delete[]nume;
		delete[]nrAnimaleSpecie;
		delete[]carnivor;
	}


	int get_nrSpecii() {
		return nrSpecii;
	}

	void set_nrSpecii(int valoareNoua) {
		if (valoareNoua > 0)
		{
			nrSpecii = valoareNoua;
		}
		else
		{
			throw "Valoarea nu este corecta.";
		}
	}

	char* get_nume() {
		return nume;
	}
	void set_nume(char* numeNou) {
		if (strlen(numeNou) > 2) {
			if(nume!=NULL)
				delete[] nume;
			nume = new char[strlen(numeNou) + 1];
			strcpy(nume, numeNou);
		}
	}

	int* get_nrAnimaleSpecie() {
		return nrAnimaleSpecie;
	}

	void set_nrAnimaleSpecie(int* vector, int nrSpecii) {
		if(nrAnimaleSpecie)
			delete[]nrAnimaleSpecie;
		
		//niciodata asa: nrAnimaleSpecie = vector;
		nrAnimaleSpecie = new int[nrSpecii];
		for (int i = 0; i < nrSpecii; i++) {
			nrAnimaleSpecie[i] = vector[i];
		}

		this->nrSpecii = nrSpecii;
	}
};


void main() {
	//Zoo z;
	//try {
	//	z.set_nrSpecii(-5);
	//}
	//catch (char* mesaj) {
	//	cout << endl << mesaj << endl;
	//	z.set_nrSpecii(3);
	//}
	//cout << z.get_nrSpecii();
	//z.set_nume("LAZ");
	//cout << z.get_nume();

	//int vector[3] = { 5, 2, 3 };
	//int nrElemente = 3;

	//z.set_nrAnimaleSpecie(vector, nrElemente);
	//int* variabila = z.get_nrAnimaleSpecie();
	//cout << variabila[1] << endl;

	//cout << z.get_nrAnimaleSpecie()[2];

	Zoo x;
	cout << x.get_nrSpecii();
	char nume[20];
	strcpy(nume, "ZOO Baneasa");
	int nr = 4;
	float pretBilet = 10;
	int nrAnimale[4] = { 2,3,7,4 };
	bool carnivor[4] = { true, true, false,false };

	Zoo y(nume, nr, pretBilet, nrAnimale, carnivor);
	cout << endl << y.get_nrSpecii() << endl;

	Zoo t("Zoo bucuresti", 5);
}