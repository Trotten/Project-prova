
#ifndef DATIPROC_H
#define DATIPROC_H


//struttura per il passaggio di informazioni dal processo figlio al processo principale (serve e viene usata dal processo 
//principale)
//tipi:
//	DISP         100
//	POSTI        101

struct datiproc{
	int tipo;		//tipo di informazione: DISP o POSTI
	int valore;		//valore dell'informazione
};
#endif
