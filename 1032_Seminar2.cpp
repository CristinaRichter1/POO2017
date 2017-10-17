//#include<iostream>
//
//using namespace std;
//
//class Programator{
//private:
//	//totul este privat
//protected:
//	//totul este protecte
//public:
//	//totul este public
//
//	char* nume;
//	float* salarii;
//	int nr_lunii;
//	int * zile_libere_luna;
//	char limbaj[20];
//
//	void afisare(){
//		cout << nume << " stie sa programeze in limbajul " << limbaj << endl;
//		for (int i = 0; i < nr_lunii; i++){
//			cout << "Luna " << (i + 1) << ": Salariu: " << salarii[i] 
//				<< ", Numar zile libere: " << zile_libere_luna[i] 
//				<< endl;
//		}
//		cout << endl;
//	}
//};
//
//
//void main(){
//
//	Programator p;
//	char buffer[20];
//	scanf("%s", &buffer);
//	p.nume = new char[strlen(buffer)+1];
//	strcpy(p.nume, buffer);
//	cin >> p.nr_lunii;
//	p.salarii = new float[p.nr_lunii];
//	for (int i = 0; i<p.nr_lunii; i++){
//		cout << "Salariul pentru luna " << (i + 1) << ":";
//		cin >> p.salarii[i];
//	}
//	p.zile_libere_luna = new int[p.nr_lunii];
//	
//	for (int i = 0; i<p.nr_lunii; i++){
//		cout << "numarul zile libere pentru luna " << (i + 1) << ":";
//		cin >> p.zile_libere_luna[i];
//	}
//	cin >> p.limbaj;
//
//	cout << "afisare programator";
//
//	p.afisare();
//
//	Programator *pp;
//	pp = new Programator();
//}