#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Salariu {
private:
	float venit;
	int impozit;
public:
	Salariu() {
		this->venit = 3000;
		this->impozit = 16;
	}
	Salariu(float venit, int impozit) {
		this->venit = venit;
		this->impozit = impozit;
	}

	Salariu operator+(Salariu s) {
		Salariu temp = *this;
		temp.venit += s.venit;
		temp.impozit = (this->impozit > s.impozit ? 
			this->impozit : s.impozit);
		return temp;
	}

	Salariu operator/(int numitor) {
		Salariu temp = *this;
		temp.venit /= numitor;
		temp.impozit = (float)temp.impozit/(float)numitor;
		return temp;
	}

	friend ostream& operator<<(ostream& iesire, Salariu s) {
		iesire << "Venitul este de " 
			<< s.venit << " cu un impozit de "
			<< s.impozit << "%." << endl;
		return iesire;
	}

};

//int medie(int a, int b) {
//	return (a + b) / 2;
//}
//
//float medie(float a, float b) {
//	return (a + b) / 2;
//}

template<class Tip>
Tip medie(Tip a, Tip b) {
	return (a + b) / 2;
}

template<class C>
class Colectie {
private:
	C* vector;
	int dimensiune;

public:
	Colectie() {
		this->dimensiune = 2;
		this->vector = new C[this->dimensiune];
	}
	Colectie(int dimensiune, C* vector) {
		this->dimensiune = dimensiune;
		this->vector = new C[this->dimensiune];
		for (int i = 0; i < this->dimensiune; i++)
		{
			this->vector[i] = vector[i];
		}
	}

	Colectie(const Colectie& colectie) {
		this->dimensiune = colectie.dimensiune;
		this->vector = new C[this->dimensiune];
		for (int i = 0; i < this->dimensiune; i++)
		{
			this->vector[i] = colectie.vector[i];
		}
	}

	Colectie operator=(const Colectie& colectie) {
		if (vector)
			delete[]vector;
		this->dimensiune = colectie.dimensiune;
		this->vector = new C[this->dimensiune];
		for (int i = 0; i < this->dimensiune; i++)
		{
			this->vector[i] = colectie.vector[i];
		}
		return *this;
	}

	~Colectie() {
		if (vector)
			delete[]vector;
	}

	friend ostream& operator<<(ostream& monitor, Colectie col) {
		monitor << " Colectia are " << col.dimensiune << " elemente:"<<endl;
		for (int i = 0; i < col.dimensiune; i++) {
			monitor << col.vector[i] << " ";
		}
		monitor << endl;
		return monitor;
	}

};


void main(int nrArgumente, char** argumente) {

	string sir;
	sir = "Popescu";
	sir += " Ion";
	cout << sir<<endl;
	cout << sir.substr(3, 4);

	vector<string>cuvinte;

	cuvinte.push_back("Popescu");
	cuvinte.push_back("Ionescu");
	cuvinte.push_back("Vasilescu");
	cout << endl;
	for (int i = 0; i < cuvinte.size(); i++)
	{
		cout << cuvinte[i] << endl;
	}

	vector<int> elemente;
	elemente.push_back(5);
	elemente.push_back(8);
	elemente.push_back(2);
	elemente.push_back(3);
	elemente.pop_back();
	for (int i = 0; i < elemente.size(); i++) {
		cout << elemente[i]<<endl;
	}
	//elemente.rever(elemente.size());

	//for (int i = 0; i < nrArgumente; i++) {
	//	cout << argumente[i]<<endl;
	//}

	//int valoare = 0;
	//valoare = atoi(argumente[1]);
	//valoare++;
	//cout << valoare;



	//int m = 8;
	//int n = 6;
	//cout << medie(m, n)<<endl;

	//float z = 6.5;
	//float y = 8.6;
	//cout << medie(z, y)<<endl;

	//Salariu s1(2000, 0);
	//Salariu s2(4000, 16);

	//cout << medie(s1, s2);

	//Salariu * v = new Salariu[45];

	//Colectie<float> vectorFloat;
	//cout << vectorFloat;

	//Colectie<Salariu> vectorSalarii;
	//cout << vectorSalarii;
}