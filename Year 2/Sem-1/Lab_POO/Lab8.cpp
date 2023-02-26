#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class Lista;
class agentie {
private:
	int tip;
	char* nume;
	int pret;
	int tenis;
	agentie* urm;

public:
	agentie(int tp, char* n, int p, int t) {
		nume = new char[strlen(n) + 1];
		tip = tp;
		strcpy(nume, n);
		pret = p;
		tenis = t;
		urm = NULL;
	}
	virtual void afisare() {
		cout << "~~~~~~~~~~~~~~~~~~~\n";
		cout << "Nume: " << nume << endl;
		cout << "Pret: " << pret << endl;
		cout << "Teren tenis: " << tenis << endl;
	}
	friend class Lista;
};
class hotel :public agentie {
private:
	int nr_stele;
	int piscina;
	int sauna;

public:
	hotel(int tp, char* n, int p, int t, int s, int ps, int sn) :agentie(tp, n, p, t) {
		nr_stele = s;
		piscina = ps;
		sauna = sn;
	}
	void afisare() {
		agentie::afisare();
		cout << "Nr stele: " << nr_stele << endl;
		cout << "Piscina: " << piscina << endl;
		cout << "Sauna: " << sauna << endl;
	}
	friend class Lista;
};
class pensiune :public agentie {
private:
	int nr_margarete;
	int gradina;

public:
	pensiune(int tp, char* n, int p, int t, int m, int g) :agentie(tp, n, p, t) {
		nr_margarete = m; 
		gradina = g;
	}

	void afisare() {
		agentie::afisare();
		cout << "Nr magarete: " << nr_margarete << endl;
		cout << "Gradina: " << gradina << endl;
	}
	friend class Lista;
};
class Lista {
public:
	agentie* head;
	void adaugare(agentie* a);
	void afisare_lista();
};

class MyException {
public:
	char str_what[80];
	int what;
	MyException() {
		*str_what = 0;
		what = 0;
	}
	MyException(char* s, int e) {
		strcpy(str_what, s);
		what = e;
	}
};

void Lista::adaugare(agentie* a) {
	agentie* p;
	p = head;
	if (p) {
		if (strcmp(a->nume, p->nume) < 0) {
			a->urm = head;
			head = a;
		}
		else {
			while (p->urm && strcmp((p->urm)->nume, a->nume) < 0) {
				p = p->urm;
			}
		}
	}
}