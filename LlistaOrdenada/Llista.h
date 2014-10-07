#ifndef __LlistaAbstractaCorregida__Llista__
#define __LlistaAbstractaCorregida__Llista__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element.h"

typedef struct N {
    Element e;
    struct N **next;
} Node;

typedef struct {
    Node *pri;
    int quants;
    int *numOrdenacion;
    char *tipusOrdenacion;
    Node **ant;
} Llista;

void LLISTA_crea(Llista *l, int quants, char *conf);

/* conf: "1>2<"
 *
 * Camp 1 decreixent
 * Camp 2 creixent
 */

/* Passant "1>2<" passara a:
 *  numOrdenacion[0] = 1
 *  numOrdenacion[1] = 2
 *
 *  tipusOrdenacion[0] = >
 *  tipusOrdenacion[1] = <
 *
 *  tipusOrdenacion es fa servir com a array de caracter, no com a cadena
 */


int LLISTA_numOrdenacions(Llista l);

void LLISTA_destrueix(Llista *l);

void LLISTA_insereix(Llista *l, Element e);

void LLISTA_esborra(Llista *l, int q);

void LLISTA_forward(Llista *l, int q);

Element LLISTA_consulta(Llista l, int q);

void LLISTA_vesInici(Llista *l, int quin);

void LLISTA_totsInici(Llista *l);

int LLISTA_esFinal(Llista l, int quin);

#endif /* defined(__LlistaAbstractaCorregida__Llista__) */
