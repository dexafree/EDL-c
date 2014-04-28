/*
 * ARCHIVO DE CABECERAS DE FUNCIONES DE UNA COLA DINÁMICA EN C
 * 
 * La cola no sigue ningún esquema de movimiento definido (ni LIFO ni FIFO)
 *
 * Por tal de movernos por ella, iremos moviendo un cursor (PDI), el cual sólo
 * puede desplazarse hacia delante (de uno en uno) o moverse al inicio
 * Podremos recuperar el elemento en el que se encuentre el PDI
 * 
 * Con el objetivo de hacerla genérica, se hablará de variables de tipo Element,
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

#ifndef _LISTA_H_
	#define _LISTA_H_

 	/*
	 * Definición inicial de tipos
	 */
	typedef struct N {
		Element e; //Contendrá el elemento como tal
		struct N *next;  //Contendrá la dirección de memoria del siguiente elemento
	}Lista;

	/*
	 * Definición del tipo Cola
	 *
	 * La cola como tal será un struct que contendrá:
	 *    + La dirección de memoria del primer elemento de la cola
	 *    + La dirección de memoria del elemento immediatamente anterior al PDI
	 */
	typedef struct{
		Node *first; // Contiene la dirección de memoria del primer nodo (elemento), para poder volver a él
		Node *before; // Contiene la dirección de memoria del nodo (elemento) immediatamente anterior al PDI
	}


	/*
	 * Devuelve una nueva instancia de Lista
	 *
	 * Parámetros: No recibe
	 * Retorno: Instancia de Lista
	 */
	Lista LISTA_create();
	void LISTA_insert(Lista *l, Element e);
	void LISTA_delete(Lista *l);
	Element LISTA_get(Lista l);
	int LISTA_empty(Lista l);
	void LISTA_goToStart(Lista *l);
	void LISTA_forward(Lista *l);
	int LISTA_end(Lista l);
	void LISTA_destroy(Lista *l);