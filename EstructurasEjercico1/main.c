
/* 
 * File:   main.c
 * Author: JOSE
 *
 * Created on 19 de noviembre de 2018, 10:47 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "FuncDeEstructuras.h"



int main(int argc, char** argv) {
    struct Persona per[50];
    int numPer;
    leerDatos(per,&numPer);
    ordenarEst(per,numPer);
    impDatos(per,numPer);
    return (EXIT_SUCCESS);
}



