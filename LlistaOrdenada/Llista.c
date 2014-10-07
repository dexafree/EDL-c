#include "Llista.h"

void throwError(char *error){

    printf("\n%s\n", error);

}

int charToNumber(char number){

    return number - '0';

}

int getTipusOrdenacio(char tipus){

    switch (tipus) {
        case '<':
            return MESPETIT;
        case '>':
            return MESGRAN;
        default:
            return IGUAL;
    }

}


int isNumber(char caracter){

    return (caracter >= 48 && caracter <= 57);

}

int isConfValid(char *conf, int quants){

    int len = (int)strlen(conf);

    if(len/2 == quants){
        if(len%2==0){

            int i;

            for(i=0; i<len; i++){
                if(i%2 == 0){
                    if(!isNumber(conf[i])) {
                        throwError("ES ESTE1");
                        return 0;
                    } else {
                        if(charToNumber(conf[i]) > NUMCAMPS){
                            throwError("ORDENACIO NO SUPORTADA");
                            printf("\nERROR DONAT A %d, el seu caracter era %c", i, conf[i]);
                        }
                    }
                } else {
                    if(conf[i] != '<' && conf[i] != '>') {
                        throwError("ES ESTE2");
                        return 0;
                    }
                }
            }

            return 1;

        } else {
            throwError("LONGITUD INVALIDA");
            return 0;
        }
    } else {
        throwError("ERROR DE LEN");
        printf("\nLEN: %d\n", len/2);
        printf("\nQUANTS: %d\n", quants);
        return 0;
    }

}

Element LLISTA_consulta(Llista l, int q){

    return l.ant[q]->next[q]->e;

}

int LLISTA_numOrdenacions(Llista l){
    return l.quants;
}


void LLISTA_crea(Llista *l, int quants, char *conf){

    if(isConfValid(conf, quants)){

        if(l != NULL){
            l->quants = quants;

            int i;

            l->numOrdenacion = (int*)malloc(sizeof(int)*quants);
            l->tipusOrdenacion = (char*)malloc(sizeof(char)*quants);

            for(i=0;i<quants;i++){
                l->numOrdenacion[i] = charToNumber(conf[i*2]);
                l->tipusOrdenacion[i] = conf[(i*2)+1];
            }

            Node *first = (Node*) malloc(sizeof(Node));

            if(first != NULL){

                Element e1;
                ELEMENT_crea(&e1, "UNDEFINED", 0, 'H', 0.00);

                first->e = e1;

                first->next = (Node**)malloc(sizeof(Node*)*quants);

                if(first->next != NULL){

                    for(i=0;i<quants;i++){
                        first->next[i] = NULL;
                    }

                    l->pri = first;
                    l->ant = (Node**)malloc(sizeof(Node*)*quants);

                    if(l->ant != NULL){

                        for(i=0;i<quants;i++){
                            l->ant[i] = first;
                        }

                    } else {
                        for(i=0;i<quants;i++){
                            free(first->next[i]);
                        }
                        free(first);
                        free(l);
                        throwError("ERROR MEMORIA ANT");
                    }

                } else {
                    free(first);
                    free(l);
                    throwError("ERROR MEMORIA POINTERPOINTER");
                }

            } else {
                free(l);
                throwError("ERROR MEMORIA NODE");
            }

        } else {
            throwError("ERROR MEMORIA LLISTA");
        }

    } else {
        throwError("CONF NO VALID");
    }

}


void posicionaLlista(Llista *l, Element e){

    int i;

    for(i=0;i<l->quants;i++){
        l->ant[i] = l->pri;
    }

    ELEMENT_debugElement(e);

    for(i=0;i<l->quants;i++){

        int numOrdenacion = l->numOrdenacion[i];

        if(((l->ant[i])->next[i]) != NULL){

            if(l->ant[i] == NULL){
                throwError("ERROR 1");
            }
            if((l->ant[i])->next[i] == NULL){
                throwError("ERROR 2");
            }

            printf("\nDEBUG. TIPUSORDENACIO[%d]: %d\n", i , getTipusOrdenacio(l->tipusOrdenacion[i]));


            while((l->ant[i])->next[i] != NULL && ELEMENT_compara(e, (l->ant[i])->next[i]->e, numOrdenacion, getTipusOrdenacio(l->tipusOrdenacion[i]))){

                l->ant[i] = (l->ant[i])->next[i];

            }
        }

    }

}

void LLISTA_insereix(Llista *l, Element e){

    int i;

    Node *aux = (Node*)malloc(sizeof(Node));

    if(aux != NULL){

        aux->e = e;

        posicionaLlista(l, e);

        aux->next = (Node **)malloc(sizeof(Node*)*(l->quants));

        if(aux->next != NULL){
            for(i=0;i<l->quants;i++){

                aux->next[i] = (l->ant[i])->next[i];
                (l->ant[i])->next[i] = aux;

            }

        } else {

            throwError("ERROR AUX NEXT");

        }

    } else {
        throwError("ERROR MEMORIA INSERT NODE");
    }

}

void LLISTA_esborra(Llista *l, int quin){

    int i;
    Node *aux;

    aux = l->ant[quin]->next[quin];

    for(i=0;i<l->quants;i++){
        l->ant[i] = l->pri;

        while(l->ant[i]->next[i] != aux){
            l->ant[i] = l->ant[i]->next[i];
        }

        l->ant[i]->next[i] = l->ant[i]->next[i]->next[i];

        free(aux->next[i]);
    }

    free(aux);

}

void LLISTA_vesInici(Llista *l, int quin){

    if(quin <= l->quants){
        l->ant[quin] = l->pri;
    } else {
        throwError("CAMP NO EXISTENT");
    }
}

void LLISTA_totsInici(Llista *l){
    int i;
    for(i=0;i<l->quants;i++){
        l->ant[i] = l->pri;
    }
}

void LLISTA_forward(Llista *l, int quin){

    if(l->ant[quin]->next[quin] != NULL){
        l->ant[quin] = l->ant[quin]->next[quin];
    } else {
        throwError("OJOOO");
    }

}

int LLISTA_esFinal(Llista l, int quin){

    if(quin > l.quants){
        throwError("OutOfBounds");
        printf("\nQUIN: %d\n", quin);
        return 1;
    } else {

        if(l.ant[quin] == NULL){
            printf("\nl.ant[%d] NULL!!!!!!!!\n", quin);
        }

        return (((l.ant[quin])->next[quin]) == NULL);
    }


}
