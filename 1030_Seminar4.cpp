#include<iostream>

using namespace std;


class Restaurant{
private:
	char* nume;
	int nrMeniuri;
	float* preturi;
	bool deschis;

public:

	Restaurant(char* nume, int nrMeniuri){
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrMeniuri = nrMeniuri;
		this->preturi = new float[nrMeniuri];
		for (int i = 0; i < nrMeniuri; i++)
			this->preturi[i] = 0;
		deschis = false;
	}

	Restaurant(){
		this->nume = new char[strlen("Shorley") + 1];
		strcpy(this->nume, "Shorley");
		this->nrMeniuri = 0;
		this->preturi = NULL;
		this->deschis = false;
	}

	Restaurant(char*nume, int nrMeniuri, float* preturi, bool deschis){
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrMeniuri = nrMeniuri;
		this->preturi = new float[nrMeniuri];
		for (int i = 0; i<nrMeniuri; i++){
			this->preturi[i] = preturi[i];
		}
		this->deschis = deschis;
	}

	int get_nrMeniuri(){
		return nrMeniuri;
	}

	void set_nrMeniuri(int nr){
		if (nr > 1)
		{
			nrMeniuri = nr;
		}
		else
		{
			throw "Valoarea este incorecta";

		}
	}

	char* get_nume(){
		return nume;
	}
	void set_nume(char* valoare){
		if (strlen(valoare) > 3){
			if (nume!=NULL)
				delete[]nume;
			nume = new char[strlen(valoare) + 1];
			strcpy(nume, valoare);
		}
	}

	float*get_preturi(){
		return preturi;
	}

	void set_preturi(float* vector, int _nrMeniuri){
		if (nrMeniuri > 1){
			if(preturi)
				delete[]preturi;
			preturi = new float[nrMeniuri];
			for (int i = 0; i < nrMeniuri; i++){
				preturi[i] = vector[i];
			}
			nrMeniuri = _nrMeniuri;
		}
	}
};


void main(){
	//Restaurant r;
	//try
	//{
	//	r.set_nrMeniuri(-5);
	//	//instructune 2

	//	//4
	//}
	//catch (char* mesaj)
	//{
	//	cout << mesaj << endl;
	//	r.set_nrMeniuri(3);
	//}
	//catch (int exceptie){

	//}

	//cout << r.get_nrMeniuri();

	//r.set_nume("restaurant");

	Restaurant r;
	cout << r.get_nrMeniuri() << endl;

	Restaurant r2("Andrei", 3, new float[3]{200, 100, 150}, true);
	cout << r2.get_nume() << endl;
}