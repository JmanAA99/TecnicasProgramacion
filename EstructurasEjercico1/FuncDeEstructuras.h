/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncDeEstructuras.h
 * Author: JOSE
 *
 * Created on 19 de noviembre de 2018, 10:59 PM
 */

#ifndef FUNCDEESTRUCTURAS_H
#define FUNCDEESTRUCTURAS_H

 void asignarDatos(struct Persona*);
 void leerDatos(struct Persona*, int *);
 void impDatos(struct Persona*, int );
 void ordenarEst(struct Persona*, int );
 void leePersona(FILE*arch,struct Persona*p);
 void cambiarEst(struct Persona*,int , int);

#endif /* FUNCDEESTRUCTURAS_H */

