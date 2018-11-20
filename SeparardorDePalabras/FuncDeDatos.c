
#include <stdio.h>
#include <stdlib.h>
#include "FuncDeCadenas.h"
#include "FuncDeDatos.h"
#include <string.h>


void leerDatos(int *codigo, char**nomb,double*sueldo,
                int *numDat){
    FILE* arch;
    char cadDatos,*datos[20];
    int cant;
    
    arch = abrirArchivo("personal.csv","r");
    *numDat=0;
    while(1){
        leerCadena(cadDatos,500,arch);
        if(feof(arch)) break;
    sacaPalabrasCSV(cadDatos, datos, &cant);
    codigo[*numDat] = atoi(datos[0]);
    nomb[*numDat] = datos[1];
    sueldo[*numDat] = atof(datos[2]);
    (*numDat)++;
    free(datos[0]);
    free(datos[2]);
    }
}












