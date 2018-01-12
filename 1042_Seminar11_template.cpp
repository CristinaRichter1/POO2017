//#include<iostream>
//#include<string>
//using namespace std;
//
////int maxim(int a, int b) {
////	//if (conditie)
////	//	true
////	//else
////	//	false
////	//	? : - operator ternar
////	//	(conditie) ? true : false;
////
////	return (a > b) ? a : b;
////
////}
//
//template<class TTY>
//TTY maxim(TTY a, TTY b) {
//	return (a > b) ? a : b;
//}
//
//class Cozonac {
//	int nrStafide;
//public:
//	Cozonac() {
//		nrStafide = 10;
//	}
//	Cozonac(int nrStafide) {
//		this->nrStafide = nrStafide;
//	}
//
//	bool operator>(Cozonac c) {
//		return this->nrStafide > c.nrStafide;
//	}
//	friend ostream& operator<<(ostream& out, Cozonac c) {
//		out << c.nrStafide << endl;
//		return out;
//	}
//};
//
//template<class TTC>
//class Colectie {
//private:
//	TTC* obiecte;
//	int nrObiecte;
//public:
//	Colectie() {
//		this->nrObiecte = 1;
//		this->obiecte = new TTC[this->nrObiecte];
//	}
//	Colectie(int nrObiecte, TTC* obiecte) {
//		this->nrObiecte = nrObiecte;
//		this->obiecte = new TTC[this->nrObiecte];
//		for (int i = 0; i < this->nrObiecte; i++) {
//			this->obiecte[i] = obiecte[i];
//		}
//	}
//	Colectie(const Colectie& c) {
//		this->nrObiecte = c.nrObiecte;
//		this->obiecte = new TTC[this->nrObiecte];
//		for (int i = 0; i < this->nrObiecte; i++) {
//			this->obiecte[i] = c.obiecte[i];
//		}
//	}
//
//	Colectie operator=(const Colectie& c) {
//		if (this->obiecte)
//			delete[]this->obiecte;
//		this->nrObiecte = c.nrObiecte;
//		this->obiecte = new TTC[this->nrObiecte];
//		for (int i = 0; i < this->nrObiecte; i++) {
//			this->obiecte[i] = c.obiecte[i];
//		}
//		return *this;
//	}
//
//	~Colectie() {
//		if (this->obiecte)
//			delete []this->obiecte;
//	}
//
//	friend ostream& operator<<(ostream& monitor, Colectie c) {
//		monitor << "Colectia are " << c.nrObiecte << " elemente:" << endl;
//		for (int i = 0; i < c.nrObiecte; i++) {
//			monitor << c.obiecte[i] << endl;
//		}
//
//		return monitor;
//	}
//};
//
//template<class TTD, class TTE>
//class Pereche {
//	TTD cheie;
//	TTE valoare;
//
//public:
//	Pereche() {
//		
//	}
//	Pereche(TTD cheie, TTE valoare) {
//		this->cheie = cheie;
//		this->valoare = valoare;
//	}
//
//	TTD getCheie() {
//		return cheie;
//	}
//	TTE getValoare() {
//		return valoare;
//	}
//	
//};
//
//template<class TTD, class TTE>
// ostream& operator<<(ostream & iesire, Pereche<TTD, TTE> p) {
//	iesire << p.getCheie() << " " << p.getValoare() << endl;
//	return iesire;
//}
//
//
//
//void main(int numar, char** argumente) {
//	//for (int i = 0; i < numar; i++)
//	//	cout << argumente[i]<<endl;
//	//cout <<"Primul fisier:" <<argumente[1];
//	//cout << "Al doilea fisier :"<< argumente[2];
//
//	//int a = 5;
//	//int b = 6;
//	//cout << maxim(a, b);
//	//float z = 6.7;
//	//float y = 7.5;
//	//cout << maxim(z, y);
//
//	//Cozonac c1(40);
//	//Cozonac c2(30);
//	//cout <<endl<< maxim(c1, c2);
//
//	//int *v = new int[5]{ 5,7,3,4,9 };
//
//	//Colectie<int> colectie(5,v);
//	//cout << colectie;
//
//	/*Cozonac* cozonaci = new Cozonac[3]{ Cozonac(),Cozonac(30),Cozonac(20) };
//	Colectie<Cozonac>lista(3, cozonaci);
//	cout << lista;*/
//
//	//Pereche<int, float> pereche(4,6.7);
//	//cout << pereche.getCheie() << " " << pereche.getValoare();
//	//Pereche<float, Cozonac> perecheC(25.6, Cozonac(50));
//	//cout<<endl << perecheC;
//
//	Pereche<string, Cozonac> *vector = 
//		new Pereche<string, Cozonac>[3]{
//		Pereche<string, Cozonac>(),
//		Pereche<string, Cozonac>("sir",Cozonac(20)),
//		Pereche<string, Cozonac>("sir2",Cozonac(30)) };
//
//
//	Colectie<Pereche<string, Cozonac>> colectie(3, vector);
//
//	cout << colectie;
//
//
//}