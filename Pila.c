/*
 * ARCHIVO DE IMPLEMENTACIÓN DE FUNCIONES DE UNA PILA DINÁMICA EN C
 * 
 * La pila sigue un esquema LIFO (Last In-First Out)
 * 
 * Por tal de hacerla genérica, se hablará de variables de tipo Element,
 * el cual a la hora de usarse en un programa real deberá sustituirse por
 * el tipo de variables que vaya a contener la pila (int, char, float, tipos propios...)
 *
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 */

#include "Pila.h"


/*
 * Devuelve una nueva instancia de Pila
 *
 * Parámetros: No recibe
 * Retorno: Instancia de Pila
 */
Pila PILA_create () {

	// Al iniciar la pila, devolveremos un valor nulo, ya que estará vacía
	return NULL;

}


/*
 * Introduce un elemento en la pila, en la posición más alta
 * 
 * Parámetros:
 *    + Pila *p: Pila a modificar pasada por referencia (ya que la modificaremos)
 *    + Element e: Elemento a introducir
 *
 * Retorno: No devuelve nada
 */
void PILA_push (Pila *p, Element e) {

	/*
	 * Nos creamos un nodo auxiliar, que será el que introduciremos realmente en la pila
	 * y pedimos memoria
	 */
	Node *aux = (Node *) malloc  (sizeof (Node) );

	// Comprovamos si la asignación de memoria se ha realizado con éxito
	if (aux != NULL) {


	 	aux->element = e; // Asignamos al contenido del nodo el elemento que hemos recibido
		aux->next = *p; // Asignamos al campo next la dirección de memoria del nodo que ahora quedará en segunda posición (desde arriba)
		*p = aux; // Asignamos el contenido de la pila (dirección del último elemento) a aux, elemento que ahora está en la posición más alta

	} else {

		//En caso de asignación fallida, mostramos error
		printf ("\nPUSH error\n");

	}

}

/*
 * Elimina el último elemento introducido en la pila
 *
 * Parámetros:
 *    + Pila *p: Pila a modificar pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void PILA_pop (Pila *p) {

	// Creamos un nodo auxiliar para almacenar el contenido temporalmente
	Node *aux;

	if (p != NULL) {

		aux = *p; // Asignamos al nodo auxiliar la dirección de memoria del último elemento (superior)

		/*
		 * Asignamos a la pila (realmente es la dirección de memoria del último elemento) la del elemento
		 * immediatamente inferior, de modo que ahora la pila referencia a ese elemento
		 */
		*p = (*p)->next; 

		/*
		 * Liberamos la memoria correspondiente al último elemento, cuya dirección se
		 * encontraba ahora guardada en aux
		 */
		free (aux); 

	} else {

		printf ("\nPOP error\n"); // En el caso de que la pila estuviera vacía, mostramos error

	}

}

/*
 * Devuelve el último elemento introducido en la pila
 *
 * Parámetros:
 *    + Pila p: Pila a modificar pasada por valor (no será necesario modificarla)
 *
 * Retorno: Elemento en la posición más alta de la pila (último introducido)
 */
Element PILA_top (Pila p) {

	Element e = ELEMENT_indefinit (); // Creamos una nueva instancia e de Elemento

	if (p != NULL) {

		/*
		 * Si la pila no está vacía, almacenamos en e el contenido del elemento situado
		 * en la dirección de memoria a la que apunta la pila, que recordemos, es la del
		 * elemento situado en la parte superior de la pila
		 */
		e = p->element; 

	}

	return e; // Devolvemos e

}

/*
 * Indica si la pila está vacía o no
 * Parámetros:
 *    + Pila p: Pila a comprobar pasada por valor (no será necesario modificarla)
 *
 * Retorno:
 *    1 Si está vacía
 *    0 Si no está vacía
 */
int PILA_empty (Pila p) {

	return p == NULL; // Devolvemos el resultado de la comprobación de si p apunta a nulo

}

void PILA_destroy (Pila *p) {

	Node *aux; // Creamos un nuevo nodo auxiliar

	// Ejecutamos el bucle mientras p no apunte a nulo
	while (*p != NULL) {

		aux = *p; // Almacenamos en el nodo auxiliar la dirección de memoria del último elemento
		*p =  (*p)->next; // Hacemos que ahora la pila apunte al elemento immediatamente inferior
		free (aux); // Liberamos la parte de memoria correspondiente al elemento superior
	}

	*p = NULL; // Forzamos que p apunte a nulo

}