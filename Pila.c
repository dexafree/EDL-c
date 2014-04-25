#include "pila.h"

Pila PILA_create(){
	return NULL;
}

void PILA_push(Pila *p, Element e){
	Node *aux = (Node *) malloc (sizeof(Node));
	if (aux!=NULL){
		(*aux).element=e;
		(*aux).next=*p;
		*p=aux;
	}else{
		printf("\nPUSH error\n");
	}
}

void PILA_pop(Pila *p){
	Node *aux;
	if (p!=NULL){
		aux=*p;
		*p=(*p)->next;
		free(aux);
	}else{
		printf("\nPOP error\n");
	}
}

Element PILA_top(Pila p){
	Element e = ELEMENT_indefinit();
	if(p!=NULL){
		e = (*p).element; // e->element
	}
	return e;
}

int PILA_empty(Pila p){
	return p==NULL;
}

void PILA_destroy(Pila *p){
	Node *aux;
	while(*p != NULL){
		aux = *p;
		*p = (*p)->next;
		free(aux);
	}
	*p = NULL
}