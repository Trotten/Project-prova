//
//  main.c
//  sistemi operativi
//
//  Created by Valerio Trotta on 02/03/16.
//  Copyright (c) 2016 Valerio Trotta. All rights reserved.
//
//Esercizio: realizzare un programma che legge da riga comando tre argomenti:
//(1) il nome di un file di input, (2) il nome di un file di output, e (3) un
//numero naturale n. Si deve copiare il file di input nel file di output
//invertendo ciascun blocco di dimensione n [invertiblocco.c] (di stringhe presumo)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void openfile(char* path_in,char* path_outp,int* fd_in,int* fd_out);
void readnumber(unsigned long* n,char* stringa);
void scambia(unsigned long size,int input,int output);
void leggiblocco(char* buffer,int input,int output,unsigned long size);
void invertiblocco(int elem,char* buffer);
void scriviblocco(int output,char* buffer,unsigned long size);

int main(int argc, const char* argv[]) {
    
    if (argc!=4){
        fprintf(stderr,"Inserire tre argomenti\n");
        exit(EXIT_FAILURE);
    }
    int input,output;
    openfile(argv[1],argv[2],&input,&output);
    unsigned long n;
    readnumber(&n,argv[3]);
    scambia(n,input,output);
    return EXIT_SUCCESS;
    

}

void openfile(char* path_in,char* path_out,int* fd_in,int* fd_out){
    *fd_in=open(path_in,O_RDONLY);
    if (*fd_in==-1){
        perror("Errore nell'apertura del file di input\n");
        exit(EXIT_FAILURE);
    }
    *fd_out=open(path_out,O_WRONLY);
    if (*fd_out==-1){
        perror("Errore nell'apertura del file di output\n");
        exit(EXIT_FAILURE);
    }
    
}


void readnumber(unsigned long* n,char* stringa){
    char* pointer;
    errno=0;
    *n=strtoul(stringa,&pointer,0);
    if (errno!=0 || *pointer!='\0'){
        perror("Errore nell'inserimento della dimensione dei blocchi\n");
        exit(EXIT_FAILURE);
    }
    if ((*n)<0){
        fprintf(stderr,"Inserire un numero maggiore di 0\n");
        exit(EXIT_FAILURE);
    }
}

void scambia(unsigned long size,int input,int output){
    char* buffer;
    buffer=(char*)calloc(size,sizeof(char));
    if (buffer==NULL){
        perror("Errore nella calloc\n");
        exit(EXIT_FAILURE);
    }
    leggiblocco(buffer,input,output,size);
    
}

void leggiblocco(char* buffer,int input,int output,unsigned long size){
    int elem=1;
    while(elem!=0){
        elem=read(input,buffer,size);
        if (elem==0){
            break;
        }
        invertiblocco(elem,buffer);
        scriviblocco(output,buffer,size);
        
    }
    
}

void invertiblocco(int elem,char* buffer){
    char temp;
    int i;
    int size=elem-1;
    for (i=0;i<elem/2;i++){
        temp=buffer[i];
        buffer[i]=buffer[size];
        buffer[size]=temp;
        size=size-1;
    }
}

void scriviblocco(int output,char* buffer,unsigned long size){
    int elem=write(output,buffer,size);
    if (elem==0 || elem==-1){
        fprintf(stderr,"Elementi non scritti correttamente\n");
        exit(EXIT_FAILURE);
    }
}




