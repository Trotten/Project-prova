#include "../basic/basic.h"
#include "../procinfo/procinfo.h"
#include "../datiprocfiglio/datiprocfiglio.h"
#include "../lavorofiglio/lavorofiglio.h"
#include "../datiproc/datiproc.h"
#include "../processoprincipale/processoprincipale.h"
#include "../procsecondario/procsecondario.h"
#include "../infoserver/infoserver.h"
#include "../datipernuoviproc/datipernuoviproc.h"
#include "../impostazioni/impostazioni.h"
#include "../setup/setup.h"



struct impostazioni *inizzializzaimp(){
struct impostazioni *impo=malloc(sizeof(struct impostazioni));
impo->procliberimin=1;
impo->procliberimax=6 ;
impo->durata_attesa=300000 ;
impo->thread_iniziali=5 ;
impo->iterazioni_massime_thread=20 ;
impo->massimo_thread_liberi=10 ;
impo->minimo_thread_liberi=30 ;
impo->log=0;
impo->serv_port=5193;
impo->backlog=10;
impo->numproc=10;
impo->vel_creazione=100;
impo->processi_iniziali=3;
return impo;
}



struct impostazioni *caricaimpostazioni(){
/*
valori per il file di impostazioni

PROCLIBERIMIN
PROCLIBERIMAX
DURATA_ATTESA
THREAD_INIZIALI
ITERAZIONI_MASSIME_THREAD
MASSIMO_THREAD_LIBERI
MINIMO_THREAD_LIBERI
LOG
SERV_PORT
BACKLOG
NUMPROC
VEL_CREAZIONE
PROCESSI_INIZIALI
*/


int num=0;
int val;
FILE *fd;
char buff[50];
struct impostazioni * imp;
imp=inizzializzaimp();
fd=fopen("impostazioni.txt","r");
if( fd==NULL ) {
	printf("Si e' verificato un errore in apertura del file di impostazioni, ");
	printf("verranno caricate quelle di default\n");
	return imp;				
}

while(1)
{

	num=fscanf(fd,"%s",buff);
	if(num==EOF)
		break;

	num=fscanf(fd,"%d",&val);
	if(num==EOF)
		break;
	
	if(strcmp("PROCLIBERIMIN",buff)==0)
	imp->procliberimin=val;
	if(strcmp("PROCLIBERIMAX",buff)==0)
	imp->procliberimax=val;
	if(strcmp("DURATA_ATTESA",buff)==0)
	imp->durata_attesa=val;
	if(strcmp("THREAD_INIZIALI",buff)==0)
	imp->thread_iniziali=val;
	if(strcmp("ITERAZIONI_MASSIME_THREAD",buff)==0)
	imp->iterazioni_massime_thread=val;
	if(strcmp("MASSIMO_THREAD_LIBERI",buff)==0)
	imp->massimo_thread_liberi=val;
	if(strcmp("MINIMO_THREAD_LIBERI",buff)==0)
	imp->minimo_thread_liberi=val;
	if(strcmp("LOG",buff)==0)
	imp->log=val;
	if(strcmp("SERV_PORT",buff)==0)
	imp->serv_port=val;
	if(strcmp("BACKLOG",buff)==0)
	imp->backlog=val;
	if(strcmp("NUMPROC",buff)==0)
	imp->numproc=val;
	if(strcmp("VEL_CREAZIONE",buff)==0)
	imp->vel_creazione=val;
	if(strcmp("PROCESSI_INIZIALI",buff)==0)
	imp->processi_iniziali=val;
}

fclose(fd);

return imp;
}

