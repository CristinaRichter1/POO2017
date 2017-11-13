#include<iostream>

using namespace std;


class Gradinita {
private:
	char* nume;
	int nrCopii;
	int * varste;
	float buget;
	bool cuPrgPrelungit;
	const int cod;
	const int nr_mese;
	static int nr_obiecte;
	static bool liber;
public:

	Gradinita operator=(const Gradinita &g) {
		if (nume != NULL)
			delete[]nume;
		this->nume = new char[strlen(g.nume) + 1];
		strcpy(this->nume, g.nume);
		this->nrCopii = g.nrCopii;
		if (varste)
			delete[]varste;
		this->varste = new int[g.nrCopii];
		for (int i = 0; i < g.nrCopii; i++) {
			this->varste[i] = g.varste[i];
		}
		this->buget = g.buget;
		this->cuPrgPrelungit = g.cuPrgPrelungit;
		return *this;
	}

	int get_cod() {
		return cod;
	}

	static bool get_liber() {
		return liber;
	}

	static void set_liber(bool _liber) {
		liber = _liber;
	}

	Gradinita() :cod(nr_obiecte), nr_mese(2) {
		this->nume = NULL;
		this->nrCopii = 0;
		this->varste = NULL;
		this->buget = 0;
		this->cuPrgPrelungit = false;
		nr_obiecte++;
	}

	Gradinita(char* nume, int nrCopii, int *varste,
		float buget, bool cuPrgPrelungit,
		int mese) :cod(nr_obiecte), nr_mese(mese)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrCopii = nrCopii;
		this->varste = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++)
		{
			this->varste[i] = varste[i];
		}
		this->buget = buget;
		this->cuPrgPrelungit = cuPrgPrelungit;
		nr_obiecte++;
	}

	Gradinita(char *nume, int nrCopii) :cod(nr_obiecte), nr_mese(2) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrCopii = nrCopii;
		this->varste = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++) {
			this->varste[i] = 0;
		}
		this->buget = 0;
		this->cuPrgPrelungit = false;
		nr_obiecte++;
	}

	Gradinita(Gradinita &g) :cod(nr_obiecte), nr_mese(g.nr_mese) {
		this->nume = new char[strlen(g.nume) + 1];
		strcpy(this->nume, g.nume);
		this->nrCopii = g.nrCopii;
		this->varste = new int[g.nrCopii];
		for (int i = 0; i < g.nrCopii; i++) {
			this->varste[i] = g.varste[i];
		}
		this->buget = g.buget;
		nr_obiecte++;
		this->cuPrgPrelungit = g.cuPrgPrelungit;
	}

	~Gradinita() {
		if (this->nume) {
			delete[]this->nume;
		}
		if (this->varste) {
			delete[]this->varste;
		}
	}

	int get_nrCopii() {
		return nrCopii;
	}

	void set_nrCopii(int nouaValoare) {
		if (nouaValoare > 0)
			nrCopii = nouaValoare;
		else
			throw "Valoare incorecta";
	}

	char* get_nume()
	{
		return nume;
	}
	void set_nume(char* noulNume) {
		if (strlen(noulNume) > 1)
		{
			if (nume != NULL)
			{
				delete[]nume;
			}
			nume = new char[strlen(noulNume) + 1];
			strcpy(nume, noulNume);
		}
	}

	int* get_varste() {
		return varste;
	}

	void set_varste(int* vector, int nrCopii) {
		if (varste)
			delete[]varste;
		varste = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++)
		{
			this->varste[i] = vector[i];
		}
		this->nrCopii = nrCopii;
	}

	Gradinita operator+(Gradinita g2) {
		Gradinita g3 = *this;
		g3.nrCopii = this->nrCopii + g2.nrCopii;
		if (g3.varste != NULL)
			delete[]g3.varste;
		g3.varste = new int[g3.nrCopii];
		for (int i = 0; i < this->nrCopii; i++)
			g3.varste[i] = this->varste[i];
		for (int i = this->nrCopii; i < g3.nrCopii; i++) 
		{
			g3.varste[i] = g2.varste[i - this->nrCopii];
		}
		g3.buget = this->buget + g2.buget;
		return g3;
	}


	Gradinita operator+(int a) {
		Gradinita g = *this;
		g.buget = this->buget + a;
		return g;
	}

	bool operator==(Gradinita g) {
		return strcmp(this->nume, g.nume) == 0 ? true : false;
	}

	operator int() { //operator int(Gradinita *this)
		return this->nrCopii;
	}

	friend Gradinita operator+(int a, Gradinita g1);
};
int Gradinita::nr_obiecte = 1;
bool Gradinita::liber = false;

Gradinita operator+(int a, Gradinita g1) {
	Gradinita g = g1;
	g.buget = a + g1.buget;
	return g;
}


void main() {
	Gradinita g1;
	Gradinita g2;

	Gradinita g3;
	g3 = g1 + g2;//g1.operator+(g2)

	int a = 500;

	g3 = g1 + a;
	g3 = a + g1;

	if (g1 == g3)
		cout << "egale";
	

	float f = 9.6;
	int fi = f;

	fi = g1;// g1.operator int(); // operator int(&g1);

	/*g3 = ++g1;
	g3 = g1++;*/
}