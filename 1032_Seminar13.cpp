#include<iostream>

using namespace std;

class Dispozitiv {
private:
	char*producator;
	bool areBaterie;
	int garantie;

public:

	int get_garantie() {
		return garantie;
	}
	virtual int getAniGarantie() {
		return garantie / 12;
	}
	Dispozitiv() {
		producator = new char[strlen("Beko") + 1];
		strcpy(producator, "Beko");
		areBaterie = false;
		garantie = 36;
	}

	Dispozitiv(char* producator, bool areBaterie, int garantie) {
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->areBaterie = areBaterie;
		this->garantie = garantie;
	}

	Dispozitiv(const Dispozitiv&d) {
		this->producator = new char[strlen(d.producator) + 1];
		strcpy(this->producator, d.producator);
		this->areBaterie = d.areBaterie;
		this->garantie = d.garantie;
	}
	~Dispozitiv() {
		if (this->producator) {
			delete[]this->producator;
		}
	}

	Dispozitiv operator=(const Dispozitiv&d) {
		if (this->producator) {
			delete[]this->producator;
		}
		this->producator = new char[strlen(d.producator) + 1];
		strcpy(this->producator, d.producator);
		this->areBaterie = d.areBaterie;
		this->garantie = d.garantie;
		return *this;
	}

	friend ostream& operator<<(ostream& out, Dispozitiv d) {
		out << d.producator << " " << d.areBaterie << " "<< d.garantie << endl;
		return out;
	}
};

class Telefon :public Dispozitiv {
private:
	bool areFir;
	bool peFirma;

public:
	Telefon() :Dispozitiv() {
		areFir = false;
		peFirma = true;
	}

	Telefon(char*producator, bool areBaterie, int garantie, 
		bool areFir, bool peFirma) :
		Dispozitiv(producator, areBaterie, garantie) {
		this->areFir = areFir;
		this->peFirma = peFirma;
	}

	 int getAniGarantie() {
		if (peFirma)
			return (this->get_garantie() / 2) / 12;
		else
			return this->get_garantie() / 12;
	}

	 friend ostream& operator<<(ostream& monitor, Telefon t) {
		 monitor << (Dispozitiv)t<<t.areFir<<" "<<t.peFirma<<endl;
		 return monitor;
	 }
};

class Smartphone :public Telefon {
private:
	int ram;
	int extraGarantie;
public:
	Smartphone() :Telefon() {
		this->ram = 0;
		this->extraGarantie = 12;
	}

	Smartphone(char*producator, bool areBaterie, int garantie,
		bool areFir, bool peFirma, int ram, int extraGarantie) 
		:Telefon(producator,areBaterie,garantie,areFir,peFirma) {
		this->ram = ram;
		this->extraGarantie = extraGarantie;
	}

	int getAniGarantie() {
		return (this->get_garantie() + extraGarantie) / 12;
	}

	friend ostream& operator<<(ostream& consola, Smartphone s) {
		consola << (Telefon)s << s.ram << " " << s.extraGarantie << endl;
		return consola;
	}

};



void main() {

	Dispozitiv* d = new Dispozitiv();
	Telefon*t = new Telefon();
	Smartphone*s = new Smartphone();
	d = t;
	d->getAniGarantie();

	cout << typeid(*d).name()<<endl;

	t = s;

	cout << typeid(*t).name() << endl;

	//
	/*Dispozitiv *d2 = new Dispozitiv();
	Telefon*pt2 = (Telefon*)d2;
	cout << *pt2;*/
	Dispozitiv *d2 = new Dispozitiv();
	Telefon* pt = dynamic_cast<Telefon*>(d2);
	if (pt) {
		cout << *pt;
	}
	else {
		cout << "Cast nereusit"<<endl;
	}
}