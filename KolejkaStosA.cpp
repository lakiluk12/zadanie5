#include <iostream>
#include <chrono>
#include "Common.h"
#include "KolejkaStosA.h"

using namespace std;
void zakolejkujA(ListA* lista, int wartosc) {
	//Tutaj dokonaj implementacji funkcji
	if (lista->counter >= lista->tabSize) {
		int* tab = new int[lista->tabSize + 1];
		for (int i = 0; i < lista->tabSize; i++) { //n*
			tab[i] = lista->tab[i]; //t 
		}
		delete[] lista->tab;
		lista->tabSize++;
		lista->tab = tab;
	}
	lista->tab[lista->counter] = wartosc;
	lista->counter++;
}
int odkolejkujA(ListA* lista) {
	//Tutaj dokonaj implementacji funkcji
	int element = lista->tab[0];
		for (int i = 1; i < lista->counter; i++) { //n*
			lista->tab[i-1] = lista->tab[i]; //t 
		}
		lista->counter--;
		return element;
}
void wrzucNaStosA(ListA* lista, int wartosc) {
	//Tutaj dokonaj implementacji funkcji
	if (lista->counter >= lista->tabSize) {
		int* tab = new int[lista->tabSize + 1];
		for (int i = 0; i < lista->tabSize; i++) { //n*
			tab[i] = lista->tab[i]; //t 
		}
		delete[] lista->tab;
		lista->tabSize++;
		lista->tab = tab;
	}
	lista->tab[lista->counter] = wartosc;
	lista->counter++;
}

int zdejmujZeStosuA(ListA* lista) {
	//Tutaj dokonaj implementacji funkcji
	lista->counter--;
	return lista->tab[lista->counter];
}

void KolejkaStosATest() {
	cout << "Test kolejka-stos z lista tablicowa" << endl;
	int numRep = 10000;
	ListA* kolejka = newAList();
	auto t1 = std::chrono::high_resolution_clock::now();		
	for (int i = 1; i < numRep; i++) {
		zakolejkujA(kolejka, i);
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	bool chk = true;
	for (int i = 1; i < numRep; i++) {
		int val = odkolejkujA(kolejka);
		if (val != i) {
			chk = false;
			break;
		}
	}
	auto t3 = std::chrono::high_resolution_clock::now();
	cout << " Kolejka wynik: " << (chk ? "OK" : "Blad") << endl;

	auto t21 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	auto t32 = std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count();
	cout << "Czas wykonania: " << t21 << " | " << t32 << endl;

	destroyAList(kolejka);

	ListA* stos = newAList();
	auto st1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < numRep; i++) {
		wrzucNaStosA(stos, i);
	}
	auto st2 = std::chrono::high_resolution_clock::now();
	bool chkS = true;
	for (int i = numRep-1; i > 0; i--) {
		int val = zdejmujZeStosuA(stos);
		if (val != i) {
			chkS = false;
			break;
		}
	}
	auto st3 = std::chrono::high_resolution_clock::now();
	cout << " Stos wynik: " << (chkS ? "OK" : "Blad") << endl;

	auto st21 = std::chrono::duration_cast<std::chrono::microseconds>(st2 - st1).count();
	auto st32 = std::chrono::duration_cast<std::chrono::microseconds>(st3 - st2).count();
	cout << "Czas wykonania: " << st21 << " | " << st32 << endl;

	destroyAList(stos);
}