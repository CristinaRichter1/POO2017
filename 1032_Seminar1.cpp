#include<iostream>

using namespace std;

struct Soldat {
	char* nume;
	char initiala;
	int varsta;
	float greutate;
	char* arma;
};

Soldat initializareSoldat() {
	Soldat soldat;
	//soldat.nume = (char*)malloc(sizeof(char)*(strlen("Popescu") + 1));
	soldat.nume = new char[strlen("Popescu") + 1];
	strcpy(soldat.nume, "Popescu");
	soldat.initiala = 'I';
	soldat.varsta = 30;
	soldat.greutate = 80.5;
	soldat.arma = new char[strlen("M4") + 1];
	strcpy(soldat.arma, "M4");

	return soldat;
}

void aniversare(Soldat *s)
{
	s->varsta++;
}

void aniversare2(Soldat &s)
{
	s.varsta++;
}
void main() {

	Soldat a;
	a = initializareSoldat();
	cout << a.nume << " are un " << a.arma<<endl;

	cout << "Varsta anterioara:"<<a.varsta<<endl;
	aniversare2(a);
	cout << "Varsta curenta:" << a.varsta;
}