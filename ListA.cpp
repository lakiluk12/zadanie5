#include <iostream>
#include "Common.h"
#include "ListA.h"

using namespace std;

ListA* newAList() {
	ListA* list = new ListA;
	list->tabSize = 5;
	list->tab = new int[list->tabSize];
	list->counter = 0;
	return list;
}

void destroyAList(ListA* list) {
	if (list != nullptr) {
		delete[] list->tab;
		delete list;
	}
}

void resize(ListA* list) {
	//To jest funkcja pomocnicza, słuzaca do zmiany rozmiaru tablicy
	int* tab = new int[list->tabSize + 1];
	for (int i = 0; i < list->tabSize; i++) { //n*
		tab[i] = list->tab[i]; //t 
	}
	delete[] list->tab;
	list->tabSize++;
	list->tab = tab;
}//o(n)

void addToAList(ListA* list, int value) {
	//Tutaj dokonaj implementacji funkcji
	if (list->counter >= list->tabSize) {
		resize(list);
	}
		list->tab[list->counter] = value;
		list->counter++;
}//o(1)

int getFromAList(ListA* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	if (index >= list->counter) {
		return NaN;
	}
	return list->tab[index];
}

int removeFromAList(ListA* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	if (index >= list->counter) {
		return NaN;
	}
	for (int i = index; i < list->counter; i++) {
		list->tab[i] = list->tab[i + 1];
	}
	list->counter--;
	return 1;
}

int sizeA(ListA* list) {
	return list->counter;
}

auto_ptr<IteratorA> getAIterator(ListA* list) {
	//Tutaj dokonaj implementacji funkcji
	IteratorA* iter = new IteratorA;
	iter->list = list;
	iter->counter = 0;
	return auto_ptr<IteratorA>(iter);
}

int iterateA(IteratorA* iterator) {
	//Tutaj dokonaj implementacji funkcji
	if (iterator->counter > iterator->list->counter) {
		return NaN;
	}
	int index = iterator->counter;
	iterator->counter++;
	return iterator->list->tab[index];
}
