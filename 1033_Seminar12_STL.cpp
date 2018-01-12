#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<numeric>
#include<string>

#include<fstream>

using namespace std;

class Vacanta {
	int nrZile;
public:
	int get_nrZile() {
		return nrZile;
	}
	Vacanta() {
		nrZile = 16;
	}
	Vacanta(int nrZile) {
		this->nrZile = nrZile;
	}
	friend ostream&operator<<(ostream&mmmP, Vacanta v) {
		mmmP << "Vacanta are " << v.nrZile << " zile." << endl;
		return mmmP;
	}

	Vacanta operator+(Vacanta v) {
		Vacanta v2 = *this;
		v2.nrZile = this->nrZile + v.nrZile;
		return v2;
	}
	friend bool operator<(const Vacanta& v1,const Vacanta& v2) {
		return v1.nrZile < v2.nrZile;
	}
};


bool metodaComparareFloat(float a, float b) {
	return a > b;
}
bool metodaComparareVacante(Vacanta v1, Vacanta v2) {
	return v1.get_nrZile() < v2.get_nrZile();
}

Vacanta metodaAdunareVacante(Vacanta v1, Vacanta v2) {
	return v1 + v2;
}
void main() {

	//ofstream f(arg[1], ios::out);
	//f << 45 << " Testing";
	//f.close();


	/*vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);

	sort(v.begin(), v.end());
	vector<int>::iterator it;
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}*/

	//list<float> lista;
	//lista.push_back(5.7);
	//lista.push_front(5.9);
	//lista.push_front(4.2);
	//lista.push_front(8.6);
	//lista.push_front(6.3);

	//lista.sort(metodaComparareFloat);

	//for (list<float>::iterator i = lista.begin(); i != lista.end(); i++)
	//{
	//	cout << *i<<" ";
	//}

	//float f=accumulate(lista.begin(), lista.end(), 0.0f);
	//cout << endl << "Suma:" << f;

	/*list<Vacanta> vacante;
	vacante.push_back(Vacanta());
	vacante.push_front(Vacanta(5));
	vacante.push_front(Vacanta(9));
	vacante.push_front(Vacanta(100));

	vacante.sort(metodaComparareVacante);

	for (list<Vacanta>::iterator it = vacante.begin(); it != vacante.end(); it++) {
		cout << *it << endl;
	}
	Vacanta v = accumulate(vacante.begin(), vacante.end(), Vacanta(0),metodaAdunareVacante);
	cout << "Super Vacanta: " << v<<endl;*/


	/*map<int, float> colectie;
	colectie.insert(pair<int, float>(5, 7.8));
	colectie.insert(pair<int, float>(6, 2.9));
	colectie.insert(pair<int, float>(2, 5.4));
	colectie.insert(pair<int, float>(5, 2.2));

	colectie[5] = 3.3;
	map<int, float>::iterator it = colectie.begin();
	while (it != colectie.end()) {
		cout << it->first << " - " << it->second<<endl;
		it++;
	}*/

	/*map<string, Vacanta> vacante;
	vacante.insert(pair<string, Vacanta>("Craciun", Vacanta()));
	vacante.insert(pair<string, Vacanta>("Intersemstriala", Vacanta(9)));
	vacante.insert(pair<string, Vacanta>("Paste", Vacanta(9)));
	vacante.insert(pair<string, Vacanta>("Mare", Vacanta(100)));

	vacante["Paste"] = Vacanta(20);
	map<string, Vacanta>::iterator it = vacante.begin();
	while (it != vacante.end()) {
		cout << it->first << " - " << it->second << endl;
		it++;
	}*/

	map<Vacanta, string>vacante;
	vacante.insert(pair<Vacanta, string>(Vacanta(), "Munte"));
	vacante.insert(pair<Vacanta, string>(Vacanta(100), "Mare"));
	vacante.insert(pair<Vacanta, string>(Vacanta(9), "tara"));
	map<Vacanta, string>::iterator it = vacante.end();
	while (it != vacante.begin()) {
		it--;
		cout << it->first << " si mergem la " << it->second << endl;
	
	}
}