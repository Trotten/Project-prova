////
////  main.c
////  sistemi operativi
////
////  Created by Valerio Trotta on 02/03/16.
////  Copyright (c) 2016 Valerio Trotta. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//
//int main(int argc, const char * argv[]) {
//    
//
//    char* pointer;
//    errno=0;
//    int number=(int)strtol(argv[1],&pointer,0);
//    if (errno!=0 || *pointer!='\0')
//    {
//        printf("Inserire solo un valore");
//        return EXIT_FAILURE;
//    }
//    
//    
//    int* list;
//    list=(int*)calloc(number,sizeof(int));
//    if (list==NULL){
//        fprintf(stderr,"errore nella calloc");
//        return EXIT_FAILURE;
//    }
//    for (int i=0;i<number;i++){
//        list[i]=i;
//    }
//    
//    for (int i=0;i<number;i++){
//        printf("%d\n",list[i]);
//    }
//    
//    
//    number=number+2;
//    
//    list=(int*)realloc(list,number*sizeof(int));
//    
//    for (int i=0;i<number;i++){
//        list[i]=i;
//    }
//    
//    for (int i=0;i<number;i++){
//        printf("%d\n",list[i]);
//    }
//    
//    
//    
//    free(list);
//    return EXIT_SUCCESS;
//}
