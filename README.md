EDL-c
=====

Estructuras de datos lineales en C

## Anotaciones previas
Por tal de hacer todas las estructuras genéricas, se hablará de variables de tipo Element, las cuales a la hora de usarse en un programa real deberán sustituirse por el tipo de variables que vaya a contener la pila (int, char, float, tipos propios...)

## Estructuras

* [Pila](#pila)
* [Cola](#cola)
* [Listas](#listas)
	* [General](#lista-general)
	* [Ordenada](#lista-ordenada)
	* [Bidireccional](#lista-bidireccional)


## Pila

### Esquema de movimiento
La pila sigue un esquema LIFO (Last In-First Out)

### Métodos

```c
/*
 * Devuelve una nueva instancia de Pila
 *
 * Parámetros: No recibe
 * Retorno: Instancia de Pila
 */
Pila PILA_create ();


/*
 * Introduce un elemento en la pila, en la posición más alta
 * 
 * Parámetros:
 *    + Pila *p: Pila a modificar pasada por referencia (ya que la modificaremos)
 *    + Element e: Elemento a introducir
 *
 * Retorno: No devuelve nada
 */
void PILA_push (Pila *p, Element e);


/*
 * Elimina el último elemento introducido en la pila
 *
 * Parámetros:
 *    + Pila *p: Pila a modificar pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void PILA_pop (Pila *p);


/*
 * Devuelve el último elemento introducido en la pila
 *
 * Parámetros:
 *    + Pila p: Pila a modificar pasada por valor (no será necesario modificarla)
 *
 * Retorno: Elemento en la posición más alta de la pila (último introducido)
 */
Element PILA_top (Pila p);


/*
 * Indica si la pila está vacía o no
 * Parámetros:
 *    + Pila p: Pila a comprobar pasada por valor (no será necesario modificarla)
 *
 * Retorno:
 *    1 Si está vacía
 *    0 Si no está vacía
 */
int PILA_empty (Pila p);


/*
 * Destruye el contenido de la pila
 *
 * Parámetros:
 *    + Pila *p: Pila a destruir pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void PILA_destroy (Pila *p);

```

## Cola

### Esquema de movimiento
La cola sigue un esquema FIFO (First In-First Out)

### Métodos

```c
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


/*
 * Devuelve el elemento situado en primera posición
 * 
 * Parámetros:
 *    + Cola c: Cola de la cual obtener el primer elemento
 *
 * Retorno: Elemento situado en el primer lugar de la cola
 */
Element COLA_first (Cola c);


/*
 * Indica si la cola está vacía o no
 * Parámetros:
 *    + Cola c: Cola a comprobar pasada por valor (no será necesario modificarla)
 *
 * Retorno:
 *    1 Si está vacía
 *    0 Si no está vacía
 */
int COLA_empty (Cola c);


/*
 * Destruye el contenido de la cola
 *
 * Parámetros:
 *    + Cola *c: Cola a destruir pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void COLA_destroy (Cola *c);
```


## Listas

## Lista general

### Esquema de movimiento

La lista no sigue ningún esquema de movimiento definido (ni LIFO ni FIFO).
La lista general sólo puede moverse hacia adelante y volver al inicio.
La posición actual estará marcada por un elemento al que llamaremos PDI, el cuál será la dirección de memoria del elemento immediatamente anterior al cual apuntará.

### Métodos

```c
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
void LISTA_insert(Lista *l, Element e);


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
 * Mueve el PDI a la posición immediatamente siguiente
 *
 * Parámetros:
 *	+ Lista *l: Lista a modificar pasada por referencia (ya que haremos una modificación a nivel interno)
 */
void LISTA_forward(Lista *l);

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
 * Destruye el contenido de la lista
 *
 * Parámetros:
 *    + Lista *l: Lista a destruir pasada por referencia (ya que la modificaremos)
 *
 * Retorno: No devuelve nada
 */
void LISTA_destroy(Lista *l);
```