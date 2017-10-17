#include<iostream>

using namespace std;

class Furnizor{
private:
	//zona de atribute si metode private
protected:
	//zona protected
private:
	//zona private
public:

	char*nume;
	char adresa[20];
	int nr_produse;
	int * coduri_produse;
	float * preturi_produse;


	void afisare(){
		cout << this->nume << " are adresa " << this->adresa << " si produsele" << endl;
		for (int i = 0; i<nr_produse; i++) {
			cout << coduri_produse[i] << ". " << preturi_produse[i] << endl;
		}
	}
};


void main(){
	Furnizor f;
	char buffer[20];
	cin >> buffer;
	f.nume = new char[strlen(buffer) + 1];
	strcpy(f.nume, buffer);
	cin >> f.adresa;
	cin >> f.nr_produse;

	f.coduri_produse = new int[f.nr_produse];
	f.preturi_produse = new float[f.nr_produse];
	for (int i = 0; i < f.nr_produse; i++){
		cout << "Cod produs " << (i + 1) << ":";
		cin >> f.coduri_produse[i];		
		cout << "Pret produs " << (i + 1) << ":";
		cin >> f.preturi_produse[i];
	}

	f.afisare();//Furnizor::afisare(f)
	
	Furnizor* pf;

	pf = new Furnizor();

}