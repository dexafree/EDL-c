/*
 * ARCHIVO DE CABECERAS DE FUNCIONES DE UNA LISTA DINÁMICA BIDIRECCIONAL EN C
 * 
 * La lista no sigue ningún esquema de movimiento definido (ni LIFO ni FIFO)
 *
 * Por tal de movernos por ella, iremos moviendo un cursor (PDI), el cual puede
 * desplazarse hacia delante (de uno en uno), hacia atrás o moverse al inicio
 * Podremos recuperar el elemento en el que se encuentre el PDI
 * 
 * Con el objetivo de hacerla genérica, se hablará de variables de tipo Element,
 * el cual a la hora de usarse en un programa real deberá sustituirse por
 * el tipo de variables que vaya a contener la lista (int, char, float, tipos propios...)
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
	} Node;

	/*
	 * Definición del tipo Lista
	 *
	 * La lista como tal será un struct que contendrá:
	 *    + La dirección de memoria del primer elemento de la lista
	 *    + La dirección de memoria del elemento immediatamente anterior al PDI
	 */
	typedef struct{
		Node *first; // Contiene la dirección de memoria del primer nodo (elemento), para poder volver a él (será un elemento no utilizable)
		Node *last; // Contiene la dirección de memoria del último nodo (elemento), para poder volver a él (será un elemento no utilizable)
		Node *pdi; // Contiene la dirección de memoria del PDI. Ahora lo hacemos así, ya que necesitaremos tenerlo guardado aparte de los otros dos
	} Lista;


	/*
	 * Devuelve una nueva instancia de Lista
	 *
	 * Parámetros: No recibe
	 * Retorno: Instancia de Lista
	 */
	Lista LISTA_create();

	/*
	 * Introduce un elemento en la lista, en la posición immediatamente siguiente al elemento del PDI
	 * 
	 * Parámetros:
	 *    + Lista *l: Lista a modificar pasada por referencia (ya que la modificaremos)
	 *    + Element e: Elemento a introducir
	 *
	 * Retorno: No devuelve nada
	 */
	void LISTA_insertForward(Lista *l, Element e);

	/*
	 * Introduce un elemento en la lista, en la posición immediatamente interior al elemento del PDI
	 * 
	 * Parámetros:
	 *    + Lista *l: Lista a modificar pasada por referencia (ya que la modificaremos)
	 *    + Element e: Elemento a introducir
	 *
	 * Retorno: No devuelve nada
	 */
	void LISTA_insertBehind(Lista *l, Element e);


	/*
	 * Elimina el elemento marcado por el PDI en la lista
	 *
	 * Parámetros:
	 *    + Lista *l: Lista a modificar pasada por referencia (ya que la modificaremos)
	 *
	 * Retorno: No devuelve nada
	 */
	void LISTA_delete(Lista *l);


	/*
	 * Devuelve el elemento marcado por el PDI dentro de la lista
	 *
	 * Parámetros:
	 *    + Lista l: Lista de la cual obtener el elemento
	 *
	 * Retorno: Elemento en la posición marcada por el PDI dentro de la lista
	 */
	Element LISTA_get(Lista l);


	/*
	 * Indica si la lista está vacía o no
	 * Parámetros:
	 *    + Lista l: Lista a comprobar pasada por valor (no será necesario modificarla)
	 *
	 * Retorno:
	 *    1 Si está vacía
	 *    0 Si no está vacía
	 */
	int LISTA_empty(Lista l);

	/*
	 * Mueve el PDI al inicio de la lista
	 *
	 * Parámetros:
	 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
	 */
	void LISTA_goToStart(Lista *l);

	/*
	 * Mueve el PDI al final de la lista
	 *
	 * Parámetros:
	 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
	 */
	void LISTA_goToEnd(Lista *l);

	/*
	 * Mueve el PDI a la posición immediatamente siguiente
	 *
	 * Parámetros:
	 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
	 */
	void LISTA_forward(Lista *l);

	/*
	 * Mueve el PDI a la posición immediatamente anterior
	 *
	 * Parámetros:
	 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
	 */
	void LISTA_behind(Lista *l);

	/*
	 * Indica si el PDI de la lista está ubicado en el último elemento
	 * Parámetros:
	 *    + Lista l: Lista a comprobar pasada por valor (no será necesario modificarla)
	 *
	 * Retorno:
	 *    1 Si es el último elemento
	 *    0 Si no es el último elemento
	 */
	int LISTA_end(Lista l);

	/*
	 * Indica si el PDI de la lista está ubicado en el primer elemento
	 * Parámetros:
	 *    + Lista l: Lista a comprobar pasada por valor (no será necesario modificarla)
	 *
	 * Retorno:
	 *    1 Si es el primer elemento
	 *    0 Si no es el primer elemento
	 */
	int LISTA_start(Lista l);


	/*
	 * Destruye el contenido de la lista
	 *
	 * Parámetros:
	 *    + Lista *l: Lista a destruir pasada por referencia (ya que la modificaremos)
	 *
	 * Retorno: No devuelve nada
	 */
	void LISTA_destroy(Lista *l);