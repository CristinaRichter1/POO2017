//#include<iostream>
//
//using namespace std;
//
//
//class Gradinita{
//private:
//	char* nume;
//	int nrCopii;
//	int * varste;
//	float buget;
//	bool cuPrgPrelungit;
//public:
//	int get_nrCopii(){
//		return nrCopii;
//	}
//
//	void set_nrCopii(int nouaValoare){
//		if (nouaValoare > 0)
//			nrCopii = nouaValoare;
//		else
//			throw "Valoare incorecta";
//	}
//
//	char* get_nume()
//	{
//		return nume;
//	}
//	void set_nume(char* noulNume){
//		if (strlen(noulNume) > 1)
//		{
//			if (nume != NULL)
//			{
//				//delete[]nume;
//			}
//			nume = new char[strlen(noulNume) + 1];
//			strcpy(nume, noulNume);
//		}
//	}
//
//	int* get_varste(){
//		return varste;
//	}
//
//	void set_varste(int* vector, int lungime){
//		//delete[]varste;
//		varste = new int[lungime];
//		for (int i = 0; i < lungime; i++)
//		{
//			varste[i] = vector[i];
//		}
//	}
//};
//
//void main(){
//	Gradinita g;
//	try{
//		g.set_nrCopii(-3);
//	}
//	catch (char* mesaj){
//		cout << mesaj;
//		g.set_nrCopii(3);
//	}
//	catch (int){
//
//	}
//
//	cout << g.get_nrCopii();
//
//	g.set_nume("Ingerul Alb");
//	cout << g.get_nume();
//
//	int vector[3] = { 5, 4, 6 };
//	int lungime = 3;
//	
//	g.set_varste(vector, lungime);
//
//	int* variabila = g.get_varste();
//	cout <<endl<< variabila[1]<<endl;
//
//	cout << endl << g.get_varste()[1];
//}