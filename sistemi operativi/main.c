//
//  main.c
//  sistemi operativi
//
//  Created by Valerio Trotta on 02/03/16.
//  Copyright (c) 2016 Valerio Trotta. All rights reserved.
//
//Esercizio: scrivere un programma per stampare in ordine lessicografico
//le parole passate come argomenti sulla linea comando (non devono esistere
//                                                      limiti al numero di parole gestibili)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct lista{
    int value;
    struct lista* next;
};

void alloca_nodo();
void aggiungi_nodo();
void rimuovi_nodo();
void libera_nodo();
void libera_lista();

int main(int argc, const char * argv[]) {
    int v;
    while (feof(stdin) == 0){       //riesegui fino a quando non si preme ctrl+d
        if (fscanf(stdin,"%d",&v)==1)
        {
            fprintf(stdout,"%d\n",v);
        }
        
    }
    fprintf(stdout,"Fine processo!");
    
    
    
    return EXIT_SUCCESS;
    

}




