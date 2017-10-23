#include<iostream>

using namespace std;

class Zoo{
private:
	char* nume;
	int nrSpecii;
	float pret;
	int* nrAnimaleSpecie;
	bool* carnivor;

public:
	int get_nrSpecii(){
		return nrSpecii;
	}

	void set_nrSpecii(int valoareNoua){
		if (valoareNoua > 0)
		{
			nrSpecii = valoareNoua;
		}
		else
		{
			throw "Valoarea nu este corecta.";
		}
	}

	char* get_nume(){
		return nume;
	}
	void set_nume(char* numeNou){
		if (strlen(numeNou) > 2){
			//delete[] nume;
			nume = new char[strlen(numeNou) + 1];
			strcpy(nume, numeNou);
		}
	}

	int* get_nrAnimaleSpecie(){
		return nrAnimaleSpecie;
	}

	void set_nrAnimaleSpecie(int* vector, int nrSpecii){
		//delete[]nrAnimaleSpecie;
		//niciodata asa: nrAnimaleSpecie = vector;


		nrAnimaleSpecie = new int[nrSpecii];
		for (int i = 0; i < nrSpecii; i++){
			nrAnimaleSpecie[i] = vector[i];
		}
	}
};


void main(){
	Zoo z;
	try{
		z.set_nrSpecii(-5);
	}
	catch (char* mesaj){
		cout << endl << mesaj << endl;
		z.set_nrSpecii(3);
	}
	cout << z.get_nrSpecii();
	z.set_nume("LAZ");
	cout << z.get_nume();

	int vector[3] = { 5, 2, 3 };
	int nrElemente = 3;

	z.set_nrAnimaleSpecie(vector, nrElemente);
	int* variabila = z.get_nrAnimaleSpecie();
	cout << variabila[1] << endl;
	
	cout << z.get_nrAnimaleSpecie()[2];
}