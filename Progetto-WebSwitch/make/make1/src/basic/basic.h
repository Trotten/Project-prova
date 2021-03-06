
#ifndef BASIC_H
#define BASIC_H


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>


#define SERV_PORT   5193
#define BACKLOG       10
#define MAXLINE     1024
#define NUMPROC       10

#define DISP	     100
#define POSTI        101

#define PROCLIBERIMIN	     1
#define PROCLIBERIMAX	     6
#define DURATA_ATTESA	     300000
#define THREAD_INIZIALI       5
#define ITERAZIONI_MASSIME_THREAD 20
#define MASSIMO_THREAD_LIBERI 100
#define MINIMO_THREAD_LIBERI 30

#endif
