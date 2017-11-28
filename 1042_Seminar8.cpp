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
		if (a3.aniDetentie != NULL)
			delete[]a3.aniDetentie;
		a3.aniDetentie = new int[a3.nrDetinuti];
		if (a3.angajat)
			delete[]a3.angajat;
		a3.angajat = new bool[a3.nrDetinuti];
		for (int i = 0; i < this->nrDetinuti; i++) {
			a3.aniDetentie[i] = this->aniDetentie[i];
			a3.angajat[i] = this->angajat[i];
		}
		for (int i = this->nrDetinuti; i < a3.nrDetinuti; i++) {
			a3.aniDetentie[i] = a2.aniDetentie[i - this->nrDetinuti];
		}
		for (int i = 0; i < a2.nrDetinuti; i++) {
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

	explicit operator float()
	{
		return buget;
	}
	explicit operator int() {
		return nrDetinuti;
	}

	int& operator[](int index) {
		if (index >= 0 && index < nrDetinuti)
			return aniDetentie[index];
		else
			throw exception("Index out of bounds");
	}

	Inchisoare operator()(float bonus) {
		Inchisoare f = *this;
		f.buget += bonus;
		return f;
	}

	Inchisoare operator()() {
		Inchisoare f = *this;
		f.nrDetinuti++;
		if (f.aniDetentie)
			delete[]f.aniDetentie;
		if (f.angajat)
			delete[]f.angajat;

		f.aniDetentie = new int[f.nrDetinuti];
		f.angajat = new bool[f.nrDetinuti];

		for (int i = 0; i < this->nrDetinuti; i++) {
			f.aniDetentie[i] = this->aniDetentie[i];
			f.angajat[i] = this->angajat[i];
		}
		f.aniDetentie[this->nrDetinuti] = 1;
		f.angajat[this->nrDetinuti] = true;
		return f;
	}

	Inchisoare operator!() {
		Inchisoare inc = *this;
		for (int i = 0; i < inc.nrDetinuti; i++) {
			inc.angajat[i] = !inc.angajat[i];
		}

		return inc;
	}

	friend Inchisoare operator+(float valoare, Inchisoare a1);
	friend istream& operator >> (istream& tttttt, Inchisoare& inc) {
		char buffer[20];
		cout << "Nume";
		tttttt >> buffer;

		if (inc.nume)
			delete[]inc.nume;
		inc.nume = new char[strlen(buffer) + 1];
		strcpy(inc.nume, buffer);

		cout << "Numar detinuti";
		tttttt >> inc.nrDetinuti;
		if (inc.aniDetentie)
			delete[]inc.aniDetentie;
		if (inc.angajat)
			delete[]inc.angajat;
		inc.aniDetentie = new int[inc.nrDetinuti];
		inc.angajat = new bool[inc.nrDetinuti];
		for (int i = 0; i < inc.nrDetinuti; i++) {
			cout << "ani detentie:";
			tttttt >> inc.aniDetentie[i];
			cout << "Angajat Da-1 NU - 0";
			tttttt >> inc.angajat[i];
		}
		cout << "buget";
		tttttt >> inc.buget;

		return tttttt;
	}
};
// :: Operator de rezolutie
int Inchisoare::nrObiecte = 1;
float Inchisoare::subventieStat = 200;


ostream& operator<<(ostream& mmmmmm, Inchisoare inc) {
	mmmmmm << inc.getid() << endl;
	mmmmmm << inc.getNume() << endl;
	mmmmmm << inc.getnrDetinuti() << endl;
	for (int i = 0; i < inc.getnrDetinuti(); i++) {
		mmmmmm << inc.getaniDetentie()[i] << " ";
		mmmmmm << inc[i] << " ";
	}

	return mmmmmm;
}

Inchisoare operator+(float valoare, Inchisoare a1) {
	Inchisoare iNoua = a1;
	iNoua.buget = a1.buget + valoare;
	return iNoua;
}

class InchisoareSigura : public Inchisoare {
private:
	int gradSecuritate;
	char* numeDirector;
public:
	InchisoareSigura():Inchisoare() {
		gradSecuritate = 4;
		numeDirector = new char[strlen("Popescu") + 1];
		strcpy(numeDirector, "Popescu");
	}
	InchisoareSigura(char* nume, float buget, int nrDetinuti, 
		int* aniDetentie, bool* angajat, int nrCelule, char* numeDirector,
		int gradSecuritate) : Inchisoare(nume,nrDetinuti,aniDetentie,buget,angajat,nrCelule) {
		this->gradSecuritate = gradSecuritate;
		this->numeDirector = new char[strlen(numeDirector) + 1];
		strcpy(this->numeDirector, numeDirector);
	}

	InchisoareSigura(const InchisoareSigura& is):Inchisoare(is) {
		this->gradSecuritate = is.gradSecuritate;
		this->numeDirector = new char[strlen(is.numeDirector) + 1];
		strcpy(this->numeDirector, is.numeDirector);
	}

	~InchisoareSigura() {
		if (numeDirector)
			delete[]numeDirector;
	}

	InchisoareSigura operator=(const InchisoareSigura& is) {
		Inchisoare::operator=(is);
		if (this->numeDirector)
			delete[]this->numeDirector;
		this->numeDirector = new char[strlen(is.numeDirector) + 1];
		strcpy(this->numeDirector, is.numeDirector);
		this->gradSecuritate = is.gradSecuritate;
		return *this;
	}

	int get_gradSecuritate() {
		return gradSecuritate;
	}

	void set_gradSecuritate(int valoare) {
		if (valoare > 0) {
			gradSecuritate = valoare;
		}
		else
			throw exception("Valoare incorecta");
	}

	operator char*() {
		return numeDirector;
	}

	InchisoareSigura operator++() {
		this->gradSecuritate++;
		return *this;
	}

	InchisoareSigura operator++(int) {
		InchisoareSigura aux = *this;
		this->gradSecuritate++;
		return aux;
	}

	InchisoareSigura operator+(Inchisoare inc) {
		InchisoareSigura temp = *this;
		int*vAni = new int[temp.getnrDetinuti() + inc.getnrDetinuti()];
		bool* vAngajat = new bool[temp.getnrDetinuti() + inc.getnrDetinuti()];
		for (int i = 0;temp.getnrDetinuti();i++) {
			vAni[i] = temp.getaniDetentie()[i];
		}
		for (int i = temp.getnrDetinuti();i < temp.getnrDetinuti() + inc.getnrDetinuti();i++) {
			vAni[i] = inc.getaniDetentie()[i - temp.getnrDetinuti()];
		}
		temp.set_aniDetentie(vAni, temp.getnrDetinuti() + inc.getnrDetinuti());

		return temp;
	}

	friend ostream& operator<<(ostream& consola, InchisoareSigura is) {

		consola << (Inchisoare)is;
		consola << is.numeDirector << endl;
		consola << is.gradSecuritate << endl;
		return consola;
	}
};

void main()
{
	InchisoareSigura is;
	cout << is.getNume();
	
	char* sa = new char[strlen((char*)is) + 1];
	strcpy(sa, is);

	Inchisoare i;
	cout << i.getNume();

	InchisoareSigura is2 = is + i;

}