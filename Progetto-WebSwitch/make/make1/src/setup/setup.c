#include "../basic/basic.h"
#include "../procinfo/procinfo.h"
#include "../datiprocfiglio/datiprocfiglio.h"
#include "../lavorofiglio/lavorofiglio.h"
#include "../datiproc/datiproc.h"
#include "../processoprincipale/processoprincipale.h"
#include "../procsecondario/procsecondario.h"
#include "../infoserver/infoserver.h"
#include "../datipernuoviproc/datipernuoviproc.h"



void *gestorenumeroprocessifiglidisponibili(void *arg){			//thread per gestire il numero di 	
									//processi figli contemporaneamente
									//disponibili nel sistema
	
	struct datipernuoviproc *dati=arg;
	struct procinfo **pro=dati->procini;
	

	//struct procinfo *procini=*pro;
		
		//if(procini==NULL)
	printf("%d\n",(int)*pro);
	if(*pro==NULL)
		//procini=aggiungiprocesso(procini,creaprocesso());	
		*pro=aggiungiprocesso(*pro,creaprocesso(dati->listens));
		

	struct procinfo *appoggio;
	int liberi;

	if(kill(getpid(),SIGUSR1)!=0)
		perror("kill");
	while(1){
	
		appoggio=*pro;
		liberi=1;
		while(appoggio->next!=NULL)
			{
				liberi++;
				appoggio=appoggio->next;

			}
		while(liberi<PROCLIBERIMIN)
			{
				aggiungiprocesso(*pro,creaprocesso(dati->listens));
				liberi++;
			}
		while(liberi>PROCLIBERIMAX)
			{
			
					//da inseire il controllo su tutti i processi in esecuzione ed eliminarne quelli liberi fino ad averne in esecuzione un numero < di PROCLIBERIMAX
			}

	usleep(DURATA_ATTESA);
	
	}
}



void sighandler(int segnale){			//funzione per gestire il segnale di che indica la terminazione del setup 
	
	if(segnale==SIGUSR1)
		printf("setup terminato\n");
	else 
		printf("%d\n",segnale);
	//signal(segnale, sighandler);
}




struct infoserver * setup(int listen){							//funzione che fa partire il 
											//processo padre e il thread di 
											//controllo dei processi figli
	

	signal(SIGUSR1, sighandler);		//SIGUSR1 generato solo attraverso l'invocazione di una kill()

	struct infoserver *inf=malloc(sizeof(struct infoserver));
	inf->pass=malloc(sizeof(struct datipernuoviproc));
	inf->pass->listens=listen;
	inf->pass->procini=malloc(sizeof(struct procinfo*));

	//*(inf->procini)=malloc(sizeof(struct procinfo));	
	//(*(inf->procini))->listensd=listens;
	//struct procinfo *procini2=NULL;
	//inf->procini=&procini2;

	int err=pthread_create(&inf->threadcontrollo,NULL,gestorenumeroprocessifiglidisponibili,inf->pass);
	if(err!=0){
		fprintf (stderr,"Errore nel setup del server\n");
		exit(1);
	}
	pause();
	return inf;
}
