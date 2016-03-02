
#include "basic/basic.h"
#include "procinfo/procinfo.h"
#include "datiprocfiglio/datiprocfiglio.h"
#include "lavorofiglio/lavorofiglio.h"
#include "datiproc/datiproc.h"
#include "processoprincipale/processoprincipale.h"
#include "procsecondario/procsecondario.h"
#include "setup/setup.h"
#include "infoserver/infoserver.h"
#include "datipernuoviproc/datipernuoviproc.h"



int main(){	
	struct infoserver *info;
		
	struct sockaddr_in    servaddr;
	int listensd;


	if ((listensd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("errore in socket");
		exit(1);
	}


	memset((void *)&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(SERV_PORT);


	if ((bind(listensd, (struct sockaddr *) &servaddr, sizeof(struct sockaddr_in))) < 0) {
		perror("errore in bind");
		exit(1);
	}


	if (listen(listensd, BACKLOG) < 0 ) { 
		perror("errore in listen");
		exit(1);
	}
/*
//////////////da spostare ne lavoro del thread....passare listensd ai figli
	int connsd;
	if ((connsd = accept(listensd, (struct sockaddr *)NULL, NULL)) < 0) {
		perror("errore in accept");
		exit(1);
	}

	//char          buff[MAXLINE];

 	//snprintf(buff, sizeof(buff), "%.24s\r\n","ciaoooooooooooo\n");

    if (write(connsd, "ciaoooooooooooo\n", strlen("ciaoooooooooooo\n")) != strlen("ciaoooooooooooo\n")) {
      perror("errore in write"); 
      exit(1);
    }

    if (close(connsd) == -1) {  		* chiude la connessione *
      perror("errore in close");
      exit(1);
    }   
*/

	
	info=setup(listensd);
pause();	//DA TOGLIERE
	struct procinfo *procini2=*(info->pass->procini);
		//printf("%d\n",(int)info);
		//printf("%d     %d        %d\n",(int)info->procini,(int)*info->procini,(int)procini2);
		//printf("%d\n",(int)procini2->procpid);
	struct lavorofiglio *c=malloc(sizeof(struct lavorofiglio));
	c->dacambiare=99;
	int g=write(procini2->pip[1],c, sizeof(struct lavorofiglio));
		if (g == -1) {
			fprintf(stderr, "Error while writing file\n");
			exit(EXIT_FAILURE);
		}

	
int pinnolone=0;
	while(1){
		//lavoro padre
			pinnolone++;
			sleep(1);
		
	}


	exit(0);
}

