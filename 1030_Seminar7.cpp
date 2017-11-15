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
		if (_nrMeniuri > 1) {
			if (preturi)
				delete[]preturi;
			preturi = new float[_nrMeniuri];
			for (int i = 0; i < _nrMeniuri; i++) {
				preturi[i] = vector[i];
			}
			nrMeniuri = _nrMeniuri;
		}
	}

	float& operator[](int index) {
		if (index >= 0 && index < nrMeniuri)
			return preturi[index];
		else
			throw new exception("Index out of bounds");
	}

	float sumaPreturi() {
		float s = 0;
		for (int i = 0;i < this->nrMeniuri;i++)
			s += this->preturi[i];
		return s;
	}

	float operator()(int nr) {
		return nr*sumaPreturi();
	}
	float operator()() {
		return sumaPreturi();
	}

	Restaurant operator!() {
		Restaurant r = *this;
		r.deschis = !this->deschis;
		return r;
	}

	friend istream& operator >> (istream& tttt, Restaurant& r) 
	{
		char buffer[20];
		cout << "Numele:";
		tttt >> buffer;
		if (r.nume)
			delete[]r.nume;
		r.nume = new char[strlen(buffer) + 1];
		strcpy(r.nume, buffer);
		cout << "Numar meniuri:";
		tttt >> r.nrMeniuri;
		cout << "Preturi:";
		if (r.preturi)
			delete[]r.preturi;
		r.preturi = new float[r.nrMeniuri];
		for (int i = 0;i < r.nrMeniuri;i++) {
			tttt >> r.preturi[i];
		}
		cout << "Este deschis? Da-1; Nu-0 ";
		tttt >> r.deschis;
		return tttt;
	};
};
//initializarea staticului se face in afara clasei
int Restaurant::nrObiecte = 1;
int Restaurant::taxaProfit = 16;


ostream& operator<<(ostream& monitor, Restaurant r) {
	monitor << r.get_id();
	monitor << r.get_nume()<<endl;
	monitor << r.get_nrMeniuri()<<endl;
	for (int i = 0;i < r.get_nrMeniuri();i++) {
		//monitor << r.get_preturi()[i] << " ";
		monitor << r[i] << " ";
	}

	monitor << endl<<endl;
	return monitor;
}

class LantRestaurante {
private:
	int nrRestaurante;
	Restaurant* restaurante;

};


void main() {
	cout << "Test";

	Restaurant r;
	r.set_preturi(new float[3]{ 45,52,68 }, 3);

	cin >> r;
	r[0] = 100;
	cout << r << endl;
	try {
		for (int i = 0;i < r.get_nrMeniuri();i++) {
			cout << r[i]<<" ";
		}
	}
	catch (exception ex) {
		cout << ex.what();
	}

	cout << endl;
	//cout << r.getProfet(3);
	cout << r(3) << endl;
	cout << r();

	Restaurant r2 = !r;

}

