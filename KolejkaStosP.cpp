#include <iostream>
#include <chrono>
#include "Common.h"
#include "KolejkaStosP.h"
using namespace std;

Element* newElement(int value) {
	Element* element = new Element;
	element->value = value;
	element->next = NULL;
	return element;
}

void zakolejkujP(ListP* lista, int wartosc) {
	//Tutaj dokonaj implementacji funkcji
	Element* nowy = newElement(wartosc);  //t1
	if (lista->first != NULL) { 
		if (lista->last != NULL) { 
			lista->last->next = nowy;
			lista->last = nowy;
		}
		else {
			lista->first->next = nowy;
			lista->last = nowy;
		}
	}
	else {
		lista->first = nowy;
	}
	lista->rozmiar++;
}

int odkolejkujP(ListP* lista) {
	//Tutaj dokonaj implementacji funkcji
	int element = lista->first->value;
	lista->first = lista->first->next;
	return element;
}

void wrzucNaStosP(ListP* lista, int wartosc) {
	//Tutaj dokonaj implementacji funkcji
	Element* nowy = newElement(wartosc);  //t1
	if (lista->last != NULL) {
		if (lista->first != NULL) {
			nowy->next = lista->first;
			lista->first = nowy;
		}
		else {
			nowy->next = lista->last;
			lista->first = nowy;
		}
	}
	else {
		lista->last = nowy;
	}
	lista->rozmiar++;
}

int zdejmujZeStosuP(ListP* lista) {
	//Tutaj dokonaj implementacji funkcji
	int element = lista->first->value;
	lista->first = lista->first->next;
	return element;
}

void KolejkaStosPTest() {
	cout << "test kolejka-stos z lista wskaznikowa" << endl;
	int numRep = 10000;
	ListP* kolejka = newPList();
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < numRep; i++) {
		zakolejkujP(kolejka, i);
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	bool chk = true;
	for (int i = 1; i < numRep; i++) {
		int val = odkolejkujP(kolejka);
		if (val != i) {
			chk = false;
			break;
		}
	}
	auto t3 = std::chrono::high_resolution_clock::now();
	cout << "Kolejka Wynik: " << (chk ? "OK" : "Blad") << endl;

	auto t21 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	auto t32 = std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count();
	cout << "Czas wykonania: " << t21 << " | " << t32 << endl;

	destroyPList(kolejka);

	ListP* stos = newPList();
	auto st1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < numRep; i++) {
		wrzucNaStosP(stos, i);
	}
	auto st2 = std::chrono::high_resolution_clock::now();
	bool chkS = true;
	for (int i = numRep - 1; i > 0; i--) {
		int val = zdejmujZeStosuP(stos);
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

	destroyPList(stos);
}