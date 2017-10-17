#include<iostream>

using namespace std;

class Spital{
private:

protected:

public:
	char* nume;
	char adresa[20];
	int nr_pacienti;
	int* varste;
	float* greutati;

	void afisare(){
		cout << "Spitalul " << nume<<" are adresa "<<adresa<<endl;
		cout << "Spitalul are " << nr_pacienti << " pacienti:" << endl;
		for (int i = 0; i < nr_pacienti; i++){
			cout << varste[i] << " - " << greutati[i] << endl;
		}
	}

};

void main(){
	Spital s;
	char buffer[10];
	std::cout << "Numele spitalului:";
	cin >> buffer;
	s.nume = new char[strlen(buffer) + 1];
	strcpy(s.nume, buffer);
	cin >> s.adresa;
	cin >> s.nr_pacienti;
	s.varste = new int[s.nr_pacienti];
	s.greutati = new float[s.nr_pacienti];

	for (int i = 0; i<s.nr_pacienti; i++){
		cout << "Varsta si greutatea pacientului "<<(i+1);
		cin >> s.varste[i];
		cin >> s.greutati[i];
	}
	s.afisare();

	Spital *ps;
	ps = new Spital();
	cin >> buffer;
	ps->nume = new char[strlen(buffer) + 1];
	strcpy(ps->nume, buffer);
	cin >> ps->adresa;
	cin >> ps->nr_pacienti;
	ps->varste = new int[ps->nr_pacienti];
	ps->greutati = new float[ps->nr_pacienti];

	for (int i = 0; i<ps->nr_pacienti; i++){
		cout << "Varsta si greutatea pacientului " << (i + 1);
		cin >> ps->varste[i];
		cin >> ps->greutati[i];
	}

	ps->afisare();
}