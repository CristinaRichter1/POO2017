#include<iostream>

using namespace std;

class Persoana {
private:
	char cnp[14];
public:
	Persoana() {
		strcpy(cnp, "1234567890123");
	}
	Persoana(char* cnp) {
		strcpy(this->cnp, cnp);
	}
	virtual float get_venit() = 0;
};


class Angajat :public Persoana {
private:
	float salariu;
	char* nume;
public:
	Angajat() :salariu(2000) {
		nume = NULL;
	}
	~Angajat(){
		if (nume)
			delete[]nume;
	}
	Angajat(char* nume, float sal) :salariu(sal) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
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
	float get_venit() {
		return salariu;
	}
	float getSalariu() {
		return salariu;
	}
};

class Director :public Angajat {
private:
	float sporConducere;
public:
	Director() :Angajat(),sporConducere(10) {

	}
	Director(char* nume, float salariu, float spor)
		:Angajat(nume, salariu), sporConducere(spor) {

	}

	float getVenit() {
		return getSalariu() + (sporConducere / 100)*getSalariu();
	}
	float get_venit() {
		return getSalariu() + (sporConducere / 100)*getSalariu();
	}
};

class Student :public Persoana {
private:
	float bursa;
public:
	Student():Persoana() {
		bursa = 720;
	}
	Student(char* cnp, float bursa) :Persoana(cnp) {
		this->bursa = bursa;
	}
	float get_venit()
	{
		return bursa;
	} 
};

void main() 
{
	//Angajat *pa;
	//pa = new Angajat("Ionescu",2000);
	//cout << pa->getVenit()<<endl;

	//pa = new Director("Popescu", 3000, 20);
	//cout << pa->getVenit();

	//delete pa;

	//Persoana *a;

	//Angajat a;

	Persoana **p;
	//p = new Persoana*();

	//p = new Persoana*[5];
	//for (int i = 0; i < 5; i++) {
	//	p[i] = new Persoana[5];
	//}

	p = new Persoana*[5];
	p[0] = new Angajat("Popescu", 2000);
	p[1] = new Director("Ionescu", 2000, 30);
	p[2] = new Student("1234567890123", 1000);
	p[3] = new Angajat("Vasilescu", 3000);
	p[4] = new Student("2134567890123", 720);

	for (int i = 0; i < 5; i++) {
		cout << p[i]->get_venit()<<endl;
	}

	for (int i = 0; i < 5; i++)
		delete p[i];

	delete[]p;


	Persoana *pa;
	Angajat a("Ionescu", 3000);
	pa = &a;

	delete pa;
}