#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include<map>
#include<string>

using namespace std;


bool metodaSortare(float a, float b) {
	return a > b;
}

class Scoala {
	int nrElevi;
public:
	Scoala() {
		nrElevi = 10;
	}
	Scoala(int nrElevi) {
		this->nrElevi = nrElevi;
	}
	friend ostream& operator<<(ostream& poM, Scoala s) {
		poM << "Numarul de elevi: " << s.nrElevi << endl;
		return poM;
	}
	int get_nrElevi() {
		return nrElevi;
	}

	Scoala operator+(Scoala s) {
		Scoala s2 = *this;
		s2.nrElevi = this->nrElevi + s.nrElevi;
		return s2;
	}

	friend bool operator<(const Scoala& s1, const Scoala& s2) {
		return s1.nrElevi < s2.nrElevi;
	}
};

bool metodaComparareScoli(Scoala s1, Scoala s2) {
	return s1.get_nrElevi() < s2.get_nrElevi();
}

Scoala metodaAdunare(Scoala s1, Scoala s2) {
	Scoala s3 = s1 + s2;
	return s3;
}

void main() {

	/*list<Scoala> scoli;
	scoli.push_back(Scoala());
	scoli.push_back(Scoala(500));
	scoli.push_back(Scoala(200));
	scoli.push_back(Scoala(50));

	scoli.sort(metodaComparareScoli);
	for (list<Scoala>::iterator it = scoli.begin(); it != scoli.end(); it++) {
		cout << *it;
	}

	Scoala s=accumulate(scoli.begin(), scoli.end(), Scoala(0), metodaAdunare);
	cout << "Super scoala:" << s;*/
	//vector<int> v;
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(7);
	//v.push_back(2);

	//sort(v.begin(), v.end());

	//vector<int>::iterator it;
	//it = v.begin();
	//while (it != v.end()) {
	//	cout << *it<<" ";
	//	it++;
	//}

	//list<float> lista;
	//lista.push_back(4.7);
	//lista.push_front(7.3);
	//lista.push_front(6.5);
	//lista.push_front(8.9);
	////lista.insert()
	//lista.sort(metodaSortare);
	//cout << endl;
	//for (list<float>::iterator i = lista.begin(); i != lista.end(); i++)
	//{
	//	cout << *i << " ";
	//}


	//map<int, float>dictionar;
	//dictionar.insert(pair<int, float>(4, 9.6));
	//dictionar.insert(pair<int, float>(6, 6.3));
	//dictionar.insert(pair<int, float>(3, 8.1));
	//dictionar.insert(pair<int, float>(4, 5.5));

	//dictionar[4] = 4.4;
	//for (map<int, float>::iterator it = dictionar.begin(); it != dictionar.end(); it++) {
	//	cout << it->first << " - " << it->second<<endl;
	//}

	//map<string, Scoala> scoli;
	//scoli.insert(pair<string, Scoala>("Scoala 43", Scoala(43)));
	//scoli.insert(pair<string, Scoala>("Scoala 56", Scoala(56)));
	//scoli.insert(pair<string, Scoala>("Scoala 3", Scoala(300)));
	//scoli.insert(pair<string, Scoala>("Scoala 7", Scoala(70)));

	//scoli["Scoala 56"] = Scoala(500);
	//for (map<string, Scoala>::iterator it = scoli.begin(); it != scoli.end(); it++) {
	//	cout << it->first << " - " << it->second<<endl;
	//}

	/*map<Scoala, float> scoli;
	scoli.insert(pair<Scoala, float>(Scoala(45), 100));
	scoli.insert(pair<Scoala, float>(Scoala(600), 50));
	scoli.insert(pair<Scoala, float>(Scoala(80), 120));
	scoli.insert(pair<Scoala, float>(Scoala(300), 80));

	map<Scoala, float>::iterator it = scoli.begin();
	while (it != scoli.end()) {
		cout << it->first << " si taxa este " << it->second << endl;
		it++;
	}*/

	string s = "Popescu ion";
	s += " Vasile";
	cout << s<<endl;
	cout << s.substr(8, 10)<<endl;
	cout << s.substr(s.find_first_of(' ', 0)+1,s.find_last_of('/0'))<<endl;
	s.replace(0,1,"p",1,1);
	cout << s;

}