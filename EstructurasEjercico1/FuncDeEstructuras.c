
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "FuncDeEstructuras.h"
#include "FuncDeCadenas.h"




void asignarDatos(struct Persona *p){
    p->dni = 123456;
    strcpy(p->nombre,"Juan Perez");
    p->sueldo=2354.84;
}

void leerDatos(struct Persona*per,int *numPer){
    FILE *arch;
    struct Persona p;
    arch=abrirArchivo("personal.csv","r");
    *numPer=0;
    while(1){
        leePersona(arch,&p);
        
    }
}








