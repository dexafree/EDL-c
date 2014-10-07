#ifndef __LlistaAbstractaCorregida__Element__
#define __LlistaAbstractaCorregida__Element__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESPETIT        0
#define MESGRAN         1
#define IGUAL           2
#define DIFERENT        3
#define MESPETITOIGUAL  4
#define MESGRANOIGUAL   5

#define NUMCAMPS 4

enum CAMPS {
    NOM,
    EDAT,
    SEXE,
    ALTURA
};

typedef struct{
    char *nom;
    int edat;
    char sexe;
    float alt;
} Element;

typedef int (*comparacio)(Element, Element, int);

void ELEMENT_crea(Element *el, char *nom, int edat, char sexe, float alt);
int ELEMENT_compara (Element e1, Element e2, enum CAMPS quin, int tip);
void ELEMENT_destrueix(Element *el);
int ELEMENT_quantsCamps();
void ELEMENT_debugElement(Element e);

#endif
