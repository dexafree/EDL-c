#ifndef _PILA_H_
	#define _PILA_H_

	typedef struct N{
		Element element;
		struct N *next;
	} Node;

	typedef Node *Pila;

	Pila PILA_create();
	void PILA_push(Pila *p, Element e);
	void PILA_pop(Pila *p);
	Element PILA_top(Pila p);
	int PILA_empty(Pila p);
	void PILA_destroy(Pila *p);

	#endif
