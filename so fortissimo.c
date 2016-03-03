//
//  so fortissimo.c
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


char* alloca_memoria(int size){
    char* stringa=(char*)calloc(size,sizeof(char));
    if (stringa==NULL){
        fprintf(stderr,"Errore nell'allocazione della memoria");
        exit(EXIT_FAILURE);
    }
    return stringa;
}

void scambia(char* carattere1,char* carattere2){
    char temp=*carattere1;
    *carattere1=*carattere2;
    *carattere2=temp;
}



void ordina_stringa(char** stringa){
    int size=(int)strlen(*stringa);
    int i,j;
    for (i=0;i<size;i++){
        for (j=0;j<size-1;j++){
            if ((*stringa)[j]>(*stringa)[j+1])
                scambia(&((*stringa)[j]),&((*stringa)[j+1]));
        }
    }
    
    
}
    



void stampa_stringa(char* stringa){
    int size=(int)strlen(stringa);
    for (int i=0;i<size;i++){
        fprintf(stdout,"%c",stringa[i]);
    }
}


    
    
int main(int argc, const char * argv[]) {
    
    
    if (argc!=2){
        fprintf(stdout,"Usage: inserire una sola parola");
        return EXIT_FAILURE;
    }
    
    int size=(int)strlen(argv[1]);
    char* stringa=alloca_memoria(size);
    strcpy(stringa,argv[1]);
    ordina_stringa(&stringa);
    stampa_stringa(stringa);
    free(stringa);
    
    
    
    
    return EXIT_SUCCESS;
    

}
