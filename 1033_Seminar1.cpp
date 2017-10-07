#include<iostream>

using namespace std;

struct Receptioner {
	char* nume;
	char sex;
	float salariu;
	int varsta;
};



Receptioner initializareReceptioner() {
	Receptioner r;
	//r.nume = (char*)malloc(sizeof(char)*(strlen("Popescu") + 1));
	r.nume = new char[strlen("Popescu") + 1];
	strcpy(r.nume, "Popescu");
	r.sex = 'F';
	r.salariu = 2500;
	r.varsta = 21;
	return r;
}

void aniversare(Receptioner r) {
	r.varsta++;
}

void aniversare2(Receptioner *r) {
	r->varsta++;
}

void main() {
	Receptioner receptioner;
	receptioner = initializareReceptioner();
	cout << receptioner.nume << " are o varsta de " << receptioner.varsta<<endl;
	aniversare2(&receptioner); 
	cout << receptioner.nume << " are o varsta de " << receptioner.varsta << endl;
}