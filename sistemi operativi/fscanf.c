////
////  main.c
////  sistemi operativi
////
////  Created by Valerio Trotta on 02/03/16.
////  Copyright (c) 2016 Valerio Trotta. All rights reserved.
////
////esercitazioni con getchar e putchar da file
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//
//
//
//int main(int argc, const char * argv[]) {
//    
//    char* stringa;
//    char* pointer;
//    errno=0;
//    int size=(int)strtol(argv[1],&pointer,0);
//    if (errno!=0 || *pointer!='\0'){
//        fprintf(stderr,"errore nella strtol");
//        exit(EXIT_FAILURE);
//    }
//    stringa=(char*)calloc(size,sizeof(char));
//    if (stringa==NULL){
//        fprintf(stderr,"errore nella calloc");
//        exit(EXIT_FAILURE);
//    }
//    fprintf(stdout,"%d\n",(int)sizeof(int));
//    fprintf(stdout,"%d\n",(int)sizeof(char));
//    int v;
//    char c;
//    while(feof(stdin)==0)
//    {
//        if (fscanf(stdin,"%d",&v)==1)
//            fprintf(stdout,"%d\n",v);
//        else if(fscanf(stdin,"%c",&c)==1){
//            fprintf(stdout,"hai inserito una stringa\n");
//            fprintf(stdout,"%c\n",c);
//        }
//    }
////    fscanf(stdin,"%d",&v);
////    fprintf(stdout,"%d\n",v);
////    return EXIT_SUCCESS;
//    
//
//}
//
//
//
//
