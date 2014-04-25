/*
 * ARCHIVO DE CABECERAS DE FUNCIONES DE UNA PILA DINÁMICA EN C
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

#ifndef _PILA_H_
	#define _PILA_H_
	

	/*
	 * Definición inicial de tipos
	 */
	typedef struct N {

		Element element; //Contendrá el elemento como tal
		struct N *next;  //Contendrá la dirección de memoria del siguiente elemento

	} Node;

	/*
	 * Definición del tipo Pila
	 *
	 * La pila como tal solo será una dirección de memoria del elemento situado en la
	 * parte superior de la misma (el último introducido), el cual a su vez, gracias a
	 * la definición hecha en el tipo Node, contendrá la del elemento immediatamente inferior
	 * en el campo next
	 */
	typedef Node *Pila;


	/*
	 * Devuelve una nueva instancia de Pila
	 *
	 * Parámetros: No recibe
	 * Retorno: Instancia de Pila
	 */
	Pila PILA_create();


	/*
	 * Introduce un elemento en la pila, en la posición más alta
	 * 
	 * Parámetros:
	 *    + Pila *p: Pila a modificar pasada por referencia (ya que la modificaremos)
	 *    + Element e: Elemento a introducir
	 *
	 * Retorno: No devuelve nada
	 */
	void PILA_push(Pila *p, Element e);


	/*
	 * Elimina el último elemento introducido en la pila
	 *
	 * Parámetros:
	 *    + Pila *p: Pila a modificar pasada por referencia (ya que la modificaremos)
	 *
	 * Retorno: No devuelve nada
	 */
	void PILA_pop(Pila *p);


	/*
	 * Devuelve el último elemento introducido en la pila
	 *
	 * Parámetros:
	 *    + Pila p: Pila a modificar pasada por valor (no será necesario modificarla)
	 *
	 * Retorno: Elemento en la posición más alta de la pila (último introducido)
	 */
	Element PILA_top(Pila p);


	/*
	 * Indica si la pila está vacía o no
	 * Parámetros:
	 *    + Pila p: Pila a comprobar pasada por valor (no será necesario modificarla)
	 *
	 * Retorno:
	 *    1 Si está vacía
	 *    0 Si no está vacía
	 */
	int PILA_empty(Pila p);


	/*
	 * Destruye el contenido de la pila
	 *
	 * Parámetros:
	 *    + Pila *p: Pila a destruir pasada por referencia (ya que la modificaremos)
	 *
	 * Retorno: No devuelve nada
	 */
	void PILA_destroy(Pila *p);

	#endif
