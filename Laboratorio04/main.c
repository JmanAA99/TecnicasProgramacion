
/* 
 * File:   main.c
 * Author: JOSE
 *
 * Created on 9 de noviembre de 2018, 09:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lab4Funciones.h"


int main(int argc, char** argv) {
    int codA[100], codAlmacenA[100], stockA[100], numArt, numCompras;
    double precioU[100], precioUD[100];
    double fechaCompra[500], horaCompra[500], montoGastado[500];
    FILE *archArt,*archTot, *archCom, *archArtOrd;
    
    archArtOrd = fopen("ArticulosOrd.txt","w");
    if(archArtOrd==NULL){
        printf("No se puede abrir ArtciculosOrd.txt");
        exit(1);
    }
    archArt=fopen("Articulos.txt","r");
    if(archArt==NULL){
         printf("No se puede abrir Articulos.txt");
         exit(1);
    }
    archCom=fopen("Compras.txt","r");
     if(archCom==NULL){
         printf("No se puede abrir Compras.txt");
         exit(1);
     }
    archTot=fopen("Totales.txt","w");
     if(archTot==NULL){
         printf("No se puede abrir Totales.txt");
         exit(1);
     }
     
    
   numArt = reescribirArticulos(codA, codAlmacenA, stockA, precioU, precioUD, archArt, archArtOrd); //SOY UN WEBON POR LA PUTA MADRE
   numCompras = determinarMontoGastado(codA, codAlmacenA, stockA, precioU, precioUD, numArt, fechaCompra, horaCompra, montoGastado, archCom);
           
    imprimirArchivoTotales(numCompras, fechaCompra, horaCompra, montoGastado, archTot);   
    
    opEstadisticas(numCompras, fechaCompra, horaCompra, montoGastado);
    
    //Ahora le haremos una modificacion agregando una busqueda binaria;
    

    return (EXIT_SUCCESS);
}
    

