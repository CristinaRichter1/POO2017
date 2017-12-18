#include<iostream>
#include<string>
#include<vector>


using namespace std;
//
//int suma(int a, int b) {
//	return a + b;
//}
//
//float suma(float a, float b) {
//	return a + b;
//}

template<class T>
T suma(T a, T b) {
	return a + b;
}

class Mobila {
private:
	int inaltime;
	float greutate;
public:
	Mobila() {
		this->inaltime = 60;
		this->greutate = 3.6;
	}
	Mobila(int inaltime, float greutate) {
		this->inaltime = inaltime;
		this->greutate = greutate;
	}

	Mobila operator+(Mobila m) {
		Mobila aux = *this;
		aux.inaltime += m.inaltime;
		aux.greutate += m.greutate;
		return aux;
	}

	friend ostream& operator<<(ostream& iesire, Mobila m) {
		iesire << m.inaltime << " " << m.greutate<<endl;
		return iesire;
	}

};

template<class M>
class Colectie {
private:
	M*vector;
	int lungime;

public:
	Colectie() {
		this->lungime = 2;
		this->vector = new M[this->lungime];
	}

	Colectie(int lungime, M*vector) {
		this->lungime = lungime;
		this->vector = new M[this->lungime];
		for (int i = 0;i < lungime;i++) {
			this->vector[i] = vector[i];
		}
	}

	Colectie(const Colectie& c) {
		this->lungime = c.lungime;
		this->vector = new M[this->lungime];
		for (int i = 0;i < c.lungime;i++) {
			this->vector[i] = c.vector[i];
		}
	}

	Colectie operator=(const Colectie& c) {
		if (vector) {
			delete[]vector;
		}
		this->lungime = c.lungime;
		this->vector = new M[this->lungime];
		for (int i = 0;i < c.lungime;i++) {
			this->vector[i] = c.vector[i];
		}
		return *this;
	}

	~Colectie() {
		if (vector) {
			delete[]vector;
		}
	}

	friend ostream& operator<<(ostream& out, Colectie c) {
		out << "Colectia are " << c.lungime << " elemente:" << endl;
		for (int i = 0;i < c.lungime;i++) {
			out << c.vector[i];
		}
		return out;
	}
	
};

void main(int numar, char** argumente) {


	string nume;
	nume = "Popescu";
	cout << nume<<endl;

	vector<string> v;
	v.push_back("Popescu");
	v.push_back("Ionescu");
	v.push_back("Vasilescu");

	for (int i = 0;i < v.size();i++) {
		cout << v[i] << endl;
	}


	//for (int i = 0;i < numar;i++) {
	//	cout << argumente[i] << endl;
	//}
	//int valoare=0;
	//if (numar > 1) {
	//	valoare=atoi(argumente[1]);
	//}
	//valoare++;
	//cout << valoare;



	/*int m = 4;
	int n = 7;
	cout << suma(m, n)<<endl;

	float z = 4.6;
	float y = 6.7;
	cout << (float)suma(z, y) << endl;

	Mobila a(70, 6);
	Mobila b(20, 2);

	Mobila c = suma(a, b);
	cout << c<<endl;*/

	//Colectie<int> c1;
	//cout << c1<<endl;

	//Colectie<Mobila> c2;
	//cout << c2;

}