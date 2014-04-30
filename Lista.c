/*
 * ARCHIVO DE IMPLEMENTACIÓN DE FUNCIONES DE UNA COLA DINÁMICA EN C
 * 
 * La cola no sigue ningún esquema de movimiento definido (ni LIFO ni FIFO)
 * 
 * Por tal de hacerla genérica, se hablará de variables de tipo Element,
 * el cual a la hora de usarse en un programa real deberá sustituirse por
 * el tipo de variables que vaya a contener la cola (int, char, float, tipos propios...)
 *
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 */

#include "Lista.h"


/*
 * Devuelve una nueva instancia de Lista
 *
 * Parámetros: No recibe
 * Retorno: Instancia de Lista
 */
Lista LISTA_create (){

	Lista l; // Declaramos la lista que devolveremos

	l.first = (Node *) malloc (sizeof (Node)); // Asignación de memoria

	if (l.first == NULL) {

		printf("Error al crear la lista\n"); // Mostramos error si no se ha hecho la asignación correctamente

	} else {

		l.first->e = ELEMENT_indefinit(); // Asignamos un elemento indefinido al primer elemento de la cola
		l.first->next = NULL; // Apuntamos el campo next del primer elemento de la cola a NULL (ya que no existe todavía)
		l.before = l.first; // Como es el primer elemento, hacemos que el primero sea el mismo que el último

	}

	return l; // Devolvemos la lista

}


/*
 * Inserta un elemento en la lista justo antes del PDI
 *
 * Parámetros: 
 *    + Lista *l: Lista a modificar pasada por referencia (ya que la modificaremos)
 *    + Element e: Elemento a insertar justo antes del PDI
 *
 * Retorno: No devuelve nada
 */
void LISTA_insert (Lista *l, Element e) {
	
	Node *aux; // Declaramos el nodo auxiliar

	aux = (Node *) malloc (sizeof (Node)); // Asignación de memoria

	if (aux == NULL) {

		printf("Error al insertar\n"); // Si ha habido un error en la asignación de memoria, mostramos el error

	} else {

		aux->e = e; // Asignamos el valor del nodo auxiliar
		aux->next = l->before->next; // Apuntamos el campo next del auxiliar al PDI actual
		l->before->next = aux; 
		l->before = aux; 

	}

}


/*
 * Elimina el elemento marcado por el PDI en la lista
 *
 * Parámetros:
 *    + Lista *l: Lista a modificar pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void LISTA_delete (Lista *l, Element e) {

	Node *aux;

	if (l->before->next == NULL) {

		printf("Error al insertar\n");

	} else {

		aux = l->before->next;
		l->before->next = aux->next;
		free(aux);

	}

}


/*
 * Devuelve el elemento marcado por el PDI dentro de la lista
 *
 * Parámetros:
 *    + Lista l: Lista de la cual obtener el elemento
 *
 * Retorno: Elemento en la posición marcada por el PDI dentro de la lista
 */
Element LISTA_get (Lista l){

	Element e = ELEMENT_indefinit();

	if (l.before->next != NULL) {

		e = l.before->next->e;

	}

	return e;
}


/*
 * Indica si la lista está vacía o no
 * Parámetros:
 *    + Lista l: Lista a comprobar pasada por valor (no será necesario modificarla)
 *
 * Retorno:
 *    1 Si está vacía
 *    0 Si no está vacía
 */
int LISTA_empty (Lista l){

	return l.first->next == NULL;

}


/*
 * Mueve el PDI al inicio de la lista
 *
 * Parámetros:
 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
 */
void LISTA_goToStart (Lista *l){

	l->before = l->first;

}


/*
 * Mueve el PDI a la posición immediatamente siguiente
 *
 * Parámetros:
 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
 */
void LISTA_forward (Lista *l){

	if(l->before->next != NULL){

		l->before = l->before->next;

	}

}


/*
 * Indica si el PDI de la lista está ubicado en el último elemento
 * Parámetros:
 *    + Lista l: Lista a comprobar pasada por valor (no será necesario modificarla)
 *
 * Retorno:
 *    1 Si es el último elemento
 *    0 Si no es el último elemento
 */
int LISTA_end (Lista l){

	return l.before->next == NULL;

}


/*
 * Destruye el contenido de la lista
 *
 * Parámetros:
 *    + Lista *l: Lista a destruir pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void LISTA_destroy (Lista *l){

	Node *aux;

	while(l->first != NULL){

		aux = l->first;
		l->first = l->first->next;
		free(aux);
	}

}