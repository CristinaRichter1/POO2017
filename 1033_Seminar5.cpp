#include<iostream>

using namespace std;

class Zoo {
private:
	char* nume;
	int nrSpecii;
	float pret;
	int* nrAnimaleSpecie;
	bool* carnivor;
	const int cod;
	static int nr_obiecte;
	const int nr_mese;
	static float taxa_stat;


public:

	Zoo operator=(const Zoo &z){
		if (this->nume != NULL)
			delete[]this->nume;
		this->nume = new char[strlen(z.nume) + 1];
		strcpy(this->nume, z.nume);
		this->nrSpecii = z.nrSpecii;
		this->pret = z.pret;
		if (nrAnimaleSpecie)
			delete[]nrAnimaleSpecie;
		this->nrAnimaleSpecie = new int[z.nrSpecii];
		if (carnivor)
			delete[]carnivor;
		this->carnivor = new bool[z.nrSpecii];
		for (int i = 0; i < z.nrSpecii; i++){
			this->nrAnimaleSpecie[i] = z.nrAnimaleSpecie[i];
			this->carnivor[i] = z.carnivor[i];
		}
		return *this;
	}

	static float get_taxa(){
		return taxa_stat;
	}

	static void set_taxa(float taxa){
		taxa_stat = taxa;
	}

	int get_cod(){
		return cod;
	}

	Zoo():cod(nr_obiecte),nr_mese(3) {
		this->nume = NULL;
		this->nrSpecii = 0;
		this->pret = 0;
		this->nrAnimaleSpecie = NULL;
		this->carnivor = NULL;
		nr_obiecte++;
	}

	Zoo(char* nume, int nrSpecii, float pret, 
		int* nrAnimaleSpecie, bool * carnivor, 
		int mese) :cod(nr_obiecte), nr_mese(mese)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrSpecii = nrSpecii;
		this->pret = pret;
		this->nrAnimaleSpecie = new int[nrSpecii];
		for (int i = 0; i < nrSpecii; i++) {
			this->nrAnimaleSpecie[i] = nrAnimaleSpecie[i];
		}
		this->carnivor = new bool[nrSpecii];
		for (int i = 0; i < nrSpecii; i++) {
			this->carnivor[i] = carnivor[i];
		}
		nr_obiecte++;
	}

	Zoo(char* nume, int nrSpecii):cod(nr_obiecte),nr_mese(3) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrSpecii = nrSpecii;
		this->pret = 0;
		this->nrAnimaleSpecie = new int[nrSpecii];
		this->carnivor = new bool[nrSpecii];
		for (int i = 0; i < nrSpecii; i++) {
			this->nrAnimaleSpecie[i] = 0;
			this->carnivor[i] = false;
		};
		nr_obiecte++;
	}

	Zoo(Zoo &z):cod(nr_obiecte),nr_mese(z.nr_mese),pret(z.pret){
		this->nume = new char[strlen(z.nume) + 1];
		strcpy(this->nume, z.nume);
		this->nrSpecii = z.nrSpecii;
		this->nrAnimaleSpecie = new int[z.nrSpecii];
		this->carnivor = new bool[z.nrSpecii];
		for (int i = 0; i < z.nrSpecii; i++){
			this->nrAnimaleSpecie[i] = z.nrAnimaleSpecie[i];
			this->carnivor[i] = z.carnivor[i];
		}
		nr_obiecte++;
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
			if (nume != NULL)
				delete[] nume;
			nume = new char[strlen(numeNou) + 1];
			strcpy(nume, numeNou);
		}
	}

	int* get_nrAnimaleSpecie() {
		return nrAnimaleSpecie;
	}

	void set_nrAnimaleSpecie(int* vector, int nrSpecii) {
		if (nrAnimaleSpecie)
			delete[]nrAnimaleSpecie;

		//niciodata asa: nrAnimaleSpecie = vector;
		nrAnimaleSpecie = new int[nrSpecii];
		for (int i = 0; i < nrSpecii; i++) {
			nrAnimaleSpecie[i] = vector[i];
		}

		this->nrSpecii = nrSpecii;
	}
};
int Zoo::nr_obiecte = 1;
float Zoo::taxa_stat = 20;

void main() {
	Zoo::get_taxa();


	Zoo z1;
	Zoo z2;
	cout << z1.get_cod() << " " << z2.get_cod() << endl;
	z1.set_taxa(10);
	cout << z2.get_taxa();


	Zoo z3("Baneasa", 3, 40, new int[3]{3, 4, 2}, new bool[3]{true, false, true}, 2);
	Zoo z4 = z3;
	cout << z4.get_nume();

	Zoo z5;
	//
	//
	//
	z5 = z3;
	cout << endl << z5.get_nume() << endl;;
}