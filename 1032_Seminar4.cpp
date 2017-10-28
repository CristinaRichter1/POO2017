#include<iostream>

using namespace std;


class Gradinita{
private:
	char* nume;
	int nrCopii;
	int * varste;
	float buget;
	bool cuPrgPrelungit;
public:

	Gradinita(){
		this->nume = NULL;
		this->nrCopii = 0;
		this->varste = NULL;
		this->buget = 0;
		this->cuPrgPrelungit = false;
	}

	Gradinita(char* nume, int nrCopii, int *varste, 
		float buget, bool cuPrgPrelungit){
		this->nume = new char[strlen(nume) +1];
		strcpy(this->nume, nume);
		this->nrCopii = nrCopii;
		this->varste = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++)
		{
			this->varste[i] = varste[i];
		}
		this->buget = buget;
		this->cuPrgPrelungit = cuPrgPrelungit;
	}

	Gradinita(char *nume, int nrCopii){
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrCopii = nrCopii;
		this->varste = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++){
			this->varste[i] = 0;
		}
		this->buget = 0;
		this->cuPrgPrelungit = false;
	}

	~Gradinita(){
		if (this->nume){
			delete[]this->nume;
		}
		if (this->varste){
			delete[]this->varste;
		}
	}

	int get_nrCopii(){
		return nrCopii;
	}

	void set_nrCopii(int nouaValoare){
		if (nouaValoare > 0)
			nrCopii = nouaValoare;
		else
			throw "Valoare incorecta";
	}

	char* get_nume()
	{
		return nume;
	}
	void set_nume(char* noulNume){
		if (strlen(noulNume) > 1)
		{
			if (nume != NULL)
			{
				delete[]nume;
			}
			nume = new char[strlen(noulNume) + 1];
			strcpy(nume, noulNume);
		}
	}

	int* get_varste() {
		return varste;
	}

	void set_varste(int* vector, int nrCopii){
		if (varste)
			delete[]varste;
		varste = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++)
		{
			this->varste[i] = vector[i];
		}
		this->nrCopii = nrCopii;
	}
};

void main(){
	/*Gradinita g;
	try{
		g.set_nrCopii(-3);
	}
	catch (char* mesaj){
		cout << mesaj;
		g.set_nrCopii(3);
	}
	catch (int){

	}

	cout << g.get_nrCopii();

	g.set_nume("Ingerul Alb");
	cout << g.get_nume();

	int vector[3] = { 5, 4, 6 };
	int lungime = 3;
	
	g.set_varste(vector, lungime);

	int* variabila = g.get_varste();
	cout <<endl<< variabila[1]<<endl;

	cout << endl << g.get_varste()[1];*/

	Gradinita g25;
	cout << g25.get_nrCopii() << endl; 
	g25.set_nrCopii(10);
	cout << g25.get_nrCopii() << endl;

	Gradinita g26("Piticot", 4, new int[4]{5, 6, 5, 6}, 1000, true);
	/*char buffer[20];
	cin >> buffer;
	g26.set_nume(buffer);*/

	cout << g26.get_nume() << endl;


	{
		Gradinita g2;
	}
}