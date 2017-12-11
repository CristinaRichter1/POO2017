#include<iostream>
#include<fstream>

using namespace std;

class Carte{
private:
	int nrAutori;
	float pret;

public:
	int get_nrAutori() {
		return nrAutori;
	}
	float get_pret() {
		return pret;
	}
	Carte() {
		nrAutori = 2;
		pret = 20;
	}
	Carte(int nrAutori, float pret) {
		this->nrAutori = nrAutori;
		this->pret = pret;
	}

	friend ifstream& operator >> (ifstream& f, Carte& c) {
		f >> c.nrAutori;
		f >> c.pret;
		return f;
	}
};


class Biblioteca {
private:
	int nrCarti;
	Carte* *carti;
public:
	Biblioteca() {
		this->nrCarti = 3;
		this->carti = new Carte*[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			this->carti[i] = new Carte();
		}
	}

	Biblioteca(int nrCarti, Carte**carti) {
		this->nrCarti = nrCarti;
		this->carti = new Carte*[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			this->carti[i] = new Carte(*carti[i]);
		}
	}

	~Biblioteca() {
		if (this->carti) {
			for (int i = 0; i < this->nrCarti; i++) {
				delete carti[i];
			}
			delete[]carti;
		}
	}

	Biblioteca(const Biblioteca& b) {
		this->nrCarti = b.nrCarti;
		this->carti = new Carte*[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			this->carti[i] = new Carte(*b.carti[i]);
		}
	}

	Biblioteca operator=(const Biblioteca& b) {
		if (this->carti) {
			for (int i = 0; i < this->nrCarti; i++) {
				delete carti[i];
			}
			delete[]carti;
		}
		this->nrCarti = b.nrCarti;
		this->carti = new Carte*[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			this->carti[i] = new Carte(*b.carti[i]);
		}
		return *this;
	}

};


ostream&operator<<(ostream& monitor, Carte c) {
	monitor << "numar autori: " << c.get_nrAutori() 
		<< endl << "Pret: " << c.get_pret() << endl;
	return monitor;
}

ofstream&operator<<(ofstream& file, Carte c) {
	file << c.get_nrAutori() << endl <<c.get_pret() << endl;
	return file;
}

void main() {
	/*Carte c(1, 40);
	cout << c;

	ofstream f("fisier.txt", ios::out);
	f << c;
	f.close();

	ifstream g("fisier.txt", ios::in);
	Carte d(4, 60);
	cout << d;
	g >> d;
	cout << d;*/

	//int nrCarti = 3;
	//Carte *carti = new Carte[nrCarti];
	//ofstream f("carti.txt", ios::out);
	//f << nrCarti<<endl;
	//for (int i = 0; i < nrCarti; i++) {
	//	f << carti[i];
	//}
	//f.close();

	//ifstream g("carti.txt", ios::in);

	//int nrCarti;
	//g >> nrCarti;
	//Carte *carti = new Carte[nrCarti];
	//for (int i = 0; i < nrCarti; i++) {
	//	g >> carti[i];
	//}

	//g.close();
	//for (int i = 0; i < nrCarti; i++) {
	//	cout << carti[i]<<endl;
	//}

	Carte c(3, 30);

	ofstream fb("fisier.bin", ios::out | ios::binary);
	fb.write((char*)&c, sizeof(Carte));
	fb.close();

	Carte d(2, 40);
	cout << d;
	ifstream gb("fisier.bin", ios::in | ios::binary);
	gb.read((char*)&d, sizeof(Carte));
	gb.close();
	cout << d;
}