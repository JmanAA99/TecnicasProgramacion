
#include <stdio.h>
#include <stdlib.h>
#include "FuncDeCadenas.h"
#include "FuncDeDatos.h"
#include <string.h>



char *leerCadena(char * cadena, int max, FILE*arch){
    int l;
    fgets(cadena,max,arch);
    if(feof(arch)) return NULL;
    l=strlen(cadena);
    cadena[l-1]=0;
    return cadena;
}


char* leerCadenaExacta(FILE*arch){
    char buff[500],*pt;
    int l;
    leerCadena(buff, 500, arch);
    if(feof(arch)) return NULL;
    l=strlen(buff);
    pt = (char*)malloc(sizeof(char)*(l+1));
    strcpy(pt,buff);
    return pt;
}


FILE* abrirArchivo(const char*nombArch,const char*modo){
    FILE* arch;
    arch = fopen(nombArch, modo);
    if(arch==NULL){
        printf("ERROR: No se puede abrir el archivo %s\n",nombArch);
        exit(1);
    }
    return arch;
}


void leeDatos(char **nomb,int *numDat){
    FILE*arch;
    char *pt;
    arch = abrirArchivo("personal.txt","r");
    *numDat=0;
    while(1){
        pt = leerCadenaExacta(arch);
        if(pt == NULL) break; //Por eso retornamos un valor a pt;
        nomb[*numDat] = pt;
        (*numDat)++;
    }
    fclose(arch);
}

void imprimirDatos(char**nomb, int numDat){
    for(int i=0;i<numDat;i++)
        printf("%-40s",nomb[i]);
}

void liberarEspacios(char**nomb, int numDat){
    for(int i=0;i<numDat;i++)
        free(nomb[i]);
    
}

void ordenar(char **nomb, int numDat){
   for(int i=0; i<numDat-1; i++)
     for(int j=i+1; j<numDat; j++)
        if (strcmp(nomb[i],nomb[j])>0)
            cambiar(nomb, i,j);
}

void cambiar(char **nomb,int i,int j){
    char* aux;
    aux = nomb[i];
    nomb[i] = nomb[j];
    nomb[j] = aux;
}

void sacaPalabras(char*frase, char**palabra,int*numPal){
    int i=0, c;
    char buff[30], *ptCad;
    *numPal=0;
    while(1){
        while(frase[i]==' ')i++; //Avanza el contador, pero no hace ni pincho
        if(frase[i]==0) break; // Termina la frase
        c=0;
        while(frase[i]!=' ' && frase[i]!=0){
            //La palabra identificada se guarda en el buffer temporar
            // Para luego ser asignada a una cadena dinamica
            buff[c]=frase[i]; 
            c++;
            i++;
        }
        buff[c] = 0; // Se le agrega el cero al final de la palabra
        ptCad = (char*)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(ptCad, buff);
        palabra[*numPal] = ptCad; //Se le asigna una direccion de memoria
        (*numPal)++;
    }
}


void sacaPalabrasCSV(char* frase, char**palabra, int*numPal){
    int i=0, c=0;
    char buff[200],*ptCad;
    (*numPal)=0;
    while(1){
        while(frase[i]==' ')i++;
        if(frase[i]==0) break;
        c=0;
        while(frase[i]!=',' && frase[i]!=0){
            buff[c]=frase[i];
            i++;
            c++;
    }
    buff[c]=0;
    ptCad =(char*)malloc(sizeof(char)*(strlen(buff)+1));
    strcpy(ptCad,buff);
    palabra[*numPal]=ptCad;
    (*numPal)++;
    }
}











