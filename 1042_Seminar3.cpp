#include<iostream>

using namespace std;

class Inchisoare {
private:
	char* nume;
	int nrDetinuti;
	int* aniDetentie;
	float buget;
	bool* angajat;

public:
	int* get_aniDetentie() {
		return aniDetentie;
	}

	void set_aniDetentie(int* vector, int nrDetinuti) {
		if (nrDetinuti > 0) {
			//delete[]aniDetentie;
			aniDetentie = new int[nrDetinuti];
			for (int i = 0; i < nrDetinuti; i++) {
				aniDetentie[i] = vector[i];
			}
		}
	}

	int get_nrDetinuti() {
		return nrDetinuti;
	}

	void set_nrDetinuti(int valoareNoua) {
		if (valoareNoua > 1)
		{
			nrDetinuti = valoareNoua;
		}
		else {
			throw "Valoare incorecta";
		}
	}

	char* get_nume() {
		return nume;
	}

	void set_nume(char* valoare) {
		if (strlen(valoare) > 2) {
			//delete[]nume;
			nume = new char[strlen(valoare) + 1];
			strcpy(nume, valoare);
		}
	}

};
void main() {
	Inchisoare inc;
	try {

		inc.set_nrDetinuti(-70);
	}
	catch (char* mesaj) {
		cout << mesaj << endl;
		inc.set_nrDetinuti(70);
	}

	cout << inc.get_nrDetinuti();

	inc.set_nume("Popescu");
	cout << inc.get_nume() << endl;


	inc.set_aniDetentie(new int[3]{ 1, 5, 2 }, 3);
	
	int* adresa;
	adresa = inc.get_aniDetentie();
	cout << adresa[1] << endl;

	cout << inc.get_aniDetentie()[2];
}