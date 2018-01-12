//#include<iostream>
//#include<vector>
//#include<list>
//#include<algorithm>
//#include<numeric>
//#include<map>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//class Fruct {
//	float calorii;
//public:
//	Fruct() {
//		calorii = 5.2;
//	}
//	Fruct(float calorii) {
//		this->calorii = calorii;
//	}
//	friend ostream&operator<<(ostream& mmp, Fruct f) {
//		mmp << "Fructul are " << f.calorii << " calorii."<<endl;
//		return mmp;
//	}
//	bool operator<(Fruct f) {
//		return this->calorii < f.calorii;
//	}
//	friend bool operator<(const Fruct& f1, const Fruct& f2) {
//		return f1.calorii < f2.calorii;
//	}
//	Fruct operator+(Fruct f) {
//		Fruct f2 = *this;
//		f2.calorii = this->calorii + f.calorii;
//		return f2;
//	}
//};
//
//bool metodaDeComparare(Fruct f1, Fruct f2) {
//	return f1 < f2;
//}
//
//Fruct metodaAdunare(Fruct f1, Fruct f2) {
//	return f1 + f2;
//}
//
//void main() {
//	//vector<bool> v;
//	//v.push_back(true);
//	//v.push_back(false);
//	//v.push_back(true);
//
//	//for (int i = 0; i < v.size(); i++) {
//	//	cout << v[i]<<" ";
//	//}
//
//	//sort(v.begin(), v.end());
//	//cout << endl;
//	//vector<bool>::iterator it;
//	//it = v.begin();
//	//while (it != v.end()) {
//	//	cout << *it<<" ";
//	//	it++;
//	//}
//
//	//list<Fruct> fructe;
//	//fructe.push_back(Fruct());
//	//fructe.push_front(Fruct(6.4));
//	//fructe.push_front(Fruct(5.8));
//	//fructe.push_front(Fruct(7.6));
//
//	//fructe.sort(metodaDeComparare);
//
//	//for (list<Fruct>::iterator i = fructe.begin(); i != fructe.end(); i++)
//	//{
//	//	cout << *i;
//	//}
//
//	//Fruct f=accumulate(fructe.begin(), fructe.end(), Fruct(0), metodaAdunare);
//	//cout << "Super fruct:" << f;
//
//
//	//string s = "sir";
//	//s = "Popescu,Ion";
//	//s += ",Vasile";
//	//cout << endl << s;
//	//string s2 = s.substr(0, s.find_first_of(',', 0));
//	//cout << endl << s2;
//
//	//map<string, Fruct> fructe;
//	//fructe.insert(pair<string, Fruct>("Mar", Fruct(20)));
//	//fructe.insert(pair<string, Fruct>("Para", Fruct(60)));
//	//fructe.insert(pair<string, Fruct>("Ananas", Fruct(30)));
//	//fructe.insert(pair<string, Fruct>("Mar", Fruct(300)));
//
//	//fructe["Mar"] = Fruct(200);
//
//	//for (map<string, Fruct>::iterator it = fructe.begin(); it != fructe.end(); it++) {
//	//	cout << "Fructul " << it->first << " - " << it->second<<endl;
//	//}
//
//	//map<Fruct, float> fructe;
//	//fructe.insert(pair<Fruct, float>(Fruct(20), 40));
//	//fructe.insert(pair<Fruct, float>(Fruct(9), 200));
//	//fructe.insert(pair<Fruct, float>(Fruct(14), 700));
//	//for (map<Fruct, float>::iterator it = fructe.begin(); it != fructe.end(); it++) {
//	//	cout << it->first << " si " << it->second<<" grame"<<endl;
//	//}
//
//
//	ifstream f("fructe.csv", ios::in);
//	int nrInregistrari;
//	f >> nrInregistrari;
//	for (int i = 0; i < nrInregistrari; i++) {
//		char buffer[50];
//		f >> buffer;
//		char*s = strtok(buffer, ",");
//		float nrCalorii = atof(s);
//		cout << "Numar Calorii:" << nrCalorii<<endl;
//		while (s = strtok(NULL, ",")) {
//			int gramaj = atoi(s);
//			cout << "Gramaj: " << gramaj << endl;
//		}
//	}
//
//}