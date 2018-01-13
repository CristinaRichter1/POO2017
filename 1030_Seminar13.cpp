#include<iostream>
#include<string>

using namespace std;

class Fiinta {
	virtual int get_varsta() = 0;
};

class Persoana:public Fiinta {
private:
	char* nume;
	int varsta;
	char gen;
public:
	Persoana() {
		this->nume = new char[strlen("Popescu") + 1];
		strcpy(this->nume, "Popescu");
		this->varsta = 16;
		gen = 'M';
	}
	Persoana(char*nume, int varsta, char gen) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->gen = gen;
	}
	~Persoana() {
		if (this->nume)
			delete[]this->nume;
	}
	Persoana(const Persoana&p) {
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->varsta = p.varsta;
		this->gen = p.gen;
	}

	Persoana operator=(const Persoana& p) {
		if (this->nume)
			delete[]this->nume;
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->varsta = p.varsta;
		this->gen = p.gen;
		return *this;
	}

	int get_varsta() {
		return varsta;
	}

	friend ostream& operator<<(ostream& out, Persoana p) {
		out << p.nume << " " << p.varsta << " " << p.gen << endl;
		return out;
	}
};

class Angajat :public Persoana {
private:
	string functie;
	float salariu;
public:
	Angajat() :Persoana("Popescu",18,'M') {
		functie = "Portar";
		salariu = 2000;
	}
	Angajat(char*nume, int varsta, char gen, string functie, 
		float salariu) 
		:Persoana(nume, varsta, gen) 
	{
		this->functie = functie;
		this->salariu = salariu;
	}

	virtual int get_varsta() {
		return Persoana::get_varsta();
	}

	friend ostream& operator<<(ostream& monitor, Angajat a) {
		monitor << (Persoana)a << a.functie << " " << a.salariu << endl;
		return monitor;
	}
};

class Profesor :public Angajat {
private:
	bool doctor;
	int nr_carti;
public:
	Profesor() :Angajat("Popescu", 28, 'F', "Lector", 2000) {
		doctor = true;
		nr_carti = 20;
	}
	Profesor(char* nume, int varsta, char gen, string functie, 
		float salariu, bool doctor, int nr_carti) 
		:Angajat(nume, varsta, gen, functie, salariu) 
	{
		this->doctor = doctor;
		this->nr_carti = nr_carti;
	}

	Profesor(Angajat a, bool doctor, int nr_carti) 
		:Angajat(a) 
	{
		this->doctor = doctor;
		this->nr_carti = nr_carti;
	}

	int get_varsta() {
		return Angajat::get_varsta();
	}
	int get_nrCarti() {
		return nr_carti;
	}

	friend ostream& operator<<(ostream& consola, Profesor p) {
		consola << (Angajat)p << p.doctor << " " << p.nr_carti<<endl;
		return consola;
	}
};

void main() {
	Persoana* p = new Persoana("Ionescu",34,'F');
	Angajat * a = new Angajat();
	Profesor* prof = new Profesor();

	p = a;

	cout<<typeid(*p).name()<<endl;

	a = prof;
	cout << typeid(*a).name() << endl;

	//p = prof;
	//cout << typeid(*p).name() << endl;

	//Fiinta *f=new Persoana();

	Angajat *a2 = new Angajat();

	Profesor *prof2 = (Profesor*)a2;
	Profesor *prof3 = dynamic_cast<Profesor*>(a2);
	if (prof3 != NULL)
	{
		cout << prof3;
	}
	else
	{
		cout << "Conversie nereusita";
	}
	//cout << *prof2;

}