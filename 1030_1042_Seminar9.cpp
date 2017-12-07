#include<iostream>
#include<fstream>

using namespace std;

class Persoana {
private:
	char*nume;
public:

	char* get_nume() {
		return nume;
	}
	virtual float getVenit() = 0;
	virtual float getSalariu() = 0;

	Persoana(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	Persoana(const Persoana & p) {
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
	}

	Persoana& operator=(const Persoana & p) {
		if (this->nume)
			delete[]this->nume;
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);

		return *this;
	}
	~Persoana() {
		if (nume)
			delete[]nume;
	}
};

class Angajat : public Persoana{
protected:
	float salariu;
public:
	Angajat(float salariuNou) :
		Persoana("Popescu"), salariu(salariuNou) {
	}
	float getSalariu() {
		return salariu;
	}
	
	virtual float getVenit() {
		return salariu;
	}
};

class Director :public Angajat {
private:
	float sporConducere;
public:
	Director(float salariu, float spor) :
		Angajat(salariu), sporConducere(spor) {

	}
	float getVenit() {
		return salariu + (salariu*sporConducere) / 100;
	}
};

class Student :public Persoana {
private:
	float bursa;
public:
	Student(char*nume, float bursa):Persoana(nume) {
		this->bursa = bursa;
	}
	float getSalariu() {
		return bursa;
	}
	float getVenit() {
		return bursa;
	}

	friend ostream & operator<<(ostream& consola,  Student s) {
		consola << s.get_nume() << " are bursa de " 
			<< s.bursa << " lei"<<endl;
		return consola;
	}

	friend ofstream & operator<<(ofstream& fisier, Student s) {
		fisier << s.get_nume() << "," << s.bursa<<endl;
		return fisier;
	}

};

void main() {

	////Persoana p;
	//Angajat* pAngajat;
	//pAngajat = new Angajat(2000);
	//Director director(2000, 20);

	//pAngajat = &director;
	//cout << pAngajat->getVenit()<<endl;


	////delete pAngajat;

	/*Persoana** persoane;
	persoane = new Persoana*[6];

	persoane[0] = new Student("Ionescu", 700);
	persoane[1] = new Director(1000, 30);
	persoane[2] = new Angajat(1500);
	persoane[3] = new Student("Popescu", 1000);
	persoane[4] = new Student("Vasielescu", 580);
	persoane[5] = new Angajat(2000);

	for (int i = 0;i < 6;i++) {
		cout << persoane[i]->getVenit()<<endl;
	}

	for (int i = 0;i < 6;i++) {
		delete persoane[i];
	}
	delete[]persoane;*/


	Student s("Popescu", 700);
	Student s2("Ionescu", 1000);
	Student s3("Vasilescu", 580);
	cout << s;

	ofstream f("fisier.csv", ios::out);
	f << s;
	f << s2 << s3;

}