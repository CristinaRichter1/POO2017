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

	Zoo operator=(const Zoo &z) {
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
		for (int i = 0; i < z.nrSpecii; i++) {
			this->nrAnimaleSpecie[i] = z.nrAnimaleSpecie[i];
			this->carnivor[i] = z.carnivor[i];
		}
		return *this;
	}

	static float get_taxa() {
		return taxa_stat;
	}

	static void set_taxa(float taxa) {
		taxa_stat = taxa;
	}

	int get_cod() {
		return cod;
	}

	Zoo() :cod(nr_obiecte), nr_mese(3) {
		this->nume = new char[strlen("Zoo") + 1];
		strcpy(this->nume, "Zoo");
		this->nrSpecii = 0;
		this->pret = 0;
		this->nrAnimaleSpecie = NULL;
		this->carnivor = NULL;
		nr_obiecte++;
	}

	bool* get_carnivor()
	{
		return carnivor;
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

	Zoo(char* nume, int nrSpecii) :cod(nr_obiecte), nr_mese(3) {
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

	Zoo(const Zoo &z) :cod(nr_obiecte), nr_mese(z.nr_mese), pret(z.pret) {
		this->nume = new char[strlen(z.nume) + 1];
		strcpy(this->nume, z.nume);
		this->nrSpecii = z.nrSpecii;
		this->nrAnimaleSpecie = new int[z.nrSpecii];
		this->carnivor = new bool[z.nrSpecii];
		for (int i = 0; i < z.nrSpecii; i++) {
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

	Zoo operator+(Zoo z2) {
		Zoo z3 = *this;
		z3.nrSpecii = this->nrSpecii + z2.nrSpecii;
		z3.pret = (this->pret > z2.pret) ?
			this->pret : z2.pret;
		if (z3.nrAnimaleSpecie != NULL)
			delete[]z3.nrAnimaleSpecie;
		if (z3.carnivor)
			delete[]z3.carnivor;

		z3.nrAnimaleSpecie = new int[z3.nrSpecii];
		z3.carnivor = new bool[z3.nrSpecii];
		for (int i = 0; i < this->nrSpecii; i++) {
			z3.nrAnimaleSpecie[i] = this->nrAnimaleSpecie[i];
			z3.carnivor[i] = this->carnivor[i];
		}
		for (int i = this->nrSpecii; i < z3.nrSpecii; i++) {
			z3.nrAnimaleSpecie[i] = z2.nrAnimaleSpecie[i - this->nrSpecii];
			z3.carnivor[i] = z2.carnivor[i - this->nrSpecii];
		}

		/*for (int i = 0; i < z2.nrSpecii; i++) {
		z3.nrAnimaleSpecie[i + this->nrSpecii] = z2.nrAnimaleSpecie[i];
		z3.carnivor[i + this->nrSpecii] = z2.carnivor[i];
		}*/

		return z3;
	}

	Zoo operator+(float a) {
		Zoo z3 = *this;
		z3.pret = this->pret + a;
		return z3;
	}

	int nrAnimale() {
		int s = 0;
		for (int i = 0; i < this->nrSpecii; i++)
			s += this->nrAnimaleSpecie[i];
		return s;
	}

	bool operator==(Zoo z) {
		return this->nrAnimale() == z.nrAnimale();
	}

	explicit operator float() {
		return this->pret;
	}

	Zoo operator++() {
		this->pret += 5;
		return *this;
	}

	Zoo operator++(int) {
		Zoo temp = *this;
		this->pret += 5;
		return temp;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->nrSpecii) {
			return nrAnimaleSpecie[index];
		}
		else
			throw new exception("index out of bounds");
	}

	Zoo operator()(float adaugare) {
		Zoo z = *this;
		z.pret += adaugare;
		return z;
	}

	Zoo operator()() {
		Zoo z = *this;
		z.pret++;
		return z;
	}

	Zoo operator!() {
		Zoo z = *this;
		//conditie ? iftrue : ifFalse
		//z.pret = (z.pret > 0) ? 0 : 10;
		if (z.pret > 0)
			z.pret = 0;
		else
			z.pret = 10;

		return z;
	}

	friend Zoo operator+(float a, Zoo z);
	friend istream& operator >> (istream& ttttt, Zoo& z) {
		cout << "Numele:";
		char buffer[20];
		ttttt >> buffer;
		if (z.nume)
			delete[]z.nume;
		z.nume = new char[strlen(buffer) + 1];
		strcpy(z.nume, buffer);
		cout << "Pret";
		ttttt >> z.pret;
		cout << "Numar specii";
		ttttt >> z.nrSpecii;
		if (z.nrAnimaleSpecie)
			delete[]z.nrAnimaleSpecie;
		if (z.carnivor)
			delete[]z.carnivor;
		z.nrAnimaleSpecie = new int[z.nrSpecii];
		z.carnivor = new bool[z.nrSpecii];

		for (int i = 0; i < z.nrSpecii; i++) {
			cout << "Nr animale specie";
			ttttt >> z.nrAnimaleSpecie[i];
			cout << "Carnivor 1 - Da; 0 - NU";
			ttttt >> z.carnivor[i];
		}
		return ttttt;
	}
};
int Zoo::nr_obiecte = 1;
float Zoo::taxa_stat = 20;

Zoo operator+(float a, Zoo z) {
	Zoo z3 = z;
	z3.pret = z.pret + a;
	return z3;
}

ostream& operator<<(ostream& mmmmm, Zoo z) {
	mmmmm << z.get_cod() << endl;
	mmmmm << z.get_nume() << endl;
	mmmmm << z.get_nrSpecii() << endl;
	for (int i = 0; i < z.get_nrSpecii(); i++)
	{
		//mmmmm << z.get_nrAnimaleSpecie()[i]<<" ";
		mmmmm << z[i] << endl;
	}
	mmmmm << endl;
	return mmmmm;
}

class ZooSafari: public Zoo {
private:
	char* numeParcare;
	float taxaMasina;
public:
	float get_taxaMasina() {
		return taxaMasina;
	}
	void set_taxaMasina(float valoare) {
		if (valoare > 0) {
			taxaMasina = valoare;
		}
		else
			throw exception("valoare incorecta");
	}

	ZooSafari():Zoo() {
		taxaMasina = 0;
		numeParcare = new char[strlen("Necunoscut") + 1];
		strcpy(numeParcare, "Necunoscut");
	}

	ZooSafari(char* nume, float pret, int nrSpecii, 
		int* nrAnimaleSpecie, bool* carnivor, int nrMese, 
		float taxaMasina, char* numeParcare)
		:Zoo(nume,nrSpecii,pret,nrAnimaleSpecie,carnivor,
			nrMese) {
		this->taxaMasina = taxaMasina;
		this->numeParcare = new char[strlen(numeParcare) + 1];
		strcpy(this->numeParcare, numeParcare);
	}
	ZooSafari(const ZooSafari & zs):Zoo(zs) {
		this->taxaMasina = zs.taxaMasina;
		this->numeParcare = new char[strlen(zs.numeParcare) + 1];
		strcpy(this->numeParcare, zs.numeParcare);
	}

	~ZooSafari() {
		if (this->numeParcare)
			delete[]this->numeParcare;
	}

	ZooSafari operator=(const ZooSafari & zs) {
		Zoo::operator=(zs);
		if (this->numeParcare)
			delete[]this->numeParcare;
		this->taxaMasina = zs.taxaMasina;
		this->numeParcare = new char[strlen(zs.numeParcare) + 1];
		strcpy(this->numeParcare, zs.numeParcare);
		
		return *this;
	}

	ZooSafari operator+=(Zoo z) {
		int*auxAnimale = new int[this->get_nrSpecii()+z.get_nrSpecii()];
		bool* auxCarnivor = new bool[this->get_nrSpecii()+z.get_nrSpecii()];
		for (int i = 0; i < this->get_nrSpecii(); i++) {
			auxAnimale[i] = this->get_nrAnimaleSpecie()[i];
			auxCarnivor[i] = this->get_carnivor()[i];
		}
		for (int i = this->get_nrSpecii(); i < z.get_nrSpecii() + this->get_nrSpecii(); i++) {
			auxAnimale[i] = z.get_nrAnimaleSpecie()[i - this->get_nrSpecii()];
			auxCarnivor[i] = z.get_carnivor()[i - this->get_nrSpecii()];
		}

		this->set_nrAnimaleSpecie(auxAnimale, this->get_nrSpecii() + z.get_nrSpecii());
		//apel seter carnivor
		return *this;
	}

	friend ostream& operator<<(ostream& consola, ZooSafari zs)
	{
		consola << (Zoo)zs;
		consola << zs.taxaMasina << endl;
		consola << zs.numeParcare << endl;
		return consola;
	}
};

void main() {
	ZooSafari zs;
	cout << zs.get_nume();

	Zoo z;
	cout << z.get_nume();
	
	//zs += 10;
	zs += z;
}