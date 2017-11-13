#include<iostream>
using namespace std;

class Inchisoare
{
private:
	char*nume;
	int nrDetinuti;
	int *aniDetentie;
	float buget;
	bool *angajat;
	// Atribut constant= caruia nu i se poate modifica valoarea; Atributul constant nu isi modifica valoarea si poate fi initializat o singura data, la crearea obiectului, in constructori. 
	// NU se fac setteri pentru atributele constante

	// Atribut static= Nu aparatine obiectului ci clasei; Atributul static va avea aceeasi valoare pt toate obiectele din acea clasa. Se initializeaza in afara clasei
	const int id;
	static int nrObiecte;
	const int nrCelule;
	static float subventieStat;

public:

	//Constructorii sunt metode speciale. Nu au tip returnat (nici macar void). Numele constructorilor este identic cu cel al clasei;
	// Au rol sa aloce memorie pentru atributele alocate dinamic si sa initializeze toate atributele.
	// Exista 2 tipuri: implicit (cel pus de compilator) , explicit(pe care il pune programatorul); Constructori expliciti: cu parametru, fara parametru, de copiere;
	//Cand programatorul scrie un constructor explicit, cel implicit nu mai exista;


	//Constructor fara parametru
	//constantele oblicatorii in antentul constructorilor
	Inchisoare() :id(nrObiecte), nrCelule(100)
	{
		nrObiecte++;
		this->nume = new char[strlen("Alcatraz") + 1];
		strcpy(this->nume, "Alcatraz");
		this->nrDetinuti = 0;
		this->aniDetentie = NULL;
		this->buget = 0;
		this->angajat = angajat = NULL;
	}

	//Constructor cu parametru
	//Polimorfism= mai multe functii cu acelasi nume si acelasi tip returnat care se diferentiaza prin nr de parametri si tipul lor si are functionalitate diferita
	Inchisoare(char *nume, int nrDetinuti, int *aniDetentie, float buget, bool *angajat, int celule) :id(nrObiecte), nrCelule(celule)
	{
		nrObiecte++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrDetinuti = nrDetinuti;
		this->aniDetentie = new int[nrDetinuti];
		this->buget = buget;
		this->angajat = new bool[nrDetinuti];
		for (int i = 0; i < nrDetinuti; i++)
		{
			this->aniDetentie[i] = aniDetentie[i];
			this->angajat[i] = angajat[i];
		}
	}
	Inchisoare(char *nume, int nrDetinuti) : id(nrObiecte), nrCelule(100)
	{
		nrObiecte++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrDetinuti = nrDetinuti;
		this->aniDetentie = new int[nrDetinuti];
		this->buget = 0;
		this->angajat = new bool[nrDetinuti];
		for (int i = 1; i < nrDetinuti; i++)
		{
			this->aniDetentie[i] = 0;
			this->angajat[i] = false;
		}
	}

	//CONSTRUCTORUL DE COPIERE
	Inchisoare(const Inchisoare&inc) : id(nrObiecte), nrCelule(inc.nrCelule)
	{
		nrObiecte++;
		this->nume = new char[strlen(inc.nume) + 1];
		strcpy(this->nume, inc.nume);
		this->aniDetentie = new int[inc.nrDetinuti];
		this->angajat = new bool[inc.nrDetinuti];
		for (int i = 0; i < inc.nrDetinuti; i++)
		{
			this->aniDetentie[i] = inc.aniDetentie[i];
			this->angajat[i] = inc.angajat[i];
		}
		this->buget = inc.buget;
		this->nrDetinuti = inc.nrDetinuti;

	}

	//Operatorii sunt functii, nume operator urmat de semn. Are acelasi corp ca cel al constructorului de copiere, dar trebuie sa dezalocam spatiul alocat dinamic
	//OPERATORUL EGAL
	Inchisoare operator=(const Inchisoare &inc)
	{
		if (nume)
			delete[] nume;
		if (aniDetentie)
			delete[] this->aniDetentie;
		if (angajat)
			delete[] this->angajat;

		this->nume = new char[strlen(inc.nume) + 1];
		strcpy(this->nume, inc.nume);
		this->aniDetentie = new int[inc.nrDetinuti];
		this->angajat = new bool[inc.nrDetinuti];
		for (int i = 0; i < inc.nrDetinuti; i++)
		{
			this->aniDetentie[i] = inc.aniDetentie[i];
			this->angajat[i] = inc.angajat[i];
		}
		this->buget = inc.buget;
		this->nrDetinuti = inc.nrDetinuti;
		return *this;
	}
	int getid()
	{
		return id;
	}
	// static in fata functiei pentru a face intreaga functie statica
	static float getsubcentieStat()
	{
		return subventieStat;
	}
	static void setsubventieStat(float subventie)
	{
		subventieStat = subventie;
	}
	int getnrDetinuti()
	{
		return this->nrDetinuti;
	}
	void setnrDetinuti(int valoareNoua)
	{
		if (valoareNoua > 1)
		{
			nrDetinuti = valoareNoua;
		}
		else
			throw "Valoare incorecta";

	}
	char *getNume()
	{
		return this->nume;
	}
	void setNume(char *valoare)
	{
		if (strlen(valoare) > 2)
		{
			if (nume != NULL)
				delete[] nume;
			nume = new char[strlen(valoare) + 1];
			strcpy(nume, valoare);
		}
	}
	int *getaniDetentie()
	{
		return aniDetentie;
	}
	void set_aniDetentie(int *vector, int nrDetinuti)
	{
		if (nrDetinuti > 0)
		{
			if (aniDetentie != NULL)
				delete[]aniDetentie;
			aniDetentie = new int[nrDetinuti];
			for (int i = 0; i < nrDetinuti; i++)
			{
				aniDetentie[i] = vector[i];
			}
			this->nrDetinuti = nrDetinuti;
		}
	}

	//Destroctoul este unic, fara parametrii, dezaloca memoria alocata dinamic
	~Inchisoare()
	{
		if (nume != NULL)
			delete[] nume;
		if (aniDetentie)
			delete[] aniDetentie;
		if (angajat)
			delete[] angajat;
	}

	Inchisoare operator+(Inchisoare a2) {//operator+(Inchisoare* this,Inchisoare a2)
		Inchisoare a3 = *this;
		a3.buget = this->buget + a2.buget;
		a3.nrDetinuti = this->nrDetinuti + a2.nrDetinuti;
		if(a3.aniDetentie !=NULL)
			delete[]a3.aniDetentie;
		a3.aniDetentie = new int[a3.nrDetinuti];
		if (a3.angajat)
			delete[]a3.angajat;
		a3.angajat = new bool[a3.nrDetinuti];
		for (int i = 0;i < this->nrDetinuti;i++) {
			a3.aniDetentie[i] = this->aniDetentie[i];
			a3.angajat[i] = this->angajat[i];
		}
		for (int i = this->nrDetinuti;i < a3.nrDetinuti;i++) {
			a3.aniDetentie[i] = a2.aniDetentie[i - this->nrDetinuti];
		}
		for (int i = 0;i < a2.nrDetinuti;i++) {
			a3.angajat[i + this->nrDetinuti] = a2.angajat[i];
		}
		return a3;
	}

	Inchisoare operator+(float valoare) {
		Inchisoare inc = *this;
		inc.buget = this->buget + valoare;
		return inc;
	}

	Inchisoare operator+=(Inchisoare a) {
		this->buget += a.buget;
		return *this;
	}

	bool operator==(Inchisoare a) {
		return this->nrDetinuti == a.nrDetinuti;
	}

	Inchisoare operator++() {
		this->buget++;
		return *this;
	}
	Inchisoare operator++(int) {
		Inchisoare aux = *this;
		this->buget++;
		return aux;
	}

	operator float()
	{
		return buget;
	}
	operator int() {
		return nrDetinuti;
	}

	friend Inchisoare operator+(float valoare, Inchisoare a1);

};
// :: Operator de rezolutie
int Inchisoare::nrObiecte = 1;
float Inchisoare::subventieStat = 200;



Inchisoare operator+(float valoare, Inchisoare a1) {
	Inchisoare iNoua = a1;
	iNoua.buget = a1.buget + valoare;
	return iNoua;
}



void main()
{

	Inchisoare a1;
	Inchisoare a2;
	a1 = a2;
	Inchisoare a3;
	a3 = a1 + a2;

	int a=6;
	int b;
	int c = a + b;
	float d=8.2;
	float c2 = a + d;

	//a1.buget=300;
	Inchisoare a4 = a1 + 500.0;

	Inchisoare a5 = 500.0 + a1;

	a5 += a1;

	if (a1 == a2)
		cout << "egale";

	a1 = ++a2;
	a3 = a4++;

	int z = 6;
	float y = 9.7;
	z = y;
	y = a1;
	z = a1;


}


