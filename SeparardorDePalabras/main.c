
/* 
 * File:   main.c
 * Author: JOSE
 *
 * Created on 19 de noviembre de 2018, 09:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncDeCadenas.h"
#include "FuncDeDatos.h"
#include <string.h>

int main(int argc, char** argv) {
    int codigo[100], numDat;
    double sueldo[100];
    char *nomb[100];
    
    char frase[500];
    char*palabra[50];
    int numPal;
    
    leerCadena(frase, 500, stdin);
    sacaPalabras(frase, palabra, &numPal);
    for(int i=0; i<numPal;i++)
        printf("%s\n",palabra[i]);
    liberarEspacios(palabra,numPal);
    
/*
    leeDatos(codigo, nomb, sueldo, &numDat);
    imprimeDatos(codigo, nomb, sueldo, numDat);
*/

    return (EXIT_SUCCESS);
}

