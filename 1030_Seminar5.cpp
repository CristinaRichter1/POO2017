#include<iostream>

using namespace std;


class Restaurant {
private:
	char* nume;
	int nrMeniuri;
	float* preturi;
	bool deschis;
	const int id;
	const int CUI;
	static int nrObiecte;
	static int taxaProfit;

public:


	const int get_id()//getter pt constant
	{
		return id;
	}


	int get_taxaProfit()//getter pt static
	{
		return taxaProfit;
	}


	void set_taxaProfit(int taxa)
	{
		taxaProfit = taxa;
	}


	~Restaurant() {
		if (nume != NULL)
			delete[] nume;
		if (preturi)
			delete[] preturi;
	}

	Restaurant(char* nume, int nrMeniuri) :id(nrObiecte), CUI(1234)
	{

		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrMeniuri = nrMeniuri;
		this->preturi = new float[nrMeniuri];
		for (int i = 0; i < nrMeniuri; i++)
			this->preturi[i] = 0;
		deschis = false;
		nrObiecte++;
	}

	Restaurant() :id(nrObiecte), CUI(1234) //initializam atributele care sunt constante in semnatura functiei; se initializeaza cu : numele atributului si in paranteza valoarea pe care vrem sa i o dam
	{

		this->nume = new char[strlen("Shorley") + 1];
		strcpy(this->nume, "Shorley");
		this->nrMeniuri = 0;
		this->preturi = NULL;
		this->deschis = false;
		nrObiecte++;
	}

	Restaurant(char*nume, int nrMeniuri, float* preturi, bool deschis, int noulCUI) :id(nrObiecte), CUI(noulCUI)
	{

		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrMeniuri = nrMeniuri;
		this->preturi = new float[nrMeniuri];
		for (int i = 0; i<nrMeniuri; i++) {
			this->preturi[i] = preturi[i];
		}
		this->deschis = deschis;
		nrObiecte++;
	}

	Restaurant(Restaurant& r) :id(nrObiecte), CUI(r.CUI) //un constructor de copiere facut dupa cel cu parametri
	{
		this->nume = new char[strlen(r.nume) + 1];
		strcpy(this->nume, r.nume);
		this->nrMeniuri = r.nrMeniuri;
		this->preturi = new float[r.nrMeniuri];
		for (int i = 0; i < r.nrMeniuri; i++)

			this->preturi[i] = r.preturi[i];
		this->deschis = r.deschis;
		nrObiecte++;


	}

	Restaurant operator=(const Restaurant& r) //ii dam constant ca sa nu modifice
	{
		if (nume)
			delete[] nume;
		if (preturi)
			delete[] preturi;
		this->nume = new char[strlen(r.nume) + 1];
		strcpy(this->nume, r.nume);
		this->nrMeniuri = r.nrMeniuri;
		this->preturi = new float[r.nrMeniuri];
		for (int i = 0; i < r.nrMeniuri; i++)

			this->preturi[i] = r.preturi[i];
		this->deschis = r.deschis;
		return *this;
	}

	int get_nrMeniuri() {
		return nrMeniuri;
	}

	void set_nrMeniuri(int nr) {
		if (nr > 1)
		{
			nrMeniuri = nr;
		}
		else
		{
			throw "Valoarea este incorecta";

		}
	}

	char* get_nume() {
		return nume;
	}
	void set_nume(char* valoare) {
		if (strlen(valoare) > 3) {
			if (nume != NULL)
				delete[]nume;
			nume = new char[strlen(valoare) + 1];
			strcpy(nume, valoare);
		}
	}

	float*get_preturi() {
		return preturi;
	}

	void set_preturi(float* vector, int _nrMeniuri) {
		if (nrMeniuri > 1) {
			if (preturi)
				delete[]preturi;
			preturi = new float[nrMeniuri];
			for (int i = 0; i < nrMeniuri; i++) {
				preturi[i] = vector[i];
			}
			nrMeniuri = _nrMeniuri;
		}
	}
};
//initializarea staticului se face in afara clasei
int Restaurant::nrObiecte = 1;
int Restaurant::taxaProfit = 16;


void main() {
	Restaurant r1;

	Restaurant r2;

	cout << r1.get_id() << " " << r2.get_id() << endl;

	cout << r1.get_taxaProfit() << " " << r2.get_taxaProfit() << endl;
	r1.set_taxaProfit(20); //apare 20 si la r1 si la r2 pt ca taxaProfit e static, e acelasi pt toate obiectele
	cout << r1.get_taxaProfit() << " " << r2.get_taxaProfit() << endl;

	Restaurant r3("Restaurant", 6);
	Restaurant r4 = r3; //se apeleaza constructor de copiere; 

	Restaurant r5;
	r5 = r3;

	//pt constante nu avem nevoie de setteri pt ca sunt constante, de getteri putem avea nevoie;
	//pt statice putem aveam si getteri si setteri
	//destructorul se apeleaza automat la sfarsitul clasei
}