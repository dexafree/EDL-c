/*
 * ARCHIVO DE IMPLEMENTACIÓN DE FUNCIONES DE UNA COLA DINÁMICA EN C
 * 
 * La cola sigue un esquema FIFO (Last In-First Out)
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

#include "Cola.h"

/*
 * Devuelve una nueva instancia de Cola
 *
 * Parámetros: No recibe
 * Retorno: Instancia de Cola
 */
Cola COLA_create () {
	Cola c; // Creamos una nueva variable de tipo cola
	c.first = (Node *) malloc (sizeof (Node) ); // Pedimos memoria para el primer elemento

	if (c.first == NULL) {

		// Si la asignación de memoria ha fallado, mostramos el error
		printf("Error al crear la cua\n");

	} else {

		c.first->e = ELEMENT_indefinit(); //Introducimos un elemento vacío en la cola
		c.first->next = NULL; // Apuntamos la dirección del siguiente elemento a nulo (ya que aún no existe)
		c.last = c.first; // Apuntamos la dirección del último elemento de la cola al primer elemento, ya que es el único

	}

	return c; // Devolvemos la cola preparada para ser usada

}


/*
 * Introduce un elemento al final de la cola, en última posición
 * 
 * Parámetros:
 *    + Cola *c: Cola a modificar pasada por referencia (ya que la modificaremos)
 *    + Element e: Elemento a introducir
 *
 * Retorno: No devuelve nada
 */
Cola COLA_enqueue (Cola *c, Element e) {

	Node *aux; // Creamos un nodo auxiliar
	aux = (Node*) malloc(sizeof(Node)); // Pedimos memoria para el elemento

	if(aux == NULL){

		// Si la asignación de memoria ha fallado, mostramos el error
		printf("Error al poner en cola\n");

	} else {

		aux->e = e; // Asignamos el valor nodo auxiliar al del elemento que hemos recibido
		aux->next = NULL; // Asignamos la dirección de memoria del siguiente elemento a nulo (ya que aún no existe)
		
		/*
		 * Asignamos la dirección de memoria del campo "next" del anterior "último elemento" a la
		 * del elemento auxiliar actual, ya que se convertirá en el último elemento
		 */
		c->last->next = aux;

		/*
		 * Apuntamos la dirección de memoria que indica el último elemento de la cola al elemento
		 * auxiliar actual, convirtiéndose así en el último elemento de la cola
		 */
		c->last = aux;

	}

}


/*
 * Elimina el último elemento introducido en la cola
 *
 * Parámetros:
 *    + Cola *p: Cola a modificar pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void COLA_dequeue(Cola *c){

	Node *aux; // Creamos un nodo auxiliar

	if(c->first->next == NULL){

		/*
		 * Si la dirección de memoria del siguiente elemento es un nulo, es
		 * señal de que no existe un siguiente elemento y mostramos error
		 */	
		printf("\nError al sacar de la cola, la cola está buida");

	} else {

		/*
		 * Hacemos que la dirección de memoria del nodo auxiliar que nos
		 * hemos creado sea la del elemento siguiente en la cola (lo guardamos)
		 */
		aux = c->first->next;

		/*
		 * Hacemos que la dirección de memoria del segundo elemento de la cola (first->next)
		 * apunte a la dirección de memoria del tercer elemento de la cola (first->next->next)
		 */
		c->first->next = c->first->next->next;

		/*
		 * Si la dirección de memoria del segundo elemento (first->next) es nulo (no existe),
		 * hacemos que la dirección de memoria del último elemento sea también el primero
		 */
		if (c->first->next == NULL) {
			c->last = c->first;
		}
		
		/*
		 * Liberamos la memoria correspondiente al elemento auxiliar
		 */
		free(aux); 

	}

}
