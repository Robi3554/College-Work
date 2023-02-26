#include <iostream>
using namespace std;

template <class TipVector> class vector {
	TipVector v[20];
	int index;
public:
	vector() { index = 0; }
	void introducere(TipVector ob);
	void afisare();
};

template<class TipVector> void vector<TipVector>::introducere(TipVector ob) {
	v[index] = ob;
	index++;
}
template<class TipVector> void vector<TipVector>::afisare() {
	if (index == 0) {
		cout << "Vectorul este gol!\n";
	}
	for (int i = 0; i < index; i++)
		cout << v[i] << " ";
}

int main() {
	vector<char> v1, v2;
	v1.introducere('a');
	v2.introducere('@');
	v1.introducere('b');
	v2.introducere('*');
	v1.introducere('c');
	v2.introducere('&');

	cout << "Vectorii cu elemente de tip char: \n";
	v1.afisare();
	cout << "\n";
	v2.afisare();
	cout << "\n";

	vector<double> x1, x2;
	x1.introducere(1);
	x2.introducere(20);
	x1.introducere(3);
	x2.introducere(40);
	x1.introducere(5);
	x2.introducere(60);

	cout << "Vectorii cu elemente de tip int:\n";
	x1.afisare();
	cout << "\n";
	x2.afisare();
	cout << "\n";
	getchar();
	return 0;
}