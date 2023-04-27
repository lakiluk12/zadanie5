#include <iostream>
#include "Common.h"
#include "ListP.h"

using namespace std;

//Element* newElement(int value);

ListP* newPList() {
	ListP* list = new ListP;
	list->first = NULL;
	list->last = NULL;
	list->rozmiar = 0;
	return list;
}

void destroyPList(ListP* list) {
	if (list != NULL) {
		while (list->first != NULL) {
			Element* curr = list->first;
			if (list->first == list->last) list->first = NULL;
			else list->first = list->first->next;
			delete curr;
		}
		delete list;
	}
}

//void addToPList(ListP* list, int value) {
//	//Tutaj dokonaj implementacji funkcji
//	Element* nowy = newElement(value);
//	if (list->first != NULL) { //t1
//		if (list->last != NULL) { //t2
//			list->last->next = nowy;
//			list->last = nowy;
//		}
//		else {
//			list->first->next = nowy;
//			list->last = nowy;
//		}
//	}
//	else {
//		list->first = nowy;
//	}
//	list->rozmiar++;
//}//    O(1)

Element* search(ListP* list, int value) {
	//Tutaj dokonaj implementacji funkcji
	Element* curr = list->first;
	Element* prev = NULL;
	while (curr != NULL && curr->value != value) {//n
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL) {//t
		return nullptr;
	}
	else {
		return curr;
	}
}//		O(n) 

int getFromPList(ListP* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	Element* curr = list->first;
	Element* prev = NULL;
	int i = 0;
	if (index >= list->rozmiar) { // t
		return NaN;
	}
	while (curr != NULL && i < index) {//n
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (curr == NULL) {		//t2
		return NULL;
	}
	else {
		return curr->value;
	}
}//	n+t+t2		O(n)

//Element* newElement(int value) {
//	Element* element = new Element;
//	element->value = value;
//	element->next = NULL;
//	return element;
//}

int removeFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int i = 0;
	Element* prev = NULL;
	while (curr != NULL && i < index) {
		prev = curr;
		curr = curr->next;
		i++;
	}
	int value;
	if (curr == NULL) { //Będzie null jeśli lista jest pusta
		list->last = prev;
		value = NaN;
	}
	else { 
		if (prev != NULL) { //Sprawdzant czy to nie pierwszy element listy		
			prev->next = curr->next;			
		}
		else {
			list->first = curr->next;
		}		
		if (curr->next == NULL) { //Jak koniec kolejki
			list->last = prev;
		}
		value = curr->value;
		list->rozmiar--;
		delete curr;
	}
	return value;
}

int sizeP(ListP* list) {
	if (list!=NULL)
		return list->rozmiar;
	return NaN;
}

auto_ptr<IteratorP> getPIterator(ListP* list) { 
	//Tutaj dokonaj implementacji funkcji
	IteratorP* nowy = new IteratorP; 
	nowy->counter = 0;
	nowy->list = list;
	nowy->curr = list->first;
	return auto_ptr<IteratorP>(nowy);
}// O(1)

int iterateP(IteratorP* iterator) { 
	//Tutaj dokonaj implementacji funkcji
	Element* bierzacy = iterator->curr;
	iterator->curr = bierzacy->next;
	return 	bierzacy->value;
}// O(1)
