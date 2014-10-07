#include <stdio.h>
#include "Llista.h"

void showHeader(char *nom){
    printf("\n***INICI %s*** \n", nom);
}

void showFooter(char *nom){
    printf("\n***FI %s*** \n", nom);
}

void test(int result, char* text){
    printf("\n%s: ", text);
    if(result){
        printf("OK\n");
    } else {
        printf("FAIL\n");
    }
}

void testElement(){
    Element e1;
    Element e2;

    ELEMENT_crea(&e1, "Jose", 20, 'H', 1.75);
    ELEMENT_crea(&e2, "Pepa", 25, 'D', 1.65);

    int test1 = ELEMENT_compara(e1, e2, NOM, MESPETIT);
    int test2 = ELEMENT_compara(e1, e2, EDAT, MESPETIT);
    int test3 = ELEMENT_compara(e1, e2, SEXE, MESGRAN);
    int test4 = ELEMENT_compara(e1, e2, ALTURA, MESGRAN);

    test(test1, "NOM");
    test(test2, "EDAT");
    test(test3, "SEXE");
    test(test4, "ALTURA");

}

void mostraLlista(Llista *l){
    LLISTA_totsInici(l);
    int i;
    for(i=0;i<8;i++){
        printf("\n*****\nORDENACIO %d\n\n", i);
        while (!LLISTA_esFinal(*l, i)) {
            ELEMENT_debugElement(LLISTA_consulta(*l, i));
            LLISTA_forward(l, i);
        }
    }

}

void ompleLlista(Llista *l){

    Element e1;
    ELEMENT_crea(&e1, "JOSE", 25, 'H', 1.54);

    Element e2;
    ELEMENT_crea(&e2, "PEPE", 20, 'H', 1.60);

    Element e3;
    ELEMENT_crea(&e3, "LAURA", 29, 'D', 1.55);

    showHeader("INSEREIX 1");
    LLISTA_insereix(l, e1);
    showFooter("INSEREIX 1");

    showHeader("INSEREIX 2");
    LLISTA_insereix(l, e2);
    showFooter("INSEREIX 2");

    showHeader("INSEREIX 3");
    LLISTA_insereix(l, e3);
    showFooter("INSEREIX 3");

}

int main(int argc, const char * argv[]) {

    Llista l;

    showHeader("TEST ELEMENT");

    testElement();

    showFooter("TEST ELEMENT");


    LLISTA_crea(&l, 8, "0>0<1>1<2>2<3>3<");



    ompleLlista(&l);


    showHeader("MOSTRA LLISTA");
    mostraLlista(&l);
    showFooter("MOSTRA LLISTA");

    return 0;
}
