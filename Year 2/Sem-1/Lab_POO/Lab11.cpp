#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

class Student {
	string nume, rol, adresa, cod_postal;
public:
	string Nume() {
		return nume;
	}
	Student(){}
	Student(string, string, string, string);
	~Student();
	void Afisare();
};

Student::Student(string nume, string rol, string adresa, string cod_postal) {
	this->nume = nume;
	this->rol = rol;
	this->adresa = adresa;
	this->cod_postal = cod_postal;
}

Student::~Student() {
	std::cout << "Destructor: Datele studentului au fost eliberate din memorie!\n";
}

void Student::Afisare() {
	cout << "Nume: " << nume << endl;
	cout << "Rol: " << rol << endl;
	cout << "Cod Postal: " << cod_postal << endl;
	cout << "Adresa: " << adresa << endl;
}

int main() {
	list <Student*> lista;
	int i = 0;
	Student* s;
	int opt;
	string nume, rol, adresa, cod_postal;
	do {
		cout << "1.Adaugare studenti!" << endl;
		cout << "2.Afisare studenti!" << endl;
		cout << "0.Iesire!" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Nume: ";
			cin >> nume;
			cout << "Rol: ";
			cin >> rol;
			cout << "Adresa: ";
			cin >> adresa;
			cout << "cod Postal: ";
			cin >> cod_postal;
			s = new Student(nume, rol, adresa, cod_postal);
			lista.push_back(s);
			break;
		case 2:
			for (auto p : lista)
				p->Afisare();
			break;
		default:
			break;
		}
	} while (opt != 0);
}