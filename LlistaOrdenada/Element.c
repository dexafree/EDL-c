#include "Element.h"

void ELEMENT_debugElement(Element e){
    printf("\nDEBUG: %s:%d:%c:%.2f\n", e.nom, e.edat, e.sexe, e.alt);
}

int comparaNom(Element e1, Element e2, int tip){

    switch (tip) {
        case MESPETIT:
            return (strcmp(e1.nom, e2.nom) < 0 );
        case MESGRAN:
            return (strcmp(e1.nom, e2.nom) > 0);
        case IGUAL:
            return (strcmp(e1.nom, e2.nom) == 0);
        case DIFERENT:
            return (strcmp(e1.nom, e2.nom) != 0);
        case MESPETITOIGUAL:
            return (strcmp(e1.nom, e2.nom) <= 0 );
        case MESGRANOIGUAL:
            return (strcmp(e1.nom, e2.nom) >= 0);
        default:
            return -1;
    }

}

int comparaEdat(Element e1, Element e2, int tip){

    switch (tip) {
        case MESPETIT:
            return (e1.edat < e2.edat);
        case MESGRAN:
            return (e1.edat > e2.edat);
        case IGUAL:
            return (e1.edat == e2.edat);
        case DIFERENT:
            return (e1.edat != e2.edat);
        case MESPETITOIGUAL:
            return (e1.edat <= e2.edat);
        case MESGRANOIGUAL:
            return (e1.edat >= e2.edat);
        default:
            return -1;
    }

}

int comparaAltura(Element e1, Element e2, int tip){

    switch (tip) {
        case MESPETIT:
            return (e1.alt < e2.alt);
        case MESGRAN:
            return (e1.alt > e2.alt);
        case IGUAL:
            return (e1.alt == e2.alt);
        case DIFERENT:
            return (e1.alt != e2.alt);
        case MESPETITOIGUAL:
            return (e1.alt <= e2.alt);
        case MESGRANOIGUAL:
            return (e1.alt >= e2.alt);
        default:
            return -1;
    }

}

int comparaSexe(Element e1, Element e2, int tip){

    switch (tip) {
        case MESPETIT:
            return e1.sexe < e2.sexe;
        case MESGRAN:
            return e1.sexe > e2.sexe;
        case IGUAL:
            return e1.sexe == e2.sexe;
        case DIFERENT:
            return e1.sexe != e2.sexe;
        case MESPETITOIGUAL:
            return e1.sexe <= e2.sexe;
        case MESGRANOIGUAL:
            return e1.sexe >= e2.sexe;
        default:
            return -1;
            break;
    }

}

int ELEMENT_compara(Element e1, Element e2, enum CAMPS quin, int tip){

    switch (quin) {
        case NOM:
            return (comparaNom(e1, e2, tip));
        case EDAT:
            return(comparaEdat(e1, e2, tip));
        case SEXE:
            return(comparaSexe(e1, e2, tip));
        case ALTURA:
            return (comparaAltura(e1, e2, tip));
        default:
            return -1;
            break;
    }

}

void ELEMENT_crea(Element *el, char *nom, int edat, char sexe, float alt){

    el->nom = nom;
    el->edat = edat;
    el->sexe = sexe;
    el->alt = alt;

}

void ELEMENT_destrueix(Element *el){

}

int ELEMENT_quantsCamps(){
    return NUMCAMPS;
}
