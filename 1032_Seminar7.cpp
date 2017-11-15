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

	//operator int() { //operator int(Gradinita *this)
	//	return this->nrCopii;
	//}

	explicit operator  float() {
		return buget / nrCopii;
	}

	Gradinita operator++() {
		this->buget *= 2;
		return *this;
	}

	Gradinita operator++(int) {
		Gradinita aux = *this;
		this->buget *= 2;
		return aux;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->nrCopii) {
			return varste[index];
		}
		else
		{
			throw new exception("Index out of bounds");
		}
	}

	Gradinita operator()(float suma) {
		Gradinita g = *this;
		g.buget += suma;
		return g;
	}
	Gradinita operator()() {
		Gradinita g = *this;
		g.buget *= 2;
		return g;
	}

	Gradinita operator!() {
		Gradinita g = *this;
		g.cuPrgPrelungit = !g.cuPrgPrelungit;
		return g;
	}

	friend Gradinita operator+(int a, Gradinita g1);
	friend istream& operator >> (istream& ttttt, Gradinita& g)
	{
		cout << "NUmele:";
		char buffer[20];
		ttttt >> buffer;
		if (strlen(buffer)>0) {
			if (g.nume)
				delete[]g.nume;
			g.nume = new char[strlen(buffer) + 1];
			strcpy(g.nume, buffer);
		}
		cout << "Numar copii:";
		ttttt >> g.nrCopii;
		if (g.varste)
			delete[]g.varste;
		g.varste = new int[g.nrCopii];
		for (int i = 0; i < g.nrCopii; i++) 
		{
			cout << "Varsta copilului " << (i + 1) << ":";
			ttttt >> g.varste[i];
		}
		cout << "Buget:";
		ttttt >> g.buget;
		return ttttt;
	}
};
int Gradinita::nr_obiecte = 1;
bool Gradinita::liber = false;

Gradinita operator+(int a, Gradinita g1) {
	Gradinita g = g1;
	g.buget = a + g1.buget;
	return g;
}

ostream& operator<<(ostream& mmmmm, Gradinita g) {
	mmmmm << g.get_cod() << endl;
	mmmmm << g.get_nume() << endl;
	mmmmm << g.get_nrCopii() << endl;
	for (int i = 0; i < g.get_nrCopii(); i++)
	{
		//mmmmm << g.get_varste()[i] << " ";
		mmmmm << g[i]<<" ";
	}

	mmmmm << endl;
	return mmmmm;
}




void main() {

	float z = 4.5;
	int a = z;
	Gradinita g1("Piticot", 2, new int[2]{ 5,6 },1000,true,9);
	//a = g;
	z = (float)g1;
	Gradinita g2;

	//g1 = g2++;

	//g1 = ++g2;

	cout << g1<<endl;
	cin >> g1;
	cout << g1;
	//g1 << cout;

	g1[0] = 6;
	//5 = 6;
	try {
		Gradinita g3 = g1(1000);
		Gradinita g4 = g1();
		Gradinita g5 = !g1;
	}
	catch (char* mesaj) {

	}
	catch (exception ex)
	{

	}
}