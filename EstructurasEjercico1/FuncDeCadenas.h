/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncDeCadenas.h
 * Author: JOSE
 *
 * Created on 19 de noviembre de 2018, 09:02 PM
 */

#ifndef FUNCDECADENAS_H
#define FUNCDECADENAS_H

char* leerCadena(char *,int, FILE*);
FILE *abrirArchivo(const char*, const char*);
char *leerCadenaExacta(FILE*);
void leeDatos(char **,int *);
void imprimirDatos(char**, int);
void liberarEspacios(char **, int);
void ordenar(char **, int );
void cambiar(char **,int ,int);
void sacaPalabras(char*, char**,int *);
void sacaPalabrasCSV(char*, char**,int *);

#endif /* FUNCDECADENAS_H */

