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

	/*Inchisoare() {
		this->nume = new char[strlen("Alcatraz") + 1];
		strcpy(this->nume, "Alcatraz");
		this->nrDetinuti = 0;
		this->aniDetentie = NULL;
		this->buget = 0;
		this->angajat = NULL;
	}
*/

	Inchisoare(char*nume, int nrDetinuti, int* aniDetentie, float buget, bool * angajat) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrDetinuti = nrDetinuti;
		this->aniDetentie = new int[nrDetinuti];
		this->buget = buget;
		this->angajat = new bool[nrDetinuti];
		for (int i = 0; i < nrDetinuti; i++) {
			this->aniDetentie[i] = aniDetentie[i];
			this->angajat[i] = angajat[i];
		}
	}

	Inchisoare(char* nume, int nrDetinuti) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrDetinuti = nrDetinuti;
		this->aniDetentie = new int[nrDetinuti];
		this->buget = 0;
		this->angajat = new bool[nrDetinuti];
		for (int i = 0; i < nrDetinuti; i++) {
			this->aniDetentie[i] = 0;
			this->angajat[i] = false;
		}

	}

	int* get_aniDetentie() {
		return aniDetentie;
	}

	void set_aniDetentie(int* vector, int nrDetinuti) {
		if (nrDetinuti > 0) {
			if(aniDetentie!=NULL)
				delete[]aniDetentie;
			this->aniDetentie = new int[nrDetinuti];
			for (int i = 0; i < nrDetinuti; i++) {
				aniDetentie[i] = vector[i];
			}
			this->nrDetinuti = nrDetinuti;
		}
	}

	int get_nrDetinuti() {
		return this->nrDetinuti;
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
		return this->nume;
	}

	void set_nume(char* valoare) {
		if (strlen(valoare) > 2) {
			if(nume!=NULL)
				delete[]nume;
			nume = new char[strlen(valoare) + 1];
			strcpy(nume, valoare);
		}
	}

};
void main() {
	//Inchisoare inc;
	//try {

	//	inc.set_nrDetinuti(-70);
	//}
	//catch (char* mesaj) {
	//	cout << mesaj << endl;
	//	inc.set_nrDetinuti(70);
	//}

	//cout << inc.get_nrDetinuti();

	//inc.set_nume("Popescu");
	//cout << inc.get_nume() << endl;


	//inc.set_aniDetentie(new int[3]{ 1, 5, 2 }, 3);

	//int* adresa;
	//adresa = inc.get_aniDetentie();
	//cout << adresa[1] << endl;

	//cout << inc.get_aniDetentie()[2];

	Inchisoare inc;
	int *ani = new int[3];
	ani[0] = 3;
	ani[1] = 2;
	ani[2] = 6;
	bool angajat[3];
	angajat[0] = true;
	angajat[1] = false;
	angajat[2] = true;

	Inchisoare inc2("Jilava",3,ani,1200,angajat);
	cout << inc.get_nume()<<endl;
	cout << inc2.get_nume()<<endl;

	Inchisoare inc3("FFFFF", 4);

	Inchisoare* IP;
	IP = new Inchisoare[4];

}