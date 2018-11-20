/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab4Funciones.h
 * Author: JOSE
 *
 * Created on 9 de noviembre de 2018, 09:53 PM
 */

#ifndef LAB4FUNCIONES_H
#define LAB4FUNCIONES_H

int reescribirArticulos(int *,int * ,int * ,double* ,double*,FILE *,FILE *);
void ordenarArticulos(int *,int * ,int * ,double* ,double* ,int );
void swap(int *, int , int );
void swapD(double *, int , int );
double buscarArticulo(int* ,int* ,int* ,double* ,double* ,int ,int ,int );
int determinarMontoGastado(int *,int* ,int* ,double*,double* ,int ,int* ,int* ,double* ,FILE* );
void ordenarTotales(int ,int* ,int* ,double* );
void descomponerHora(int*,int*,int*,int );
void descomponerFecha(int *,int*,int*,int );
void imprimirArchivoTotales(int , int* ,int* ,double* ,FILE* );
void ordenarxCosto(int ,int* ,int* ,double*);
void opEstadisticas(int ,int* ,int* ,double* );









#endif /* LAB4FUNCIONES_H */

