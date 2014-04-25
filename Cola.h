/*
 * ARCHIVO DE CABECERAS DE FUNCIONES DE UNA COLA DINÁMICA EN C
 * 
 * La cola sigue un esquema FIFO (First In-First Out)
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


#ifndef _COLA_H_
	#define _COLA_H_

	/*
	 * Definición inicial de tipos
	 */
	typedef struct N {
		Element e; // Contendrá el valor del elemento como tal
		struct N *next; // Contendrá la dirección de memoria del elemento immediatamente siguiente
	} Node;

	typedef struct{
		Node *first; // Contiene la dirección de memoria del primer nodo (elemento)
		Node *last;  // Contiene la dirección de memoria del último nodo (elemento) añadido
	} Cola;

	/*
	 * Devuelve una nueva instancia de Cola
	 *
	 * Parámetros: No recibe
	 * Retorno: Instancia de Cola
	 */
	Cola COLA_create ();


	/*
	 * Introduce un elemento al final de la cola, en última posición
	 * 
	 * Parámetros:
	 *    + Cola *c: Cola a modificar pasada por referencia (ya que la modificaremos)
	 *    + Element e: Elemento a introducir
	 *
	 * Retorno: No devuelve nada
	 */
	void COLA_enqueue (Cola *c, Element e);


	/*
	 * Elimina el último elemento introducido en la cola
	 *
	 * Parámetros:
	 *    + Cola *p: Cola a modificar pasada por referencia (ya que la modificaremos)
	 *
	 * Retorno: No devuelve nada
	 */
	void COLA_dequeue (Cola *c);


	
	Element COLA_front (Cola c);
	int COLA_empty (Cola c);
	void COLA_destroy (Cola *c);

	#endif