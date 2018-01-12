#include<iostream>

using namespace std;

class Teren {
private:
	float suprafata;
	char* adresa;
public:
	float get_suprafata() {
		return suprafata;
	}
	float suprafata_utila() {
		return suprafata;
	}
	Teren() {
		this->suprafata = 1000;
		this->adresa = new char[strlen("Bucuresti") + 1];
		strcpy(this->adresa, "Bucuresti");
	}
	Teren(float suprafata, char* adresa) {
		this->suprafata = suprafata;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
	}
	Teren(const Teren& t) {
		this->suprafata = t.suprafata;
		this->adresa = new char[strlen(t.adresa) + 1];
		strcpy(this->adresa, t.adresa);
	}
	Teren operator=(const Teren& t) {
		if (this->adresa)
			delete[]this->adresa;
		this->adresa = new char[strlen(t.adresa) + 1];
		strcpy(this->adresa, t.adresa);
		this->suprafata = t.suprafata;
		return *this;
	}
	~Teren() {
		if (adresa)
			delete[]adresa;
	}

	friend ostream&operator<<(ostream& monitor, Teren t) {
		monitor << t.adresa << " " << t.suprafata << endl;
		return monitor;
	}
};

class Parc :public Teren {
private:
	bool locJoaca;
	float suprafataParcare;
public:
	Parc() :Teren() {
		locJoaca = true;
		suprafataParcare = 200;
	}
	Parc(char* adresa, float suprafata, bool locJoaca, 
		float suprafataParcare) :
		Teren(suprafata, adresa) {
		this->locJoaca = locJoaca;
		this->suprafataParcare = suprafataParcare;
	}
	virtual float suprafataUtila() {
		return this->get_suprafata() - suprafataParcare;
	}
	friend ostream& operator<<(ostream& out, Parc p) {
		out << (Teren)p << p.locJoaca << " " << p.suprafataParcare << endl;
		return out;
	}
};

class ParcAcvatic :public Parc {
private:
	int nr_etaje;
	float suprafata_bazine;
public:
	ParcAcvatic() :Parc() {
		nr_etaje = 2;
		suprafata_bazine = 400;
	}
	ParcAcvatic(char* adresa, float suprafata, 
		bool locJoaca, float suprafataParcare, 
		int nr_etaje, float suprafata_bazine) :
		Parc(adresa, suprafata, locJoaca, 
			suprafataParcare) {

		this->nr_etaje = nr_etaje;
		this->suprafata_bazine = suprafata_bazine;

	}

	float suprafataUtila() {
		return this->get_suprafata()*nr_etaje - suprafata_bazine;
	}

	friend ostream& operator<<(ostream& consola, ParcAcvatic p) {
		consola << (Parc)p << p.nr_etaje << " " << p.suprafata_bazine << endl;
		return consola;
	}
};

void main() {

	Teren* t = new Teren();
	Parc* p = new Parc();
	ParcAcvatic* pa = new ParcAcvatic();


	t = p;

	cout << typeid(*t).name() << endl;

	p = pa;
	cout << typeid(*p).name() << endl;
	
	Parc *p2 = new Parc();

	//ParcAcvatic *ppa = (ParcAcvatic*)p2;
	//cout << *ppa;

	ParcAcvatic*ppa = dynamic_cast<ParcAcvatic*>(p2);
	if (ppa) {
		cout << *ppa;
	}
	else {
		cout << "Cast nereusit"<<endl;
	}

}