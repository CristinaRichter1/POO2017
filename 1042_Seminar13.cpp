#include<iostream>
#include<string>

using namespace std;

class Fiinta {
public:
	virtual float get_venit()=0;
};


class Persoana:public Fiinta {
private:
	char* nume;
	int varsta;
	float venit;
public:
	Persoana() {
		this->nume = new char[strlen("Popescu") + 1];
		strcpy(this->nume, "Popescu");
		this->varsta = 17;
		this->venit = 200;
	}
	Persoana(char* nume, int varsta, float venit) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->venit = venit;
	}
	Persoana(const Persoana& p) {
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->varsta = p.varsta;
		this->venit = p.venit;
	}
	~Persoana() {
		if (this->nume)
			delete[]this->nume;
	}
	Persoana operator=(const Persoana& p) {
		if (this->nume)
			delete[]this->nume;
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->varsta = p.varsta;
		this->venit = p.venit;
		return *this;
	}

	float get_venit() {
		return venit;
	}

	friend ostream& operator<<(ostream& consola, Persoana p) {
		consola << p.nume << " " << p.varsta << " " << p.venit << endl;
		return consola;
	}
};

class Adult :public Persoana {
private:
	float salariu;
	bool studiiSuperioare;
public:
	Adult() :Persoana("Popescu",18,200) {
		salariu = 2000;
		studiiSuperioare = true;
	}
	Adult(char*nume, int varsta, float venit, float salariu, bool studiiSuperioare) 
		:Persoana(nume, varsta, venit) {
		this->salariu = salariu;
		this->studiiSuperioare = studiiSuperioare;
	}
	float get_venit() {
		return salariu;
	}

	friend ostream&operator<<(ostream&monitor, Adult a) {
		monitor << (Persoana)a << a.salariu << " " << a.studiiSuperioare << endl;
		return monitor;
	}
};

class Profesor :public Adult {
private:
	string functie;
	int sporVechime;
public:
	Profesor() :Adult("Popescu",26,200,2000,true) {
		functie = "Conferentiar";
		sporVechime = 20;
	}
	Profesor(char* nume, int varsta, float venit, float salariu, bool studiiSuperioare, 
		string functie, int spor) 
		:Adult(nume, varsta, venit, salariu, studiiSuperioare) 
	{
		this->functie = functie;
		this->sporVechime = spor;
	}
	float get_venit() {
		return Adult::get_venit() + (sporVechime/100)*Adult::get_venit();
	}
	string get_functie() {
		return functie;
	}
	friend ostream&operator<<(ostream& out, Profesor p) {
		out << (Adult)p << p.functie << " " << p.sporVechime << endl;
		return out;
	}
};

void main() {
	Persoana *p = new Persoana();
	Adult *a = new Adult();
	Profesor*prof = new Profesor();

	p = a;

	cout << typeid(*p).name() << endl;

	a = prof;

	cout << typeid(*a).name() << endl;

	Adult *a2 = new Adult();

	//Profesor *prof2 = (Profesor*)a2;
	//cout << *prof2;
	Profesor* prof2 = dynamic_cast<Profesor*>(a2);
	if (prof2) {
		cout << prof2;
	}
	else
		cout << "Cast inposibil"<<endl;

	Fiinta* f = new Adult();
}