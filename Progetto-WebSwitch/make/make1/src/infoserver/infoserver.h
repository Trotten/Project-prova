
#ifndef INFOSERVER_H
#define INFOSERVER_H

struct infoserver{
						//struttura per la creazione del primo processo e 
						//del thread di controllo
	
	struct datipernuoviproc *pass;
	pthread_t threadcontrollo;

};




#endif
