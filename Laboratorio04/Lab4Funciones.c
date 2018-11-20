
#include <stdio.h>
#include <stdlib.h>
#include "Lab4Funciones.h"


int reescribirArticulos(int *codA,int * codAlmacenA,int * stockA,double* precioU,double* precioUD,FILE *archArt,FILE *archArtOrd){
    //Leer Archivo y asignar arreglos
    int numArt=0;
    while(1){
        fscanf(archArt,"%d %d %lf %lf %d",&codA[numArt],&codAlmacenA[numArt],&precioU[numArt]
                ,&precioUD[numArt],&stockA[numArt]);
        if(feof(archArt)) break;
        numArt++;
    }
    //fclose(archArt);
    
    ordenarArticulos(codA, codAlmacenA, stockA, precioU, precioUD, numArt); // CARAJO HASTA AHORA NO SE
    
    for(int i=0;i<numArt;i++){
        fprintf(archArtOrd,"%20d %20d %20.2lf %20.2lf %20d\n",codA[i],codAlmacenA[i],precioU[i]
                ,precioUD[i],stockA[i]);
    }
    
  fclose(archArtOrd);
  return numArt;
}


 void ordenarArticulos(int *codA,int * codAlmacenA,int * stockA,double* precioU,double* precioUD,int numArt){
     for(int i=0;i<numArt-1;i++)
         for(int j=i+1;j<numArt;j++)
             if(codA[j]<codA[i]){
                 swap(codA,i,j);
                 swap(codAlmacenA,i,j);
                 swap(stockA, i,j);
                 swapD(precioU, i,j);
                 swapD(precioUD,i,j);
             }
 }

  void swap(int *arr, int i, int j){
     int aux;
     aux=arr[i];
     arr[i]=arr[j];
     arr[j]=aux;
 }
 
 
 void swapD(double *arr, int i, int j){
     double aux;
     aux=arr[i];
     arr[i]=arr[j];
     arr[j]=aux;
 }
 
int determinarMontoGastado(int *codA,int* codAlmacenA,int* stockA,double* precioU,double* precioUD,int numArt,int* fechaCompra,int* horaCompra,double* montoGastado,FILE* archCom){
    int numCompras,dd,mm,aa,hor,min,seg,dniCliente, codigoP, cantP;
    int fechaC, tiempoCom;
    double precioxProd, totalCompra;
    
    numCompras=0;
   
        while(1){
            fscanf(archCom,"%d/%d/%d %d:%d:%d %d",&dd,&mm,&aa,&hor,&min,&seg,&dniCliente);
            if(feof(archCom)) break;
            fechaC=aa*10000+mm*100+dd;
            tiempoCom=hor*3600+min*60+seg;
            totalCompra=0;
            while(1){
                fscanf(archCom,"%d %d",&codigoP, &cantP);
                if(fgetc(archCom)=='\n') break;
                precioxProd = buscarArticulo(codA, codAlmacenA, stockA, precioU, precioUD, numArt, cantP, codigoP);
                if(precioxProd!=-1)
                totalCompra+=precioxProd;
                
            }
            fechaCompra[numCompras]=fechaC;
            horaCompra[numCompras]=tiempoCom;
            montoGastado[numCompras]=totalCompra;
            numCompras++;        
 }
  return numCompras; 
  
}


double buscarArticulo(int* codA,int* codAlmacenA,int* stockA,double* precioU,double* precioUD,int numArt,int cantP,int codigoP){
     int i, indice;
     double precioXprod;
       
       for(i=0;i<numArt;i++){
           if(i==numArt) return -1;
            if(codigoP==codA[i]){
                if(cantP<=stockA[i]){
                    if(cantP%12==0) precioXprod=precioUD[i]*cantP;
                    else precioXprod=precioU[i]*cantP;
                    stockA[i]-=cantP;        
                }
                else if(cantP>stockA[i]){
                    precioXprod=precioU[i]*stockA[i];
                    stockA[i]=0;
                }
       }
    }
     
     
       
    return precioXprod;   
    
}

void imprimirArchivoTotales(int numCompras, int* fechaCompra,int* horaCompra,double* montoGastado,FILE* archTot){
    int dd,mm,aa,hor,min,seg;
    int c;
    ordenarTotales(numCompras,fechaCompra, horaCompra, montoGastado);
    for(int i=0; i<numCompras;i++){
        
    descomponerFecha(&aa,&mm,&dd,fechaCompra[i]);
    descomponerHora(&hor,&min,&seg,horaCompra[i]);
    fprintf(archTot,"%d/%d%/%d     %02d:%02d:%02d   %.2lf\n",dd,mm,aa,hor,min,seg,montoGastado[i]);
    
    
    
    }
    fclose(archTot);
    
}

void descomponerFecha(int *aa,int*mm,int*dd,int fecha){
    *aa=fecha/10000;
    fecha%=10000;
    *mm=fecha/100;
    fecha%=100;
    *dd=fecha;
    
    
}
void descomponerHora(int*hor,int*min,int*seg,int horaC){
    *hor=horaC/3600;
    horaC%=3600;
    *min=horaC/60;
    horaC%=60;
    *seg=horaC;
}

void ordenarTotales(int numCompras,int* fechaCompra,int* horaCompra,double* montoGastado){
    for(int i=0;i<numCompras-1;i++)
        for(int j=i+1;j<numCompras;j++)
            if(fechaCompra[i]>fechaCompra[j]||
               fechaCompra[i]==fechaCompra[j] && horaCompra[i]>fechaCompra[j]){
                swap(fechaCompra, i,j);
                swap(horaCompra,i,j);
                swapD(montoGastado,i,j);
            }
    
}


void opEstadisticas(int numCompras,int* fechaCompra,int* horaCompra,double* montoGastado){
    double mediana, promedio, suma;
    ordenarxCosto(numCompras, fechaCompra, horaCompra, montoGastado);
    for(int i=0;i<numCompras;i++){
        suma+=montoGastado[i];
    }
    promedio=suma/numCompras;
    
    if(numCompras%2==0){
        mediana=(montoGastado[numCompras/2]+montoGastado[(numCompras+1)/2])/2;
    }
    else mediana=montoGastado[numCompras/2];
                
              
    printf("El promedio es: %.2lf\n",promedio);
    printf("La mediana es : %.2lf\n",mediana);
}




void ordenarxCosto(int numCompras,int* fechaCompra,int* horaCompra,double* montoGastado){
    for(int i=0;i<numCompras-1;i++)
        for(int j=i+1;j<numCompras;j++)
            if(montoGastado[i]>montoGastado[j]){
                swap(fechaCompra,i,j);
                swap(horaCompra,i,j);
                swapD(montoGastado,i,j);
            }
}






 
 
 





