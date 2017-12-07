#include<iostream>

using namespace std;

class Persoana {
private:
	int varsta;
public:
	virtual float getVenit() = 0;
	virtual float get_Salariu() = 0;
	Persoana() :varsta(24) {

	}
	Persoana(int varsta) {
		this->varsta = varsta;
	}
};

class Angajat: public Persoana {

private:
	char* nume;
	float salariu;
public:
	float getSalariu() {
		return salariu;
	}
	float get_Salariu() {
		return salariu;
	}
	char* get_nume() {
		return nume;
	}
	Angajat() :salariu(2000) {
		nume = new char[strlen("Popescu") + 1];
		strcpy(nume, "Popescu");
	}
	Angajat(char *nume, float valoare) :salariu(valoare) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	~Angajat() {
		if (nume)
			delete[]nume;
	}
	Angajat(const Angajat& a) {
		this->salariu = a.salariu;
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
	}
	Angajat operator=(const Angajat& a) {
		this->salariu = a.salariu;
		if (nume)
			delete[]nume;
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		return *this;
	}

	virtual float getVenit() {
		return salariu;
	}
};

class Director : public Angajat {
private:
	float sporConducere;
public:
	Director() :Angajat(), sporConducere(20) {

	}

	Director(char*nume, float salariu, float spor) 
		:Angajat(nume, salariu), sporConducere(spor) {

	}

	float getVenit() {
		return getSalariu() + (getSalariu()*sporConducere / 100);
	}


};

class Student : public Persoana {
private:
	float bursa;
public:
	Student() :Persoana() {
		bursa = 700;
	}
	Student(int varsta, float bursa):Persoana(varsta) {
		this->bursa = bursa;
	}
	float getVenit() {
		return bursa;
	}
	float get_Salariu() {
		return bursa;
	}
};



void main() 
{
	//Angajat *pa;
	//pa = new Angajat("Ionescu",4000);
	//cout << pa->getVenit()<<endl;

	//Director d("Vasilescu", 3000, 10);
	//pa = new Director();
	//int var;
	//cin >> var;

	//if (var == 0) {
	//	pa = new Angajat("Ionescu", 3000);
	//}
	//else
	//{
	//	pa = new Director("Ionescu", 3000, 20);
	//}
	//	//pa = &d;

	//cout << pa->getVenit()<<endl;


	////delete pa;
	
	//Persoana p;
/*
	Angajat ang;*/


	Persoana **pa;
	int nrPersoane = 5;
	pa = new Persoana*[nrPersoane];

	pa[0] = new Student(19, 1000);
	pa[1] = new Angajat("popescu", 2000);
	pa[2] = new Director("ionescu", 2000, 20);
	pa[3] = new Student(20, 700);
	pa[4] = new Student(21, 1000);

	for (int i = 0; i < nrPersoane; i++) {
		cout << pa[i]->getVenit()<<endl;
	}

	for (int i = 0; i < nrPersoane; i++) {
		delete pa[i];
	}
	delete[]pa;

}