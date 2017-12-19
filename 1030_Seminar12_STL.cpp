#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include<map>

using namespace std;

template<class T1, class T2>
class Pereche {
	T1 cheie;
	T2 valoare;
public:
	Pereche() {

	}
	Pereche(T1 cheie, T2 valoare) {
		this->cheie = cheie;
		this->valoare = valoare;
	}
	T1 get_cheie() {
		return cheie;
	}
	T2 get_valoare() {
		return valoare;
	}
};


class Calculator {
	float ram;
	int spatiu;

public:
	Calculator() {
		this->ram = 4;
		this->spatiu = 256;
	}

	Calculator(float ram, int spatiu) {
		this->ram = ram;
		this->spatiu = spatiu;
	}

	friend ostream& operator<<(ostream& out, Calculator c) {
		out << c.ram << " GB, " << c.spatiu << " GB." << " ";
		return out;
	}

	//bool operator<(Calculator c) {
	//	return this->ram < c.ram;
	//}
	friend bool operator<(const Calculator& c1, const Calculator & c2) {
		return c1.ram < c2.ram;
	}

	int getSpatiu() {
		return spatiu;
	}

	void setSpatiu(int spatiu) {
		this->spatiu = spatiu;
	}
};

bool metodaComparare(Calculator c1, Calculator c2) {
	return c1 < c2;
}

bool metodaSortare(float f1, float f2) {
	return f1 < f2;
}

bool metodaFiltrare(Calculator c) {
	return c.getSpatiu() > 128;
}

Calculator metodaAdunare(Calculator c1, Calculator c2) {
	Calculator c3(0, c1.getSpatiu() + c2.getSpatiu());
	
	return c3;
}



void main() {

	/*Pereche<int, float> pereche(3,8.6);
	cout << pereche.get_cheie() << " " << pereche.get_valoare();

	*/
	//vector<int> v;
	//v.push_back(5);
	//v.push_back(8);
	//v.push_back(9);
	//v.push_back(4);

	//vector<int>::iterator it = v.begin();
	//while (it != v.end()) {
	//	cout << *it<<" ";
	//	it++;
	//}

	//cout << endl;
	//sort(v.begin(), v.end());
	//reverse(v.begin(), v.end());
	//for (vector<int>::iterator i = v.begin();i != v.end();i++) {
	//	cout << *i << " ";
	//}

	//pentur sortarea unei liste se foloseste metoda sort pe obiectul de tipul list
	//nu se foloseste la fel ca la vector metoda sort() din algorithm.

	//list<Calculator> calculatoare;
	//calculatoare.push_back(Calculator(8, 512));
	//calculatoare.push_front(Calculator(16, 128));
	//calculatoare.push_front(Calculator(12, 256));

	//calculatoare.sort(metodaComparare);

	//for (list<Calculator>::iterator it = calculatoare.begin();it != calculatoare.end();it++) {
	//	cout << *it<<endl;
	//}

	//list<float> lista;
	//lista.push_back(8.6);
	//lista.push_back(4.3);
	//lista.push_back(7.9);
	//lista.push_back(8.2);

	//lista.sort(metodaSortare);


	//list<float>::iterator it = lista.begin();
	//while (it != lista.end()) {
	//	cout << *it << " ";
	//	it++;
	//}

	//map<int, int> dictionar;
	//dictionar.insert(pair<int, int>(3, 8));
	//dictionar.insert(pair<int, int>(5, 7));
	//dictionar.insert(pair<int, int>(6, 4));
	//dictionar.insert(pair<int, int>(5, 8));

	//map<int, int>::iterator it = dictionar.begin();
	//while (it != dictionar.end()) {
	//	cout << it->first << " " << it->second << endl;
	//	it++;
	//}

	//map<int, Calculator> calculatoare;
	//calculatoare.insert(pair<int, Calculator>(11, Calculator(8, 128)));
	//calculatoare.insert(pair<int, Calculator>(12, Calculator(12, 256)));
	//calculatoare.insert(pair<int, Calculator>(13, Calculator(16, 512)));
	//calculatoare.insert(pair<int, Calculator>(14, Calculator(4, 256)));

	//calculatoare[13] = Calculator(2, 64);

	//for (map<int, Calculator>::iterator it = calculatoare.begin();it != calculatoare.end();it++) {
	//	cout << it->first << " " << it->second;
	//}


	//map<Calculator, bool> calculatoare;
	//calculatoare.insert(pair<Calculator, bool>(Calculator(8, 256), true));
	//calculatoare.insert(pair<Calculator, bool>(Calculator(12, 512), false));
	//calculatoare.insert(pair<Calculator, bool>(Calculator(4, 128), true));
	//calculatoare.insert(pair<Calculator, bool>(Calculator(16, 512), false));

	//map<Calculator, bool>::iterator it = calculatoare.begin();
	//while (it != calculatoare.end()) {
	//	cout << it->first << " " << it->second<<endl;
	//	it++;
	//}

	vector<Calculator> calc;
	calc.push_back(Calculator(4, 128));
	calc.push_back(Calculator(16, 1024));
	calc.push_back(Calculator(8, 512));
	calc.push_back(Calculator(12, 256));

	int nrSuperCalculatoare = count_if(calc.begin(), calc.end(), metodaFiltrare);

	cout << nrSuperCalculatoare << endl;

	//metoda accumulate primeste primul element din colectie, ultimul element, valoarea de la care se pleaca (s=0) si metoda folosita pentru adunare
	Calculator C = accumulate(calc.begin(), calc.end(),Calculator(0,0), metodaAdunare);

	cout << C;
}