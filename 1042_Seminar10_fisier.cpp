#include<iostream>
#include<fstream>

using namespace std;

class Camera {
private:
	float suprafata;
public:
	float get_suprafata() {
		return suprafata;
	}
	Camera() {
		this->suprafata = 20;
	}
	Camera(float suprafata) {
		this->suprafata = suprafata;
	}
};

class Casa {
private:
	int nrCamere;
	Camera* * camere;
public:
	Casa() {
		this->nrCamere = 3;
		camere = new Camera*[this->nrCamere];
		for (int i = 0;i < this->nrCamere;i++) {
			this->camere[i] = new Camera();
		}
	}
	Casa(int nrCamere, Camera**camere) {
		this->nrCamere = nrCamere;
		this->camere = new Camera*[this->nrCamere];
		for (int i = 0;i < this->nrCamere;i++) {
			this->camere[i] = new Camera(*camere[i]);
		}
	}

	Casa(const Casa& c) {
		this->nrCamere = c.nrCamere;
		this->camere = new Camera*[this->nrCamere];
		for (int i = 0;i < this->nrCamere;i++) {
			this->camere[i] = new Camera(*c.camere[i]);
		}
	}

	Casa operator=(const Casa& c) {
		if (this->camere)
		{
			for (int i = 0;i < this->nrCamere;i++) {
				delete camere[i];
			}
			delete[]camere;
		}

		this->nrCamere = c.nrCamere;
		this->camere = new Camera*[this->nrCamere];
		for (int i = 0;i < this->nrCamere;i++) {
			this->camere[i] = new Camera(*c.camere[i]);
		}

		return *this;
	}
	~Casa() {
		if (this->camere)
		{
			for (int i = 0;i < this->nrCamere;i++) {
				delete camere[i];
			}
			delete[]camere;
		}
	}

	friend ostream& operator<<(ostream& iesire, Casa c) {
		iesire << "Numar camere:" << c.nrCamere<<endl;
		for (int i = 0;i < c.nrCamere;i++) {
			iesire << c.camere[i]->get_suprafata()<<" ";
		}
		return iesire;
	}

	friend ofstream& operator<<(ofstream& iesire, Casa c) {
		iesire << c.nrCamere << ",";
		for (int i = 0;i < c.nrCamere;i++) {
			iesire << c.camere[i]->get_suprafata() << ",";
		}
		return iesire;
	}

	friend ifstream& operator >> (ifstream & tastatura, Casa &c) {
		if (c.camere)
		{
			for (int i = 0;i < c.nrCamere;i++) {
				delete c.camere[i];
			}
			delete[]c.camere;
		}
		tastatura >> c.nrCamere;
		c.camere = new Camera*[c.nrCamere];
		for (int i = 0;i < c.nrCamere;i++) {
			float val;
			tastatura >> val;
			c.camere[i] = new Camera(val);
		}
		return tastatura;
	}

};


void main() {

	//Casa casa;
	//cout << casa;

	//ofstream f("fisier.txt", ios::out);
	//f << casa;

	//f.close();

	//ifstream g("fisier.txt", ios::in);
	//int nr = 2;
	//Camera **v = new Camera*[nr];
	//v[0] = new Camera(40);
	//v[1] = new Camera(30);
	//Casa d(nr,v);
	//cout << d;
	//g >> d;
	//cout << d;

	//Casa c;
	//ofstream f("fisier.csv", ios::out);
	//f << c;

	//f.close();
	{
		Casa c;
		ofstream f("fisier.bin", ios::out | ios::binary);
		f.write((char*)&c, sizeof(Casa));
		f.close();
	}
	int nr = 2;
	Camera **v = new Camera*[nr];
	v[0] = new Camera(40);
	v[1] = new Camera(30);
	Casa d(nr,v);

	ifstream g("fisier.bin", ios::in | ios::binary);
	g.read((char*)&d, sizeof(Casa));
	cout << d;
	g.close();



}