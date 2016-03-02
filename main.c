//
//  main.c
//  
//
//  Created by Valerio Trotta on 02/03/16.
//
//

#include <stdio.h>

int function(int v);
int v=1;
int g=1;


int main (int argc, char* argv[])
{
    
//    v=function(v);
//    fprintf(stdout, "%d\n",v);
//    v=function(v);
//    fprintf(stdout, "%d\n",v);
//    v=function(v);
//    fprintf(stdout, "%d\n",v);
    int *pointer;
    pointer=&g;
    g=g+1;
    printf("%d\n",g);
    printf("%d\n",*pointer);
    g=g+1;
    printf("%d\n",g);
    printf("%d\n",*pointer);
    
}

int function(int v1){
    g=g+v1;
    return g;
}
