#include<iostream>

using namespace std;


class Restaurant{
private:
	char* nume;
	int nrMeniuri;
	float* preturi;
	bool deschis;

public:
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
			//delete[]nume;
			nume = new char[strlen(valoare) + 1];
			strcpy(nume, valoare);
		}
	}

	float*get_preturi(){
		return preturi;
	}

	void set_preturi(float* vector, int nrMeniuri){
		if (nrMeniuri > 1){
			//delete[]preturi;
			preturi = new float[nrMeniuri];
			for (int i = 0; i < nrMeniuri; i++){
				preturi[i] = vector[i];
			}
		}
	}
};


void main(){
	Restaurant r;
	try
	{
		r.set_nrMeniuri(-5);
		//instructune 2

		//4
	}
	catch (char* mesaj)
	{
		cout << mesaj<<endl;
		r.set_nrMeniuri(3);
	}
	catch (int exceptie){

	}

	cout << r.get_nrMeniuri();

	r.set_nume("restaurant");
}